You are given an integer N. Your task is to return an array ans of length N + 1 
where each ans[i] represents the number of 1's in the binary representation of i.

Input Format:
--------------
A single integer N, representing the range from 0 to N.

Output Format:
---------------
An array of N+1 integers where each element represents the count of 1s in the binary representation of each number from 0 to N.

Sample Input-1:
---------------
2

Sample Output-1:
----------------
[0,1,1]

Explanation:
------------
0 --> 0
1 --> 1
2 --> 10

Sample Input-2:
---------------
5

Sample Output-2:
--------------- 
[0,1,1,2,1,2]

Explanation:
------------
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

```java
import java.util.*;
class CountingBits{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.print(getCountingBits(n));
    }
    static ArrayList<Integer> getCountingBits(int n){
        ArrayList<Integer> res=new ArrayList<>();
        res.add(0);
        for(int i=1;i<=n;i++){
            int count=0;
            int q=i;
            while(q>0){
                count+=q&1;
                q=(q>>1);
            }
            
            res.add(count);
        }
        return res;
    }
}

```