Given a graph which represents a flow network where every edge has a capacity. 
Also, given two vertices source 's' and sink 't' in the graph, find the maximum possible flow from s to t with the following constraints:
	- Flow on an edge doesn't exceed the given capacity of the edge.
	- Incoming flow is equal to outgoing flow for every vertex except s and t.

Input Format:
------------------
Line-1: An integer V, number of vertices in graph
Next V lines: V space separated integers, graph[][], 
                       the adjacency matrix of the grpah.
Last Line: Two space separated integers, s and t, source and sink.

input=
//Enter number of vertices 
6
//Enter the adjacency matrix of the directed graph
0 16 13  0   0   0
0  0  10 12  0   0
0  4   0   0  14  0
0  0   9   0   0  20
0  0   0   7   0  4
0  0   0   0   0  0
//Enter source and sink 
0 5
Output =23

Example 2:
input=
//Enter number of vertices 
6
//Enter the adjacency matrix of the directed graph
0 7 4 0 0 0
0 0 0 5 3 0
0 3 0 0 2 0
0 0 0 0 0 8
0 0 0 3 0 5
0 0 0 0 0 0
//Enter source and sink
0 5
output=10

```java

import java.util.*;
class MaxFlowEk
{
    static int V; // number of vertices in the graph
   
	// method to find the maximum flow in a flow network using the Edmonds-Karp algorithm
    static int findMaxFlow(int[][] graph, int source, int sink) 
    {
        //write your code here and return a number of maxflow
        int rGraph[][]=new int[V][V];
	    
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            rGraph[i][j]=graph[i][j];
	        }
	    }
	    int parent[]=new int[V];
		int count=0;
	    
	    while(bfs(rGraph,s,t,parent)){
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

	// helper method to find the shortest augmenting path in the residual graph using BFS
	static boolean bfs(int[][] residualGraph, int source, int sink, int[] parent) 
	{
        boolean[] visited = new boolean[V];
        Arrays.fill(visited, false);
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(source);
        visited[source] = true;
        parent[source] = -1;        
        while (!queue.isEmpty()) 
		{
            int u = queue.poll();
            for (int v = 0; v < V; v++) 
			{
                if (!visited[v] && residualGraph[u][v] > 0) 
				{
                    queue.add(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return visited[sink];
    }  
	
    public static void main(String[] args) 
    {
		Scanner s=new Scanner(System.in);
		//System.out.println("Enter number of vertices");
		V=s.nextInt();
		int[][] graph = new int[V][V]; 
		//System.out.println("Enter the adjacency matrix of the directed graph");
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				graph[i][j]=s.nextInt();

		//System.out.println("Enter source and sink");
		int source = s.nextInt();
		int sink = s.nextInt();
		int maxFlow = findMaxFlow(graph, source, sink);
		System.out.println(maxFlow);
    }
}

```