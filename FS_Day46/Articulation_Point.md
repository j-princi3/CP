A vertex is said to be an articulation point in a graph 
if removal of the vertex and associated edges disconnects the graph.

So, the removal of articulation points increases the number of connected components in a graph.

The main aim here is to find out all the articulations points in a graph.


Sample Input-1:
---------------
5
5
1 0
0 2
2 1
0 3
3 4

Sample Output-1:
----------------
[0, 3]

Sample Input-2:
---------------
4
3
0 1
1 2
2 3

Sample Output-2:
----------------
[1, 2]


Sample Input-3:
---------------
7
8
0 1 
1 2
2 0 
1 3
1 4
1 6
3 5
4 5

Sample Output-3:
----------------
[1]

Sample Input-4:
---------------
5
4
0 1
1 2
2 3
3 4

Sample Output-4:
----------------
[1, 2, 3]

```java
import java.util.*;
public class ArticulationPoint 
{
	static int time;

	static void addEdge(ArrayList<ArrayList<Integer> > adj, int u, int v)
	{
		adj.get(u).add(v);
		adj.get(v).add(u);
	}
    
    //Any supporting functionalities, goes here

	static TreeSet<Integer>  AP(ArrayList<ArrayList<Integer> > adj, int V)
	{
		//Write your code here and return a list of articulation points
		TreeSet<Integer> ap=new TreeSet<>();

		boolean visited[]=new boolean[V];
		int lowestTime[]=new int[V];
		int discoveryTime[]=new int[V];
		int parent[]=new int[V];
		Arrays.fill(parent,-1);
		Arrays.fill(discoveryTime,-1);
		Arrays.fill(lowestTime,-1);

		dfs(visited,lowestTime,discoveryTime,parent,adj,ap,0,-1);
		return ap;
	}

	static void dfs(boolean visited[],int lowestTime[],int discoveryTime[],int parent[],ArrayList<ArrayList<Integer>> adj,TreeSet<Integer>  ap,int node,int p){
		visited[node]=true;
		lowestTime[node]=discoveryTime[node]=time;
		int child=0;

		time++;
		for(int nbr:adj.get(node)){
			if(nbr==node) continue;

			if(!visited[nbr]){
				dfs(visited, lowestTime, discoveryTime, parent, adj, ap, nbr,node);
				lowestTime[node]=Math.min(lowestTime[nbr],lowestTime[node]);
				if(lowestTime[nbr]>=discoveryTime[node] && p!=-1){
					ap.add(node);
				}
				child++;
			}else{
				lowestTime[node]=Math.min(lowestTime[node],discoveryTime[nbr]);
			}
			
		}

		if(child>1 && p!=-1){
			ap.add(node);
		}
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		// Creating first example graph
		int V = sc.nextInt();
		int e = sc.nextInt();
		ArrayList<ArrayList<Integer> > adj1 = new ArrayList<ArrayList<Integer> >(V);
		for (int i = 0; i < V; i++)
			adj1.add(new ArrayList<Integer>());
		int s,d;
		for(int i=0;i<e;i++){
			s=sc.nextInt();
			d=sc.nextInt();
			addEdge(adj1, s, d);
		}		
		System.out.println((AP(adj1,V)));				
	}
}
```