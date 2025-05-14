interface One{
  static int getInt() {
    return 1;
  }
}
// The static interface methods are not inherited by a class implementing 
// the interface
class test implements One{  
  public static void main(String[] args){
    test obj = new test();
    //obj.getInt();    
    System.out.println(One.getInt());
  }
}
