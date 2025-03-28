interface One{
  static int m1(){
    return 1;
  }
}
interface Two {
  static int m1(){
    return 2;
  }
}
class test implements One, Two{ 
  public static void main(String[] args){
    One obj = new test();
    System.out.println(One.m1());
    System.out.println(Two.m1());
    //System.out.println(obj.m1());
  }
}
