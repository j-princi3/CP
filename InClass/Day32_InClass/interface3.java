interface one {
  int m1();
  int m2(int x, int y);
}
interface two {
  int m2();
  int m1();
}
interface three {
  int m3();
  int m2(int x);
}
class test implements three, one, two{    
  public int m1() { return 1; }
  public int m2() {  return 2; }
  public int m3() {  return 3; }
  public int m2(int x) {  return 4; }
  public int m2(int x, int y) {  return 5; }

  public static void main(String[] args){
    test obj = new test();
    System.out.println(obj.m1());
    System.out.println(obj.m2());
    System.out.println(obj.m2(10));
    System.out.println(obj.m3());
    System.out.println(obj.m2(1, 2));
  }
}
