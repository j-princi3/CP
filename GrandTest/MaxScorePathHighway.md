# 🚀 Maximum Score of a Valid Path

Given two sorted arrays `nums1` and `nums2` with distinct integers, the goal is to determine the **maximum score** from all valid paths.

## 🧠 Problem Statement

A valid path is defined as:

- Start from index 0 of either `nums1` or `nums2`.
- Traverse from left to right.
- You are allowed to **switch paths** **only** at elements common to both arrays.
- A common element is **counted only once** in the final score.

The score is the **sum of unique values** in a chosen valid path.  
Return the **maximum possible score**, modulo `10⁹ + 7`.

---

## 📥 Sample Test Case 1

Input: nums1 = [2,4,5,8,10] nums2 = [4,6,8,9]

Output: 30

## 🧩 Explanation:

### Valid paths:

- From `nums1`: `[2,4,5,8,10]`, `[2,4,5,8,9]`
- From `nums2`: `[4,6,8,10]`, `[4,6,8,9]`
- Mixed paths using common values `4` and `8`:  
  e.g., `[2,4,6,8,10]` → Score = `2 + 4 + 6 + 8 + 10 = 30`

---

## 🖼️ Visual Diagram (Example 1)

🖼️ **Insert the following diagram here**

> _You can illustrate this with two rows (nums1 and nums2) and arrows showing where switching is allowed._

**📌 Image Placeholder:**  
`![Valid Path Illustration](../assets/lc_1537_gt1.png)`

---

## ✅ Optimal Approach: Two Pointer + Greedy

### Why This Works:

- Arrays are strictly increasing.
- We can move forward only.
- Switching is only possible at matching values.
- So we use **two partial sums**:
  - `sum1` → total so far in `nums1`
  - `sum2` → total so far in `nums2`

### Greedy Choice:

- At a common value, take the **maximum** of both partial sums + the common value.
- Reset both sums and continue.

---

## 💡 Time and Space Complexity

| Complexity | Value                                                           |
| ---------- | --------------------------------------------------------------- |
| Time       | `O(m + n)` where `m` and `n` are lengths of `nums1` and `nums2` |
| Space      | `O(1)` — uses constant space                                    |

---

## ✅ Java Implementation

```java
import java.util.Scanner;

public class HighwayMaxScore {
    private static final int MOD = 1_000_000_007; //Equivalent to 10^9 + 7

    public static int getMaxScore(int[] nums1, int[] nums2) {
        //Write your code and return an integer, the maximum score
        int m = nums1.length;
        int n = nums2.length;

        int i = 0 , j = 0;

        // simulatenously calc the sum
        long sum1 = 0 , sum2 = 0;
        long score = 0;
        while(i < m && j < n){
            if(nums1[i] == nums2[j]){
                score += Math.max(sum1,sum2) + nums1[i];
                sum1 = sum2 = 0;
                i++;
                j++;
            }else if(nums1[i] < nums2[j]){
                sum1 += nums1[i];
                i++;
            }else {
                sum2 += nums2[j];
                j++;
            }
        }

        while(i < m) sum1 += nums1[i++];
        while(j < n) sum2 += nums2[j++];

        score += Math.max(sum1,sum2);
        return (int)(score % MOD);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read Highway A
        int n = scanner.nextInt();
        int[] highwayA = new int[n];
        for (int i = 0; i < n; i++) {
            highwayA[i] = scanner.nextInt();
        }

        // Read Highway B
        int m = scanner.nextInt();
        int[] highwayB = new int[m];
        for (int i = 0; i < m; i++) {
            highwayB[i] = scanner.nextInt();
        }

        // Calculate and print max score
        System.out.println(getMaxScore(highwayA, highwayB));

        scanner.close();
    }
}

```