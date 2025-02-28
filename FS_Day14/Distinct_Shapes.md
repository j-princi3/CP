Viraj Aanand is a wedding planner, He ordered his assistant to decorate a wall.
The decorator plans to decorate the wall with two different colored balloons.
The wall size is M*N, The decorator can decorate the wall using M*N balloons
the balloons are blue or white in color.

Blue colored ballons represented with digit-1 and 
White colored ballons represented with digit-0.

The blue colored balloons forms different shapes, that are connected 4 directonally.
The directons are upwards, downwards, left, and right. Viraj Aanand got an idea to 
count the unique shapes formed by blue colored ballons.

You will be given the decorated wall as a matrix wall[][].
Your task is to help, Viraj Aanand to count the unique shapes.

Input Format:
-------------
Line-1: Two space separated integers M and N, size of the wall.
Next M lines: N space separated integers, either 0 or 1.

Output Format:
--------------
Print an integer, Number of distinct shapes formed by blue balloons.


Sample Input-1:
---------------
4 5
1 1 0 0 0
1 1 0 0 0
0 0 0 1 1
0 0 0 1 1

Sample Output-1:
----------------
1


Sample Input-2:
---------------
5 5
1 1 0 1 1
1 0 0 0 1
0 0 0 0 0
1 0 0 0 1
1 1 0 1 1

Sample Output-2:
----------------
4

```java
import java.util.*;
class DistinctShapes{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int r=sc.nextInt();
        int c=sc.nextInt();
        int arr[][]=new int[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr[i][j]=sc.nextInt();
            }
        }
        System.out.println(getUniqueShapes(arr,r,c));
    }
    static int getUniqueShapes(int arr[][],int r,int c){
        Set<String> shapes=new HashSet<>();
        boolean visited[][]=new boolean[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && arr[i][j]==1){
                    shapes.add(dfs(visited,arr,r,c,i,j));
                }
            }
        }
        return shapes.size();
    }
    static String dfs(boolean visited[][],int arr[][],int r,int c,int i,int j){
        String res="00";
        Stack<int[]> s=new Stack<>();
        s.push(new int[]{i,j});
        while(!s.isEmpty()){
            int curr[]=s.pop();
            int currX=curr[0];
            int currY=curr[1];
            
            if(visited[currX][currY]) continue;
            visited[currX][currY]=true;
            
            int dx[]={0,0,-1,1};
            int dy[]={-1,1,0,0};
            
            for(int k=0;k<4;k++){
                int newX=dx[k]+currX;
                int newY=dy[k]+currY;
                
                if(newX<0 || newY<0 || newX>=r || newY>=c) continue;
                if(visited[newX][newY] || arr[newX][newY]==0) continue;
                
                s.push(new int[]{newX,newY});
                res+=String.valueOf(i-newX)+String.valueOf(j-newY);
                
            }
        }
        

        return res;
    }
}
```