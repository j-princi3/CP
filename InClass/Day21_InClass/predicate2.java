import java.util.*;

class predicate2 {
  public static void main(String args[]){
    List<Integer> al = new ArrayList<>();
    for(int i = 0; i < 10; i++)
      al.add(i);

    System.out.println(al); 
    al.removeIf(n -> n % 2 != 0);
    System.out.println(al); 
   }
}