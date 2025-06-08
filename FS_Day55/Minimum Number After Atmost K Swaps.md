You are given a string S representing a positive integer and an integer k. Your task is to find the smallest possible number that can be formed by performing at most k swaps between any two digits of the string.
If k == 0, return the original number.
If the number is already the smallest possible permutation, return it as-is.
If the input is null or empty, return it unchanged.

A swap operation means exchanging the positions of any two digits (not necessarily adjacent). Each swap counts as one operation. The goal is to minimize the number.

Input Format:
-----------
A string S of digits (1 ≤ S.length ≤ 10)
An integer k (0 ≤ k ≤ 10) representing the number of allowed swaps.

Output Format:
------------
A string representing the smallest number possible after performing at most k swaps.

Constraints:
--------------
1 ≤ length(S) ≤ 10
0 ≤ k ≤ 10
Digits are in the range '0' to '9'
No leading zeros in input unless the number is exactly "0"
Each swap counts as 1 operation, regardless of position

Sample Input-1:
------------
934651
2

Sample Output-1:
----------------
134569

Sample Input-2:
-------------
11111
3
Sample Output-2:
--------------
11111

```java
import java.util.*;
class Solution{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        int swaps=sc.nextInt();
        
        int k=0;
        for(int i=0;i<s.length()-1;i++){
            k=i;
            if(swaps<=0){
                continue;
            }
            int min=Integer.parseInt(s.charAt(i)+"");
            for(int j=i+1;j<s.length();j++){
                if(Integer.parseInt(s.charAt(j)+"")<min){
                    k=j;
                    min=Integer.parseInt(s.charAt(j)+"");
                }
            }
            if(k!=i){
                if((i==0 && min!=0)|| i<s.length()){
                    String c=s.substring(i,i+1);
                    swaps--;
                    s=s.substring(0,i)+String.valueOf(min)+s.substring(i+1,k)+c+s.substring(k+1);
                }
            }
        }
        System.out.println(s);
        return ;
    }
}
```