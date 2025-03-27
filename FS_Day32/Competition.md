There are n football players standing in the ground, coach wants to know the 
P-th largest height of the players. Given an array of heights[] and the value of P. 
Help the coach to find the P'th largest height.

Note: You are supposed to print the P'th largest height in the sorted order of heights[].
      Not the P'th distinct height.

Input Format:
-------------
Line-1: Size of array n and P value(space separated)
Line-2: Array elements of size n.

Output Format:
--------------
Print P'th largest height.

Sample input-1:
---------------
8 2
1 2 1 3 4 5 5 5

Sample output-1:
----------------
5

Sample input-2:
---------------
6 3
2 4 3 1 2 5

Sample output-2:
----------------
3

```java
import java.util.Scanner;

public class Solution {


    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        // Read the comma separated words
        String input = sc.nextLine();
        String[] words = input.split(",");

        // Initialize commonMask with all 26 bits set (each bit represents a letter from 'a' to 'z')
        int commonMask = (1 << 26) - 1;  // Equivalent to 0b111...111 (26 ones)

        // For each word, build its bit mask and update the commonMask using bitwise AND.
        for (String word : words) {


            int mask = 0;
            for (char c : word.toCharArray()) {


                mask |= 1 << (c - 'a');  // Set the bit corresponding to the letter
            }
            // Keep only those bits that are common in all words processed so far.
            commonMask &= mask;
        }

        // Count the number of set bits in commonMask. This count represents the number of characters common to all words.
        int count = Integer.bitCount(commonMask);
        System.out.println(count);
    }

}
```