You're given a binary tree represented in level-order (with -1 denoting nulls). Your task is to print all paths 
from each leaf node to the root, preserving the order from leaf → parent → … → root. 
Each path should be printed on a new line, with node values joined by " —> ".
If the current node is null, return.
If the current node is a leaf (no left or right children), print the current path.

Input Format:
------------
Line-1: A single line containing space-separated integers representing the binary tree in level-order.
Use -1 to represent a null (no child).

Output Format:
--------------
Each line represents one path from a leaf node to the root.
Node values must be joined using " —> ".
Order of output paths may vary based on traversal, but all valid paths must be included

Constraints:
-------------
1 ≤ number of nodes ≤ 10^4
Node values are integers in the range [-10^9, 10^9]
Input tree is binary (each node has at most two children)
Input is provided in level-order, and -1 denotes nulls

Sample Input-1:
------------------
1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1

Sample Output-1:
--------------
4 —> 2 —> 1  
5 —> 2 —> 1  
8 —> 6 —> 3 —> 1  
9 —> 6 —> 3 —> 1  
7 —> 3 —> 1

Sample Input-2:
-------------
1 -1 2 -1 3 -1 4

Sample Output-2:
-------------------
4 —> 3 —> 2 —> 1


```java
import java.util.*;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int v){
        val=v;
        left=null;
        right=null;
    }
}
class Main{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String word[]=sc.nextLine().split(" ");
        int n=word.length;
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=Integer.parseInt(word[i]);
        }
        if(n==0){
            return;
        }
        TreeNode root=new TreeNode(arr[0]);
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        int i=1;
        while(i<n){
            TreeNode curr=q.poll();
            if(arr[i]!=-1){
                curr.left=new TreeNode(arr[i]);
                q.offer(curr.left);
            }
            i++;
            
            if(i<n){
                if(arr[i]!=-1){
                    curr.right=new TreeNode(arr[i]);
                    q.offer(curr.right);
                }
            }
            i++;
        }
        ArrayList<Integer> s=new ArrayList<>();
        dfs(root,s);
    }
    static void dfs(TreeNode curr,ArrayList<Integer> s){
        if(curr==null){
            return ;
        }
        s.add(curr.val);
         if (curr.left == null && curr.right == null) {
            for (int j = s.size() - 1; j >= 0; j--) {
                System.out.print(s.get(j));
                if (j > 0) System.out.print(" —> ");
            }
            System.out.println();
         }
        
        dfs(curr.left,s);
        // s.remove(s.size()-1);
        dfs(curr.right,s);
        s.remove(s.size()-1);
        
    }
}
```