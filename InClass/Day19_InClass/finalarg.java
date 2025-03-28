class finalarg
{
   public static void add(final int num1, final int num2, int num3) {
	  num1 = 100;
      num3 = num1 + num2;
      System.out.println("num3 is " + num3);
   }

  	public static void main(String [] args) 
   {
      int result = 0;
      add(2, 3, result);
      System.out.println("result is " + result);
   }
}
