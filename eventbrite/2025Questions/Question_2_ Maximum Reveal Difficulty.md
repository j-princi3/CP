
**Type**: Greedy / Partitioning  
**Difficulty**: Medium  
**Tags**: Greedy, Combinatorics, Subset Sum, Partition

### Problem Statement:
You are given `n` modules with a `difficulty[]` array. You need to divide them into 3 **non-empty** groups such that:
- Each module is in exactly one group
- Each group is assigned to a different server
- Then choose one module from each group and find **max(|a-b| + |b-c| + |c-a|)** over all such selections

Return the **maximum possible overall difficulty**.

### Input Example:
```text
difficulty = [5, 6, 1, 4, 2]
```

### Output:
```text
8
```

Explanation: Choose groups as:
- Group 1: [5, 6, 4]
- Group 2: [1]
- Group 3: [2]
Then from these, pick 6 (G1), 1 (G2), 2 (G3). Total difficulty: `|6-1| + |1-2| + |2-6| = 5+1+4 = 10` (or another valid optimal combination).

### Similar LeetCode Problems:
- [LeetCode 805 - Split Array With Same Average](https://leetcode.com/problems/split-array-with-same-average/)  
- [LeetCode 698 - Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)  
- [LeetCode 1388 - Pizza With 3n Slices (Greedy Partition)](https://leetcode.com/problems/pizza-with-3n-slices/)

### Approach Guidance:
Brute-force all 3-group partitions (O(3^n)), but optimize using greedy heuristics. Maximize min/max elements among the 3 groups.

### Your Solution Template:
```java
public static int getMaxDifficulty(List<Integer> difficulty) {
    // TODO: Generate all valid 3-group partitions
    // TODO: For each partition, pick one value from each group and compute max(|a-b| + |b-c| + |c-a|)
    // Hint: This simplifies to 2 * (max - min)
    return 0;
}
```


### Advice:
- For **Q1**, prelearn: `DFS from every node`, `Floyd-Warshall`, or `Tree DP`
- For **Q2**, learn: `k-group partition logic`, `max pairwise diff`, or reduce to `max-min` selection

These are **NOT easy to fully solve in 1 hr**, especially without pattern recognition.
