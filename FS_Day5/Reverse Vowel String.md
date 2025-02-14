Given a string s, reverse only all the vowels in the 
string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can 
appear in both lower and upper cases, more than once.

Sample Input-1:
---------------
hello

Sample Output-1:
----------------
holle

Sample Input-2:
----------------
Keshavmemorial

Sample Output-2:
----------------
Kashivmomerael

```java
import java.util.*;
class ReverseVowels{
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        System.out.println(getReverseVowel(s));
    }
    static String getReverseVowel(String s){
        
        StringBuilder sb=new StringBuilder(s);
        
        ArrayList<Character> vowels=new ArrayList<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        vowels.add('U');
        vowels.add('O');
        vowels.add('I');
        vowels.add('E');
        vowels.add('A');
        int left=0;
        int right=s.length()-1;
        
        while(left<right){
            if(vowels.contains(s.charAt(left))&& vowels.contains(s.charAt(right))){
                
                char v=s.charAt(right);
                
                sb.setCharAt(right,sb.charAt(left));
                
                sb.setCharAt(left,v);
                
                right--;
                left++;
                
            }
            if(!vowels.contains(s.charAt(left))){
                left++;
            }
            if(!vowels.contains(s.charAt(right))){
                right--;
            }
        }
        return sb.toString();
    }
}
```