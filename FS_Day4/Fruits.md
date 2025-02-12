#medium 
#flexibleslidingwindow  
You are visiting a farm that has a single row of fruit trees arranged from left to right.

The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. 

However, the owner has some strict rules that you must follow:
You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.

Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree)
while moving to the right. The picked fruits must fit in one of your baskets.

Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Sample Input-1:
---------------
3
1 2 1

Sample Output-1: 
----------------
3

Explanation: We can pick from all 3 trees.

Sample Input-2:
--------------- 
4
0 1 2 2 

Sample Output-2: 
----------------
3

Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Sample Input-3: 
---------------- 
5
1 2 3 2 2

Sample Output-4: 
----------------
4

Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

```java
import java.util.*;
class Fruit{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(getFruitsMax(arr,n));
    }
    static int getFruitsMax(int arr[],int n){
        
        HashMap<Integer,Integer> s=new HashMap<>();
        int maxFruits=0;
        int left=0;
        
        for(int i=0;i<n;i++){
            
            s.put(arr[i],s.getOrDefault(arr[i],0)+1);
            
            while(s.size()>2){
                s.put(arr[left],s.getOrDefault(arr[left],0)-1);
                
                if(s.get(arr[left])==0){
                    s.remove(arr[left]);
                }
                left++;
                
            }
            
            maxFruits=Math.max(maxFruits,i-left+1);
            
        }
        
        return maxFruits;
    } 
}
```