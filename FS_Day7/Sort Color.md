You are given an array nums of size n, where each element represents an object colored red, white, or blue. 
Your task is to sort the array in-place so that all objects of the same color are adjacent, following the order:
-> Red (0)
-> White (1)
-> Blue (2)

Rules:
-> You must not use the built-in sort function.
-> You must modify the array in-place with a time-efficient approach.

Input Format:
-------------
Line 1: An integer n, representing the size of the array.
Line 2: n space-separated integers representing the array nums, where each element is either 0 (red), 1 (white), or 2 (blue).

Output Format:
--------------
Line-1: Print the sorted array as n space-separated integers.

Constraints:
------------
-> 1≤n≤300
-> nums[i]∈{0,1,2} (each element is either 0, 1, or 2)

Sample Input-1:
---------------
6
2 0 2 1 1 0

Sample Output-1:
----------------
0 0 1 1 2 2

Sample Input-2:
---------------
3
2 0 1

Sample Output-2:
----------------
0 1 2

```java
import java.util.*;
class SortColors{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
        }
        getSortedColors(arr,n);
    }
    static void getSortedColors(int arr[],int n){
        int left=0;
        int right=n-1;
        int mid=0;
        while(mid<=right && left<=mid){
            if(arr[mid]==0){
                int temp=arr[left];
                arr[left]=arr[mid];
                arr[mid]=temp;
                left++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }else if(arr[mid]==2){
                int temp=arr[right];
                arr[right]=arr[mid];
                arr[mid]=temp;
                right--;
            }else{
                break;
            }
            // for(int i:arr){
            //     System.out.print(i+" ");
            // }
        }
        for(int i:arr){
            System.out.print(i+" ");
        }
        
    }
}
```