public class Singleton{
	int value;
    static Singleton obj = null;
	private Singleton() {
		value = 10;
	}
  public int getValue(){
    return value;
  }
  public void setValue(int value){
    this.value = value;
  }
  public static Singleton getInstance(){
    if(obj == null){
      System.out.println("if block");	
      obj = new Singleton();
    }
    else {
      System.out.println("else block");	
    }
    return obj;
  }

	public static void main(String []args) 
	{
    Singleton s1 = Singleton.getInstance();
    System.out.println("s1 value is " + s1.getValue());	
    s1.setValue(30);
    Singleton s2 = Singleton.getInstance();		
    System.out.println("s2 value is " + s2.getValue());	
    s1.setValue(50);
    Singleton s3 = Singleton.getInstance();
    System.out.println("s1 value is " + s1.getValue());	
    System.out.println("s2 value is " + s2.getValue());	
    System.out.println("s3 value is " + s3.getValue());
	System.out.println(s1 == s2 );	
	System.out.println(s2 == s3 );	
	s3 = null;
  }
}
