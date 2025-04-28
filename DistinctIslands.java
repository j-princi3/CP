import java.util.*;

class Solution 
{    
    private static final int[] dRow = {-1, 1, 0, 0};
    private static final int[] dCol = {0, 0, -1, 1};
    
    private class DisjointSet 
	{
        private int[] parent;
        private int[] size;
        
        public DisjointSet(int V) 
		{
            parent = new int[V];
            size = new int[V];
            for (int i=0; i<V; i++) {
                size[i] = 1;
                parent[i] = i;
            }
        }
        
        public int find(int u) {
            return parent[u] == u ? u : (parent[u] = find(parent[u]));
        }
        
        public void union(int u, int v) 
		{
            int p1 = find(u);
            int p2 = find(v);
            if (p1 == p2) 
				return;

            if (size[p1] < size[p2]) 
			{
                parent[p1] = p2;
                size[p2] += size[p1];
            } else {
                parent[p2] = p1;
                size[p1] += size[p2];
            }
        }
    }
    
    public int numDistinctIslands(int[][] grid) 
	{
	    //Write your code here and return an integer, number of distinct shapes formed
	    int r=grid.length;
	    int c=grid[0].length;
	    DisjointSet d=new DisjointSet(r*c);
	    
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(grid[i][j]==1){
	                int curr=i*c+j;
	                for(int k=0;k<4;k++){
	                    int x=i+dRow[k];
	                    int y=j+dCol[k];
	                    int neigh=x*c+y;
	                    
	                    if(x>=0 && y>=0 && y<c && x<r && grid[x][y]==1){
	                        d.union(curr,neigh);
	                    }
	                }
	            }
	        }
	    }
	    
	    HashMap<Integer,List<Integer>> islands=new HashMap<>();
	    for(int i=0;i<r*c;i++){
	        if(grid[i/c][i%c]==1){
	            if(!islands.containsKey(d.parent[i])){
	                islands.put(d.parent[i],new ArrayList<>());
	            }
	            islands.get(d.parent[i]).add(i);
	            
	        }
	    }
	    Set<String> s=new HashSet<>();
	    
	    for(Map.Entry<Integer,List<Integer>> e:islands.entrySet()){
	        StringBuilder sb=new StringBuilder("");
	        List<Integer> list=e.getValue();
	        int nb=list.get(0);
	        for(int i=0;i<list.size();i++){
	            sb.append(String.valueOf(list.get(i)-nb));
	        }
	        s.add(sb.toString());
	    }
	    
	    System.out.println(islands+" "+s);
	    return s.size();
	    
	}
}

public class DistinctIslands
{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int m=sc.nextInt();
		int n=sc.nextInt();
		int grid[][]=new int[m][n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				grid[i][j]=sc.nextInt();
				
		System.out.println(new Solution().numDistinctIslands(grid));
	}
}