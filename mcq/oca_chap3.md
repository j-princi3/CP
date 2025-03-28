

---

## Q1

**Question:**  
What will be the output of below statements?

```java
String s1 = "abc";
String s2 = "def";
System.out.println(s1.compareTo(s2));
```

**Options:**  
A. 0  
B. true  
C. -3  
D. false

**Answer:** C

---

## Q2

**Question:**  
What will be the output of below code snippet?

```java
String s1 = "abc";
String s2 = new String("abc");
s2.intern();
System.out.println(s1 == s2);
```

**Options:**  
A. false  
B. true  
C. null

**Answer:** A

---

## Q3

**Question:**  
What will be the output of below code snippet?

```java
StringBuffer sb = new StringBuffer("11111");
System.out.println(sb.insert(3, false).insert(5, 3.3).insert(7, "One"));
```

**Answer:**  
`111fa3.One3lse11`

---

## Q4

**Question:**  
Given:

```java
public class Mutant {
	public static void main(String[] args){
		StringBuilder sb = new StringBuilder("abc");
		String s = "abc";
		sb.reverse().append("d");
		s.toUpperCase().concat("d");
		System.out.println("." + sb +  ".");
	}
}
```

Which two substrings will be included in the result?

**Options:**  
A. .abc.  
B. .ABCd.  
C. .ABCD.  
D. .cbad.  
E. .dcfa.

**Answer:** D

---

## Q5

**Question:**  
Which are the results of the following code? (Choose all that apply)

```java
String numbers = "012345678";
System.out.println(numbers.substring(1, 3));
System.out.println(numbers.substring(7, 7));
System.out.println(numbers.substring(7));
```

**Options:**  
A. 12  
B. 123  
C. 7  
D. 78  
E. A blank line.  
F. An exception is thrown.  
G. The code does not compile.

**Answer:** A, D, E

---

## Q6

**Question:**  
Given the following class definition, what is the maximum number of import statements that can be discarded and still have the code compile? (Assume that the `Blackhole` class is defined only in the `stars` package.)

```java
package planetarium;
import java.lang.*;
import stars.*;
import java.lang.Object;
import stars.Blackhole;

public class Observer {
	public void find(Blackhole blackhole) {}
}
```

**Options:**  
A. Zero  
B. One  
C. Two  
D. Three

**Answer:** D

---

## Q7

**Question:**  
Which statement about the JVM is true?

**Options:**  
A. The JVM schedules garbage collection on a predictable schedule.  
B. The JVM ensures that the application will always terminate.  
C. The JVM requires a properly defined entry point method to execute the application.  
D. A Java compiled code can be run on any computer.

**Answer:** C

---

## Q8

**Question:**

```java
import java.util.Date;
class Test {
	public static void main(String [] args) {
		Date date = null;
		if (date == null)
			System.out.println("date is null");
	}
}
```

**Options:**  
a) date is null  
b) no output  
c) compilation fails  
d) null pointer exception

**Answer:** A

---

## Q9

**Question:**

```java
import java.time.*;
class Test {
	public static void main(String[] args) {
	  LocalDate d = LocalDate.of(2017, Month.JANUARY, 5);
	  d = d.plusDays(2);
	  LocalDate d1 = LocalDate.of(2017, Month.JANUARY, 5);
  	  d1 = d1.plusDays(2);
	  if(d == d1)
		  System.out.println(1);
	  else if(d.equals(d1))
		  System.out.println(2);
	  else
   			System.out.println(3);
	}
}
```

**Options:**  
a) 1  
b) 2  
c) 3  
d) compilation fails  
e) run time exception  
f) none of these

**Answer:** B

---

## Q10

**Question:**

```java
import java.time.*;
class Test {
	public static void main(String[] args) {
	  LocalDate d = LocalDate.of(2017, Month.JANUARY, 5);
	  d.plusDays(2).plusMonths(5).minusDays(1);
	  System.out.println(d);
	}
}
```

**Options:**  
a) 2017-06-06  
b) 2017-01-05  
c) 2017-05-06  
d) 2017-06-05  
e) 2017-01-07  
f) 2017-05-06  
g) compilation fails

**Answer:** B

---

## Q11

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

---

## Q12

**Question:**

```java
import java.time.*;
class Test {
	public static void main(String[] args) {
	  LocalDate d = LocalDate.of(2017, Month.JANUARY, 5);
	  d.plusDays(2);
	  LocalDate d1 = LocalDate.of(2017, Month.JANUARY, 5);
  	  d1 = d1.plusDays(2);
	  if(d == d1)
		  System.out.println(1);
	  else if(d.equals(d1))
		  System.out.println(2);
	  else
   			System.out.println(3);
	}
}
```

**Options:**  
a) 1  
b) 2  
c) 3  
d) compilation fails  
e) run time exception  
f) none of these

**Answer:** C

---

## Q13

**Question:**

```java
import java.time.*;
class Test{
	public static void main(String[] args){
      	LocalDate s = LocalDate.of(2017, Month.JANUARY, 1);
       	Period period = Period.ofWeeks(1);
       	Period period1 = Period.ofDays(2);
	  	LocalDate d = s.plus(period).minus(period1);
		System.out.println(d);
	}
}
```

**Options:**  
a) 2017-01-08  
b) 2017-02-07  
c) 2017-01-06  
d) 2017-01-07  
e) compilation fails  
f) none of these

**Answer:** C

---

## Q14

**Question:**

```java
class Test {
    public static void main(String args[]) {
	    int arr[] = new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	    int n = 6;
        n = arr[arr[n] / 2];
	    System.out.println(arr[n] / 2);
    } 
}
```

**Options:**  
a) 3  
b) 0  
c) 6  
d) 1

**Answer:** D

---

## Q15

**Question:**  
What is the result of the following code?

```java
int total = 0;
StringBuilder letters = new StringBuilder("abcdefg");
total += letters.substring(1, 2).length();
total += letters.substring(6, 6).length();
total += letters.substring(6, 5).length();
System.out.println(total);
```

**Options:**  
A. 1  
B. 2  
C. 3  
D. 7  
E. An exception is thrown.  
F. The code does not compile.

**Answer:** E

---

## Q16

**Question:**  
What is the result of the following code? (Choose all that apply)

```java
StringBuilder numbers = new StringBuilder("0123456789");
numbers.delete(2, 8);
numbers.append("-").insert(2, "+");
System.out.println(numbers);
```

**Options:**  
A. 01+89–  
B. 012+9–  
C. 012+–9  
D. 0123456789  
E. An exception is thrown.  
F. The code does not compile.

**Answer:** A

---

## Q17

**Question:**  
Which of these array declarations is not legal? (Choose all that apply)

**Options:**  
A. `int[][] scores = new int[5][];`  
B. `Object[][][] cubbies = new Object[3][0][5];`  
C. `String beans[] = new beans[6];`  
D. `java.util.Date[] dates[] = new java.util.Date[2][];`  
E. `int[][] types = new int[];`  
F. `int[][] java = new int[][];`

**Answer:** C, E, F

---

## Q18

**Question:**  
What is the result of the following?

```java
int[] random = { 6, -4, 12, 0, -10 };
int a = 12;
int b = Arrays.binarySearch(random, a);
System.out.println(b);
```

**Options:**  
A. 2  
B. 4  
C. 6  
D. The result is undefined.  
E. An exception is thrown.  
F. The code does not compile.

**Answer:** D

---

## Q19

**Question:**  
What is the result of the following?

```java
String[] names = {"Tom", "Dick", "Harry"};
List<String> list = names.asList();
list.set(0, "Sue");
System.out.println(names[0]);
```

**Options:**  
A. Sue  
B. Tom  
C. Compiler error on line 7.  
D. Compiler error on line 8.  
E. An exception is thrown.

**Answer:** C

---

## Q20

**Question:**  
Given:

```java
public class Dims {
    public static void main(String[] args) {
        int[][] a = { {1,2}, {3,4} };
        int[] b = (int[]) a[1];
        Object o1 = a;
        int[][] a2 = (int[][]) o1;
        int[] b2 = (int[]) o1;
        System.out.println(b[1]);
    }
}
```

What is the result? (Choose all that apply.)

**Options:**  
A. 2  
B. 4  
C. An exception is thrown at runtime  
D. Compilation fails due to an error on line 4  
E. Compilation fails due to an error on line 5  
F. Compilation fails due to an error on line 6  
G. Compilation fails due to an error on line 7

**Answer:** C

---

## Q21

**Question:**  
What is the value of `thatNumber` after the execution of the following code snippet?

```java
long thatNumber = 5 >= 5 ? 1+2 : 1*1;
if(++thatNumber < 4)
    thatNumber += 1;
```

**Options:**  
A. 3  
B. 4  
C. 5  
D. The answer cannot be determined until runtime.

**Answer:** B

---

## Q22

**Question:**  
Given:

```java
class Dozens {
  int[] dz = {1,2,3,4,5,6,7,8,9,10,11,12};
}
public class Eggs {
  public static void main(String args[]){
     Dozens[] da = new Dozens[3];
     da[0] = new Dozens();
     Dozens d = new Dozens();
     da[1] = d;
     d = null;
     da[1] = null;
     //do stuff
  }
}
```

Which two are true about the objects created within `main()`, and which are eligible for garbage collection when line 14 is reached?

**Options:**  
A. Three objects were created  
B. Four objects were created  
C. Five objects were created  
D. Zero objects are eligible for GC  
E. One object is eligible for GC  
F. Two objects are eligible for GC  
G. Three objects are eligible for GC

**Answer:** C and F

---

## Q23

**Question:**  
Given:

```java
public class Tailor {
	public static void main(String args[]){
		byte[][] ba = { {1,2,3,4}, {1,2} };
		System.out.println(ba[1].length + " " + ba.length);
	}
}
```

What is the result?

**Options:**  
A. 2 4  
B. 2 7  
C. 3 2  
D. 3 7  
E. 4 2  
F. 4 7  
G. Compilation fails

**Answer:** C

---

## Q24

**Question:**  
Which of the following types is `taxis` not allowed to be in order for this code to compile?

```java
for (Object obj : taxis) {
    //...
}
```

**Options:**  
A. ArrayList  
B. int[]  
C. StringBuilder  
D. All of these are allowed.

**Answer:** C

---

## Q25

**Question:**  
Which of the following can be inserted into the blank to create a date of June 21, 2014? (Choose all that apply)

```java
import java.time.*;
public class StartOfSummer {
  public static void main(String[] args) {
      LocalDate date = ____________________________;
  }
}
```

**Options:**  
A. new LocalDate(2014, 5, 21);  
B. new LocalDate(2014, 6, 21);  
C. LocalDate.of(2014, 5, 21);  
D. LocalDate.of(2014, 6, 21);  
E. LocalDate.of(2014, Calendar.JUNE, 21);  
F. LocalDate.of(2014, Month.JUNE, 21);

**Answer:** D, F

---

## Q26

**Question:**  
What is the output of the following code?

```java
LocalDate date = LocalDate.parse("2018-04-30", DateTimeFormatter.ISO_LOCAL_DATE);
date.plusDays(2);
date.plusHours(3);
System.out.println(date.getYear() + " " + date.getMonth() + " " + date.getDayOfMonth());
```

**Options:**  
A. 2018 APRIL 2  
B. 2018 APRIL 30  
C. 2018 MAY 2  
D. The code does not compile.  
E. A runtime exception is thrown.

**Answer:** D

---

## Q27

**Question:**  
What is the output of the following code?

```java
LocalDate date = LocalDate.of(2018, Month.APRIL, 40);
System.out.println(date.getYear() + " " + date.getMonth() + " " + date.getDayOfMonth());
```

**Options:**  
A. 2018 APRIL 4  
B. 2018 APRIL 30  
C. 2018 MAY 10  
D. Another date.  
E. The code does not compile.  
F. A runtime exception is thrown.

**Answer:** F

---

## Q28

**Question:**  
What is the output of the following code?

```java
LocalDate date = LocalDate.of(2018, Month.APRIL, 30);
date.plusDays(2);
date.plusYears(3);
System.out.println(date.getYear() + " " + date.getMonth() + " " + date.getDayOfMonth());
```

**Options:**  
A. 2018 APRIL 2  
B. 2018 APRIL 30  
C. 2018 MAY 2  
D. 2021 APRIL 2  
E. 2021 APRIL 30  
F. 2021 MAY 2  
G. A runtime exception is thrown.

**Answer:** B

---

## Q29

**Question:**  
What is the output of the following code?

```java
LocalDateTime d = LocalDateTime.of(2015, 5, 10, 11, 22, 33);
Period p = Period.of(1, 2, 3);
d = d.minus(p);
DateTimeFormatter f = DateTimeFormatter.ofLocalizedTime(FormatStyle.SHORT);
System.out.println(d.format(f));
```

**Options:**  
A. 3/7/14 11:22 AM  
B. 5/10/15 11:22 AM  
C. 3/7/14  
D. 5/10/15  
E. 11:22 AM  
F. The code does not compile.  
G. A runtime exception is thrown.

**Answer:** E

---

## Q30

**Question:**  
What is the output of the following code?

```java
LocalDateTime d = LocalDateTime.of(2015, 5, 10, 11, 22, 33);
Period p = Period.ofDays(1).ofYears(2);
d = d.minus(p);
DateTimeFormatter f = DateTimeFormatter.ofLocalizedDateTime(FormatStyle.SHORT);
System.out.println(f.format(d));
```

**Options:**  
A. 5/9/13 11:22 AM  
B. 5/10/13 11:22 AM  
C. 5/9/14  
D. 5/10/14  
E. The code does not compile.  
F. A runtime exception is thrown.

**Answer:** B

---

## Q31

**Question:**  
What is the result of the following?

```java
LocalDate xmas = LocalDate.of(2016, 12, 25);
xmas.setYear(2017);
System.out.println(xmas.getYear());
```

**Options:**  
A. 2016  
B. 2017  
C. The code does not compile.  
D. The code compiles but throws an exception at runtime.

**Answer:** C

---

## Q32

**Question:**

```java
import java.time.*;
public class Bachelor {
	public static void main(String[] args) {
		LocalDate d = LocalDate.of(2018, 8, 15);
		d = d.plusDays(1);
		LocalDate d2 = d.plusDays(1);
		LocalDate d3 = d2;
		d2 = d2.plusDays(1);
		System.out.println(d + " " + d2 + " " + d3); //Line X
	}
}
```

Which are true? (Choose all that apply.)

**Options:**  
A. The output is: 2018-08-16 2018-08-17 2018-08-18  
B. The output is: 2018-08-16 2018-08-18 2018-08-17  
C. The output is: 2018-08-16 2018-08-17 2018-08-17  
D. At line X, zero LocalDate objects are eligible for garbage collection  
E. At line X, one LocalDate object is eligible for garbage collection  
F. At line X, two LocalDate objects are eligible for garbage collection  
G. Compilation fails

**Answer:** B and E

---

## Q33

**Question:**  
What is the output of the following application?

```java
package voting;
public class Election {
    public void calculateResult(Integer candidateA, Integer candidateB) {
        boolean process = candidateA == null || candidateA.intValue() < 10;
        boolean value = candidateA && candidateB;
        System.out.print(process || value);
    }
    public static void main(String[] unused) {
        new Election().calculateResult(null, 203);
    }
}
```

**Options:**  
A. true  
B. false  
C. The code does not compile.  
D. The code compiles but throws a NullPointerException on line 3 at runtime.

**Answer:** C

---

## Q34

**Question:**  
What is the output of the following?

```java
public class Shoelaces {
    public static void main(String[] args) {
        String tie = null;
        while (tie == null)
            tie = "shoelace";
        System.out.print(tie);
    }
}
```

**Options:**  
A. null  
B. shoelace  
C. shoelaceshoelace  
D. None of these

**Answer:** B

---

## Q35

**Question:**  
What is the result of the following?

```java
int count = 10;
List<Character> chars = new ArrayList<>();
do {
	chars.add('a');
	for (Character x : chars)
	    count -= 1;
} while (count > 0);
System.out.println(chars.size());
```

**Options:**  
A. 3  
B. 4  
C. The code does not compile.  
D. None of these

**Answer:** B

---

## Q36

**Question:**  
What is the result of the following code?

```java
do {
    int count = 0;
    do {
        count++;
    } while (count < 2);
    break;
} while (true);
System.out.println(count);
```

**Options:**  
A. 2  
B. 3  
C. The code does not compile.  
D. This is an infinite loop.

**Answer:** C

---

## Q37

**Question:**  
Which of the following can replace line 4 to print "avaJ"? (Choose all that apply.)

```java
3: StringBuilder puzzle = new StringBuilder("Java");
// INSERT CODE HERE
5: System.out.println(puzzle);
```

**Options:**  
A. `puzzle.reverse();`  
B. `puzzle.append("vaJ$").substring(0, 4);`  
C. `puzzle.append("vaJ$").delete(0, 3).deleteCharAt(puzzle.length() - 1);`  
D. `puzzle.append("vaJ$").delete(0, 3).deleteCharAt(puzzle.length());`  
E. None of the above.

**Answer:** A, C

---

## Q38

**Question:**  
What change would allow the following code snippet to compile? (Choose all that apply.)

```java
3: long x = 10;
4: int y = 2 * x;
```

**Options:**  
A. No change; it compiles as is.  
B. Cast x on line 4 to int.  
C. Change the data type of x on line 3 to short.  
D. Cast 2 * x on line 4 to int.  
E. Change the data type of y on line 4 to short.  
F. Change the data type of y on line 4 to long.

**Answer:** B, C, D, F

---

## Q39

**Question:**  
What is the output of the following code snippet?

```java
3: boolean x = true, z = true;
4: int y = 20;
5: x = (y != 10) ^ (z = false);
6: System.out.println(x + ", " + y + ", " + z);
```

**Options:**  
A. true, 10, true  
B. true, 20, false  
C. false, 20, true  
D. false, 20, false  
E. false, 20, true  
F. The code will not compile because of line 5.

**Answer:** B

---

## Q40

**Question:**  
What is the output of the following code snippet?

```java
import java.util.*;
class Test {
  public static void main(String args[]) {
    List list = new ArrayList();
    list.add("kmit");
    list.add("ngit");
    list.add("cbit");
    list.add("kmit");
    list.add("cbit");
    System.out.println(list.remove(list.get(2)));
  }
}
```

**Options:**  
a) cbit  
b) ngit  
c) two cbit will removed from list  
d) compilation fails  
e) none of these

**Answer:** E

---

## Q41

**Question:**  
What is the output of the following code? (Choose all that apply.)

```java
import java.util.*;
class Test {
    public static void main(String[] args) {
        List<Integer> ages = new ArrayList<>();
        ages.add(Integer.parseInt("5"));
        ages.add(Integer.valueOf("6"));
        ages.add(7);
        ages.add(null);
        for (int age : ages)
            System.out.print(age);
    }
}
```

**Options:**  
a) The code compiles.  
b) The code throws a runtime exception.  
c) Exactly one of the add statements uses autoboxing.  
d) Exactly two of the add statements use autoboxing.  
e) Exactly three of the add statements use autoboxing.

**Answer:** A, B, C

---

## Q42

**Question:**  
Which are the results of the following code? (Choose all that apply.)

```java
class Test {
	public static void main(String[] args) {
		String numbers = "012345678";
		System.out.println(numbers.substring(1, 3));
		System.out.println(numbers.substring(7, 7));
		System.out.println(numbers.substring(7));
	} 
}
```

**Options:**  
a) 12  
b) 123  
c) 7  
d) 78  
e) A blank line.  
f) An exception is thrown.  
g) The code does not compile.

**Answer:** A, D, E

---

## Q43

**Question:**  
What is the output of the following code snippet?

```java
class Test {
    public static void main(String[] args) {
		StringBuilder s1 = new StringBuilder();
  		System.out.println(s1.length() + " " + s1.capacity());
	}
}
```

**Options:**  
a) 0 16  
b) null 16  
c) null null  
d) compilation fails  
e) Null pointer exception

**Answer:** A

---

## Q44

**Question:**

```java
// What is the output of the following code?
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
e) infinite loop  
f) compilation fails

**Answer:** C

---

## Q45

**Question:**

```java
// What is the output of the following code?
class Test {
    public static void main(String[] args) {
	    for(int i = 0; i < 10; ) {  // Line -3
		    i = i++;
		    System.out.println(i);
	    }
    }
}
```

**Options:**  
a) 1  
b) 9  
c) 10  
d) compilation fails  
e) none of these

**Answer:** E

---

## Q46

**Question:**

```java
public class Test {
  public static void main(String args[]){
    String s = "fs";
    String s1 = new String("fs");
    StringBuilder sb = new StringBuilder("fs");
    System.out.print(s.equals(s1) + "," + s1.equals(sb) + "," + s.equals(sb));
  }
}
```

**Options:**  
a) true, true, true  
b) true, true, false  
c) true, false, false  
d) false, false, false  
e) false, false, true  
f) false, true, true

**Answer:** C

---

## Q47

**Question:**

```java
class Emp {
	int empno = 20; 
}
class Test {
	static int a = 3;
	public static void main(String[] args) {
		Emp e = new Emp();
		Test t = new Test();
		t.m1(e, a);
		System.out.println(e.empno);
		System.out.println(a);
	}	
	void m1(Emp e, int a) {
     		e.empno = 100;
     		a = 50;
	}
}
```

**Options:**  
a)

```
20
3
```

b)

```
20 
50
```

c)

```
100
3
```

d)

```
100
50
```

**Answer:** C

---

## Q48

**Question:**

```java
class A {
   static int num = 10;
   public static void main(String[] args) {
     new A().m1(num);
     System.out.print(" " + num);
   }
 
   void m1(int num) {
     num++;
     for(int num = 3; num < 6; num++)
          System.out.print(" " + num);
   }
}
```

**Options:**  
a) 5 7  
b) 5 8  
c) 8 7  
d) 8 8  
e) Compilation fails  
f) An exception is thrown at runtime

**Answer:** E

---

## Q49

**Question:**  
Given:

```java
String stuff = "TV";
String res = null;

if(stuff.equals("TV")){
	res = "Walter";
} else if(stuff.equals("Movie")){
	res = "White";
} else {
	res = "No Result";
}
```

Which code fragment can replace the if block?

**Options:**  
A. `stuff.equals("TV") ? res= "Walter" : stuff.equals("Movie") ? res = "White" : res = "No Result";`  
B. `res = stuff.equals("TV") ? "Walter" else stuff.equals("Movie") ? "White" : "No Result";`  
C. `res = stuff.equals("TV") ? stuff.equals("Movie") ? "Walter" : "White" : "No Result";`  
D. `res = stuff.equals("TV") ? "Walter" : stuff.equals("Movie") ? "White" : "No Result";`

**Answer:** B

---

## Q50

**Question:**  
Given the code fragment:

```java
7. StringBuilder sb1 = new StringBuilder("Duke");
8. String str1 = sb1.toString();
// insert code here
9. System.out.print(str1 == str2);
```

Which code fragment, when inserted at line 9, enables the code to print `true`?

**Options:**  
A. `String str2 = str1;`  
B. `String str2 = new String(str1);`  
C. `String str2 = sb1.toString();`  
D. `String str2 = "Duke";`

**Answer:** A

---
