Given a graph which represents a flow network where every edge has a capacity. 
Also, given two vertices source 's' and sink 't' in the graph, find the maximum possible
flow from s to t with the following constraints:
	- Flow on an edge doesn't exceed the given capacity of the edge.
	- Incoming flow is equal to outgoing flow for every vertex except s and t.

Input Format:
------------------
Line-1: An integer V, number of vertices in graph
Next V lines: V space separated integers, graph[][], 
                       the adjacency matrix of the grpah.
Last Line: Two space separated integers, s and t, source and sink.

Output Format:
--------------------
Print an integer, the maximum possible flow of the graph


Sample Input:
------------------
6
0 16 13 0 0 0
0 0 10 12 0 0
0 4 0 0 14 0
0 0 9 0 0 20
0 0 0 7 0 4
0 0 0 0 0 0
0 5


Sample Output:
--------------------
23

Sample input 
-------------------
6
0 7 4 0 0 0
0 0 0 5 3 0
0 3 0 0 2 0
0 0 0 0 0 8
0 0 0 3 0 5
0 0 0 0 0 0
0 5

Sample Output:
--------------------
10

Sample input 
-------------------
6
0 8 3 0 0 0
0 0 0 9 0 0
0 0 0 7 4 0
0 0 1 0 0 2
0 0 0 0 0 5
0 0 0 0 0 0
0 5

Sample Output:
--------------------
6

```java
import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.LinkedList;

public class MaxFlowFF 
{
	static int V; // Number of vertices in graph

	/* Returns true if there is a path from source 's' to sink 't' in 
	residual graph. Also fills parent[] to store the path */
	boolean dfs(int rGraph[][], int s, int t, int parent[])
	{
		// Create a visited array and mark all vertices as not visited
		boolean visited[] = new boolean[V];
		for (int i = 0; i < V; ++i)
			visited[i] = false;

		// Create a queue, enqueue source vertex and mark source vertex as visited
        Stack<Integer> stack = new Stack<>();
        stack.push(s);
		visited[s] = true;
		parent[s] = -1;

		// Standard DFS Loop
		while (!stack.isEmpty()) 
		{
			int u = stack.pop();
			
			for (int v = 0; v < V; v++) 
			{
				if (visited[v] == false	&& rGraph[u][v] > 0) 
				{
					if (v == t) 
					{
						parent[v] = u;
						return true;
					}
					stack.push(v);
					parent[v] = u;
					visited[v] = true;
				}
			}
		}

		// We didn't reach sink in BFS starting from source, so return false
		return false;
	}

	// Returns the maximum flow from s to t in the given graph
	int fordFulkerson(int graph[][], int s, int t)
	{
	    //write your code here and return int, max flow
	    int rGraph[][]=new int[V][V];
	    
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            rGraph[i][j]=graph[i][j];
	        }
	    }
	    int parent[]=new int[V];
		int count=0;
	    
	    while(dfs(rGraph,s,t,parent)){
			int minPath=Integer.MAX_VALUE;
	        int v=t;
	        int u=parent[v];
            while(u!=s){
                minPath=Math.min(graph[u][v],minPath);
                v=u;
                u=parent[u];
            }
			count+=minPath;

			v=t;
			u=parent[v];
			while(u!=s){
				rGraph[u][v]-=minPath;
				v=u;
				u=parent[u];
			}
	    }
		return count;
	}

	public static void main(String[] args)	throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		V=sc.nextInt();
		int graph[][] = new int[V][V];
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				graph[i][j]=sc.nextInt();

		int s = sc.nextInt();
		int t = sc.nextInt();

		System.out.println(new MaxFlowFF().fordFulkerson(graph, s, t));
	}
}
```