Mr.Uday is trying to develop a software which reads array of strings from user and gives the
longest common prefix of those strings, if no common prefix then it will give empty string. 
Help uday to develop program.


Input Format: 
-------------
Line-1: array of strings seperated by ','

Output Foramt: 
--------------
longest common prefix.

Sample Input-1:
---------------
flower,flow,flight

Sample Output-1: 
----------------
fl

Sample Input-2:
--------------
dog,racecar,car

Sample Output-2:
----------------
""

Explanation: There is no common prefix among the input strings.

Note: USE TRIE DATASTRUCTURE
      STRING SHOULD CONTAIN ONLY LOWER CASE ALPHABETS(a to z  only)



```java
import java.util.*;
class TrieNode {
    char val;
    boolean isEnd;
    TrieNode[] children;
    
    public TrieNode() {
        this.children = new TrieNode[26];
    }
    
    public TrieNode(char c) {
        this();
        this.val = c;
    }
}

class Trie {
    private TrieNode root;
    
    public Trie() {
        this.root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode curr = this.root;
        
        for (char c : word.toCharArray()) {
            if (curr.children[c - 'a'] == null) {
                curr.children[c - 'a'] = new TrieNode(c);
            }
            
            curr = curr.children[c - 'a'];
        }
        
        curr.isEnd = true;
    }
    
    public String longestCommonPrefix() {
        //Write your code here and return string
        TrieNode cur=root;
        int count=0;
        StringBuilder sb=new StringBuilder("");
        
        while(cur!=null){
            count=0;
            TrieNode sub=null;
            for(int i=0;i<26;i++){
                if(cur.children[i]!=null){
                    
                    sub=cur.children[i];
                    if(count==0){
                        sb.append(cur.children[i].val);
                    }
                    count++;
                }
            }
            // System.out.println(sb);
            if(count==1){
                cur=sub;
            } // System.out.println(sb);
            else{
                return sb.toString().substring(0,sb.toString().length()-1);
            }
            
        }
        return sb.toString().substring(0,sb.toString().length()-1);
        
    }
    
   
}

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        
        Trie trie = new Trie();
        
        for (String word : strs) {
            trie.insert(word);
        }
        
        return trie.longestCommonPrefix();
    }
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		String[] str = sc.nextLine().trim().split(",");
		System.out.println(new Solution().longestCommonPrefix(str));
	}

}```