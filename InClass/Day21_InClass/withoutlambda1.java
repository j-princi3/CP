@FunctionaInterface
interface MathOperation { //functional interface
  int operation(int a, int b);
}

class addOperation implements MathOperation {
  public int operation(int a, int b){
    return a + b;
  }
}

class subtractionOperation implements MathOperation {
  public int operation(int a, int b){
    return a - b;
  }
}

class multiplicationOperation implements MathOperation {
  public int operation(int a, int b){
    return a * b;
  }
}

class divisionOperation implements MathOperation {
  public int operation(int a, int b){
    return a / b;
  }
}

class test {
   public static void main(String args[]){
      MathOperation obj = new addOperation();
      System.out.println(obj.operation(10, 5));	

      obj = new subtractionOperation();
      System.out.println(obj.operation(10, 5));

      obj = new multiplicationOperation();
      System.out.println(obj.operation(10, 5));

      obj = new divisionOperation();
      System.out.println(obj.operation(10, 5));
   }	
}