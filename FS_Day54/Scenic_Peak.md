# Finding a Scenic Peak in a Mountain Trail

## Problem Description

You're hiking along a beautiful mountain trail, and the elevation at each point is recorded in an array `heights`, where each element represents the height at that specific point.

A **scenic peak** is a spot on the trail that is not lower than its immediate neighbors. That means it either:
- Stands higher than those beside it, or
- Is at the start or end of the trail and not lower than its single neighbor

Your goal is to identify any one such scenic peak and return its elevation (value).

## Input Format
- Line-1: An integer n, the size of the array
- Line-2: A list of n space-separated integers representing heights

## Output Format
- Line-1: The elevation value of any one scenic peak


## Examples

### Example 1:
```
Sample Input-1:
-------------
5
2 4 6 3 1
Sample Output-1:
-------------
6
```
The value 6 at index 2 is a scenic peak because it's higher than both of its neighbors (4 and 3).

### Example 2:
```
Sample Input-2:
-------------
6
1 3 20 4 1 0
Sample Output-2:
-------------
20
```
The value 20 at index 2 is a scenic peak because it's higher than both of its neighbors (3 and 4).

### Example 3:
```
Sample Input-3:
-------------
4
10 8 6 4
Sample Output-3:
-------------
10
```
The value 10 at index 0 is a scenic peak because it's at the start of the trail and higher than its only neighbor (8).


## Constraints
- 1 ≤ n ≤ 10^5
- -10^9 ≤ heights[i] ≤ 10^9
- n must be greater than or equal to 1
- There will always be at least one scenic peak in the array
- Output must be a single elevation value from the array that qualifies as a scenic peak
- An efficient approach is expected, ideally O(log n)


## Solution

The problem can be efficiently solved using binary search, which gives us the desired O(log n) time complexity.

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }
        System.out.println(findScenicPeak(heights));
        scanner.close();
    }
    
    public static int findScenicPeak(int[] heights) {
        int n = heights.length;
        if (n == 1) return heights[0]; 
        if (heights[0] >= heights[1]) return heights[0];  
        if (heights[n-1] >= heights[n-2]) return heights[n-1];  
        
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > 0 && mid < n - 1) {
                if (heights[mid] >= heights[mid - 1] && heights[mid] >= heights[mid + 1]) {
                    return heights[mid];
                }
                if (heights[mid] < heights[mid + 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                break;
            }
        }
        return -1;
    }
}
```

