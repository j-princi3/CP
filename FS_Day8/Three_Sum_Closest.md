#2-pointer 
#easy You are given three sorted integer arrays A[], B[], and C[], and an integer target.

Your task is to find one element from each array (A[i], B[j], and C[k]) such that the sum of these three elements is equal to target.

If there is no exact match, return the triplet with the minimum absolute difference to the target.

Input Format:
-------------
Line 1: An integer N, the size of the first array.
Line 2: N space-separated integers representing elements of array A.
Line 3: An integer M, the size of the second array.
Line 4: M space-separated integers representing elements of array B.
Line 5: An integer P, the size of the third array.
Line 6: P space-separated integers representing elements of array C.
Line 7: An integer target, the required sum.

Output Format:
--------------
Line-1: Print the triplet (A[i], B[j], C[k]) that either matches the target or has the closest sum to the target.

Constraints:
------------
Time Complexity: O(N + M + P)
Space Complexity: O(1)

Sample Input-1:
---------------
4
5 10 20 30
4
1 3 7 10
4
2 5 8 12
25

Sample Output-1:
----------------
10 7 8

Explanation:
-------------
The sum 10 + 7 + 8 = 25, which exactly matches target.


Sample Input-2:
---------------
3
1 5 10
3
3 6 9
3
4 7 8
30

Sample Output-2:
----------------
10 9 8

Explanation:
------------
The sum 10 + 9 + 8 = 27, which is the closest sum to 30 (minimum absolute difference |30 - 27| = 3).

```java
import java.util.*;
class ClosestTripletSum{


    public static void main(String args[]){


        Scanner sc=new Scanner(System.in);
        int n1=sc.nextInt();
        int num1[]=new int[n1];
        for(int i=0;i<n1;i++){
            num1[i]=sc.nextInt();
        }
        int n2=sc.nextInt();
        int num2[]=new int[n2];
        for(int i=0;i<n2;i++){
            num2[i]=sc.nextInt();
        }
        int n3=sc.nextInt();
        int num3[]=new int[n3];
        for(int i=0;i<n3;i++){
            num3[i]=sc.nextInt();
        }
        int target=sc.nextInt();
        getClosest(target,num1,n1,num2,n2,num3,n3);
    }
    static void getClosest(int target,int num1[],int n1,int num2[],int n2,int num3[],int n3){

        int arr[]=new int[3];
        Arrays.sort(num1);
        Arrays.sort(num2);
        Arrays.sort(num3);
        int sum=0;
        int t=Integer.MAX_VALUE;
        for(int i=0;i<n1;i++){
	        int left=0;
            int right=n3-1;
            while(left<n2 && right>=0){
                if(target==num2[left]+num3[right]+num1[i]){
                    System.out.print(num1[i]+" "+num2[left]+" "+num3[right]);
                    t=0;
                    return ;
                }
                if(Math.abs(num2[left]+num3[right]+num1[i]-target)<t){
		            t=Math.abs(num2[left]+num3[right]+num1[i]-target);
                    arr[0]=num1[i];arr[1]=num2[left];arr[2]=num3[right];
                    sum=num2[left]+num3[right]+num1[i];
                }
                if(target>num2[left]+num3[right]+num1[i]){
	                left++;
                }else{
	                right--;
                }
            }
            
        }
        System.out.print(arr[0]+" "+arr[1]+" "+arr[2]);
        return ;
    

}

}
```