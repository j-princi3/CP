#dfs
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:
i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

Input Format:
-------------
Line-1: An integer n
Line-2: n space separated integers

Output Format:
--------------
Line-1: An integer

Sample Input-1:
---------------
10
100 -23 -23 404 100 23 23 23 3 404

Sample Output-1:
----------------
3

Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Sample Input-2:
---------------
1
7

Sample Output-2: 
----------------
0

Explanation: Start index is the last index. You do not need to jump.

Sample Input-3:
---------------
8
7 6 9 6 9 6 9 7

Sample Output-3:
----------------
1

Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 
 Constraints:
 ------------
1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

```java
import java.util.*;
class MinJumps{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(getMinJump(arr,n));
    }
    static int getMinJump(int arr[],int n){
        HashMap<Integer,ArrayList<Integer>> map=new HashMap<>();
        for(int i=0;i<n;i++){
            if(!map.containsKey(arr[i])){
                map.put(arr[i],new ArrayList<Integer>());
            }
        }
        for(int i=0;i<n;i++){
            map.get(arr[i]).add(i);
        }
        // System.out.println(map);
        
        Queue<int[]> q=new LinkedList<>();
        boolean visited[]=new boolean[n];
        
        q.offer(new int[]{arr[0],0,0});
        
        while(!q.isEmpty()){
            
            int curr[]=q.poll();
            
            if(curr[1]==n-1){
                return curr[2];
            }
            
            if(visited[curr[1]]) continue;
            visited[curr[1]]=true;
            
            
            ArrayList<Integer> c=map.get(curr[0]);
            if(!c.contains(curr[1]-1) && curr[1]-1>0){
                c.add(curr[1]-1);
            }
            
            if(!c.contains(curr[1]+1) && curr[1]+1<n){
                c.add(curr[1]+1);
            }
            
            
            for(int i=0;i<c.size();i++){
                
                if(visited[c.get(i)]) continue;
                
                q.offer(new int[]{arr[c.get(i)],c.get(i),curr[2]+1});
            }
        }
        return -1;
    }
}
```