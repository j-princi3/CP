In Turkey, an ice cream parlour gives an offer to a lucky kid.
The parlour keep N icecream cups in a row, and there are different flavours 
of icecreams, where i-th cup filled with the flavour[i] type of ice cream.

The kid can pick the continuous set of ice cream cups, where the cups filled
with the icecreams of atmost two different flavours. The kid wants to 
pick maximum number of icecream cups from the row.

You will be given the integer array, flavours[] of size N.
Your task is to help the kid to pick the maximum number of icecream cups 
with atmost two different flavours.


Input Format:
-------------
Line-1: An integer, number of icecreams.
Line-2: N space separated integers, flavours[] 

Output Format:
--------------
Print an integer result, maximum number of icecream cups can be picked.


Sample Input-1:
---------------
10
1 2 3 1 1 3 3 2 3 2

Sample Output-1:
----------------
5

Explanation:
------------
The kid can pick the continuous set of icecream cups as follows: 3 1 1 3 3
Where the cups are filled with two different flavours, 1 and 3.



Sample Input-2:
---------------
10
2 1 1 3 2 1 3 0 0 3

Sample Output-2:
----------------
4

```java
import java.util.*;
class MaxIcecream{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(getMaxIcecream(arr,n));
    }
    static int getMaxIcecream(int arr[],int n){
        HashMap<Integer,Integer> freq=new HashMap<>();
        int max=Integer.MIN_VALUE;
        int start=0;
        for(int i=0;i<n;i++){
            freq.put(arr[i],freq.getOrDefault(arr[i],0)+1);
            if(freq.size()>2){
                while(start<n && freq.size()>2){
                    if(freq.get(arr[start])==1){
                        freq.remove(arr[start]);
                    }else{
                        freq.put(arr[start],freq.get(arr[start])-1);
                    }
                    start++;
                }
            }
            if(freq.size()==2){
                int sum=0;
                for(Map.Entry<Integer,Integer> s: freq.entrySet()){
                    sum+=s.getValue();
                }
                max=Math.max(sum,max);
            }
            // System.out.println(freq);
            
        }
        return max;
    }
}
```