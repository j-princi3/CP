You are given an m x n grid where each cell can have one of three values:
-> 0 representing an empty cell,
-> 1 representing a fresh orange, or
-> 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.


Input Format:
-------------
Line-1: Two integers, m and n, represents grid[] sizes
Line-2 to m: n Space separated integers, represents grid[i][j]

Output Format:
--------------
Line-1: An integer

Sample Input-1:
---------------
3 3
2 1 1
1 1 0
0 1 1

Sample Output-1:
----------------
4

Sample Input-2:
---------------
3 3
2 1 1
0 1 1
1 0 1

Sample Output-2:
----------------
-1

Explanation: 
-------------
The orange in the bottom left corner (row 2, column 0) is never rotten, 
because rotting only happens 4-directionally.

Sample Input-3:
---------------
1 1
0 2

Sample Output-3:
----------------
0

Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
Constraints:
------------
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

```java
import java.util.*;

class RottingOranges {
    
    static Queue<int []> q=new LinkedList<>();
    
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        int grid[][]=new int[m][n];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=sc.nextInt();
            }
        }
        System.out.println(orangesRotting(grid));
        
    }
    static int orangesRotting(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        boolean visited[][]=new boolean[m][n];
        
        int maxTime=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==2){
                    q.offer(new int[]{i,j,0});
                    
                }
            } 
        }
        // System.out.println(q);
        maxTime=bfs(grid,m,n,visited);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    return -1;
                    
                }  
            }
        }

  

        return maxTime;
    }

    static int bfs(int [][]grid,int m,int n,boolean [][]visited){

        int time=0;
        while(!q.isEmpty()){
            int curr[]=q.poll();

            // System.out.println(curr[0]+" "+curr[1]+" "+curr[2]);
            if(visited[curr[0]][curr[1]] ) continue;
            time=curr[2];
            
            visited[curr[0]][curr[1]]=true;
            
            int dy[]={-1,1,0,0};
            int dx[]={0,0,-1,1};
            
            for(int k=0;k<4;k++){
                
                int x=dx[k]+curr[0];
                int y=dy[k]+curr[1];
                
                if(x>=m || y>=n || x<0 || y<0) continue;
                if(visited[x][y] || grid[x][y]==2 || grid[x][y]==0) continue;
                
                q.offer(new int[]{x,y,time+1});
            }
        }

        return time;
    }

}
```