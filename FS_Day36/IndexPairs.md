An 8th standard student has been assigned a task as part of punishment for his mistake.

The task is, there is an input string STR(without any space) and an array of 
strings words[]. Print all the pairs of indices [s, e] where s, e are starting 
index and ending index of every string in words[] in the input string STR.

Note: Print the pairs[s, e] in sorted order.
(i.e., sort them by their first coordinate, and in case of ties sort them by 
their second coordinate).

Input Format
------------
Line-1: string STR(without any space)
Line-2: space separated strings, words[]

Output Format
-------------
Print the pairs[s, e] in sorted order.


Sample Input-1:
---------------
thekmecandngitcolleges
kmec ngit colleges

Sample Output-1:
----------------
3 6
10 13
14 21


Sample Input-2:
---------------
xyxyx
xyx xy

Sample Output-2:
----------------
0 1
0 2
2 3
2 4

Explanation: 
------------
Notice that matches can overlap, see "xyx" is found at [0,2] and [2,4].


Sample Input-3:
---------------
kmecngitkmitarecsecolleges
kmit ngit kmec cse

Sample Output-3:
----------------
0 3
4 7
8 11
15 17

```java
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

}

public class IndexPairs {
    private static void printPairs(String[] words, String text) {



        Trie trie = new Trie();
        for (String word : words) {


            trie.insert(word);
        }

        // now travrese thorugh the text
        int n = text.length();
        
        int i = 0;
        while (i < n) {


            TrieNode crawl = trie.getRoot();

            int idx = text.charAt(i) - 'a';

            int j = i;
            if (crawl.children[idx] != null) {


                // start traversing
                while (j < n  && crawl.children[text.charAt(j) - 'a'] != null) {


                    crawl = crawl.children[text.charAt(j) - 'a'];
                    if (crawl.eow) {
                        
                        System.out.println(i + " " + j);
                    }
                    j++;
                }

            }

            i++;

        }

    }

    public static void main(String[] args) {


        try(Scanner sc = new Scanner(System.in)){



            String text = sc.nextLine();
    
            String[] words = sc.nextLine().split(" ");
    
            printPairs(words, text);

        }catch(Exception e){


            System.out.println(e.getMessage());
        }


    }

}
```