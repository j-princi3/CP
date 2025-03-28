
## Question 1

**How many objects are eligible for garbage collection right before the end of the main method?**

```java
1: public class Person {
2: public Person youngestChild;
3:
4: public static void main(String... args) {
5: Person elena = new Person();
6: Person diana = new Person();
7: elena.youngestChild = diana;
8: diana = null;
9: Person zoe = new Person();
10: elena.youngestChild = zoe;
11: zoe = null;
12: }
13: }
```

A. None  
B. One  
C. Two  
D. Three

**Ans:** B

---

## Question 2

**Fill in the blanks to indicate whether a primitive or wrapper class can be assigned without the compiler using the autoboxing feature.**

```java
_______first = Integer.parseInt("5");  
_______second = Integer.valueOf("5");
```

A. int, int  
B. int, Integer  
C. Integer, int  
D. Integer, Integer

**Ans:** B

---

## Question 3

**Which of the following correctly assigns animal to both variables?**  
I. `String cat = "animal", dog = "animal";`  
II. `String cat = "animal"; dog = "animal";`  
III. `String cat, dog = "animal";`  
IV. `String cat, String dog = "animal";`

A. I  
B. I, II  
C. I, III  
D. I, II, III, IV

**Ans:** A

---

## Question 4

**Which of the following lines contains a compiler error?**

```java
String title = "Weather"; // line x1  
int hot, double cold; // line x2  
System.out.println(hot + " " + title); // line x3
```

A. x1  
B. x2  
C. x3  
D. None of the above

**Ans:** B

---

## Question 5

**What is the result of compiling and executing the following application?**

```java
package forecast;
public class Weather {
private static boolean heatWave = true;
public static void main() {
boolean heatWave = false;
System.out.print(heatWave);
}
}
```

A. true  
B. false  
C. It does not compile.  
D. It compiles but throws an error at runtime.

**Ans:** D

---

## Question 6

**What is the result of compiling and executing the following class?**

```java
package sports;
public class Bicycle {
String color = "red";
private void printColor(String color) {
color = "purple";
System.out.print(color);
}
public static void main(String[] rider) {
new Bicycle().printColor("blue");
}
}
```

A. red  
B. purple  
C. blue  
D. It does not compile.

**Ans:** B

---

## Question 7

**What is the result of compiling and executing the following class?**

```java
public class RollerSkates {
static int wheels = 1;
int tracks = 5;
public static void main(String[] arguments) {
RollerSkates s = new RollerSkates();
int feet=4, tracks = 15;
System.out.print(feet + tracks + s.wheels);
}
}
```

A. The code does not compile.  
B. 5  
C. 10  
D. 20

**Ans:** D

---

## Question 8

**Given the following application, what is the expected output?**

```java
public class Keyboard {
private boolean numLock = true;
static boolean capLock = false;
public static void main(String... shortcuts) {
System.out.print(numLock+" "+capLock);
}
}
```

A. true false  
B. false false  
C. It does not compile.  
D. It compiles but throws an exception at runtime.

**Ans:** C

---

## Question 9

**Given the following class definition, what is the maximum number of import statements that can be discarded and still have the code compile?**  
For this question, assume that the `Broccoli` class is in the `food.vegetables` package, and the `Apple` class is the `food.fruit` package.

```java
package food;
import food.vegetables.*;
import food.fruit.*;
import java.util.Date;
public class Grocery {
Apple a; Broccoli b; Date c;
}
```

A. 0  
B. 1  
C. 2  
D. 3

**Ans:** A

---

## Question 10

**Given the file Magnet.java below, which of the marked lines can you independently insert the line `public String color;` into and still have the code compile?**

```java
// line a1  
public class Magnet {  
// line a2  
public void attach() {  
// line a3  
}  
// line a4  
}
```

A. a1 and a3  
B. a2 and a4  
C. a2, a3, and a4  
D. a1, a2, a3, and a4

**Ans:** B