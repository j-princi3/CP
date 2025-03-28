#dp
Mr.Sharvanand is playing with array of integers, his task is to find largest sum. The sum is calculated by adding individual products( multiplying each element of array with its position) and every time rotate nums in clockwise direction, like this find n different  sums if there are n elements in an array, finally return the largest of these sums. Help sharvanand to find largest sum.  
you are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.
Example 1:
Input: 4 
 4 3 2 6
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.

Example 2:
Input: 1
100
Output: 0

```java
import java.util.*;
class maxSum{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.print(getMaxSumAfterRotation(arr,n));
    }
    static int getMaxSumAfterRotation(int arr[],int n){
        int dp[]=new int[n];
        int sum=0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            dp[0]+=arr[i]*i;
        }
        for(int i=1;i<arr.length;i++){
            dp[i]=dp[i-1]+sum-n*arr[arr.length-i];
        }
        // for(int i=0;i<arr.length;i++){
        //     System.out.print(dp[i]+" ");
        // }
        Arrays.sort(dp);
        return dp[n-1];
    }
}
```