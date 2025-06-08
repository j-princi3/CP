## Problems Included

1. **Emphatic Pronunciation Counter** - Count valid original words for emphatic pronunciations
2. **Palindrome Partitioning** - Find all valid palindromic segmentations
3. **Bijective String Matching** - Check if two strings can be mapped bijectively

---

## Problem 1: Emphatic Pronunciation Counter

### Description

"Emphatic Pronunciation" is where we replicate letters in a word to emphasize their impact. For example, "oh my god" becomes "ohhh myyy goddd". A valid emphatic pronunciation requires:
- Replicated groups must be at least 3 characters
- Replicated count must be ≥ original group size

### Input Format
- **Line 1**: Emphatic pronunciation word
- **Line 2**: Space-separated candidate words

### Output Format
- Integer count of valid original words

### Examples

**Input 1:**
```
goood
good goodd
```
**Output:** `1`

**Input 2:**
```
heeelllooo
hello hi helo
```
**Output:** `2`

### Code Implementation

```java
import java.util.*;

class Main {
    public static void main(String[] arr) {
        Scanner s = new Scanner(System.in);
        String em = s.nextLine();
        String[] words = s.nextLine().trim().split(" ");
        int c = 0;
        for (String i : words) {
            if (valid(i, em)) {
                c++;
            }
        }
        System.out.print(c);
    }
    
    static boolean valid(String word, String em) {
        int i = 0, j = 0;
        int n = word.length();
        int m = em.length();
        while (i < n && j < m) {
            char a = word.charAt(i);
            char b = em.charAt(j);
            if (a != b) return false;
            int ec = 0, wc = 0;
            while (i < n && word.charAt(i) == a) {
                wc++;
                i++;
            }
            while (j < m && em.charAt(j) == b) {
                ec++;
                j++;
            }
            if (ec < wc) return false;
            if (ec < 3 && ec != wc) return false;
        }
        return i == n && j == m;
    }
}
```

---

## Problem 2: Palindrome Partitioning (Magical Spells)

### Description

In the ancient land of Palindoria, wizards write spells as strings. For effectiveness, each segment must be a palindrome. Find all valid ways to partition a spell into palindromic segments.

### Input Format
- Single string (spell)

### Output Format
- List of all valid palindromic partitions

### Examples

**Input 1:**
```
aab
```
**Output:** `[[a, a, b], [aa, b]]`

**Input 2:**
```
a
```
**Output:** `[[a]]`

### Code Implementation

```java
import java.util.*;

class Main {
    public static void main(String[] arr) {
        Scanner s = new Scanner(System.in);
        String str = s.next();
        System.out.print(partition(str));
    }
    
    public static List<List<String>> partition(String spell) {
        List<List<String>> res = new ArrayList<>();
        backtrack(spell, 0, new ArrayList<>(), res);
        return res;
    }

    private static void backtrack(String spell, int start, List<String> current, List<List<String>> res) {
        if (start == spell.length()) {
            res.add(new ArrayList<>(current));
            return;
        }
        for (int end = start + 1; end <= spell.length(); end++) {
            String substr = spell.substring(start, end);
            if (isPalindrome(substr)) {
                current.add(substr);
                backtrack(spell, end, current, res);
                current.remove(current.size() - 1); 
            }
        }
    }

    private static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right)
            if (s.charAt(left++) != s.charAt(right--))
                return false;
        return true;
    }
}
```

---

## Problem 3: Bijective String Matching

### Description

Determine if string S2 can match string S1 through a bijective mapping. Each character in S1 must map to a unique substring in S2, and each substring in S2 must correspond to exactly one character in S1.

### Input Format
- Two strings S1 and S2 on one line

### Output Format
- Boolean result (true/false)

### Examples

**Input 1:**
```
abab kmitngitkmitngit
```
**Output:** `true`

**Input 2:**
```
aaaa kmjckmjckmjckmjc
```
**Output:** `true`

**Input 3:**
```
mmnn pqrxyzpqrxyz
```
**Output:** `false`

### Code Implementation

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] input = s.nextLine().split(" ");
        String s1 = input[0];
        String s2 = input[1];
        System.out.println(canMatch(s1, s2));
    }
    
    static boolean canMatch(String s1, String s2) {
        return backtrack(s1, s2, 0, 0, new HashMap<>(), new HashSet<>());
    }
    
    static boolean backtrack(String s1, String s2, int i1, int i2, 
                           Map<Character, String> charToStr, Set<String> usedStr) {
        if (i1 == s1.length() && i2 == s2.length()) return true;
        if (i1 == s1.length() || i2 == s2.length()) return false;
        
        char c = s1.charAt(i1);
        
        if (charToStr.containsKey(c)) {
            String mapped = charToStr.get(c);
            if (i2 + mapped.length() > s2.length()) return false;
            if (!s2.substring(i2, i2 + mapped.length()).equals(mapped)) return false;
            return backtrack(s1, s2, i1 + 1, i2 + mapped.length(), charToStr, usedStr);
        }
        
        for (int len = 1; len <= s2.length() - i2; len++) {
            String substr = s2.substring(i2, i2 + len);
            if (usedStr.contains(substr)) continue;
            
            charToStr.put(c, substr);
            usedStr.add(substr);
            
            if (backtrack(s1, s2, i1 + 1, i2 + len, charToStr, usedStr)) {
                return true;
            }
            
            charToStr.remove(c);
            usedStr.remove(substr);
        }
        
        return false;
    }
}
```

---
