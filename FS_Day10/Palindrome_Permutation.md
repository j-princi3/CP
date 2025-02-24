AlphaCipher is a string formed from another string by rearranging its letters

You are given a string S.
Your task is to check, can any one of the AlphaCipher is a palindrome or not.

Input Format:
-------------
A string S

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
carrace

Sample Output-1:
----------------
true


Sample Input-2:
---------------
code

Sample Output-2:
----------------
false

```java
import java.util.*;
class PalindromePermutation{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        System.out.print(validityCheck(s));
    }
    static boolean validityCheck(String s){
        int bitmask=0;
        for(int i=0;i<s.length();i++){
            int n=s.charAt(i)-'a';
            bitmask=bitmask^(1<<n);
        }
        return bitmask==0 || (bitmask&(bitmask-1))==0;
    }
}
```