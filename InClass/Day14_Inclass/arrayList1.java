import java.util.*;

class arrayList1 {
  public static void main(String args[]) {
    ArrayList list1 = new ArrayList();
    list1.add("kmit");
    list1.add(Boolean.TRUE);
    list1.add(1, 21);
    System.out.println(list1.size());
    System.out.println(list1);
	
    System.out.println(list1.remove("kmit"));
    System.out.println(list1.remove(1));
    System.out.println(list1);
  }
}