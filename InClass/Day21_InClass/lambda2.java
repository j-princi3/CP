// Lambda expressions are used primarily to define inline implementation of a
// functional interface, i.e., an interface with a single method only.

// Lambda expression eliminates the need of anonymous class and gives a 
// simple yet powerful functional programming capability to Java.

public class lambda2 {
   public static void main(String args[]){
      lambda2 obj = new lambda2();
		
      // with type declaration
      MathOperation addition = (int a, int b) -> a + b;
		
      // without type declaration
      MathOperation subtraction = (a, b) -> a - b;
		
      // with return statement along with curly braces
      MathOperation multiplication = (int a, int b) -> { return a * b; };
		
      // without return statement and without curly braces
      MathOperation division = (int a, int b) -> a / b;
		
      System.out.println(obj.operate(10, 5, addition));
      System.out.println(obj.operate(10, 5, subtraction));
      System.out.println(obj.operate(10, 5, multiplication));
      System.out.println(obj.operate(10, 5, division));		
   }
	
   interface MathOperation {
      int operation(int a, int b);
   }

   private int operate(int a, int b, MathOperation mathOperation){
      return mathOperation.operation(a, b);
   }
}