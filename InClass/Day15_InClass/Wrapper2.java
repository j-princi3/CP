import java.util.Date;

class wrapper2
{
  public static void main(String [] args) {
    Integer i1 = 42;
    System.out.println("Integer " + i1.intValue());

    Float f1 = Float.valueOf("3.14f");
    System.out.println("Float " + f1.floatValue());

    Boolean b1 = Boolean.valueOf("TRUE");
    System.out.println("Boolean " + b1.booleanValue());

    int iVal = Integer.parseInt("123");
    System.out.println(iVal);

    iVal = Integer.parseInt("12c");
    System.out.println(iVal);
  }
}
