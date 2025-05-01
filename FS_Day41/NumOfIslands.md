Ibrahim is an interior designer wants to color wall of size M*N. 
He plans to color the wall and put lights of two different colors

The designer can lit the wall using M*N lights.The lights are Blue or pink
in color. Blue colored lights represented with digit-1 and pink colored lights 
represented with digit-0.

The Blue colored lights forms different shapes, that are connected 4 directonally.
The directons are upwards, downwards, left, and right. Ibrahim got an idea to 
count the number of shapes formed by blue colored lights.

You will be given the decorated wall as a matrix wall[][].
Your task is to help Ibrahim to count the number of shapes by the lights.

Input Format:
-------------
Line-1: Two space separated integers M and N, size of the wall.
Next M lines: N space separated integers, either 0 or 1.

Output Format:
--------------
Print an integer, Number of distinct shapes formed by Blue Lights.


Sample Input-1:
---------------
4 5
1 1 0 1 1
1 1 0 0 1
0 0 0 0 0
1 1 0 0 0

Sample Output-1:
----------------
3


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
public class NumOfIslands 
{
	private int[] sz;
	private int[] parent;
	private int rows, cols;
	public int find(int p) 
	{
		while (parent[p] != p) 
			p = parent[p];
		return p;
	}

	public void union(int p, int q) 
	{
		int rootP = find(p);
		int rootQ = find(q);

		if (rootP == rootQ) return;
		
		if (sz[rootP] < sz[rootQ])	
		{
			sz[rootQ] += sz[rootP]; 
			parent[rootP] = rootQ;
		}
		else
		{
			sz[rootP] += sz[rootQ]; 
			parent[rootQ] = rootP;
		}
	}

	public int numIslands(int[][] grid) 
	{
        this.rows=grid.length;
        this.cols=grid[0].length;
        
        this.parent=new int[rows*cols];
        this.sz=new int[rows*cols];
        
        for(int i=0;i<sz.length;i++){
            parent[i]=i;
            sz[i]=1;
        }
        
        
        int dir[][]={{0,-1},{0,1},{-1,0},{1,0}};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int curr=cols*i+j;
                if(grid[i][j]==1 ){
                    for(int k=0;k<4;k++){
                        int x=i+dir[k][0];
                        int y=j+dir[k][1];
						
                        if(x>=0 && y>=0 && y<cols && x<rows && grid[x][y]==1){
                            int ncurr=x*cols+y;
                            union(curr,ncurr);
							// System.out.println(curr+" "+ncurr+" "+x+" "+y);
                        }
                    }
                }
            }
        }
        Set<Integer> s=new HashSet<>();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    s.add(find(i*cols+j));
                }
            }
        }
// 		System.out.println(s);
        return s.size();
	}

	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		int row=s.nextInt();
		int col=s.nextInt();	
		int arr[][]=new int[row][col];
		for (int i=0;i<row ;i++ )
		{
			for (int j=0;j<col ;j++ )
			{
				arr[i][j]=s.nextInt();
			}
		}
		System.out.println(new NumOfIslands().numIslands(arr));
	}
}
```