Imagine you're the chief curator at a renowned museum that houses a rare collection 
of ancient artifacts. These artifacts are arranged in a special display that 
follows a strict rule: any artifact positioned to the left of another has a lower 
value, and any artifact on the right has a higher value. 

Your task is to transform this display into what is known as a "Greater Artifact 
Display." In this new arrangement, each artifact’s new value will be its original 
value plus the sum of the values of all artifacts that are more valuable than it.

Sample Input-1:
---------------
4 2 6 1 3 5 7

Sample Output-1:
----------------
22 27 13 28 25 18 7

Explanation:
-------------
Input structure 
       4
      / \
     2   6
    / \ / \
   1  3 5  7

Output structure:
        22
      /   \
     27   13
    / \   / \
   28 25 18  7

Reverse updates:
- Artifact 7: 7
- Artifact 6: 6 + 7 = 13
- Artifact 5: 5 + 13 = 18
- Artifact 4: 4 + 18 = 22
- Artifact 3: 3 + 22 = 25
- Artifact 2: 2 + 25 = 27
- Artifact 1: 1 + 27 = 28
```java
//wrong solution(not passing all test case)
import java.util.*;

class Node{
    int val;
    Node left;
    Node right;
    
    public Node(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

public class Solution{
    static int s=0;
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String[] s = sc.nextLine().split(" ");
        
        int[]arr = new int[s.length];
        for(int i=0;i<s.length;i++){
            arr[i] = Integer.parseInt(s[i]);
        }
        
        Node root = build(arr);
        
        Sum(root,0);
        
        levelorder(root);
    }
    
    public static Node build(int[] arr){
        if(arr.length==0){
            return null;
        }
        Node root=new Node(arr[0]);
        Node r=root;
        for(int i=1;i<arr.length;i++){
            insert(arr[i],root);
        }
        return r;
    }
    
    public static void insert(int data,Node r){
        if(r.val>data){
            if(r.left==null){
                r.left=new Node(data);
                return ;
            }else{
                insert(data,r.left);
            }
        }else{
            if(r.right==null){
                r.right=new Node(data);
                return ;
            }else{
                insert(data,r.right);
            }
        }
    }
    
    
    public static void Sum(Node root,int sum){
       if(root==null){
           return ;
       }
       Sum(root.right,sum);
       s+=root.val;
       root.val=s;
       Sum(root.left,sum);
       
    }
    
    public static void levelorder(Node root) {
        if (root == null) return;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            Node current = queue.poll();
            System.out.print(current.val + " "); // Print current node
            
            if (current.left != null) queue.offer(current.left);
            if (current.right != null) queue.offer(current.right);
        }
    }
}

```