You are given an array of positive integers.

Your task is to find a contiguous subarray where all elements are unique

and return the maximum possible sum that can be obtained by erasing exactly one such subarray.

  

A subarray is defined as a contiguous sequence of elements within the given array.

  

Input Format:

-------------

Line-1: An integer N, representing the number of elements in the array.

Line-2: Space-separated integers, representing the elements of the array.

  

Output Format:

--------------

Line-1: A single integer, representing the maximum sum of a contiguous subarray with all unique elements.

  

Sample Input-1:

---------------

5

4 2 4 5 6

  

Sample Output-1:

----------------

17

  

Explanation:

-------------

The longest unique subarray is [2, 4, 5, 6] with a sum of 2 + 4 + 5 + 6 = 17.

This is the maximum possible sum that can be obtained.

  
  

Sample Input-2:

---------------

6

1 2 3 1 2 3

  

Sample Output-2:

----------------

6

  
  

Explanation:

------------

The longest unique subarray is [1, 2, 3] with a sum of 1 + 2 + 3 = 6.

This sum cannot be improved by choosing another unique subarray.

```java
import java.util.*;
class MaxScore{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(getMaxScore(arr,n));
    }
    static int getMaxScore(int arr[],int n){
        
        int sum=0;
        int gsum=0;
        int left=0;
        HashMap<Integer,Integer> map=new HashMap<>();
        
        for(int i=0;i<n;i++){
            
            if(map.containsKey(arr[i]) && map.get(arr[i])>=left){
                int j=left;
                left=map.get(arr[i])+1;
                while(j<left){
                    sum-=arr[j];
                    j++;
                }
                // System.out.println(sum);
            }
            
            sum+=arr[i];
            map.put(arr[i],i);
            gsum=Math.max(gsum,sum);
            
            // System.out.println(gsum);
        }
        
        // System.out.println(left);
        
        return gsum;
    }
}
```