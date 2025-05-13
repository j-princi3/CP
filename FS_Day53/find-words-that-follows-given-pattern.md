A secret agent receives a list of encrypted codewords. 
Each codeword must follow the same symbol sequence as a given prototype code. 
Your mission is to find which codewords follow the same symbol arrangement.

NOTE:
Matching is not about the actual characters, but how they repeat.
For example, “moon” = m o o n → pattern: first letter, two repeated letters, and a unique last letter.

Input Format:
-------------
Line-1: A space-separated list of words 
Line-2: A string representing the reference pattern

Output Format:
---------------------
Line-1: A list of words that follow the same pattern, if not found print -1


Sample Input-1:
---------------
Leet abcd loot geek cool for peer dear seed meet noon mess loss
moon

Sample Output-1:
----------------
leet loot geek cool peer seed meet


Sample Input-2:
----------------
leet abcd loot geek cool for peer dear
lamp

Sample Output-2:
----------------
abcd dear


```java
import java.util.*;
class Main{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String word=sc.nextLine();
        String w[]=word.split(" ");
        String pattern=sc.next();
        ArrayList<String> res=new ArrayList<>();
        followingPattern(res,w,pattern);
        if(res.size()==0){
            System.out.println(-1);
            return ;
        }
        for(int i=0;i<res.size();i++)
            System.out.print(res.get(i)+" ");
        return ;
    }
    static void followingPattern(ArrayList<String> res,String w[],String pattern){
        String s=getPattern(pattern);
        for(int i=0;i<w.length;i++){
            if(s.equals(getPattern(w[i]))){
                res.add(w[i]);
            }
        }
    }
    static String getPattern(String w){
        int n=w.length();
        String r="";
        // int j=1;
        // int i=0;
        // while(i<n){
        //     while(j<n && i<n && w.charAt(j)==w.charAt(i)){
        //         j++;
        //     }
        //     r+=String.valueOf(j-i)+".";
        //     i=j;
        //     j++;
        // }
        HashMap<Character,Integer> lastOcc=new HashMap<>();
        int j=0;
        for(int i=0;i<n;i++){
            if(!lastOcc.containsKey(w.charAt(i))){
                lastOcc.put(w.charAt(i),j);
                j++;
            }
            r+=String.valueOf(lastOcc.get(w.charAt(i)))+".";
        }
        return r;
    }
}
```