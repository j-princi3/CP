package Grand Test-1;
/*
You are managing a library system that tracks book prices stored in a Binary Search Tree (BST). 
Given a floating-point target price and a number K, 
return the K book prices from the BST that are numerically closest to the target, 
sorted in ascending order.

Input Format:
-------------
Line-1: An integer N — number of books (nodes in the BST).
Line-2: N space-separated integers — book prices to be inserted into the BST.
Line-3: A floating-point number T — the target price.
Line-4: An integer K — number of closest book prices to return.

Output Format:
---------------
Line-1: Print K integers in ascending order — the closest prices to the target.

Sample Input-1:
---------------
7
5 3 8 2 4 6 9
4.3
3

Sample Output-1:
----------------
3 4 5

Explanation: 
------------
        5
       / \
      4   8
     /   / \
    3   6   9

Closest prices to 4.3: 4, 5, and 3 → sorted: 3 4 5

Sample Input-2:
---------------
3
1 2 3
2.0
1

Sample Output-2:
----------------
2

Explanation: 
------------
        2
       / \
      1   3
  
Closest prices to 2.0: 2
 */
```java
import java.util.*;

public class ClosestKBookPrices {

    static class TreapNode {
        int val;
        double diff;
        int priority;
        TreapNode left, right;

        TreapNode(int val,double diff) {
            this.val = val;
            this.diff = diff;
            this.priority = new Random().nextInt();
        }
    }

    static class Treap {
        TreapNode root;

        void insert(int val,double diff) {
            root = insert(root, new TreapNode(val,diff));
        }

        private TreapNode insert(TreapNode root, TreapNode node) {
            if (root == null) return node;
            if (node.diff < root.diff) {
                root.left = insert(root.left, node);
                if (root.left.priority > root.priority)
                    root = rotateRight(root);
            } else {
                root.right = insert(root.right, node);
                if (root.right.priority > root.priority)
                    root = rotateLeft(root);
            }
            return root;
        }

        private TreapNode rotateRight(TreapNode y) {
            TreapNode x = y.left;
            y.left = x.right;
            x.right = y;
            return x;
        }

        private TreapNode rotateLeft(TreapNode x) {
            TreapNode y = x.right;
            x.right = y.left;
            y.left = x;
            return y;
        }

        void inorder(TreapNode node, List<Integer> result,int[] k) {
            if (node == null) return;
            inorder(node.left, result,k);
            k[0]--;
            if(k[0] >= 0) {
                result.add(node.val);
            }else{
                return;
            }
            
            inorder(node.right, result,k);
        }
    }

    //Any supporting functions write here

    // Get K closest books
    // public static List<Integer> getClosestK(List<Integer> sorted, double target, int k) {
    //     //Write your code here and return the list
        
        
    // }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();  // number of books
        int[] prices = new int[N];
        Treap treap = new Treap();
        for (int i = 0; i < N; i++) {
            prices[i] = sc.nextInt();
        }

        double target = sc.nextDouble(); //the target price
        int k = sc.nextInt(); //number of closest book prices to return
        
        for(int i = 0 ; i < N ; i++){
            int price = prices[i];
            double diff = Math.abs(price - target);
            treap.insert(price,diff);
        }
        
        List<Integer> sorted = new ArrayList<>();
        treap.inorder(treap.root, sorted,new int[]{k});
        Collections.sort(sorted);
        
        for (int val : sorted) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}```