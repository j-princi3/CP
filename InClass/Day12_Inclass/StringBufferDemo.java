package InClass.Day12_Inclass;
class StringBuilderDemo 
{
  public static void main(String [] args) {
    StringBuilder sb1 = new StringBuilder("Java"); 
    StringBuilder sb2 = sb1;   	
    System.out.println("sb1 = " + sb1);
    System.out.println("sb2 = " + sb2);
    sb1.append(" Bean"); 	
    System.out.println("sb1 = " + sb1);
    System.out.println("sb2 = " + sb2);

    sb1.insert(4, "**");
    System.out.println("sb1 = " + sb1);
    System.out.println("sb2 = " + sb2);

    StringBuilder sb3 = new StringBuilder("Genesis");
    StringBuilder sb4 = sb3; 

    System.out.println("sb3 reverse = " + sb3.reverse());
    System.out.println("sb3 = " + sb3);
    System.out.println("sb4 = " + sb4);
    System.out.println("sb4 string representation = " + sb4.toString());

    sb3.append(" ").append(true).append(" ").append("kmit").append(10);
    System.out.println("sb4 = " + sb4);
  }
}
