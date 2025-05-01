/*
Vihaar is working with strings. 
He is given two strings A and B, and another string T,
where the length of A and B is same.

You can find the relative groups of letters from A and B,
using the following rule set:
- Equality rule: 'p' == 'p'
- Symmetric rule: 'p' == 'q' is same as 'q' == 'p'
- Transitive rule: 'p' == 'q' and 'q' == 'r' indicates 'p' == 'r'.

Vihaar has to form the relatively smallest string of T,
using the relative groups of letters.

For example, if A ="pqr" and B = "rst" , 
then we have 'p' == 'r', 'q' == 's', 'r' == 't' .

The relatives groups formed using above rule set are as follows: 
[p, r, t] and [q,s] and  String T ="tts", then relatively smallest string is "ppq".

You will be given the strings A , B and T.
Your task is to help Vihaar to find the relatively smallest string of T.


Input Format:
-------------
Three space separated strings, A , B and T

Output Format:
--------------
Print a string, relatively smallest string of T.


Sample Input-1:
---------------
kmit ngit mgit

Sample Output-1:
----------------
ggit

Explanation: 
------------
The relative groups using A nd B are [k, n], [m, g], [i], [t] and
the relatively smallest string of T is "ggit"


Sample Input-2:
---------------
attitude progress apriori

Sample Output-2:
----------------
aaogoog

Explanation: 
------------
The relative groups using A nd B are [a, p], [t, r, o], [i, g] and [u, e, d, s]
the relatively smallest string of T is "aaogoog"
 */

```java

import java.util.*;
class DisjointSet {
	private int[] parent;

	public DisjointSet(){
		this.parent = new int[26];
		init();
	}
	// Creates n sets with single item in each
	private void init(){
		for(int i = 0 ; i < 26 ; i++){
		    this.parent[i] = i; // initially parent of every one is him self or her self
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
	    	    
        if(pv >= pu){
            // connect pv to pu
            parent[pv] = pu; // connect larger character to smaller character , parent should be smaller
        }else{
            parent[pu] = pv;
        }
	   
	}
	
	
}
	
	

public class Smallest_Equivalent_String {

    private static String getRelativelySmallerString(String A,String B,String ref){

        DisjointSet dsu = new DisjointSet();

        // Now start building the dsu
        for(int i = 0 ; i < A.length() ; i++){
            int u = A.charAt(i) - 'a';
            int v = B.charAt(i) - 'a';

            dsu.unionByRank(u, v);
        }
        
        StringBuilder sb = new StringBuilder();
        for(char ch : ref.toCharArray()){
            int idx = ch - 'a';

            sb.append((char)(dsu.findUParent(idx) + 'a'));
        }

        return sb.toString();

    }
    public static void main(String[] args) {
        
        try(Scanner sc = new Scanner(System.in)){
            String[] inp = sc.nextLine().split(" ");
    
            String A = inp[0];
            String B = inp[1];
            String ref = inp[2];
    
            System.out.println(getRelativelySmallerString(A,B,ref));
        }
    }
}
```