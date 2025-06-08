## Problem 1: Text Editor Auto-Correction

### Description
A text editor application allows users to perform automated corrections in documents. The feature scans the document and replaces every distinct instance of a specified incorrect phrase with a corrected one.

However, to avoid infinite loops and ambiguity, the editor replaces only non-overlapping occurrences of the phrase from left to right, one at a time.

### Input Format
- Line-1: A string `S` representing the original word
- Line-2: A string `P` representing the pattern to be replaced
- Line-3: A string `R` representing the replacement phrase (Special character)

### Output Format
A string with all non-overlapping occurrences of `P` in `S` replaced with `R`

### Example
**Input:**
- word = "ABCABCXABC"
- pattern = "ABC"
- ch = '@'

**Explanation:**
```
Original string:  A B C A B C X A B C
                  [ABC] [ABC]   [ABC] → all 3 are non-overlapping
Output: @ @ X @
```

### Sample Input
```
ABABABAB
AB
@
```

### Sample Output
```
@@@@
```

### Code
```java
import java.util.*;

class Main{
    public static void main(String[] arr){
        Scanner s=new Scanner(System.in);
        String str=s.nextLine().trim();
        String p=s.nextLine().trim();
        String r=s.nextLine().trim();
        System.out.println(replace(str,p,r));
        s.close();
    }
    
    static String replace(String str,String p,String r){
        if(str.isEmpty()){
            return "";
        }
        if(p.isEmpty()){
            return str;
        }
        if(p.length()>str.length()){
            return str;
        }
        return str.replace(p,r);
    }
}
```

---

## Problem 2: Number Card Pair Game

### Description
You're playing a number card game. You have a bunch of number cards with values written on them, possibly repeated and out of order. Your goal is to find all unique pairs of cards (a,b) such that: b - a = k

Output the pairs in any order, but each on a new line.

### Input Format
- Line-1: An integer n — the number of number cards
- Line-2: n space-separated integers — the values on the number cards
- Line-3: An integer k — the target difference

### Output Format
Print each valid unique pair (a, b) such that b - a = k, one per line
Format: (b, a)

### Constraints
- 1 ≤ n ≤ 10^5
- 0 ≤ arr[i] ≤ 10^9
- 0 ≤ k ≤ 10^9
- Input array may contain duplicates
- No extra space is allowed (excluding input array and recursion/sorting stack)
- Output must contain only unique pairs (no duplicates)

### Sample Input-1
```
8
1 5 2 2 2 5 5 4
3
```

### Sample Output-1
```
(4, 1)
(5, 2)
```

### Sample Input-2
```
6
1 3 5 7 9 11
2
```

### Sample Output-2
```
(3, 1)
(5, 3)
(7, 5)
(9, 7)
(11, 9)
```

### Sample Input-3
```
8
1 2 3 4 5 6 7 8
1
```

### Sample Output-3
```
(2, 1)
(3, 2)
(4, 3)
(5, 4)
(6, 5)
(7, 6)
(8, 7)
```

### Code
```java
import java.util.*;

class Main{
    public static void main(String[] arr){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int[] ar=new int[n];
        for(int i=0;i<n;i++){
            ar[i]=s.nextInt();
        }
        int k=s.nextInt();
        pair(n,ar,k);
        s.close();
    }
    
    static void pair(int n,int[] arr,int k){
        Arrays.sort(arr);
        int i=0,j=1;
        while(i<n && j<n){
            if(i==j || arr[j]-arr[i]<k){
                j++;
            }else if(arr[j]-arr[i]>k){
                i++;
            }else { 
                System.out.println("(" + arr[j] + ", " + arr[i] + ")");
                int a=arr[i], b=arr[j];
                while (i<n && arr[i]==a) i++;
                while (j<n && arr[j]==b) j++;
            }
        }
    }
}
```

---

## Problem 3: GridFlow Snake Sequence

### Description
GridFlow Technologies is developing a path optimization tool for data transmission in a grid-based communication network, represented as an N × N square matrix of integers. Each cell contains a numeric value, and the goal is to find the longest "snake sequence" within the grid.

A snake sequence is a path of numbers where each subsequent number is located either to the right or down of the current number and differs from it by exactly + or - 1. The task is to compute the maximum length of such a snake sequence and outputs one valid sequence.

### Constraints
- 1 ≤ N ≤ 100 (matrix dimension)
- -1000 ≤ Matrix[i][j] ≤ 1000 (value in each cell)
- At least one snake sequence exists in the matrix

### Input Format
- Line-1: An integer: N (size of the square matrix)
- Line-2 to N: The next N lines each contain N integers, representing the values in the matrix

### Output Format
Line-1: Maximum length number. If maximum length not exists then write 0.

### Sample Input-1
```
3
1 3 5
7 9 11
13 15 17
```

### Sample Output-1
```
0
```

### Explanation
No two adjacent elements differ by + or - 1.

### Sample Input-2
```
5
7 5 2 3 1
3 4 1 4 4
1 5 6 7 8
3 4 5 8 9
3 2 2 7 6
```

### Sample Output-2
```
7
```

### Explanation
The 5 × 5 matrix contains several snake sequences. One maximum length snake sequence is:
- Start at (0,1): 5
- Move down to (1,1): 4 (5-1)
- Move down to (2,1): 5 (4+1)
- Move right to (2,2): 6 (5+1)
- Move right to (2,3): 7 (6+1)
- Move right to (2,4): 8 (7+1)
- Move down to (3,4): 9 (8+1, invalid, but check down to (3,3))
- From (2,3): 7, move down to (3,3): 8 (7+1)
- Move down to (4,3): 7 (8-1)

This sequence (5 → 4 → 5 → 6 → 7 → 8 → 7) has a length of 7 and satisfies the + or - 1 constraint for each step, moving only right or down.

---

## Problem 4: Manufacturing Weight Pair Finder

### Description
Mr. Ram works in a manufacturing industry where items of different weights are produced. His task is to find pairs of items whose weight difference is equal to a given value k. You are asked to write a program to help Mr. Ram achieve this without using extra space.

### Input Format
- Line-1: An integer n, the number of items (weights)
- Line-2: n space-separated positive integers representing the weights of the items
- Line-3: An integer k, the desired difference between the weights of the paired items

### Output Format
Line-1 to n: Print the pairs of integers where the difference between the two numbers in each pair is exactly k. Each pair should be printed on a new line.

### Constraints
- The input list will contain distinct integers
- You are not allowed to use extra space, so you must solve the problem in-place or by using a fixed amount of space

### Sample Input-1
```
8
1 2 3 4 5 6 7 8
3
```

### Sample Output-1
```
1 4
2 5
3 6
4 7
5 8
```

### Sample Input-2
```
10
5 10 15 20 25 30 35 40 45 50
5
```

### Sample Output-2
```
5 10
10 15
15 20
20 25
25 30
30 35
35 40
40 45
45 50
```

### Code
```java
import java.util.*;

class Main{
    public static void main(String[]a) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt(),w[]=new int[n],k,i=0,j=1,d;
        for(int x=0;x<n;x++) w[x]=s.nextInt();
        k=s.nextInt();
        Arrays.sort(w);
        while(j<n){
            d=w[j]-w[i];
            if(d==k){
                System.out.println(w[i]+" "+w[j]);
                i++;
                j++;
            }else if(d<k){
                j++;
            }else {
                i++;
                if(i==j) j++;
            }
        }
    }
}
```


---