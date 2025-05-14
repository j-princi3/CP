package InClass.Day12_Inclass;
class string1 {
	public static void main(String[] args) 	{
    String s1 = "1"; 
    String s2 = s1;
    s1 += "2"; 
    s1 += 3; 
    System.out.println(s1); 
    System.out.println(s2); 

    String s3 = "5";
    String s4 = s3.concat("6");
    s4.concat("7");
    System.out.println(s3);
    System.out.println(s4);
  }
}