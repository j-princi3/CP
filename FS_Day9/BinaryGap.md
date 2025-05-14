#bitmanipulation 
#medium 
You are given a positive integer n. 
Your task is to determine the longest distance between any two adjacent 1s in its binary representation.

Definitions:
Two 1s are considered adjacent if there are only 0’s separating them (possibly no 0’s).
The distance between two adjacent 1’s is the absolute difference between their bit positions.
If there are no two adjacent 1's, return 0.

For example, the two 1's in "1001" have a distance of 3.

Input Format:
-------------
Line-1: An integer number

Output Format:
--------------
Line-1: An integer number

Sample Input-1:
---------------
22

Sample Output-1:
----------------
2

Explanation:
------------
Binary representation of 22 is "10110".
Adjacent 1s appear at positions: (1,3) and (3,4)
Distances: 3 - 1 = 2, 4 - 3 = 1
Maximum distance is 2.

Sample Input-2:
---------------
8

Sample Output-2: 
----------------
0

Explanation:
-------------
Binary representation of 8 is "1000".
There is only one 1, so no adjacent pairs exist.
Output is 0.

```java
import java.util.Scanner;

public class AdjacentOnesDistance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        
        // Convert n to its binary string representation.
        // Example: 22 --> "10110"
        String binary = Integer.toBinaryString(n);
        
        // Initialize variables to store the maximum distance and the last seen position of '1'
        int maxDistance = 0;
        int prevPosition = -1;
        
        // Iterate over the binary string. We treat the position index starting from 0 on the left.
        // However, if you need to consider the position as shown in the explanation (starting from 1),
        // we add 1 to the index.
        for (int i = 0; i < binary.length(); i++) {
            if (binary.charAt(i) == '1') {
                // if a previous '1' was found, calculate the distance.
                if (prevPosition != -1) {
                    int distance = (i - prevPosition);  // distance in index difference
                    maxDistance = Math.max(maxDistance, distance);
                }
                // update the previous position where '1' was seen
                prevPosition = i;
            }
        }
        
        // If there are no adjacent ones then maxDistance remains 0.
        System.out.println(maxDistance);
    }
}

```