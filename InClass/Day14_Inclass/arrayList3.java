import java.util.*;

class arrayList3 {
  public static void main(String args[]) {
    ArrayList list1 = new ArrayList();
    list1.add("kmit");
    list1.add("genesis");
    System.out.println(list1);
    System.out.println(list1.isEmpty());
    list1.set(0,"ngit");
    list1.set(1,"keshav");
    System.out.println(list1);
    list1.clear();
    System.out.println(list1.isEmpty());
  }
}