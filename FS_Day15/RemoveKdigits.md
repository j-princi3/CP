#stack
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
input =1432219
3
output =1219

num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.


Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.



```java
import java.util.*;
class RemoveKdigits{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        int k=sc.nextInt();
        System.out.println(Long.parseLong(getResult(s,k)));
    }
    static String getResult(String s,int k){
        if(s.length()<=k){
            return "0";
        }
        Stack<Character> st=new Stack<>();
        int i=0;
        while(i<s.length()){
            if(st.isEmpty()){
                st.push(s.charAt(i));
                i++;
            }else{
                if(k>0){
                    while(!st.isEmpty() && k>0){
                        int curr=Integer.parseInt(st.peek()+"");
                        if(curr>Integer.parseInt(s.charAt(i)+"")){
                            st.pop();
                            k--;
                        }else{
                            break;
                        }
                    }
                }
                st.push(s.charAt(i));
                i++;
            }
        }
        while(k>0 && !st.isEmpty()){
            st.pop();
            k--;
        }
        StringBuilder res=new StringBuilder("");
        while(!st.isEmpty()){
            res.append(st.pop());
        }
        res.reverse();
        return res.toString();
    }
}
```