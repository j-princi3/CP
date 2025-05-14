#bitmanipulation
#medium 
Mr Bond is a spy and he is working on a mission to solve that mission he needs 
list of numbers which are password to a secret locker, he got a secret code from his informer 
which consists of a circular array code of length of n and a key k.

To decrypt the code, he must replace every number. All the numbers are replaced simultaneously.
with your programming skills help bond to decrypt the code.
The following are the rules to be followed to decrypt the code.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.

As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Input Format: 
-------------
Line-1: An integer (n)
Line-2: n space separated integers
Line-3: An integer (k)

Output Format:
---------------
Line-1: list of integers

Sample Input-1:
---------------
4
5 7 1 4
3

Sample Output-1: 
----------------
[12,10,16,13]

Explanation: Each number is replaced by the sum of the next 3 numbers. 
The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.

Sample Input-2:
---------------
4
1 2 3 4
0

Sample Output-2:
----------------
[0,0,0,0]

Explanation: When k is zero, the numbers are replaced by 0. 

Sample Input-3:
---------------
4
2 4 9 3
-2

Sample Output-3:
----------------
[12,5,6,13]

Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. 
Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
 

Constraints:

n == code.length
1 <= n <= 100
1 <= code[i] <= 100
-(n - 1) <= k <= n - 1

```java
import java.util.*;
class Decode{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int nextRange=sc.nextInt();
        System.out.print(getDecoded(arr,n,nextRange));
    }
    static ArrayList<Integer> getDecoded(int arr[],int n,int range){
        ArrayList<Integer> res=new ArrayList<>();
        
        if(range>=0){
            for(int i=0;i<n;i++){
                int j=1;
                int sum=0;
                int index=i+j;
                while(j<=range){
                    if(index<n){
                        sum+=arr[index];
                    }else{
                        index=0;
                        sum+=arr[index];
                    }
                    index++;
                    j++;
                }
                res.add(sum);
            }
        }else{
            for(int i=0;i<n;i++){
                int j=-1;
                int sum=0;
                int index=i+j;
                while(j>=range){
                    if(index>=0){
                        sum+=arr[index];
                    }else{
                        index=n-1;
                        sum+=arr[index];
                    }
                    index--;
                    j--;
                }
                res.add(sum);
            }
        }
            
        // for(int i=0;i<n;i++){
        //     int j=1;
        //     if(range<0){
        //         j=-1;
        //     }
        //     while(j<=range){
        //         if(i+j>)
        //     }
        // }
        return res;
    }
}
```