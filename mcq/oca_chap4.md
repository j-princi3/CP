
## Question 1

Which of the following are primitives?

```java
int[] lowercase = new int[0];
Integer[] uppercase = new Integer[0];
```

**Options:**

- A. Only lowercase
- B. Only uppercase
- C. Bother lowercase and uppercase
- D. Neither lowercase nor uppercase

**Answer:** D

---

## Question 2

Given the following two methods, which method call will not compile?

```java
public void printStormName(String... names) {
    System.out.println(Arrays.toString(names));
}
public void printStormNames(String[] names) {
    System.out.println(Arrays.toString(names));
}
```

**Options:**

- A. printStormName("Arlene");
- B. printStormName(new String[] { "Bret" });
- C. printStormNames("Cindy");
- D. printStormNames(new String[] { "Don" });

**Answer:** C

---

## Question 3

What are the names of the methods to do searching and sorting respectively on arrays? **Options:**

- A. Arrays.binarySearch() and Arrays.linearSort()
- B. Arrays.binarySearch() and Arrays.sort()
- C. Arrays.search() and Arrays.linearSort()
- D. Arrays.search() and Arrays.sort()

**Answer:** B

---

## Question 4

What does this code output?

```java
String[] nums = new String[] { "1", "9", "10" };
Arrays.sort(nums);
System.out.println(Arrays.toString(nums));
```

**Options:**

- A. [1, 9, 10]
- B. [1, 10, 9]
- C. [10, 1, 9]
- D. None of these

**Answer:** B

---

## Question 5

How many of the following are legal declarations?

```java
String lion [] = new String[] {"lion"};
String tiger [] = new String[1] {"tiger"};
String bear [] = new String[] {};
String ohMy [] = new String[0] {};
```

**Options:**

- A. None
- B. One
- C. Two
- D. Three

**Answer:** C

---

## Question 6

How many of the following are legal declarations?

```java
float[] lion = new float[];
float[] tiger = new float[1];
float[] bear = new[] float;
float[] ohMy = new[1] float;
```

**Options:**

- A. None
- B. One
- C. Two
- D. Three

**Answer:** B

---

## Question 7

Which line of code causes an ArrayIndexOutOfBoundsException?

```java
String[][] matrix = new String[1][2];
matrix[0][0] = "Don't think you are, know you are.";       
matrix[0][1] = "I'm trying to free your mind Neo";         
matrix[1][0] = "Is all around you ";                       
// m1
// m2
// m3
matrix[1][1] = "Why oh why didn't I take the BLUE pill?";  // m4
```

**Options:**

- A. m1
- B. m2
- C. m3
- D. m4

**Answer:** C

---

## Question 8

What does the following output?

```java
String[] os = new String[] { "Mac", "Linux", "Windows" };
Arrays.sort(os);
System.out.println(Arrays.binarySearch(os, "Mac"));
```

**Options:**

- A. 0
- B. 1
- C. 2
- D. The output is not defined.

**Answer:** B

---

## Question 9

How many objects are created when running the following code?

```java
Integer[] lotto = new Integer[4];
lotto[0] = new Integer(1_000_000);
lotto[1] = new Integer(999_999);
```

**Options:**

- A. Two
- B. Three
- C. Four
- D. Five

**Answer:** B

---

## Question 10

How many of the following are legal declarations?

```java
[][] String alpha;
[] String beta;
String[][] gamma;
String[] delta[];
String epsilon[][];
```

**Options:**

- A. Two
- B. Three
- C. Four
- D. Five

**Answer:** B

---

## Question 11

What happens when calling the following method with a non-null and non-empty array?

```java
public static void addStationName(String[] names) {
    names[names.length] = "Times Square";
}
```

**Options:**

- A. It adds an element to the array the value of which is Times Square.
- B. It replaces the last element in the array with the value Times Square.
- C. It does not compile.
- D. It throws an exception.

**Answer:** D

---

## Question 12

What is a possible output of the following code?

```java
String[] strings = new String[2];
System.out.println(strings);
```

**Options:**

- A. [null, null]
- B. [,]
- C. [Ljava.lang.String;@74a14482
- D. None of the above

**Answer:** C

---

## Question 13

Which is the first line to prevent this code from compiling and running without error?

```java
char[][] ticTacToe = new char[3][3];                 
ticTacToe[1][3] = 'X';                               
ticTacToe[2][2] = 'X';
ticTacToe[3][1] = 'X';
// r1
// r2
System.out.println(ticTacToe.length + " in a row!"); // r3
```

**Options:**

- A. Line r1
- B. Line r2
- C. Line r3
- D. None of the above

**Answer:** B

---

## Question 14

What is the result of running the following as `java Copier`?

```java
package duplicate;
public class Copier {
    public static void main(String... original) {
        String... copy = original;
        System.out.println(copy.length + " " + copy[0]);
    }
}
```

**Options:**

- A. 0
- B. 0 followed by an exception
- C. 1 followed by an exception
- D. The code does not compile.

**Answer:** D

---

## Question 15

What is the result of running the following program?

```java
1: package fun;  
2: public class Sudoku {  
3:     static int[][] game = new int[6][6];
4:       
5:     public static void main(String[] args) {
6:         game[3][3] = 6;      
7:         Object[] obj = game;         
8:         obj[3] = "X";         
9:         System.out.println(game[3][3]);         
10:    }              
11: }
```

**Options:**

- A. X
- B. The code does not compile.
- C. The code compiles but throws a NullPointerException at runtime.
- D. The code compiles but throws a different exception at runtime.

**Answer:** D

---

## Question 16

What does the following output?

```java
String[] os = new String[] { "Mac", "Linux", "Windows" };
Arrays.sort(os);
System.out.println(Arrays.binarySearch(os, "RedHat"));
```

**Options:**

- A. -1
- B. -2
- C. -3
- D. The output is not defined.

**Answer:** C

---

## Question 17

What is the output of the following when run as `java FirstName Wolfie`?

```java
public class FirstName {
    public static void main(String... names) {
        System.out.println(names[0]);
    }
}
```

**Options:**

- A. FirstName
- B. Wolfie
- C. The code throws an ArrayIndexOutOfBoundsException.
- D. The code throws a NullPointerException.

**Answer:** B

---

## Question 18

Which is the first line to prevent this code from compiling and running without error?

```java
char[][] ticTacToe = new char[3][3];                 
ticTacToe[0][0] = 'X';                               
ticTacToe[1][1] = 'X';
ticTacToe[2][2] = 'X';
// r1
// r2
System.out.println(ticTacToe.length + " in a row!"); // r3
```

**Options:**

- A. Line r1
- B. Line r2
- C. Line r3
- D. None of these

**Answer:** D

---

## Question 19

How many dimensions does the array reference `moreBools` allow?

```java
boolean[][] bools[], moreBools;
```

**Options:**

- A. One dimension
- B. Two dimensions
- C. Three dimensions
- D. None of the above

**Answer:** B

---

## Question 20

What is the result of running the following program?

```java
1: package fun;   
2: public class Sudoku {   
3:     static int[][] game;      
4:    
5:     public static void main(String[] args) {      
6:         game[3][3] = 6;         
7:         Object[] obj = game;         
8:         game[3][3] = "X";         
9:         System.out.println(game[3][3]);         
10:    }     
11: }
```

**Options:**

- A. X
- B. The code does not compile.
- C. The code compiles but throws a NullPointerException at runtime.
- D. The code compiles but throws a different exception at runtime.

**Answer:** B

---

## Question 21

What is the output of the following when run as `java Count "1 2"`?

```java
public class Count {
    public static void main(String target[]) {
        System.out.println(target.length);
    }
}
```

**Options:**

- A. 0
- B. 1
- C. 2
- D. The code does not compile.

**Answer:** B

---

## Question 22

Which of the following statements are true? I. You can always change a method signature from `call(String[] arg)` to `call(String... arg)` without causing a compiler error in the calling code.  
II. You can always change a method signature from `call(String... arg)` to `call(String[] arg)` without causing a compiler error in the existing code.

**Options:**

- A. I
- B. II
- C. Both I and II
- D. Neither I nor II

**Answer:** A

---

## Question 23

Which of these four array references can point to an array that is different from the others? **Options:**

- A. `int[][][][] nums1a, nums1b;`
- B. `int[][][] nums2a[], nums2b;`
- C. `int[][] nums3a[][], nums3b[][];`
- D. `int[] nums4a[][][], numbs4b[][][];`

**Answer:** B

---

## Question 24

What is the output of the following when run as `java unix.EchoFirst seed flower`?

```java
package unix;
import java.util.*;
public class EchoFirst {
    public static void main(String[] args) {
        Arrays.sort(args);
        String result = Arrays.binarySearch(args, args[0]);
        System.out.println(result);
    }
}
```

**Options:**

- A. 0
- B. 1
- C. The code does not compile.
- D. The code compiles but throws an exception at runtime.

**Answer:** C

---

## Question 25

What is the output of the following application?

```java
package beach;
import java.util.function.*;
class Tourist {
    public Tourist(double distance) {
        this.distance = distance;
    }
    public double distance;
}
public class Lifeguard {
    private void saveLife(Predicate<Tourist> canSave, Tourist tourist) {
        System.out.print(canSave.test(tourist) ? "Saved" : "Too far");  // y1
    }
    public final static void main(String... sand) {
        new Lifeguard().saveLife(s -> s.distance < 4, new Tourist(2));  // y2
    }
}
```

**Options:**

- A. Saved
- B. Too far
- C. The code does not compile because of line y1.
- D. The code does not compile because of line y2.

**Answer:** A

---

## Question 26

Which of the following is not a functional interface in the `java.util.function` package? **Options:**

- A. BiPredicate
- B. DoubleUnaryOperator
- C. ObjectDoubleConsumer
- D. ToLongFunction

**Answer:** C

---

## Question 27

Which of the following three functional interfaces is not equivalent to the other two? **Options:**

- A. BiFunction<Double, Double, Double>
- B. BinaryOperator
- C. DoubleFunction
- D. None of these. All three are equivalent.

**Answer:** C

---

## Question 28

Given the code fragments:

**Person.java:**

```java
public class Person {
    String name;
    int age;
    public Person(String n, int a) {
        name = n;
        age = a;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
}
```

**Test.java:**

```java
public static void checkAge(List<Person> list, Predicate<Person> predicate) {
    for (Person p: list) {
        if (predicate.test(p)) {
            System.out.println(p.name + " ");
        }
    }
}

public static void main(String[] args) {
    List<Person> iList = Arrays.asList(
        new Person("Hank", 45),
        new Person("Charlie", 40),
        new Person("Smith", 38)
    );
}
// line n1
```

Which code fragment, when inserted at line n1, enables the code to print Hank?

**Options:**

- A. `checkAge(iList, ( ) -> p.getAge() > 40);`
- B. `checkAge(iList, Person p -> p.getAge() > 40);`
- C. `checkAge(iList, p -> p.getAge() > 40);`
- D. `checkAge(iList, (Person p) -> { p.getAge() > 40; });`

**Answer:** C

---

## Question 29

Given:

```java
class Vehicle {
    int x;
    Vehicle() {
        this(10); // line n1
    }
    Vehicle(int x) {
        this.x = x;
    }
}
class Car extends Vehicle {
    int y;
    Car() {
        this(20); // line n2
    }
    Car(int y) {
        this.y = y;
    }
    public String toString() {
        return super.x + ":" + this.y;
    }
}
```

And given the code fragment:

```java
Vehicle y = new Car();
System.out.println(y);
```

What is the result?

**Options:**

- A. 10:20
- B. 0:20
- C. Compilation fails at line n1
- D. Compilation fails at line n2

**Answer:** A

---

## Question 30

Which of the following is correct about Java 8 lambda expression? **Options:**

- A. Lambda expressions are used primarily to define inline implementation of a functional interface.
- B. Lambda expression eliminates the need of anonymous class and gives a very simple yet powerful functional programming capability to Java.
- C. Both of these.
- D. None of these.

**Answer:** C

---

## Question 31

Which of the following is the correct lambda expression which adds two numbers and returns their sum? (Choose all that apply) **Options:**

- A. `(int a, int b) -> { return a + b; };`
- B. `(a, b) -> { return a + b; };`
- C. `a, b -> { return a + b; };`
- D. A, B, C are correct
- E. None of the above.

**Answer:** A, B

---

## Question 32

Choose all that apply:

```java
class Test {
    int x = 10;
    Test()  { System.out.print(x + " "); }
    private Test(int x)  { 
        this.x = x;                                       // Line-5 
        System.out.print(x + " ");   
    }
    public static void main(String[] args) {
        Test t = new Test(10);                    // line-9
        t.x = 20;                                 // line-10
        System.out.println(this.x);               // line-11
    }
}
```

**Options:**

- a) 10
- b) 20
- c) compilation fails at Line-5
- d) compilation fails at Line-10
- e) compilation fails at Line-11
- f) none of these

**Answer:** E

---

## Question 33

```java
class Test {
    final int x;  
    Test() {       
        x = 10;
        System.out.print(x + " ");
    }
    Test(int y) {  
        x = 20;
        System.out.print(x + " ");
    }
   
    public static void main(String[] args) {
        Test t = new Test(30);
    }
}
```

**Options:**

- a) 0
- b) 10
- c) 20
- d) 30
- e) compilation fails
- f) none of these

**Answer:** C

---

## Question 34

What is the result of the following code? (Choose all that apply)

```java
StringBuilder numbers = new StringBuilder("0123456789");
numbers.delete(2, 8);
numbers.append("-").insert(2, "+");
System.out.println(numbers);
```

**Options:**

- A. 01+89–
- B. 012+9–
- C. 012+–9
- D. 0123456789
- E. An exception is thrown.
- F. The code does not compile.

**Answer:** A

---

## Question 35

Which of the following are true? (Choose all that apply) **Options:**

- A. An array has a fixed size.
- B. An ArrayList has a fixed size.
- C. An array allows multiple dimensions.
- D. An array is ordered.
- E. An ArrayList is ordered.
- F. An array is immutable.
- G. An ArrayList is immutable.

**Answer:** A, C, D, E

---

## Question 36

What is the result of the following?

```java
4: List<Integer> list = Arrays.asList(10, 4, -1, 5);
5: Collections.sort(list);
6: Integer array[] = list.toArray(new Integer[4]);
7: System.out.println(array[0]);
```

**Options:**

- A. –1
- B. 10
- C. Compiler error on line 4.
- D. Compiler error on line 5.
- E. Compiler error on line 6.
- F. An exception is thrown.

**Answer:** A

---

## Question 37

What is the result of the following?

```java
import java.time.*;
import java.util.*;
class Test {
    public static void main(String[] args) {
        List<String> hex = Arrays.asList("30", "8", "3A", "FF");
        Collections.sort(hex);
        int x = Collections.binarySearch(hex, "8");
        int y = Collections.binarySearch(hex, "3A");
        int z = Collections.binarySearch(hex, "4F");
        System.out.println(x + " " + y + " " + z);
    }
}
```

**Options:**

- A. 0 1 –2
- B. 0 1 –3
- C. 2 1 –2
- D. 2 1 –3
- E. None of the above.
- F. The code doesn’t compile.

**Answer:** D

---

## Question 38

```java
class A {
    int x = 10;
    A() {
        this(20);
    }
    A(int x) {
        System.out.println(x); 
    }
}
class Test {
    public static void main(String[] args) {
        A a = new A(30);
    }
}
```

**Options:**

- a) 10
- b) 20
- c) 30
- d) compilation fails
- e) none of these

**Answer:** C

---

## Question 39

Given:

```java
public class StringManipulator {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("hello");
        String s = "world";
        sb.append(" ").append(s.toUpperCase());
        s = s.replace('o', '0');
        System.out.println("[" + sb + "]");
    }
}
```

Which two substrings will be included in the result?

**Options:**

- A. [hello world]
- B. [hello WORLD]
- C. [hello w0rld]
- D. [hello world0]
- E. [hello w0rLD]

**Answer:** B

---

## Question 40

```java
interface I {
    void m1();    // Line-2
}
class A implements I {   // Line-4
    void m1() { System.out.println(1); }  // Line-5
}
class B extends A {                                           
    public void m1() { System.out.println(2); }   // Line-8
    public static void main(String[] args) {
        A a = new A();                                          
        a.m1();  // Line-11
    }
}
```

**Options:**

- a) 1
- b) 2
- c) compilation fails at Line-2
- d) compilation fails at Line-4
- e) compilation fails at Line-5
- f) compilation fails at Line-8
- g) compilation fails at Line-11

**Answer:** E

---

## Question 41

Suppose we have a class named Test. Which of the following statements are true? (Choose all that apply)

```java
1: public class Test {
2:     public static void main(String[] args) {
3:         Test one = new Test();
4:         Test two = new Test();
5:         Test three = one;
6:         one = null;
7:         Test four = one;
8:         three = null;
9:         two = null;
10:        two = new Test();
11:        System.gc();
12:     }
13: }
```

**Options:**

- A. The Test object from line 3 is first eligible for garbage collection immediately following line 6.
- B. The Test object from line 3 is first eligible for garbage collection immediately following line 8.
- C. The Test object from line 3 is first eligible for garbage collection immediately following line 12.
- D. The Test object from line 4 is first eligible for garbage collection immediately following line 9.
- E. The Test object from line 4 is first eligible for garbage collection immediately following line 11.
- F. The Test object from line 4 is first eligible for garbage collection immediately following line 12.

**Answer:** B, D

---

## Question 42

```java
class Test {
    public static void main(String [] args) {
        int a = 10;
        if (++a = 11)
            System.out.println(a);
        else
            ++a;
        System.out.println(a);
    }
}
```

**Options:**

- a) 10
- b) 11
- c) 12
- d) Compilation fails
- e) Run time exception

**Answer:** D

---

## Question 43

What is the output of the following code snippet?

```java
3: int x1 = 50, x2 = 75;
4: boolean b = x1 >= x2;
5: if (b = true) System.out.println("Success");
6: else System.out.println("Failure");
```

**Options:**

- A. Success
- B. Failure
- C. The code will not compile because of line 4.
- D. The code will not compile because of line 5.

**Answer:** A

---

## Question 44

What is the output of the following code snippet?

```java
3: int count = 0;
4: ROW_LOOP: for(int row = 1; row <= 3; row++)
5:     for(int col = 1; col <= 2; col++) {
6:         if (row * col % 2 == 0) continue ROW_LOOP;
7:         count++;
8:     }
9: System.out.println(count);
```

**Options:**

- A. 1
- B. 2
- C. 3
- D. 4
- E. 6
- F. The code will not compile because of line 6.

**Answer:** B

---

## Question 45

What is the correct syntax of a lambda expression for a `Predicate<String>` that checks if a string is empty? **Options:**

- A) `Predicate<String> p = s -> s.isEmpty();`
- B) `Predicate<String> p = (s) -> { return s.isEmpty(); }`
- C) `Predicate<String> p = (String s) -> s.isEmpty();`
- D) All of these

**Answer:** D

---

## Question 46

Which statement is true about `Predicate<T>`? **Options:**

- A) It takes an argument of type T and returns a boolean
- B) It can have multiple abstract methods
- C) It is available from Java 7 onwards
- D) It does not belong to `java.util.function` package

**Answer:** A

---

## Question 47

What will be the output of the following code?

```java
import java.util.function.Predicate;

public class Main {
    public static void main(String[] args) {
        Predicate<String> startsWithA = str -> str.startsWith("A");
        Predicate<String> endsWithX = str -> str.endsWith("X");

        Predicate<String> combined = startsWithA.and(endsWithX);

        System.out.println(combined.test("AppleX"));
    }
}
```

**Options:**

- A) true
- B) false
- C) Compilation error
- D) Runtime exception

**Answer:** A

---

## Question 48

Which of the following is NOT a valid lambda expression? **Options:**

- A) `(x, y) -> x + y`
- B) `(String s) -> { return s.length(); }`
- C) `() -> System.out.println("Hello");`
- D) `int x -> x * 2;`

**Answer:** D

---

## Question 49

What is the functional method of the `Predicate<T>` interface? **Options:**

- A) `apply(T t)`
- B) `accept(T t)`
- C) `test(T t)`
- D) `evaluate(T t)`

**Answer:** C

---

## Question 50

What will be the output of the following code?

```java
import java.util.function.Predicate;

public class Test {
    public static void main(String[] args) {
        Predicate<String> isEmpty = String::isEmpty;
        System.out.println(isEmpty.test(""));
    }
}
```

**Options:**

- A) true
- B) false
- C) Compilation error
- D) Runtime exception

**Answer:** A
