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

public class ValidWordAbbreviation {
    public static boolean isValidWordAbbreviation(String word, String abbr) {
        int i = 0, j = 0;
        int m = word.length(), n = abbr.length();
        while (i < m && j < n) {
            if (Character.isDigit(abbr.charAt(j))) {
                if (abbr.charAt(j) == '0')
                    return false; // no leading zeros
                int num = 0;
                while (j < n && Character.isDigit(abbr.charAt(j))) {
                    /*
                     * abbr = "i12iz4n"
                     * At j = 1, we find digit '1'.
                     * num = 0 * 10 + (1 - 0) = 1.
                     * At j = 2, we find digit '2'.
                     * num = 1 * 10 + (2 - 0) = 12.
                     * Now, num holds the value 12, meaning we skip 12 characters in the word!
                     */
                    num = num * 10 + (abbr.charAt(j) - '0');
                    j++;
                }
                i += num;
            } else {
                if (word.charAt(i) != abbr.charAt(j))
                    return false;
                i++;
                j++;
            }
        }
        return i == m && j == n;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String word = sc.next();
        String abbrivation = sc.next();
        System.out.println(new ValidWordAbbreviation().isValidWordAbbreviation(word, abbrivation));
    }
}
```