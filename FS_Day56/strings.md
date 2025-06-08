## Problem 1: String Interleaving Task Scheduler

### Description
Alice and Bob have their own task lists represented as strings. Each character is a task. You need to find all valid ways to create a shared task schedule that includes all tasks from both lists, but without changing the order of tasks for either person.

An interleaving of two strings X and Y is a combination of characters where:
- All characters from both strings are used exactly once
- The order of characters from each original string is maintained

### Example
If X = "AB" and Y = "CD", valid interleaving's are:
- "ABCD" (A→B→C→D)
- "ACBD" (A→C→B→D)
- "ACDB", "CABD", "CADB", "CDAB"

### Input Format
Line-1: two space-separated strings

### Output Format
Line-1: List of strings(interleaving's) that matches order of characters.

### Sample Input-1
```
ABC ACB
```

### Sample Output-1
```
[AACBCB, ABCACB, ACBABC, ABACCB, ACABCB, AABCCB, ACABBC, AACBBC, ABACBC, AABCBC]
```

### Sample Input-2
```
12 AB
```

### Sample Output-2
```
[12AB, 1A2B, 1AB2, A12B, A1B2, AB12]
```

### Code
```java
import java.util.*;

public class InterleavingStringsFormattedInput{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x=sc.next();
        String y=sc.next();
        Set<String> rs=new HashSet<>();
        gen(x, y, "", rs);
        List<String> result=new ArrayList<>(rs);
        Collections.sort(result);
        System.out.println(result);
    }

    static void gen(String X, String Y, String res, Set<String> result) {
        if(X.length() == 0 && Y.length() == 0){
            result.add(res);
            return;
        }
        if(X.length() > 0){
            gen(X.substring(1),Y,res + X.charAt(0),result);
        }
        if(Y.length() > 0){
            gen(X,Y.substring(1),res + Y.charAt(0),result);
        }
    }
}
```

---

## Problem 2: Isomorphic String Checker

### Description
You are given two strings. Determine whether the first string can be converted to the second by replacing each character with a unique character while preserving the order.

Each character from the first string must map to one and only one character in the second string and vice versa. Two characters in the first string cannot map to the same character in the second.

Two strings are isomorphic if:
- Each character in the first-string maps to one unique character in the second string
- This mapping must be consistent throughout the string
- No two different characters from the first-string map to the same character in the second string

### Input Format
Line-1: two space-separated strings

### Output Format
Line-1: Boolean value True/False

### Sample Input-1
```
ACAB XCXY
```

### Sample Output-1
```
True
```

### Explanation
A → X, C → C, B → Y — all mappings are unique and consistent.

### Sample Input-2
```
FOO BAR
```

### Sample Output-2
```
False
```

### Code
```java
import java.util.*;

public class IsomorphicStringsCheck{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        String str2 = sc.next();
        System.out.println(iso(str1, str2));
    }

    public static boolean iso(String s1, String s2) {
        if(s1.length() != s2.length()) return false;
        Map<Character, Character> map1 = new HashMap<>();
        Set<Character> mappedChars = new HashSet<>();
        for(int i = 0; i < s1.length(); i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            if(map1.containsKey(c1)) {
                if (map1.get(c1) != c2) return false;
            }else{
                if (mappedChars.contains(c2)) return false;
                map1.put(c1, c2);
                mappedChars.add(c2);
            }
        }
        return true;
    }
}
```

---

## Problem 3: Secret Agent Pattern Matcher

### Description
A secret agent receives a list of encrypted codewords. Each codeword must follow the same symbol sequence as a given prototype code. Your mission is to find which codewords follow the same symbol arrangement.

**NOTE:** Matching is not about the actual characters, but how they repeat. For example, "moon" = m o o n → pattern: first letter, two repeated letters, and a unique last letter.

### Input Format
- Line-1: A space-separated list of words
- Line-2: A string representing the reference pattern

### Output Format
Line-1: A list of words that follow the same pattern, if not found print -1

### Sample Input-1
```
Leet abcd loot geek cool for peer dear seed meet noon mess loss
moon
```

### Sample Output-1
```
leet loot geek cool peer seed meet
```

### Sample Input-2
```
leet abcd loot geek cool for peer dear
lamp
```

### Sample Output-2
```
abcd dear
```

### Code
```java
import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] words=sc.nextLine().toLowerCase().split(" ");
        String pattern=sc.nextLine().toLowerCase();
        List<String>result=new ArrayList<>();
        String p=encode(pattern);
        for(String word : words){
            if(encode(word).equals(p)) {
                result.add(word);
            }
        }
        if(result.isEmpty()){
            System.out.println("-1");
        } else{
            System.out.println(String.join(" ", result));
        }
    }

    private static String encode(String word){
        Map<Character, Integer> map=new HashMap<>();
        StringBuilder sb=new StringBuilder();
        int code=0;
        for(char c : word.toCharArray()){
            if(!map.containsKey(c)){
                map.put(c,code++);
            }
            sb.append(map.get(c));
        }
        return sb.toString();
    }
}
```

---