

---

# 20 Java MCQs

---

## Q1

**Question:**  
What is the output of the following code?

```java
class Test {
    public static void main(String[] args) {
        int a = 60;
        int b = 50;
        System.out.println(a & b);
    }
}
```

**Options:**  
a) 0  
b) 1  
c) Compilation fails  
d) None of these

**Answer:** d  
_Explanation: The bitwise AND of 60 and 50 results in 48._

---

## Q2

**Question:**  
What is the output of the following code?

```java
class Test {
    int x;
    public static void main(String[] args) {
        Test t = new Test();
        t.x = 10;
        do {
            System.out.println(t.x);
        } while(1);
    }
}
```

**Options:**  
a) 0  
b) 10  
c) Infinite loop  
d) Compilation fails  
e) None of these

**Answer:** d  
_Explanation: The condition in the `do...while` loop is not a boolean expression, causing a compilation error._

---

## Q3

**Question:**  
What is the output of the following code?

```java
class Test {
    public static void main(String[] args) {
        int x = 1;
        for (int y = 3, x = 2; x < 3; x++) {
            System.out.println(x);
        }
    }
}
```

**Options:**  
a) 1  
b) 2  
c) 3  
d) Compilation fails  
e) None of these

**Answer:** d  
_Explanation: The variable `x` is declared twice (once outside and again in the for-loop initialization), which causes a compilation error._

---

## Q4

**Question:**  
What is the output of the following code?

```java
class Test {
    public static void main(String[] args) {
        int a = 60;
        int b = 50;
        System.out.println((a < b) ? (a & b) : (a | b));
    }
}
```

**Options:**  
a) 60  
b) 50  
c) 48  
d) 62  
e) Compilation fails

**Answer:** d  
_Explanation: Since a (60) is not less than b (50), the expression evaluates to (a | b). The bitwise OR of 60 and 50 is 62._

---

## Q5

**Question:**  
What is the output of the following code snippet?

```java
class Test {
    public static void main(String[] args) {
        int x = 4;
        long y = x * 4 - x++;
        if(y < 10)
            System.out.println("Too Low");    // Line-5
        else 
            System.out.println("Just right");   // Line-6
        else 
            System.out.println("Too High");     // Line-7
    }
}
```

**Options:**  
A. Too Low  
B. Just Right  
C. Too High  
D. Compiles but throws a NullPointerException  
E. The code will not compile because of line 6.  
F. The code will not compile because of line 7.

**Answer:** F  
_Explanation: The code contains two `else` clauses, which is a compile-time error._

---

## Q6

**Question:**  
What is the output of the following code?

```java
class Test { // line-1
    public static void main(String[] args) { // line-2
        int x = 5; // line-3
        System.out.println(x > 2 ? x < 4 ? 10 : 8 : 7); // line-4
    } // line-5
} // line-6
```

**Options:**  
A. 5  
B. 4  
C. 10  
D. 8  
E. 7  
F. The code will not compile because of line 4

**Answer:** D  
_Explanation: The nested ternary operator evaluates as follows: Since `x > 2` (5 > 2) is true, it evaluates the second part: `x < 4 ? 10 : 8`. Because 5 is not less than 4, it returns 8._

---

## Q7

**Question:**  
What is the output of the following code?

```java
class Test {
    public static void main(String[] args) {
        boolean keepGoing = true;
        int result = 15, i = 10;
        do {
            i--;
            if(i == 8) 
                keepGoing = false;
            result -= 2;
        } while(keepGoing);
        System.out.println(result);
    }
}
```

**Options:**  
a) 15  
b) 13  
c) 11  
d) 9  
e) Infinite loop  
f) Compilation fails

**Answer:** c  
_Explanation: The loop runs until i decrements from 10 to 8. The value of result decrements by 2 each time, resulting in 11._

---

## Q8

**Question:**  
What is the output of the following code?

```java
class Test {
    public static void main(String[] args) {
        int count = 0;
        ROW_LOOP: for(int row = 1; row <= 3; row++)
            for(int col = 1; col <= 2; col++) {
                if(row * col % 2 == 0)
                    continue ROW_LOOP;  // Line-6
                count++;
            }
        System.out.println(count);
    }
}
```

**Options:**  
A. 1  
B. 2  
C. 3  
D. 4  
E. 6  
F. The code will not compile because of line 6.

**Answer:** B  
_Explanation: The `continue ROW_LOOP;` statement causes the inner loop to exit early in certain cases, resulting in a final count of 2._

---

## Q9

**Question:**  
What is the output of the following code?

```java
class Test {
    public static void main(String[] args) {
        int count = 5;
        switch(count) {
            default:  
                System.out.println(-1); 
                break;
            case 5:  
                System.out.println(1);    
                continue;
            case 2:  
                System.out.println(2); 
                break;
        }
    }
}
```

**Options:**  
a) -1  
b) 1  
2  
c) 1  
d) Prints 1 infinite times  
e) Compilation fails  
f) None of these

**Answer:** e  
_Explanation: The `continue` statement cannot be used inside a switch block, causing a compilation error._

---

## Q10

**Question:**  
What is the output of the following code?

```java
class Test {
    public static void main(String[] args) {
        int count = 1;
        fs: if(count == 1) {
            continue fs;
            System.out.println(1);
        }
        else if(count == 2)
            System.out.println(2);
        else
            break;
    }
}
```

**Options:**  
a) 1  
b) Prints nothing  
c) Prints 1 infinite times  
d) None of these

**Answer:** d  
_Explanation: The use of `continue` and `break` is illegal outside of loop constructs, so this code will not compile._

---

## Q11

**Question:**  
Given two files:

_File 1 (in package `pkgA`):_

```java
package pkgA;
public class Foo {
    int a = 5;
    protected int b = 6;
    public int c = 7;
}
```

_File 2 (in package `pkgB`):_

```java
package pkgB;
import pkgA.*;
public class Baz {
    public static void main(String[] args) {
        Foo f = new Foo();
        System.out.print(" " + f.a);
        System.out.print(" " + f.b);
        System.out.print(" " + f.c);
    }
}
```

**Options:**  
A. 5 6 7  
B. 5 followed by an exception  
C. Compilation fails with an error on line 7  
D. Compilation fails with an error on line 8  
E. Compilation fails with an error on line 9  
F. Compilation fails with an error on line 10

**Answer:** D and E  
_Explanation: `f.a` is package-private and `f.b` is protected; thus, in a different package they are not accessible._

---

## Q12

**Question:**  
Given that a `Date` class exists in both the `java.util` and `java.sql` packages, what is the result of compiling the following class?

```java
import java.util.*;
import java.sql.*;
public class BirthdayManager {
    private Date rob = new Date();
    private java.util.Date sharon = new java.util.Date();
}
```

**Options:**  
A. The code does not compile because of lines 1 and 2.  
B. The code does not compile because of line 4.  
C. The code does not compile because of line 5.  
D. The code compiles without issue.

**Answer:** B  
_Explanation: The ambiguous import of `Date` causes line 4 to be ambiguous because both `java.util.Date` and `java.sql.Date` are imported._

---

## Q13

**Question:**  
How many of the following methods compile?

```java
public String convert(int value) {
    return value.toString();
}
public String convert(Integer value) {
    return value.toString();
}
public String convert(Object value) {
    return value.toString();
}
```

**Options:**  
A. None  
B. One  
C. Two  
D. Three

**Answer:** C  
_Explanation: The first method does not compile because `int` is a primitive and does not have a `toString()` method. The other two compile._

---

## Q14

**Question:**  
Which of the following does not compile?

```java
A. int num = 999;
B. int num = 9_9_9;
C. int num = _9_99;
D. None of these; these all compile.
```

**Answer:** C  
_Explanation: In Java, numeric literals cannot begin with an underscore._

---

## Q15

**Question:**  
Which is the first line to trigger a compiler error?

```java
double d1 = 5f; // p1
double d2 = 5.0; // p2
float f1 = 5f;   // p3
float f2 = 5.0;  // p4
```

**Options:**  
A. p1  
B. p2  
C. p3  
D. p4

**Answer:** D  
_Explanation: `5.0` is a double literal and cannot be directly assigned to a float without a cast._

---

## Q16

**Question:**  
Of the types `double`, `int`, and `short`, how many could fill in the blank to have this code output 0?

```java
public static void main(String[] args) {
    _______ defaultValue;
    System.out.println(defaultValue);
}
```

**Options:**  
A. None  
B. One  
C. Two  
D. Three

**Answer:** A  
_Explanation: Local variables in Java must be initialized before use; no default value is provided for primitives in this context._

---

## Q17

**Question:**  
What is the output of the following?

```java
Integer integer = new Integer(4);
System.out.print(integer.byteValue());
System.out.print("-");
int i = new Integer(4);
System.out.print(i.byteValue());
```

**Options:**  
A. 4-0  
B. 4-4  
C. The code does not compile.  
D. The code compiles but throws an exception at runtime.

**Answer:** C  
_Explanation: The code does not compile because you cannot assign a new Integer object directly to an int variable without unboxing, but the declaration here is ambiguous._

---

## Q18

**Question:**  
How many of the String objects are eligible for garbage collection right before the end of the main method?

```java
public static void main(String[] fruits) {
    String fruit1 = new String("apple");
    String fruit2 = new String("orange");
    String fruit3 = new String("pear");
    fruit3 = fruit1;
    fruit2 = fruit3;
    fruit1 = fruit2;
}
```

**Options:**  
A. None  
B. One  
C. Two  
D. Three

**Answer:** C  
_Explanation: Two String objects ("orange" and "pear") become eligible for garbage collection because no reference points to them._

---

## Q19

**Question:**  
What does the following code output?

```java
public class InitOrder {
    public String first = "instance";
    public InitOrder() {
        first = "constructor";
    }
    { first = "block"; }
    public void print() {
        System.out.println(first);
    }
    public static void main(String... args) {
        new InitOrder().print();
    }
}
```

**Options:**  
A. block  
B. constructor  
C. instance  
D. The code does not compile.

**Answer:** B  
_Explanation: Instance initializer blocks run before the constructor, but the constructor then sets the value to "constructor"._

---

## Q20

**Question:**  
What is the output of the following?

```java
package beach;
public class Sand {
    public Sand() {
        System.out.print("a");
    }
    public void Sand() {
        System.out.print("b");
    }
    public void run() {
        new Sand();
        Sand();
    }
    public static void main(String... args) {
        new Sand().run();
    }
}
```

**Options:**  
A. a  
B. ab  
C. aab  
D. Compilation fails

**Answer:** C  
_Explanation: The constructor prints "a". The method `Sand()` is not a constructor but a method (it’s never called directly) so calling `new Sand().run()` results in two constructor calls: one in `run()` and one from the call in `main()`, leading to "aab"._

---
