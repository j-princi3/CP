In your computer lab, network switches are connected using Ethernet cables to form a LAN. 
However, a new hardware technician inadvertently connected switches in a way that created a cycle,
resulting in a network loop. 
As a consequence, the network has become unstable. You need to identify and remove the specific cable that 
is causing the loop. 
If there are multiple cables contributing to the loop, you should remove the one that was most recently added

Sample Input-1:
---------------
3
0 1
0 2
1 2

Sample Output-1:
----------------
[1 2]

Sample Input-2:
---------------
5
0 1
1 2
2 3
0 3
0 4

Sample Output-2:
----------------
[0,3]
 

Constraints:
------------
-> n == edges.length
-> 3 <= n <= 1000
-> edges[i].length == 2
-> 1 <= ai < bi <= edges.length
-> ai != bi
-> There are no repeated edges.
-> The given graph is connected.

```java
import java.util.*;
class LAN{
    static int parent[];
    int size[];
    LAN (int n){
        this.parent=new int[n];
        this.size=new int[n];
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
     public int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
     }
    
    public void union(int u,int v){
        int up=find(u);
        int vp=find(v);
        
        if(up==vp) return ;
        
        if(size[up]>size[vp]){
            size[up]+=size[vp];
            parent[vp]=up;
        }else{
            size[vp]+=size[up];
            parent[up]=vp;
        }
    } 
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        LAN l =new LAN(n);
        int edges[][]=new int[n][2];
        for(int i=0;i<n;i++){
            edges[i][0]=sc.nextInt();
            edges[i][1]=sc.nextInt();
        }
        
        for(int i=0;i<n;i++){
            if(l.find(edges[i][0])==l.find(edges[i][1])){
                System.out.println("["+edges[i][0]+","+edges[i][1]+"]");
                return ;
            }
            l.union(edges[i][0],edges[i][1]);
        }
        return ;
    }
}
```