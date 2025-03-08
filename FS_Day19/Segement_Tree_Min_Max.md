Malika taught a new fun time program practice for Engineering Students.
As a part of this she has given set of N numbers, and asked the students 
to perform the operations listed below:
1. sumRange(start, end) - return the sum of numbers between the indices start and end, both are inclusive.
2. update(ind, val) - update the value at the index 'ind' to 'val'.
3. Find the min value in the given range
4. Find the max value in the given range 

Your task is to solve this problem using Segment Tree concept.

Input Format:
-------------
Line-1: Two integers N and Q, size of the array(set of numbers) and query count.
Line-2: N space separated integers.
next Q lines: Three integers option, start/ind and end/val.

Output Format:
--------------
An integer result, for every sumRange query.


Sample Input:
-------------
8 7
4 2 13 3 25 16 17 8
1 2 6		//sumRange
1 0 7		//sumRange
3 2 6       //get max value in the range
2 2 18	    //update
2 4 17	    //update
1 2 6		//sumRange
4 1 5       // get min value in the range
 

Sample Output:
--------------
74
88
25
71
2

```java
import java.util.*;
public class SegmentTreeTest{
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

        segment s=new segment(arr,0,n-1);
        segment temp=s;
        s.buildSegmentTree(temp, 0, n-1);
        for(int i=0;i<q;i++){
            if(query[i][0]==1){
                
                System.out.println(s.sumRange(temp,query[i][1],query[i][2] ));
            }else if(query[i][0]==2){
                
                s.updateTree(temp,query[i][1],query[i][2] );
            }else if(query[i][0]==3){
                
                System.out.println(s.findMin(temp,query[i][1],query[i][2] ));
            }else if(query[i][0]==4){
                System.out.println(s.findMax(temp,query[i][1],query[i][2] ));
            }
        }
        // s.printTree(temp);
        // s.printTree(s);

    }
    
}
class segment{
    
    int start;
    int end;
    int sum;
    int min;
    int max;
    segment left;
    segment right;
    int arr[];
    
    segment(int arr[],int start,int end){
        this.arr=arr;
        this.start=start;
        this.end=end;
        left=null;
        right=null;
        min=Integer.MAX_VALUE;
        max=Integer.MIN_VALUE;
    }
    
    int buildSegmentTree(segment seg,int s,int e){
        if(s==e){
            seg.sum=arr[s];
            seg.min=arr[s];
            seg.max=arr[s];
            return arr[s];
        }
        int mid=(s+e)/2;
        seg.left=new segment(arr, s, mid);
        seg.right=new segment(arr, mid+1, e); 
        // System.out.println(s+" "+e);
        int l=buildSegmentTree(seg.left,s,mid);
        int r=buildSegmentTree(seg.right,mid+1,e);
        seg.sum=l+r;
        seg.min=Math.min(seg.left.min,seg.right.min);
        seg.max=Math.max(seg.left.max,seg.right.max);
        // System.out.println(seg.sum);
        return l+r;
    }

    void printTree(segment s){
        if(s==null){
            return ;
        }
        printTree(s.left);
        // System.out.print(s.sum+" ");
        printTree(s.right);
        System.out.print(s.min+" ");
    }

    void updateTree(segment seg,int index,int val){

        if(seg.start==seg.end && seg.start==index){
            seg.sum=val;
            seg.min=val;
            seg.max=val;
            return;
        }

        int mid=(seg.start+seg.end)/2;

        if(index>=seg.start && index<=mid){
            updateTree(seg.left, index, val);
        }else{
            updateTree(seg.right, index, val);
        }
        seg.sum=seg.left.sum+seg.right.sum;
        seg.min=Math.min(seg.left.min,seg.right.min);
        seg.max=Math.max(seg.left.max,seg.right.max);
    }

    int sumRange(segment seg ,int rs,int re){

        if(rs==seg.start && re==seg.end){
            return seg.sum;
        }

        int s=0;
        int mid=(seg.start+seg.end)/2;

        if(rs>mid && re<=seg.end){
            s+=sumRange(seg.right, rs, re);
        }else if(rs>=seg.start && re<=mid){
            s+=sumRange(seg.left, rs, re);
        }else{
            s+=sumRange(seg.left, rs, mid);
            s+=sumRange(seg.right, mid+1, re);
        }
        return s;
    }

    int findMin(segment seg ,int rs,int re){

        if(rs==seg.start && re==seg.end){
            return seg.min;
        }
        
        int mid=(seg.start+seg.end)/2;

        if(rs>mid && re<=seg.end){
            return findMin(seg.right, rs, re);
        }else if(rs>=seg.start && re<=mid){
            return findMin(seg.left, rs, re);
        }
        return Math.min(findMin(seg.left, rs, mid),findMin(seg.right, mid+1, re));
    }

    int findMax(segment seg ,int rs,int re){

        if(rs==seg.start && re==seg.end){
            return seg.max;
        }
        int mid=(seg.start+seg.end)/2;

        if(rs>mid && re<=seg.end){
            return findMax(seg.right, rs, re);
        }else if(rs>=seg.start && re<=mid){
            return findMax(seg.left, rs, re);
        }
        return Math.max(findMax(seg.right, mid+1, re),findMax(seg.left, rs, mid));
        
    }
    
    
}

```