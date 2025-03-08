Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

Sample Input-1:
---------------
00110110
2

Sample Output-1: 
----------------
true

Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.

Sample Input-2:
---------------
0110
1

Sample Output-2: 
----------------
true

Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Sample Input-3:
---------------
0110
2

Sample Output-3: 
----------------
false

Explanation: The binary code "00" is of length 2 and does not exist in the array.
 

Constraints:
------------
1 <= s.length <= 5 * 10^5
s[i] is either '0' or '1'.
1 <= k <= 20
```java
import java.util.*;
class BinarySubString{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        int n=sc.nextInt();
        
        System.out.println(isBinarySubString(s,n));
    }
    
    static boolean isBinarySubString(String s,int n){
        int totalCount=1<<n;
        HashSet<String> seen=new HashSet<>();
        
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<n;i++){
            sb.append(s.charAt(i));
        }
        
        seen.add(sb.toString());
        
        for(int i=n;i<s.length();i++){
            // System.out.println(i);
            sb.deleteCharAt(0);
            sb.append(s.charAt(i));
            seen.add(sb.toString());
            
            if(seen.size()==totalCount){
                return true;
            }
        }
        return false;
    }
    
    //--------------Brute Force---------------------
    
    // static boolean isBinarySubString(String s,int n){
    //     ArrayList<String> res=new ArrayList<>();
        
    //     getAllBinary(n-1,res,0,n);
    //     // System.out.println(res);
    //     for(int i=0;i<res.size();i++){
    //         if(s.indexOf(res.get(i))==-1){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // static void getAllBinary(int index,ArrayList<String> res,int num,int size){
    //     if(index==-1){
    //         String s=Integer.toBinaryString(num);
    //         for(int i=1;i<=size-s.length();i++){
    //             s="0"+s;
    //         }
    //         res.add(s);
            
    //         return ;
    //     }
    //     getAllBinary(index-1,res,num|(1<<index),size);
    //     getAllBinary(index-1,res,num,size);
    // }
    
}
```