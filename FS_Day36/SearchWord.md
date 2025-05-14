You are working on strings, list of words are given as source and 
list of words are given as target, you need to find words from target list are present in the source list or not.
if a word is present then print true otherwise print false. 

NOTE: Use Trie Datastructure

Input Format:
-------------
Line-1: A single integer N
Line-2: List contains N space separated words of source list.
Line-3: A single integer M
Line-4: List contains contain M space separated words of target list.

Output Format:
---------------
Line-1: List contains true or false

Sample Input-1:
---------------
5
abc def ghi jkl mno
4
abc fed ghi lkj

Sample Output-1: 
----------------
[true,false,true,false]

Sample Input-2:
---------------
10
a b c d e f g h i j
5
abc d ef g j

Sample Output-2:
----------------
[false, true, false, true, true]


```java
import java.util.Arrays;
import java.util.Scanner;

class TrieNode {
    TrieNode[] children;
    boolean eow;

    public TrieNode() {
        this.children = new TrieNode[26];
        this.eow = false;
    }
}

class Trie {
    private TrieNode root;

    public Trie() {
        this.root = new TrieNode();
    }

    public TrieNode getRoot() {
        return root;
    }

    public void insert(String word) {
        TrieNode crawl = root;

        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';

            if (crawl.children[idx] == null) {
                crawl.children[idx] = new TrieNode();
            }

            crawl = crawl.children[idx];
        }

        crawl.eow = true;

    }


    public boolean search(String word) {
        TrieNode crawl = root;

        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';

            if (crawl.children[idx] == null) {
                return false;
            }

            crawl = crawl.children[idx];
        }

        return crawl.eow;

    }

}

public class SearchList {

    private static boolean[] searchWords(String[] source, String[] target) {
        Trie trie = new Trie();

        for (String word : source) {
            trie.insert(word);
        }
        
        boolean[] ans = new boolean[target.length];
        int idx = 0;
        for(String word : target){
            ans[idx++] = trie.search(word);
        }

        return ans;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {

            int n = sc.nextInt();
            String[] source = new String[n];
            for(int i = 0 ; i < n ; i++){
                source[i] = sc.next();
            }
            
            
            int m = sc.nextInt();
            String[] target = new String[m];

            for(int i = 0 ; i < m ; i++){
                target[i] = sc.next();
            }

            System.out.println(Arrays.toString(searchWords(source, target)));

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
  
```
