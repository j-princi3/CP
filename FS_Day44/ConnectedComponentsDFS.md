There are N cities, and M routes[], each route is a path between two cities.
routes[i] = [city1, city2], there is a travel route between city1 and city2.
Each city is numbered from 0 to N-1.
 
There are one or more Regions formed among N cities. 
A Region is formed in such way that you can travel between any two cities 
in the region that are connected directly and indirectly.
 
Your task is to findout the number of regions formed between N cities. 
 
Input Format:
-------------
Line-1: Two space separated integers N and M, number of cities and routes
Next M lines: Two space separated integers city1, city2.
 
Output Format:
--------------
Print an integer, number of regions formed.
 
 
Sample Input-1:
---------------
5 4
0 1
0 2
1 2
3 4
 
Sample Output-1:
----------------
2
 
 
Sample Input-2:
---------------
5 6
0 1
0 2
2 3
1 2
1 4
2 4
 
Sample Output-2:
----------------
1
```java
import java.util.*;
class ConnectedComponents {
    public int countComponents(int n, int[][] edges) {
        //Write your code here and return an integer
        boolean visited[]=new boolean[n];
        HashMap<Integer,ArrayList<Integer>> map=new HashMap<>();
        
        for(int i=0;i<n;i++){
            map.put(i,new ArrayList<Integer>());
        }
        
        for(int i[]:edges){
            map.get(i[0]).add(i[1]);
            map.get(i[1]).add(i[0]);
        }
        
        int count=0;
        for(int i=0;i<visited.length;i++){
            if(!visited[i]){
                dfs(map,visited,i);
                count++;
            }
        }
        return count;
    }    
   //Any supporting functinalities, write here
   public void dfs(HashMap<Integer,ArrayList<Integer>> map,boolean visited[],int index){
       ArrayList<Integer> arr=map.get(index);
       visited[index]=true;
       
       for(int i=0;i<arr.size();i++){
           if(!visited[arr.get(i)]){
               dfs(map,visited,arr.get(i));
           }
       }
   }
   
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int e = sc.nextInt();
        int[][] edges = new int[e][2];        
        for (int i = 0; i < e; i++) {
            for (int j = 0; j < 2; j++) {
                edges[i][j] = sc.nextInt();
            }
        }        
        int result = new ConnectedComponents().countComponents(n, edges);
        System.out.println(result);
    }
}

```