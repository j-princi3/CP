Malika taught a new fun time program practice for Engineering Students.
As a part of this she has given set of N numbers, and asked the students 
to perform the operations listed below:
1. sumRange(start, end) - return the sum of numbers between the indices start and end, both are inclusive.
2. update(ind, val) - update the value at the index 'ind' to 'val'.

Your task is to solve this problem using Fenwick Tree concept.

Input Format:
-------------
Line-1: Two integers N and Q, size of the array(set of numbers) and query count.
Line-2: N space separated integers.
next Q lines: Three integers option, start/ind and end/val.

Output Format:
--------------
An integer result, for every sumRange query.


Sample Input-1:
---------------
8 5
1 2 13 4 25 16 17 8
1 2 6		//sumRange
1 0 7		//sumRange
2 2 18	//update
2 4 17	//update
1 2 7		//sumRange

Sample Output-1:
----------------
75
86
80



Sample Input-2:
---------------
8 5
1 2 13 4 25 16 17 8
1 2 6		
1 0 7		
2 2 18	
2 4 17	
1 0 7

Sample Output-2:
----------------
75
86
83


```java
import java.util.*;
class FenWickTree{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int q=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int query[][]=new int[q][3];
        for(int i=0;i<q;i++){
            query[i][0]=sc.nextInt();
            query[i][1]=sc.nextInt();
            query[i][2]=sc.nextInt();
        }
        fenwickTree(query,n,q,arr);
    }
    static void fenwickTree(int query[][],int n,int q,int arr[]){
        fenwick fw=new fenwick(arr,n);
        int i=0;
        // for(int j=0;j<n+1;j++){
        //     System.out.print(fw.bit[j]+" ");
        // }
        while(i<q){
            if(query[i][0]==1){
                // System.out.print("Message");
                System.out.println(fw.getSumRange(query[i][1],query[i][2]));
            }else if(query[i][0]==2){
                fw.updateBit(query[i][1],query[i][2]);
            }
            i++;
        }
    }
    
}
class fenwick{
    int bit[];
    int size;
    int arr[];
    fenwick(int arr[],int n){
        this.size=n;
        this.arr=arr;
        this.bit=new int[size+1];
        for(int i=0;i<n;i++){
            init(i,arr[i]);
        }
    }
    void init(int i,int val){
        i++;
        while(i<=size){
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int getSumRange(int start,int end){
        // System.out.println("ll");
        // if(start==0){
        //     return sum(end);
        // }
        return sum(end)-sum(start-1);
    }
    int sum(int i){
        int addition=0;
        i++;
        while(i>0){
            addition+=bit[i];
            i-=(i&-i);
        }
        return addition;
        
    }
    void updateBit(int i,int val){
        int diff=val-arr[i];
        arr[i]=val;
        for(int j=0;j<=size;j++){
            System.out.print(bit[j]+" ");
        }
        init(i,diff);
    }
    
}
```