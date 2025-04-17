Sridhar brought his latest Apple iPhone 12 pro. He started his conversation 
with one of his friend on WhatsApp with list of words.

Now it’s our task to find and return what are the most common words 
in the list of words he used in sorted order based on occurrence from 
largest to smallest. If any of words he used are having same occurrence 
then consider the lexicographic order.

You will be given a list of words, you need to print top P number of 
most common used words as described in the statement. 

Input Format:
-------------
Line-1: comma separated line of words, list of words.
Line-2: An integer P, number of words to display. 

Output Format:
--------------
Print P number of most common used words.


Sample Input-1:
---------------
ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are,case
3

Sample Output-1:
----------------
[are, case, egg]

Sample Input-2:
---------------
ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are
3

Sample Output-2:
----------------
[are, egg, case]


```java
import java.util.*;

class Node
{
    public char c;
    public boolean isWord;
    public int count;
    public Node[] children;
    public String str;

    public Node(char c)
	{
        this.c = c;
        this.isWord = false;
        this.count = 0;
        children = new Node[26];
        str = "";
    }
}

class Trie
{
    public Node root;
    public Trie(){
        this.root = new Node('\0');
    }
    public void insert(String word)
	{
        Node curr = root;
        for(int i  = 0;i<word.length();i++){
            char c = word.charAt(i);
            if(curr.children[c-'a'] == null){
                curr.children[c-'a'] = new Node(c);
            }
            curr = curr.children[c-'a'];
        }
        curr.isWord = true;
        curr.count +=1;
        curr.str = word;       
    }

    public void traverseUtils(Node root, PriorityQueue<Node> pq)
	{
        //Write your code here
        if(root==null){
            return ;
        }
        for(int i=0;i<26;i++){
            
            if(root==null) continue;
            
            if(root.children[i]!=null){
                if(root.children[i].isWord){
                    pq.offer(root.children[i]);    
                }
                traverseUtils(root.children[i],pq);
            }
            
        }
        return ;
        
    }
    public void traverse(int p){
        PriorityQueue<Node> pq=new PriorityQueue<>((a,b)->{
            if(a.count==b.count){
                return (a.str).compareTo(b.str);
            }else{
                return b.count-a.count;
            }
            
        });
        traverseUtils(root,pq);
        ArrayList<String> res=new ArrayList<>();
        while(!pq.isEmpty() && p>0){
            res.add(pq.poll().str);
            p--;
        }
        System.out.println(res);
        return ;
    }
}

public class FrequentWord 
{
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);
        String line1 = sc.nextLine();
        int p = sc.nextInt();
        String[] words = line1.split(",");
        Trie t = new Trie();
        
        for(int i = 0;i<words.length;i++){
           t.insert(words[i]);
        }
        
        t.traverse(p);
        
	    //Write your code here
    }
}
```