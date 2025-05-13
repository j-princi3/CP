You are a software engineer at TechNet Solutions, a company specializing in network infrastructure analysis for 
large-scale communication systems. The company is developing a fault-tolerant network simulation tool to identify
robust communication clusters within a network grid. The network is represented as an M × N binary matrix, where
each cell is either active (1) or inactive (0). 

Your task is to process the binary matrix and determine the size of the largest square submatrix of 1's, 
representing a robust communication cluster, while adhering to the following constraints:
1. The cluster must not include nodes on the network's perimeter (i.e., the first or last row or column of 
the matrix) to avoid external interference.
2. The cluster must include at least one "critical node," defined as an active node (1) surrounded by at least
three inactive nodes (0's) in its four adjacent cells (up, down, left, right), as these nodes are pivotal for 
maintaining connectivity.
3. If multiple clusters of the same size exist, prioritize the one located closer to the bottom of the matrix 
(highest sum of row indices) to optimize signal propagation.

Constraints:
-------------
1. 3 ≤ M, N ≤ 1000 (to allow non-perimeter clusters).
2. Matrix elements are either 0 (inactive) or 1 (active).
3. At least one critical node exists in the matrix.

Input Format:
-------------

Line-1: Two integers: M (number of rows) and N (number of columns).
Line-2 to M: The next M lines each contain N integers (0 or 1), representing the binary network grid.

Output Format:
---------------

Line-1: An integer, The size of the largest square submatrix of 1’s is <size> other wise if no valid cluster 
exists print 0.

Sample Input-1:
---------------
6 6
0 0 1 0 1 1
0 1 1 1 0 0
0 0 1 1 1 1
1 1 1 0 1 1
1 0 1 1 1 1
1 1 1 1 1 0

Sample Output-1:
---------------- 
2

Explanation
------------
The network grid contains a 2 × 2 cluster of active nodes starting at position (2, 3):
1 1
1 1

Sample Input-2:
---------------
1 1
0

Sample Output-2:
---------------- 
0


```java
// only 50 marks
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LargestSquareMatrix {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[][] mat = new int[M][N];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                mat[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // Compute dp for largest square ending at (i,j)
        int[][] dp = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 1) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = 1 + Math.min(dp[i-1][j],
                            Math.min(dp[i][j-1], dp[i-1][j-1]));
                    } else {
                        dp[i][j] = 1;
                    }
                }
            }
        }

        // Identify critical nodes
        boolean[][] critical = new boolean[M][N];
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 1) {
                    int zeroCount = 0;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dr[d];
                        int nj = j + dc[d];
                        if (ni < 0 || ni >= M || nj < 0 || nj >= N || mat[ni][nj] == 0) {
                            zeroCount++;
                        }
                    }
                    critical[i][j] = (zeroCount >= 3);
                }
            }
        }

        // Build prefix sum for critical
        int[][] pref = new int[M+1][N+1];
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                pref[i][j] = (critical[i-1][j-1] ? 1 : 0)
                    + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        int bestSize = 0;
        int bestBottomRow = -1;

        // Iterate over possible bottom-right corners, avoiding perimeter
        for (int i = 1; i < M-1; i++) {
            for (int j = 1; j < N-1; j++) {
                int maxk = dp[i][j];
                maxk = Math.min(maxk, Math.min(i, j) + 1);
                // ensure the square stays off the last row/col: bottom row i <= M-2 and j <= N-2
                if (i > M-2 || j > N-2) continue;

                for (int k = maxk; k > bestSize; k--) {
                    int top = i - k + 1;
                    int left = j - k + 1;
                    if (top < 1 || left < 1) continue;
                    // Check for at least one critical node in region using prefix sum
                    int sumCrit = pref[top + k][left + k]
                        - pref[top][left + k] - pref[top + k][left] + pref[top][left];
                    if (sumCrit > 0) {
                        if (k > bestSize || (k == bestSize && i > bestBottomRow)) {
                            bestSize = k;
                            bestBottomRow = i;
                        }
                        break; // no need to check smaller k for this cell
                    }
                }
            }
        }

        System.out.println(bestSize);
    }
}

```