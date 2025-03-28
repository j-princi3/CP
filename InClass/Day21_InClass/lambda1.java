// Lambda expressions are used primarily to define inline implementation of a
// functional interface, i.e., an interface with a single method only.

// Lambda expression eliminates the need of anonymous class and gives a 
// simple yet powerful functional programming capability to Java.

public class lambda1 {
   public static void main(String args[]){
      // with type declaration
      MathOperation addition = (int a, int b) -> a + b;
	  System.out.println(addition.getClass().getName());
		
      // without type declaration
      MathOperation subtraction = (a, b) -> a - b;
	  System.out.println(subtraction);
		
      // with return statement along with curly braces
      MathOperation multiplication = (int a, int b) -> { return a * b; };
		
      // without return statement and without curly braces
      MathOperation division = (int a, int b) -> a / b;
		
      System.out.println(addition.operation(10, 5));
      System.out.println(subtraction.operation(10, 5));
      System.out.println(multiplication.operation(10, 5));
      System.out.println(division.operation(10, 5));
   }
	@FunctionalInterface
   interface MathOperation {
      int operation(int a, int b);
   }
}