#bitmanipulation #bruteforce 
Given two integers left and right, return the count of numbers in the inclusive range [left, right]
 having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has the number of 1's present when written in binary.

For example, 21 written in binary is 10101, which has 3 set bits.
 
Input Format:
-------------
Line-1: Two separated integers

Output Format:
--------------
Line-1: An integer

Sample Input-1:
---------------
6  10

Sample Output-1:
---------------
4

Explanation:
------------
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.

Sample Input-2:
---------------
10 15

Sample Output-2:
---------------
5

Explanation:
------------
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
5 numbers have a prime number of set bits.


```java
import java.util.*;
class PrimeSetBits{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int l=sc.nextInt();
        int h=sc.nextInt();
        System.out.println(getPrimeNumbers(l,h));
    }
    static int getPrimeNumbers(int l,int h){
        int n=0;
        for(int i=l;i<=h;i++){
            int setbit=0;
            int j=i;
            while(j!=0){
                setbit+=j&1;
                j=j>>1;
            }
            // System.out.println(setbit);
            int flag=0;
            if(setbit==1){
                flag=1;
            }
            for(int k=2;k<setbit;k++){
                if(setbit%k==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                n++;
            }
        }
        return n;
    }
}
```