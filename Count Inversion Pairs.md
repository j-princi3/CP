# Counting Inversions in an Array

## Problem Description

You are given an array of integers. An inversion is defined as a pair of indices (i, j) such that:
- i < j, and
- A[i] > A[j]

Your task is to count the total number of such inversion pairs in the array.

Inversions indicate how far an array is from being sorted. If the array is completely sorted in ascending order, the number of inversions is 0. If it's sorted in descending order, the number of inversions is at its maximum.

## Input Format
- Line-1: An integer n — the number of elements in the array
- Line-2: A list of n space-separated integers A[0], A[1], ..., A[n-1]

## Output Format
- Line-1: A single integer — the total number of inversions in the array

## Example Results

```
Sample Input-1:
-------------
6
3 -1 0 -2 2 1
Sample Output-1:
-------------
8
```
Inversions are: (3, -1)(3, 0)(3, -2)(3, 2)(3, 1)(-1, -2)(0, -2)(2, 1)

```
Sample Input-2:
-------------
4
4 3 2 1
Sample Output-2:
-------------
6
```
Inversions: All pairs where left > right — total = 6

```
Sample Input-3:
-------------
6
1 2 3 4 5 6
Sample Output-3:
-------------
0
```

## Constraints
- 1 ≤ n ≤ 1000
- -10^9 ≤ A[i] ≤ 10^9
- Elements can be positive, negative, or zero
- Input array may be partially or completely unsorted
- Time complexity should be O(n log n)

## Approach 1: Brute Force (O(n²))

The brute force approach checks all possible pairs:

```java
import java.util.*;
class Main {
    public static void main(String[] arr) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = s.nextInt();
        }
        int c = 0;
        for(int i = 0; i < a.length; i++) {
            for(int j = i + 1; j < a.length; j++) {
                if(i < j && a[i] > a[j]) {
                    c++;
                }
            }
        }
        System.out.println(c);
        s.close();
    }
}
```

While this works for small inputs, it's not efficient enough for larger inputs due to its O(n²) time complexity.

## Approach 2: Merge Sort (O(n log n))

We can use a modified merge sort algorithm to count inversions efficiently. The key insight is that inversions can be counted during the merge step of merge sort:

```java
import java.util.*;
public class Main {
    static int[] temp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        temp = new int[n];
        for(int i = 0; i < n; i++) a[i] = sc.nextInt();
        System.out.println(mergeSort(a, 0, n-1));
    }
    
    static int mergeSort(int[] arr, int left, int right) {
        if(left >= right) return 0;
        int mid = (left + right) / 2;
        int inv = mergeSort(arr, left, mid);
        inv += mergeSort(arr, mid + 1, right);
        inv += merge(arr, left, mid, right);
        return inv;
    }
    
    static int merge(int[] arr, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left, inv = 0;
        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                inv += (mid - i + 1); // Count inversions
            }
        }
        while(i <= mid) temp[k++] = arr[i++];
        while(j <= right) temp[k++] = arr[j++];
        for(int p = left; p <= right; p++) arr[p] = temp[p];
        return inv;
    }
}
```
