Given an undirected graph of V vertices and E edges. 
Our task is to find all the bridges in the given undirected graph. 

A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected.

Sample Input-1:
---------------
4 //no of vertices
3 //no of edges
0 1
0 2
1 3

Sample Output-1:
----------------
1 3
0 1
0 2

Sample Input-2:
---------------
5 
5
1 0
1 2
0 2
3 0
3 4

Sample Output-2:
---------------
3 4
0 3
```java
import java.io.*;
import java.util.*;
import java.util.LinkedList;

class FindingBridges 
{
    private int V;   // No. of vertices    
	// Array  of lists for Adjacency List Representation
    private LinkedList<Integer> adj[];
    int time = 0;

	// Constructor
	FindingBridges (int v)
    {
        V = v;
        adj = new LinkedList[v];
        for (int i=0; i<v; ++i)
            adj[i] = new LinkedList();
    }

    // Function to add an edge into the graph
    void addEdge(int v, int w)
    {
        adj[v].add(w);  // Add w to v's list.
        adj[w].add(v);    //Add v to w's list
    }
    
   
    // DFS based function to find all bridges
    void dfs(boolean visited[],int timeOfInsert[],int lowestTime[],int node,int parent){
        visited[node]=true;
        timeOfInsert[node]=lowestTime[node]=time;
        time++;
        
        for(int i:adj[node]){
            if(i==parent) continue;
            
            if(!visited[i]){
                dfs(visited,timeOfInsert,lowestTime,i,node);
                lowestTime[node]=Math.min(lowestTime[i],lowestTime[node]);
                
                if(timeOfInsert[node]<lowestTime[i]){
                    System.out.println(node+" "+i);
                }
            }else{
                lowestTime[node]=Math.min(lowestTime[i],lowestTime[node]);
            }
        }
    }
    void bridge()
    {
       //Write your code here and print edges
       int timeOfInsert[]=new int[V];
       int lowestTime[]=new int[V];
       
       boolean visited[]=new boolean[V];
       dfs(visited,timeOfInsert,lowestTime,0,-1);
    }

    public static void main(String args[])
    {      
        Scanner sc=new Scanner(System.in);
        int v=sc.nextInt();
        int e=sc.nextInt();
        
		FindingBridges g = new FindingBridges (v);
        for(int i=0;i<e;i++)
        {
            int end1=sc.nextInt();
            int end2=sc.nextInt();
            g.addEdge(end1,end2);
        }
		//System.out.println("Bridges in graph");     
        g.bridge();       
    }
}


```