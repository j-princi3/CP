// Wrappers are immutable
class wrapper3
{
  public static void main(String [] args) {
    Integer y = 123; 
    Integer x = y;
    System.out.println(x == y);
    y++; 
    System.out.println(x + " " + y); 
    System.out.println(x == y);
  }
}
