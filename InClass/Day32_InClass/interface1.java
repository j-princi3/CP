interface Demo{
  int add(int a, int b);    // public abstract is added
  int valuex = 20;          // public static final is added
}
class c1{
 	public int subtract(int x, int y){
    return(x - y);
 	}
}
class test extends c1 implements Demo{   	
  public int add(int x,int y){
    return x + y;
  }
  public static void main(String[] args){
    test obj = new test();
    System.out.println(obj.add(20, 10));
    System.out.println(obj.subtract(20, 10));
    System.out.println("Interface field value is " + Demo.valuex);
  }
}
