## Problem 1: Binary Tree Leaf-to-Root Paths

### Description

In the Kingdom of Arboran, the Great World Tree links numerous realms. Each realm may branch into two sub-realms through a Northern gate (N) or a Southern gate (S). The heart of the tree is Realm 1. A frontier realm is one without any outgoing gates, marking the edge of explored lands.

Your mission is to aid the Royal Cartographer by listing every route from each frontier realm back to Realm 1.

### Input Format
- **Line 1**: Space-separated integers representing the tree in level-order traversal, using `-1` to mark missing children

### Output Format
- **Line 1**: List of paths, where each path represents a frontier-to-root route

### Example

**Input:**
```
1 2 3 4 5 6 7 -1 -1 -1 -1 8 9
```

**Output:**
```
[[4,2,1], [5,2,1], [8,6,3,1], [9,6,3,1], [7,3,1]]
```

**Tree Visualization:**
```
        1
      /   \
     2     3
    / \   / \
   4  5  6   7
         / \
        8   9
```
### Time Complexity
- **Time**: O(n) where n is the number of nodes
- **Space**: O(h) where h is the height of the tree (recursion stack)

---

## Problem 2: Shortest Path in Binary Maze

### Description

Find the shortest path in a binary maze from a source cell to a destination cell. You can move in four cardinal directions (up, down, left, right) and only traverse cells with value `1` (open cells). Cells with value `0` are blocked.

### Input Format
- **Line 1**: Two integers `R C` (dimensions of the maze)
- **Next R lines**: Each line contains `C` space-separated integers (0 or 1)
- **Next line**: Two integers representing source coordinates `(sr, sc)`
- **Next line**: Two integers representing destination coordinates `(dr, dc)`

### Output Format
- **Line 1**: Length of shortest path, or `-1` if no path exists

### Example

**Input:**
```
10 10
1 1 1 1 1 0 0 1 1 1
0 0 1 0 1 1 0 1 0 1
0 0 1 0 1 1 1 0 0 1
1 0 1 1 1 0 1 1 0 1
0 0 0 1 0 0 0 1 0 1
1 0 1 1 1 0 0 1 1 0
0 0 0 0 1 0 0 1 0 1
0 1 1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 1 1 1
0 0 1 0 0 1 1 0 0 1
0 0
5 7
```

**Output:**
```
12
```

**Path Visualization (marked with 'x'):**
```
[x, x, x, x, x, 0, 0, 1, 1, 1]
[0, 0, 1, 0, x, 1, 0, 1, 0, 1]
[0, 0, 1, 0, x, x, x, 0, 0, 1]
[1, 0, 1, 1, 1, 0, x, x, 0, 1]
[0, 0, 0, 1, 0, 0, 0, x, 0, 1]
[1, 0, 1, 1, 1, 0, 0, x, 1, 0]
```

### Time Complexity
- **Time**: O(R × C) where R and C are maze dimensions
- **Space**: O(R × C) for the visited array and BFS queue

---

### Sample Input Files

Create `input1.txt` for Tree Problem:
```
1 2 3 4 5 6 7 -1 -1 -1 -1 8 9
```

Create `input2.txt` for Maze Problem:
```
10 10
1 1 1 1 1 0 0 1 1 1
0 0 1 0 1 1 0 1 0 1
0 0 1 0 1 1 1 0 0 1
1 0 1 1 1 0 1 1 0 1
0 0 0 1 0 0 0 1 0 1
1 0 1 1 1 0 0 1 1 0
0 0 0 0 1 0 0 1 0 1
0 1 1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 1 1 1
0 0 1 0 0 1 1 0 0 1
0 0
5 7
```

---

## Code Implementation

```java
import java.util.*;

public class BinaryMazeShortestPath {
    // Define direction vectors (up, down, left, right)
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    // BFS helper class to store coordinates and distance
    static class Cell {
        int x, y, dist;
        Cell(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
    
    // Check if the cell is valid for BFS
    static boolean isValid(int x, int y, int R, int C, int[][] maze, boolean[][] visited) {
        return (x >= 0 && x < R && y >= 0 && y < C &&
                maze[x][y] == 1 && !visited[x][y]);
    }
    
    // Main method to find shortest path
    public static int shortestPath(int[][] maze, int R, int C, int sr, int sc, int dr, int dc) {
        if (maze[sr][sc] == 0 || maze[dr][dc] == 0) return -1;
        
        Queue<Cell> queue = new LinkedList<>();
        boolean[][] visited = new boolean[R][C];
        
        queue.add(new Cell(sr, sc, 0));
        visited[sr][sc] = true;
        
        while (!queue.isEmpty()) {
            Cell curr = queue.poll();
            
            // Destination reached
            if (curr.x == dr && curr.y == dc)
                return curr.dist;
            
            // Explore 4 directions
            for (int d = 0; d < 4; d++) {
                int newX = curr.x + dx[d];
                int newY = curr.y + dy[d];
                
                if (isValid(newX, newY, R, C, maze, visited)) {
                    visited[newX][newY] = true;
                    queue.add(new Cell(newX, newY, curr.dist + 1));
                }
            }
        }
        return -1; // No path
    }
    
    // Main input driver
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt(), C = sc.nextInt();
        int[][] maze = new int[R][C];
        
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                maze[i][j] = sc.nextInt();
        
        int sr = sc.nextInt(), scPos = sc.nextInt();
        int dr = sc.nextInt(), dc = sc.nextInt();
        
        int result = shortestPath(maze, R, C, sr, scPos, dr, dc);
        System.out.println(result);
    }
}
```
