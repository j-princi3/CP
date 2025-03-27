An English competition is taking place in a school. One problem is given in the following manner 
There are words formed with lower case alphabets, participants need to find the count of characters which are repeatedly appeared in all words. 
If no such characters are there, then return 0.

Note: give solution using bit manipulation only

Input Format: 
-------------
Line-1: comma separated strings

Output Format:
--------------
Line-1: an integer

Sample Input-1:
---------------
abc,abc,bc

Sampel Output-1:
----------------
2

Explanation:
------------
The characters 'b' and 'c' appear in each word, so there output is 2 .

Sample Input-2:
---------------
abcdde,baccd,eeabg

Sample Output-2:
----------------
2

Explanation:
------------
Only 'a' and 'b' occur in every word.


Constraints
Each word consists of only lower-case letters ('a'-'z').
```java
import java.util.*;

class TreapNode {
    int data;
    int priority;
    TreapNode left;
    TreapNode right;

    TreapNode(int data) {
        this.data = data;
        // Random priority for balancing (between 0 and 999)
        this.priority = new Random().nextInt(1000);
        this.left = this.right = null;
    }
}

public class KthLargest {
    static int k; // This will be set to n - p + 1, to find the p-th largest element

    // Left rotation for balancing
    public static TreapNode rotateLeft(TreapNode root) {
        TreapNode R = root.right;
        TreapNode X = root.right.left;
        R.left = root;
        root.right = X;
        return R;
    }

    // Right rotation for balancing
    public static TreapNode rotateRight(TreapNode root) {
        TreapNode L = root.left;
        TreapNode Y = root.left.right;
        L.right = root;
        root.left = Y;
        return L;
    }

    // Insert a node into the treap while maintaining BST and heap properties
    public static TreapNode insertNode(TreapNode root, int data) {
        if (root == null) {
            return new TreapNode(data);
        }
        if (data < root.data) {
            root.left = insertNode(root.left, data);
            if (root.left != null && root.left.priority > root.priority) {
                root = rotateRight(root);
            }
        } else {
            root.right = insertNode(root.right, data);
            if (root.right != null && root.right.priority > root.priority) {
                root = rotateLeft(root);
            }
        }
        return root;
    }

    // Inorder traversal (ascending order). Decrement k at each visited node.
    // When k reaches 0, print the node's data (the kth smallest, which corresponds to p-th largest).
    static void inorder(TreapNode root) {
        if (root == null)
            return;
        inorder(root.left);
        k--;
        if (k == 0) {
            System.out.print(root.data);
            return;
        }
        inorder(root.right);
    }

    // For debugging: Print the treap nodes in inorder fashion (data and priority)
    static void printTreap(TreapNode root) {
        if (root == null)
            return;
        printTreap(root.left);
        // System.out.println(root.data + " " + root.priority);
        printTreap(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Number of elements and the p-th largest element to find
        int n = sc.nextInt();
        int p = sc.nextInt();
        // Set k = n - p + 1 so that the kth smallest in inorder is the p-th largest overall.
        k = n - p + 1;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        TreapNode root = null;
        for (int a : arr) {
            root = insertNode(root, a);
        }
        // Optional: Print the treap nodes (data and priority) for visualization.
        printTreap(root);
        // Perform inorder traversal to find and print the p-th largest element.
        inorder(root);
    }
}

```