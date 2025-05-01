// Program to implement Disjoint Set Data Structure.

/*
5 = number of friends
3 = number of relationships
2 = number of friendship check
input=5
3
0 2
4 2
3 1
2
4 0
1 0
output=4 is a friend of 0
1 is not a friend of 0

*/
```java

import java.util.*;

class DisjointSet {
	private int[] rank, parent;
	private int n;

	public DisjointSet(int n){
		this.rank = new int[n];
		this.parent = new int[n];
		this.n = n;
		makeSet();
	}
	// Creates n sets with single item in each
	private void makeSet(){
		for(int i = 0 ; i < n ; i++){
		    this.parent[i] = i;
		}
	}

	// Returns representative of x's set
	public final int findUParent(int node){
		if(parent[node] == node){
		    return node;
		}
		
		return parent[node] = findUParent(parent[node]);
	}

	// Unites the set that includes x and the set that includes x
	public void unionByRank(int u, int v){
	    
	    int pu = findUParent(u);
	    int pv = findUParent(v);
	    
	    if(pu == pv) return; // do not connect again if they belong to same component
	    
	    if(rank[pu] == rank[pv]){
	        // connect pv to pu
	        parent[pv] = pu;
	        rank[pu]++;
	    }else if(rank[pv] < rank[pu]){
	        parent[pv] = pu;
	    }else{
	        parent[pu] = pv;
	    }
	}
	
	public boolean areFriends(int u,int v){
	    return findUParent(u) == findUParent(v);
	}
	
	
}

public class DSU_Test {
	public static void main(String[] args){
		try(Scanner sc=new Scanner(System.in)){
		    
		    int n = sc.nextInt();
		    DisjointSet dsu = new DisjointSet(n);
		    
		    int r = sc.nextInt();
		    
		    for(int i = 0 ; i < r ; i++){
		        int u = sc.nextInt();
		        int v = sc.nextInt();
		        dsu.unionByRank(u,v);
		    }
		    
		    int checks = sc.nextInt();
		    
		    for(int i = 0 ; i < checks ; i++){
		        int u = sc.nextInt();
		        int v = sc.nextInt();
		        
		        if(dsu.areFriends(u,v)){
		            System.out.println(u + " is a friend of " + v);
		        }else{
		            System.out.println(u + " is not a friend of " + v);
		        }
		    }
		
	    }		
	}
}
```