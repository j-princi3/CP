import java.util.*;

class arrayList5 {
  public static void main(String args[]) {
    ArrayList list1 = new ArrayList();
    list1.add("ngit");
	list1.add("kmit");

    ArrayList list2 = new ArrayList();
    list2.add("kmit");
    list2.add("ngit");
    System.out.println(list1.equals(list2));

    list2.set(0, "ngit");
    list2.set(1, "kmit");
    System.out.println(list1.equals(list2));
  }
}