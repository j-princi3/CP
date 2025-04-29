  
### Problem Statement:
A company has a network of servers represented as a tree (undirected graph with no cycles). Each server is a node. You are given:
- `server_nodes`: Total number of servers (nodes)
- `server_from[]`: List of edges (from nodes)
- `server_to[]`: List of edges (to nodes)
- `server_weight[]`: List of edge weights between connected servers
- `signal_speed`: A signal can travel a path if the **total weight of that path is divisible by signal_speed**

For each server `i`, calculate how many other servers it can communicate with (i.e., for every other server `j`, if the distance from i to j is divisible by `signal_speed`, it's valid).

### Input Example:
```text
server_nodes = 4
server_from = [1, 2, 3]
server_to =   [2, 3, 4]
server_weight = [2, 2, 2]
signal_speed = 2
```

### Output:
```text
[6, 6, 6, 6]
```

Each server can communicate with 2 others where the path weight is divisible by 2. => 

### Similar LeetCode Problems:
- [LeetCode 743 - Network Delay Time](https://leetcode.com/problems/network-delay-time/)  
- [LeetCode 787 - Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)  
- [LeetCode 399 - Evaluate Division (DFS weighted graph)](https://leetcode.com/problems/evaluate-division/)  

### Approach Guidance:
You need to compute **all-pairs shortest paths** (Floyd-Warshall for dense graphs or Dijkstra from every node for sparse graphs). Then filter distances divisible by `signal_speed`. Since it’s a tree, better to precompute distances using **DFS from every node** (O(N^2)).

### Your Solution Template:
```java
public static List<Integer> getServerPairs(int serverNodes, List<Integer> serverFrom,
                                           List<Integer> serverTo, List<Integer> serverWeight,
                                           int signalSpeed) {
    // TODO: Implement tree construction using adjacency list
    // TODO: For each node, run DFS to calculate distances to all others
    // TODO: Count pairs where distance is divisible by signalSpeed
    return new ArrayList<>();
}
```

---
