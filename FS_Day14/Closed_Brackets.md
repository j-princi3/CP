Clavius, the person who suggested grouping of data using brackets.
He has suggested that the group of brackets should be Well-Formed.

A string is said to be Well-Formed, if:
    - Any open bracket must have corresponding two consecutive close brackets.
    - Open bracket must appear before the corresponding close brackets.

You will be given a string B, consists of square brackets only '[' , ']'.
In one operation, you can insert one square bracket at any position of B.
i.e., Given B = [[]]], in one operation you can add a open square bracket,
now B can be Well-Formed string, if you add at index 2,3,4 or 5 => [[]]]]

Your task is to return the least number of operations required,
to make B as a Well-Formed string.

Input Format:
-------------
A string, B contains only characters '[', ']'

Output Format:
--------------
Print an integer value.


Sample Input-1:
---------------
[]]][

Sample Output-1:
----------------
4


Sample Input-2:
---------------
[]][[]]

Sample Output-2:
----------------
2


```java
import java.util.*;
class ClosedBrackets{

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        System.out.println(minInsertions(s));
    }
    static int minInsertions(String s){
        Stack<Character> st=new Stack<>();
        int count=0;
        int i=0;
        while(i<s.length()){


            if(st.isEmpty()){


                int j=0;
                while(i<s.length() && s.charAt(i)==']'){
                    j++;
                    i++;
                }
                if(j!=0 && j%2==0){
                    count+=j/2;
                }else if(j!=0 && j%2!=0){
                    count+=(j/2)+2;
                }else if(i<s.length()){
                    st.push(s.charAt(i));
                    i++;
                }
            }else{
                if(st.peek()==']'){
                    if(s.charAt(i)==']'){
                        st.pop();
                        st.pop();
                    }else{
                        count++;
                        st.pop();
                    }
                    
                }else{
                    st.push(s.charAt(i));
                }
                i++;
            }
            // System.out.println(count+" "+st);
        }
        if(!st.isEmpty()){
            if(st.peek()==']'){
                count+=(st.size()-1)*2-1;
            }else{
                count+=st.size()*2;
            }
        }
        return count;
    

    }

}
```