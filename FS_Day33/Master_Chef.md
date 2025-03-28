#topologicalsort

Imagine you're the master chef in a renowned kitchen, tasked with preparing a 
spectacular dinner consisting of numDishes unique dishes, labeled from 
0 to numDishes - 1. However, the recipes have dependencies—certain dishes can 
only be prepared after completing others. You’re given a list called dependecies, 
where each element dependencies[i] = [Xi, Yi] means that you must finish 
preparing dish Yi before starting dish Xi.

For instance, the pair [2, 1] implies that to create dish 2, 
dish 1 must be prepared first.

Return the ordering of dishes that a chef should take to finish all dishes.
	- the result set should follow the given order of conditions.
	- If it is impossible to complete all dishes, return an empty set.


Input Format:
-------------
Line-1: An integer numDishes, number of Dishes.
Line-2: An integer m, number of dependencies.
Next m lines: Two space separated integers, Xi and Yi.

Output Format:
--------------
Return a list of integers, the ordering of dishes that a chef should finish.

Sample Input-1:
---------------
4
3
1 2
3 0
0 1

Sample Output-1:
----------------
[2, 1, 0, 3]

Explanation: There are 4 dishes. Since dish 1 requires dish 2, dish 3 requires 
dish 0 and dish 0 requires dish 1, you can prepare dishes in the order 2 1 0 3.


Sample Input-2:
---------------
2
2
1 0
0 1

Sample Output-1:
----------------
[]

Explanation: There are 2 dishes, but dish 1 depends on dish 0 and dish 0 depends 
on dish 1. This circular dependency makes it impossible to prepare all dishes.

Constraints:
------------
- 1 <= numDishes <= 2000  
- 0 <= m <= 5000  
- dependencies[i].length == 2  
- 0 <= Xi, Yi < numDishes  
- All the dependency pairs are unique.

```java
import java.util.*;
public class Solution{
    public static List<Integer> find(int numDishes, int[][]dependencies ){
        //Write your code here
        HashMap<Integer,ArrayList<Integer>> list=new HashMap<>();
        ArrayList<Integer> res=new ArrayList<>();
        int freq[]=new int[numDishes];
        boolean[] made=new boolean[numDishes];
        
        for(int i=0;i<numDishes;i++){
            list.put(i,new ArrayList<>());
        }
        
        for(int i[]:dependencies){
            list.get(i[1]).add(i[0]);
            freq[i[0]]=freq[i[0]]+1;
        }
        
        Queue<Integer> q=new LinkedList<>();
        for(int i=0;i<numDishes;i++){
            if(freq[i]==0){
                q.offer(i);
            }
        }
        
        while(!q.isEmpty()){
            int curr=q.poll();
            made[curr]=true;
            res.add(curr);
            
            for(int i:list.get(curr)){
                if(!made[i]){
                    freq[i]--;
                }
                if(freq[i]==0){
                    q.offer(i);
                }
            }
        }
        return res;
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int numDishes = sc.nextInt(),m = sc.nextInt();
        int[][] dependencies = new int[m][2];
        for (int i=0;i<m ;i++ )
        {
            dependencies[i][0] = sc.nextInt();
            dependencies[i][1] = sc.nextInt();
        }
        System.out.println(find(numDishes,dependencies));
    }
}


```