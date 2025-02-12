#easy 
#2-pointer 
You are given an array people, where each element people[i] represents the weight of the i-th person. 
You also have an unlimited number of boats, but each boat has a maximum weight capacity defined by limit.

Each boat can carry at most two people at the same time, as long as their combined weight does not exceed the limit.

Your task is to determine the minimum number of boats required to transport all the given people across safely.

Input Format:
-------------
Line 1: An integer N, representing the number of people.
Line 2: N space-separated integers, representing the weight of each person.
Line 3: An integer limit, representing the maximum weight capacity of a boat.

Output Format:
--------------
Print a single integer, the minimum number of boats needed.

Sample Input-1:
---------------
2
1 2
3

Sample Output-1:
----------------
1

Explanation: Only 1 boat is needed, as both people (weights 1 and 2) fit within the limit of 3.

Sample Input-2:
---------------
4
3 2 2 1
3

Sample Output-2:
----------------
3

Explanation:
------------
Boat 1: (1,2)
Boat 2: (2)
Boat 3: (3)
Total boats required: 3.

Sample Input-3:
---------------
4
3 5 3 4
5

Sample Output-3:
----------------
4

Explanation:
------------
Boat 1: (3)
Boat 2: (3)
Boat 3: (4)
Boat 4: (5)
Total boats required: 4.
```java
import java.util.*;
class Boat{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int limit=sc.nextInt();
        Arrays.sort(arr);
        System.out.print(getMinBoats(n,arr,limit));
        
    }
    static int getMinBoats(int n,int arr[],int limit){
        int start=0;
        int count=0;
        int end=n-1;
        // boolean visited[]=new boolean[n];
        while(start<=end){
            if(arr[start]+arr[end]>limit){
                end--;
                count++;
            }else{
                
                start++;
                end--;
                count++;
            }
        }
        
        return count;
    }
}
```