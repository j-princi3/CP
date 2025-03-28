interface IOne{
  default int getInt(){
    return 1;
  }
  default String getString(){
    return "IOne";
  }
}
interface ITwo extends IOne{
  default int getInt(){
    return 2;
  }
  default float getFloat(){
    return 1.2F;
  }
}

// Identify the errors in this code
class test implements ITwo{   	  
  public static void main(String[] args){
    //IOne obj1 = new IOne(); 
    ITwo obj = new test();
    System.out.println(obj.getInt());
    System.out.println(obj.getFloat());
    System.out.println(obj.getString());
  }
}
