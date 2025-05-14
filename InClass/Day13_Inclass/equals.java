class demo {
  private int value;  

  demo(int val)  {
    value = val;
  }

  @Override 
  public boolean equals(Object obj)  {
    System.out.println("object Equals called");
    if((obj instanceof demo) && (((demo)obj).value == this.value))
      return true;
    else
      return false;
  }
  @Override
	  public String toString(){
	  	return ""+value;
	}
}

class equals {
  public static void main(String args[]) {
    demo obj1 = new demo(10);
    demo obj2 = new demo(11);
    
    System.out.println("using == " + (obj1 == obj2));
    System.out.println("using equals " + obj1.equals(obj2));
	System.out.println(obj1);
  }
}
