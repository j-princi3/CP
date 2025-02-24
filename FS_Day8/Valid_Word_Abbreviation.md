#2-pointer 
#medium 
Given a non-empty string s and an abbreviation abbr, 
return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

Notice that only the above abbreviations are valid abbreviations of the string "word". 
Any other string is not a valid abbreviation of "word".

Note: Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Input Format:
-------------
Line-1: A string, S contains only lowercase letters
Line-2: A string, abbr contains lowercase letters and digits

Output Format:
--------------
Line-1: A boolean value.
Sample Input-1:
---------------
1+12=1320
internationalization
i12iz4n

Sample Output-1:
---------------
true

Sample Input-2:
---------------
apple
a2e

Sample Output-2:
---------------
false

Time Complexity: O(n) where n=max(len(word),len(abbr))
Auxiliary Space:  O(1).

```java
import java.util.*;
class ValidWordAbbreviation{
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        String abbr=sc.next();
        System.out.print(getValidityCheck(s,abbr));
    }
    static boolean getValidityCheck(String s,String abbr){
        int aIndex=0;
        int sIndex=0;
        while(aIndex<abbr.length()){
            String digits="";
            
            if( abbr.charAt(aIndex)=='0'){
                return false;
            }
            while(aIndex<abbr.length() && abbr.charAt(aIndex)>='0' && abbr.charAt(aIndex)<='9'){
                
                digits+=abbr.charAt(aIndex);
                
                aIndex++;
                
            }
            
            if(!digits.equals("")){
                sIndex+=Long.parseLong(digits);
                
            }
            
            
            if(sIndex>s.length() || aIndex>abbr.length() ||(aIndex<abbr.length() && sIndex==s.length())){
                return false;
            }else if(sIndex<s.length() && aIndex<abbr.length() && abbr.charAt(aIndex)==s.charAt(sIndex)){
                
                aIndex++;
                sIndex++;
            }else if(sIndex<s.length() && aIndex<abbr.length() && abbr.charAt(aIndex)!=s.charAt(sIndex)){
                
                return false;
            }
            
            
        }
        if(sIndex<s.length() ||aIndex<abbr.length() ){
            return false;
        }
        return true;
    }
}
```