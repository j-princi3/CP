You are given an array of people, which are the attributes of some people in 
a queue (not necessarily in order). 
Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki 
other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. 
The returned queue should be formatted as an array queue, where queue[j] = [hj, kj]
is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

Input Format : 
--------------
Line-1: An integer n
Line-2: n number of pairs

Output Format : 
--------------
list of n pairs

Sample Input-1:
---------------
6
7 0
4 4
7 1
5 0
6 1
5 2

Sample Output-1: 
---------------
[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

Sample Input-2:
--------------
6
6 0 
5 0 
4 0
3 2
2 2
1 4

Sample Output-2: 
----------------
[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:
-------------
1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.

```java
import java.util.*;

public class Solution {


    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        // Read the number of people
        int n = Integer.parseInt(sc.nextLine().trim());
        int[][] people = new int[n][2];
        
        // Read n pairs of inputs
        for (int i = 0; i < n; i++) {


            String line = sc.nextLine().trim();
            String[] parts = line.split(" ");
            people[i][0] = Integer.parseInt(parts[0]); // height
            people[i][1] = Integer.parseInt(parts[1]); // k value
        }
        
        // Sort the array:
        // - Descending order by height.
        // - If heights are equal, sort ascending by k.
        Arrays.sort(people, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {


                if (a[0] != b[0])
                    return b[0] - a[0];
                return a[1] - b[1];
            }
        });
        
        // Insert each person into the list at index = k value.
        List<int[]> queue = new LinkedList<>();
        for (int[] person : people) {


            queue.add(person[1], person);
        }
        
        // Print the result in the desired format.
        System.out.print("[");
        for (int i = 0; i < queue.size(); i++) {


            int[] person = queue.get(i);
            System.out.print("[" + person[0] + "," + person[1] + "]");
            if (i != queue.size() - 1)
                System.out.print(",");
        }
        System.out.println("]");
    }

}
```