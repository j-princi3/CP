You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. 
Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
Return the minimum time required for all buses to complete at least totalTrips trips.

Input Format:
-------------
Line-1: An integer n, size of time
Line-2: n space separated integers, time[i]
Line-3: An integer, totalTrips

Sample Input-1:
---------------
3
1 2 3
5

Sample Output-1: 
----------------
3
 
Explanation:
-------------
-> At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
-> At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
-> At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.

Sample Input-2:
---------------
1
2
1

Sample Output-2: 
----------------
2


Explanation:
--------------
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.
 

Constraints:
------------
1 <= time.length <= 10^5
1 <= time[i], totalTrips <= 10^7

```java
import java.util.*;
class BinaryTrips{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int target=sc.nextInt();
        System.out.println(getBinaryTrips(arr,n,target));
    }
    static int getBinaryTrips(int arr[],int n,int target){
        Arrays.sort(arr);
        int low=1;
        int high=target*arr[0];
        
        while(low<high){
            int mid=(low+high)/2;
            if(getTrips(mid,arr,n,target)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
    static boolean getTrips(int mid,int arr[],int n,int target){
        int s=0;
        for(int i=0;i<n;i++){
            s+=mid/arr[i];
        }
        if(s>=target){
            return true;
        }
        return false;
    }
}
```