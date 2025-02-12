#medium 
#slidingwindow 
A string is good if there are no repeated characters.
Given a string s, return the number of good substrings of length three in s.
Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
A substring is a contiguous sequence of characters in a string.

Sample Input-1:
---------------
xyzzaz

Sample Output-1:
----------------
1

Explanation: 
------------
There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".

Sample Input-2:
---------------
aababcabc

Sample Output-2:
----------------
4

Explanation: 
------------
There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".

```java
import java.util.*;
class GoodStrings{
    public static void main (String[] args) {
        Scanner sc=new Scanner (System.in);
        String s=sc.next();
        System.out.println(getSum(s));
    }
    static int getSum(String s){
        
        HashMap<Character,Integer> map=new HashMap<>();
        int count=0;
        int flag=1;
        
        if(3>s.length()){
            return 1;
        }
        
        for(int i=0;i<3;i++){
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
        }
        
        for(Map.Entry<Character,Integer> e:map.entrySet()){
            if(e.getValue()>1){
                flag=0;
                break;
            }
        }
        
        if(flag==1){
            count++;
        }
        
        for(int i=3;i<s.length();i++){
            map.put(s.charAt(i-3),map.get(s.charAt(i-3))-1);
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
            flag=1;
            
            
            for(Map.Entry<Character,Integer> e:map.entrySet()){
                if(e.getValue()>1){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                count++;
            }
        }
        return count;
    }
}
```