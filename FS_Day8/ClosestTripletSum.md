#easy 
#2-pointer 
You are given an integer array nums of length n and an integer target. 
Your task is to find three integers in nums such that their sum is closest to the given target.

Return the sum of these three integers.

You may assume that each input would have exactly one solution.

Input Format:
-------------
Line-1: An integer n, the size of the array.
Line-2: n space-separated integers representing the elements of the array nums.
Line-3: A single integer target.

Output Format:
--------------
Line-1: Print a single integer, representing the sum of three integers closest to the target.

Sample Input-1:
---------------
4
-1 2 1 -4
1

Sample Output-1:
----------------
2

Sample Input-2:
---------------
3
0 0 0
1

Sample Output-2:
----------------
0

```java
import java.util.*;
class ThreeSumClosest{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int num[]=new int[n];
        for(int i=0;i<n;i++){
            num[i]=sc.nextInt();
        }
        int target=sc.nextInt();
        System.out.print(getClosest(target,num,n));
    }
    static int getClosest(int target,int num[],int n){
        Arrays.sort(num);
        int sum=0;
        int t=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                if(target==num[left]+num[right]+num[i]){
                    t=0;
                    return target;
                }
                if(Math.abs(num[left]+num[right]+num[i]-target)<t){
                    t=Math.abs(num[left]+num[right]+num[i]-target);
                    sum=num[left]+num[right]+num[i];
                }
                if(target>num[left]+num[right]+num[i]){
                    left++;
                }else{
                    right--;
                }
            }
            
        }
        return sum;
    }
}
```