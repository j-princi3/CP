#2-pointer 
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

Input Format:
-------------
Line-1: An integer N
Line-2: N space seperated integers

Output Format:
--------------
Line-1: A list of integers

Sample Input-1:
---------------
5
-4 -1 0 3 10

Sample Output-1: 
----------------
[0, 1, 9, 16, 100]

```java
import java.util.*;
class squares{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int res[]=getSquares(arr,n);
        for(int i=0;i<n;i++){
            System.out.print(res[i]+" ");
        }
    }
    static int[] getSquares(int arr[],int n){
        int left=0;
        int right=n-1;
        int res[]=new int[n];
        int index=n-1;
        while(left<=right){
            if(Math.abs(arr[left])>Math.abs(arr[right])){
                res[index]=arr[left]*arr[left];
                index--;
                left++;
            }else{
                res[index]=arr[right]*arr[right];
                right--;
                index--;
                
            }
        }
        return res;
        
    }
}

```