There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store.
You are given an integer array customers of length n where customers[i] is the number of the customer
that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1
if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, 
otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, 
but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.
 
Sample Input-1:
---------------
8
1 0 1 2 1 1 7 5
0 1 0 1 0 1 0 1
3

Sample Output-1: 
----------------
16

Explanation:
------------
The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

Sample Input-2:
---------------
1
1
0
1

Sample Output-2:
----------------
1
 

Constraints:

n == customers.length == grumpy.length
1 <= minutes <= n <= 2 * 104
0 <= customers[i] <= 1000
grumpy[i] is either 0 or 1.

```java
import java.util.*;
class Solution{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int customer[]=new int[n];
        int grumpy[]=new int[n];
        for(int i=0;i<n;i++){
            customer[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++){
            grumpy[i]=sc.nextInt();
        }
        
        int k=sc.nextInt();
        int index[]=new int[2];
        
        int sum=getMaxTime(index,k,customer,n);
        // System.out.println(sum+" "+index[0]+" "+index[1]);
        sum+=getTimeNotGrumppy(customer,n,grumpy,index);
        // System.out.println(sum);
        System.out.println(sum);
    }
    static int getTimeNotGrumppy(int customer[],int n,int grumpy[],int index[]){
        int sum=0;
        for(int i=0;i<n;i++){
            if((i<index[0] || i>index[1]) && grumpy[i]==0){
                sum+=customer[i];
            }
        }
        return sum;
    }
    static int getMaxTime(int index[],int k,int customer[],int n){
        
        int sum=0;
        int max=Integer.MIN_VALUE;
        
        for(int i=0;i<k;i++){
            sum+=customer[i];
        }
        
        if(max<sum){
            max=Math.max(max,sum);
            index[0]=0;
            index[1]=k-1;
        }
        
        for(int i=k;i<n;i++){
            sum+=customer[i]-customer[i-k];
            if(max<sum){
                max=Math.max(max,sum);
                index[0]=i-k+1;
                index[1]=i;
            }
            
        }
        return max;
    }
}
```