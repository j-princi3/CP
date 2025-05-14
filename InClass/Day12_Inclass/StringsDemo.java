package InClass.Day12_Inclass;
class StringsDemo {
  public static void main(String [] args) {
    String x = "Java"; 
    String y = x; 
    System.out.println("y string = " + y);

    x = x + " Bean"; 
    System.out.println("x string = " + x);
    System.out.println("y string = " + y);
    y = y.replace("Ja", "PT");
    System.out.println("x string = " + x);
    System.out.println("y string = " + y);

    String str1 = "Genesis";
    String str2 = str1; 
  
    System.out.println("str1 converted " + str1.toUpperCase());
    System.out.println("str1 string = " + str1);
    System.out.println("str2 string = " + str2);
  }
}
