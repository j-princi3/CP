import java.util.Date;

class wrapper1
{
  	public static void main(String [] args) {
      Object obj = new Object();
      System.out.println("getClass " + obj.getClass());
      System.out.println("string representation = " + obj.toString());

      double d1 = 3.0;
      int i1 = 3; 
      if ( d1==i1 )
         System.out.println("wrappers are equal"); 
      else
         System.out.println("wrappers not equal");

      Double d2 = d1.valueOf("3.0d"); 
      if (d1.equals(d2))
         System.out.println("Doubles are equal"); 
      else
         System.out.println("Doubles are not equal");

      if (d1 == d2)
         System.out.println("Doubles are =="); 
      else
         System.out.println("Doubles are !=");
  	}
}
