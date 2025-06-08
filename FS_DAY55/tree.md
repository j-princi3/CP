## Problem 1: Network Communication Path

### Description
Bubloo is working with computer networks, where servers are connected in a hierarchical structure, represented as a Binary Tree. Each server (node) is uniquely identified by an integer value.

The task is to find the shortest communication path (in terms of network hops) between two specific servers in the network.

### Network Structure
- The network of servers follows a binary tree topology
- Each server (node) has a unique identifier (integer)
- If a server does not exist at a certain position, it is represented as '-1' (NULL)

### Input Format
- Line-1: Space separated integers, elements of the tree
- Line-2: Two space separated integers, represents node ids

### Output Format
Print an integer value representing the minimum number of network hops.

### Sample Input-1
```
1 2 4 3 5 6 7 8 9 10 11 12
4 8
```

### Sample Output-1
```
4
```

### Explanation
The edges between 4 and 8 are: [4,1], [1,2], [2,3], [3,8]

### Sample Input-2
```
1 2 4 3 5 6 7 8 9 10 11 12
6 6
```

### Sample Output-2
```
0
```

### Explanation
No edges between 6 and 6.

### Code
```java
import java.util.*;

class TreeNode{
    TreeNode left;
    TreeNode right;
    int val;
    TreeNode(int val){
        this.val=val;
        this.left=this.right=null;
    }
}

class TreeBuilder{
    public TreeNode buildTree(int[] levelorder){
        int rootvalue=levelorder[0];
        TreeNode root=new TreeNode(rootvalue);
        Queue<TreeNode>q=new LinkedList();
        q.offer(root);
        int i=1;
        int n=levelorder.length;
        while(i<n){
            TreeNode node=q.poll();
            if(i<n && levelorder[i]!=-1){
                node.left=new TreeNode(levelorder[i]);
                q.offer(node.left);
            }
            i++;
            if(i<n && levelorder[i]!=-1){
                node.right=new TreeNode(levelorder[i]);
                q.offer(node.right);
            }
            i++;
        }
        return root;
    }
    
    public int distancebetweennodes(TreeNode root,int point1,int point2){
        // Implementation needed
    }
    
    public int calculatedistance(TreeNode root,int point,int dist){
        // Implementation needed
    }
    
    public TreeNode findlca(TreeNode root,int point1,int point2){
        // Implementation needed
    }
}

class Solution{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        
        String[] s=sc.nextLine().split(" ");
        int n=s.length;
        int a[]=new int[n];
        for(int i=0;i<n;i++){
            a[i]=Integer.parseInt(s[i]);
        }
        int point1=sc.nextInt();
        int point2=sc.nextInt();
        TreeBuilder tree=new TreeBuilder();
        TreeNode root=tree.buildTree(a);
        System.out.println(tree.distancebetweennodes(root,point1,point2));
    }
}
```

---

## Problem 2: Alchemist's Elixir Brewing

### Description
You are a renowned Alchemist exploring a mystical forest teeming with magical plants. Each plant you encounter has a unique Essence Power represented by an integer in the array plants of length n.

By collecting essences from consecutive plants, you can brew powerful Elixirs. The potency of an elixir is determined by the sum of the essence powers of the plants used. Due to the complexity of brewing, you can only create elixirs using sequences of plants that are at least m in length.

Your objective is to find the kth smallest elixir potency that can be brewed from these sequences.

### Example 1
**Input:** n=3 plants = [2, 1, 3], k = 2, m = 2  
**Output:** 4

**Explanation:**
Possible elixirs (sequences of length ≥ 2):
- [2, 1]: Potency = 2 + 1 = 3
- [1, 3]: Potency = 1 + 3 = 4
- [2, 1, 3]: Potency = 2 + 1 + 3 = 6

Ordered elixir potencies: 3, 4, 6  
The 2nd smallest elixir potency is 4.

### Input Format
- Line-1: 3 space separated integers, n, k, m
- Line-2: n space separated integers, plantEssences[]

### Output Format
An integer, The kth smallest elixir potency

### Sample Input
```
4 3 2
3 -3 5 2
```

### Sample Output
```
4
```

### Explanation
Possible elixirs (sequences of length ≥ 2):
- [3, -3]: Potency = 3 + -3 = 0
- [-3, 5]: Potency = -3 + 5 = 2
- [5, 2]: Potency = 5 + 2 = 7
- [3, -3, 5]: Potency = 3 + -3 + 5 = 5
- [-3, 5, 2]: Potency = -3 + 5 + 2 = 4
- [3, -3, 5, 2]: Potency = 3 + -3 + 5 + 2 = 7

Ordered elixir potencies: 0, 2, 4, 5, 7, 7  
The 3rd smallest elixir potency is 4.

---

## Problem 3: Prime Sequence Beauty

### Description
In a distant galaxy, there exists an ancient space station covered in a vast array of digital codes. These codes are believed to hold the key to unlocking powerful alien technology. The interstellar explorers call these codes "prime sequences."

The prime-sequence beauty of the digital code is defined as the number of prime sequences that meet the following conditions:
- The prime sequence has a length of k
- The prime sequence is a divisor of the entire digital code
- The prime sequence is a prime number

### Note
- Leading zeros in prime sequences are allowed
- 0 is not a divisor of any value
- A prime sequence is a contiguous sequence of characters in the main digital code

### Input Format
- Line-1: space separated String and integer, code and K

### Output Format
An integer, the prime-sequence beauty of the code.

### Sample Input-1
```
239246 2
```

### Sample Output-1
```
1
```

### Explanation
The following are the prime sequences of length k:
- "23" from "239246": 23 is a divisor of 239246 and is a prime number
- "39" from "239246": 39 is not a divisor
- "92" from "239246": 92 is not a divisor
- "24" from "239246": 24 is not a divisor of 239246
- "46" from "239246": 46 is a divisor of 239246 but is not a prime number

Therefore, the prime-sequence beauty is 1.

### Sample Input-2
```
24224 1
```

### Sample Output-2
```
3
```

### Code
```java
import java.util.*;

class Solution{
    public static void main(String[] arr){
        Scanner s=new Scanner(System.in);
        String str=s.next();
        int k=s.nextInt();
        System.out.print(getc(str,k));
        s.close();
    }
    
    static int getc(String str,int k){
        if(k>str.length() || k==0){
            return 0;
        }
        int c=0;
        long n=Long.parseLong(str);
        StringBuilder t=new StringBuilder(str.substring(0,k));
        long num=Long.parseLong(t.toString());
        if(ispri(num) && isdivi(num,n)){
            c++;
        }
        for(int i=k;i<str.length();i++){
            t.deleteCharAt(0);
            t.append(str.charAt(i));
            long number=Long.parseLong(t.toString());
            if(ispri(number) && isdivi(number,n)){
                c++;
            }
        }
        return c;
    }
    
    static boolean ispri(long num){
        if(num<=1){
            return false;
        }
        for(long i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    
    static boolean isdivi(long num,long n){
       return num!=0 && n%num==0;
    }
}
```

---
