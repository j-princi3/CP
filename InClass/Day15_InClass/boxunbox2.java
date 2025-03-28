import java.util.*;

class boxunbox2
{
	public static void main(String [] args) 
	{
    List <Double> list1 = new ArrayList<>();
    list1.add(1.2); 
    list1.add(new Double(3)); 
    System.out.println(list1);
    double first = list1.get(0);
    System.out.println(first);
    System.out.println(list1);

    list1.add(null);
    System.out.println(list1);
    double d = list1.get(list1.size() - 1);
  }
}
