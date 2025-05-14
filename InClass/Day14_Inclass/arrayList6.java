import java.util.*;

class arrayList6 {
  public static void main(String args[]) {
    List<String> list1 = new ArrayList<>();
    list1.add("kmit");
    list1.add("ngit");

    Object[] objectArray = list1.toArray();
    System.out.println(objectArray.length +" "+ Arrays.toString(objectArray));
	list1.add("hello");
    //String[] stringArray = list1.toArray(new String[0]);
	objectArray[0] = "genesis";
    System.out.println(Arrays.toString(objectArray)+" "+list1); 
  }
}