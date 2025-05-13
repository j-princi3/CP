You are given two strings. Determine whether the first string can be converted to the second 
by replacing each character with a unique character while preserving the order.

Each character from the first string must map to one and only one character in the second string and vice versa.
Note: Two characters in the first string cannot map to the same character in the second.

Explanation:
------------
Two strings are isomorphic if:
•	Each character in the first-string maps to one unique character in the second string.
•	This mapping must be consistent throughout the string.
•	No two different characters from the first-string map to the same character in the second string.


Input Format:
-------------------
Line-1: two space-separated strings

Output Format:
----------------------
Line-1: Boolean value True/False


Sample Input-1:
---------------
ACAB XCXY

Sample Output:
----------------------
True

Explanation:
------------
A → X, C → C, B → Y — all mappings are unique and consistent.


Sample Input:
---------------------
FOO BAR

Sample Output:
----------------------
False


```java
import java.util.*;
class IsomorphicStringsCheck{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s1=sc.next();
        String s2=sc.next();
        
        System.out.println(isIsomorphicString(s1,s2));
    }
    static boolean isIsomorphicString(String s1,String s2){
        HashMap<Character,Character> forward=new HashMap<>();
        HashMap<Character,Character> backward=new HashMap<>();
        if(s1.length()!=s2.length()){
            return false;
        }
        
        for(int i=0;i<s1.length();i++){
            
            char c=s1.charAt(i);
            if(forward.containsKey(c)){
                
                if(forward.get(c)!=s2.charAt(i)){
                    return false;
                }else{
                    continue;
                }
            }else{
                forward.put(c,s2.charAt(i));
            }
            
            c=s2.charAt(i);
            if(backward.containsKey(c)){
                
                if(backward.get(c)!=s1.charAt(i)){
                    return false;
                }else{
                    continue;
                }
            }else{
                backward.put(c,s1.charAt(i));
            }
        }
        return true;
    }
}
```