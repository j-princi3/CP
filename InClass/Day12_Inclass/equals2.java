package InClass.Day12_Inclass;
class equals2 {
  public static void main(String args[]) {
    StringBuilder sb1 = new StringBuilder("hello");
    StringBuilder sb2 = new StringBuilder("hello");
    System.out.println(" == " + (sb1 == sb2));
    System.out.println("equals " + sb1.equals(sb2));
    System.out.println("equals2 " + sb1.toString().equals(sb2.toString()));

    String s1 = "kmit";
    String s2 = "kmit";    
    System.out.println(" == " + (s1 == s2));
    System.out.println("equals " + s1.equals(s2));
  }
}
