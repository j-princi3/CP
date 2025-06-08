## Table of Contents
1. [Problem 1: Castle Secret Corridors (Diameter of Binary Tree)](#problem-1-castle-secret-corridors)
2. [Problem 2: Spy Network Decoder (String to Tree Construction)](#problem-2-spy-network-decoder)
3. [Problem 3: Royal Lineage Transcription (Tree to String Serialization)](#problem-3-royal-lineage-transcription)

---

## Problem 1: Castle Secret Corridors
**Theme:** Finding the longest secret route in an ancient castle
**Algorithm:** Diameter of Binary Tree

### Problem Description
Design a network of secret corridors in an ancient castle where each chamber leads to at most two other chambers. Find the longest secret route between any two chambers.

### Examples
**Example 1:**
- Input: `1 2 3 4 5`
- Output: `3`
- Structure:
```
       1
      / \
     2   3
    / \
   4   5
```
- Longest route: 4 → 2 → 1 → 3 (3 corridors)

**Example 2:**
- Input: `1 -1 2 3 4`
- Output: `2`
- Structure:
```
   1
    \
     2
    / \
   3   4
```
- Longest route: 3 → 2 → 4 (2 corridors)

### Implementation

```java
import java.util.*;

class Solution {
    private int diameter;
    
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return diameter;
    }
    
    int dfs(TreeNode n) {
        if (n == null) return 0;
        int lh = dfs(n.left);
        int rh = dfs(n.right);
        diameter = Math.max(diameter, lh + rh);
        return 1 + Math.max(lh, rh);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { 
        this.val = x; 
    }
}

public class BTDiameter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine().trim();
        if (line.isEmpty()) {
            return;
        }
        
        String[] tokens = line.split("\\s+");
        List<Integer> nodes = new ArrayList<>();
        for (String token : tokens) {
            nodes.add(Integer.parseInt(token));
        }
        
        TreeNode root = buildTree(nodes);
        System.out.println(new Solution().diameterOfBinaryTree(root));
    }
    
    static TreeNode buildTree(List<Integer> nodes) {
        if (nodes.isEmpty() || nodes.get(0) == -1) {
            return null;
        }
        
        TreeNode root = new TreeNode(nodes.get(0));
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int index = 1;
        
        while (index < nodes.size()) {
            TreeNode current = queue.poll();
            if (current == null) continue;
            
            // Process left child
            if (index < nodes.size()) {
                int leftVal = nodes.get(index++);
                if (leftVal != -1) {
                    current.left = new TreeNode(leftVal);
                    queue.offer(current.left);
                }
            }
            
            // Process right child
            if (index < nodes.size()) {
                int rightVal = nodes.get(index++);
                if (rightVal != -1) {
                    current.right = new TreeNode(rightVal);
                    queue.offer(current.right);
                }
            }
        }
        
        return root;
    }
}
```

### Complexity
- **Time Complexity:** O(n) where n is the number of nodes
- **Space Complexity:** O(h) where h is the height of the tree

---

## Problem 2: Spy Network Decoder
**Theme:** Decoding hierarchical spy network structure
**Algorithm:** String to Binary Tree Construction

### Problem Description
Decode a secret message that outlines a covert spy network hierarchy. The message uses numbers and parentheses to represent the network structure.

### Format Rules
- String starts with the leader's ID
- Parentheses enclose subordinate networks
- First parentheses = left branch, second = right branch

### Examples
**Example 1:**
- Input: `4(2(3)(1))(6(5))`
- Output: `[4, 2, 6, 3, 1, 5]`
- Structure:
```
        4
       / \
      2   6
     / \  /
    3   1 5
```

**Example 2:**
- Input: `4(2(3)(-1))(6(5)(7))`
- Output: `[4, 2, 6, 3, -1, 5, 7]`
- Structure:
```
         4
       /   \
      2     6
     / \   / \
    3  -1 5   7
```

### Implementation

```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { 
        this.val = x; 
    }
}

class Solution {
    public TreeNode str2tree(String s) {
        if (s == null || s.length() == 0) return null;
        Stack<TreeNode> st = new Stack<>();
        int i = 0;
        
        while (i < s.length()) {
            char ch = s.charAt(i);
            if (ch == ')') {
                st.pop();
                i++;
            } else if (ch >= '0' && ch <= '9' || ch == '-') {
                int b = i;
                while (i < s.length() && (Character.isDigit(s.charAt(i)) || s.charAt(i) == '-')) {
                    i++;
                }
                int val = Integer.parseInt(s.substring(b, i));
                TreeNode a = new TreeNode(val);
                if (!st.isEmpty()) {
                    TreeNode par = st.peek();
                    if (par.left == null) {
                        par.left = a;
                    } else {
                        par.right = a;
                    }
                }
                st.push(a);
            } else {
                i++;
            }
        }
        return st.isEmpty() ? null : st.peek();
    }
}

public class ConstructBT {
    static List<Integer> levelOrderTraversal(TreeNode root) {
        List<Integer> levelOrder = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root == null) return levelOrder;
        q.offer(root);
        
        while (!q.isEmpty()) {
            TreeNode curr = q.poll();
            levelOrder.add(curr.val);
            if (curr.left != null) {
                q.offer(curr.left);
            }
            if (curr.right != null) {
                q.offer(curr.right);
            }
        }
        return levelOrder;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine().trim();
        if (line.isEmpty()) {
            return;
        } 
        TreeNode root = new Solution().str2tree(line);
        System.out.print(levelOrderTraversal(root));
    }     
}
```

### Complexity
- **Time Complexity:** O(n) where n is the length of the string
- **Space Complexity:** O(h) where h is the height of the tree

---

## Problem 3: Royal Lineage Transcription
**Theme:** Recording royal family tree on a sacred scroll
**Algorithm:** Binary Tree to String Serialization

### Problem Description
Transcribe a royal dynasty using specific customs for recording monarchs and their descendants with parentheses notation.

### Transcription Rules
- Each monarch's number is their signature
- Descendants are enclosed in parentheses
- First-born in first parentheses, second-born in second
- Empty parentheses omitted unless needed to show succession gaps

### Examples
**Example 1:**
- Input: `1 2 3 4`
- Output: `1(2(4))(3)`
- Structure:
```
        1
       / \
      2   3
     /    
    4
```

**Example 2:**
- Input: `1 2 3 -1 4`
- Output: `1(2()(4))(3)`
- Structure:
```
        1
       / \
      2   3
       \
        4
```

**Example 3:**
- Input: `1 2 3 4 -1 5 6 -1 7`
- Output: `1(2(4()(7)))(3(5)(6))`

### Implementation

```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { 
        this.val = x; 
    }
}

class Solution {
    public String tree2str(TreeNode root) {
        if (root == null) return "";
        
        StringBuilder sb = new StringBuilder();
        sb.append(root.val);
        
        if (root.left != null || root.right != null) {
            sb.append("(");
            sb.append(tree2str(root.left));
            sb.append(")");
            
            if (root.right != null) {
                sb.append("(");
                sb.append(tree2str(root.right));
                sb.append(")");
            }
        }
        
        return sb.toString();
    }
}

public class RoyalLineage {
    static TreeNode buildTree(List<Integer> nodes) {
        if (nodes.isEmpty() || nodes.get(0) == -1) {
            return null;
        }
        
        TreeNode root = new TreeNode(nodes.get(0));
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int index = 1;
        
        while (index < nodes.size()) {
            TreeNode current = queue.poll();
            if (current == null) continue;
            
            // Process left child
            if (index < nodes.size()) {
                int leftVal = nodes.get(index++);
                if (leftVal != -1) {
                    current.left = new TreeNode(leftVal);
                    queue.offer(current.left);
                } else {
                    queue.offer(null);
                }
            }
            
            // Process right child
            if (index < nodes.size()) {
                int rightVal = nodes.get(index++);
                if (rightVal != -1) {
                    current.right = new TreeNode(rightVal);
                    queue.offer(current.right);
                } else {
                    queue.offer(null);
                }
            }
        }
        
        return root;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine().trim();
        if (line.isEmpty()) {
            return;
        }
        
        String[] tokens = line.split("\\s+");
        List<Integer> nodes = new ArrayList<>();
        for (String token : tokens) {
            nodes.add(Integer.parseInt(token));
        }
        
        TreeNode root = buildTree(nodes);
        System.out.println(new Solution().tree2str(root));
    }
}
```

### Complexity
- **Time Complexity:** O(n) where n is the number of nodes
- **Space Complexity:** O(h) where h is the height of the tree

---
