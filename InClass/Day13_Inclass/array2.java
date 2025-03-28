import java.util.*;

class array2 {
  public static void main(String args[]) {
    int [] arr = {16, 3, 12, 1};
    Arrays.sort(arr);
    for(int i = 0; i < arr.length; i++)
      System.out.println(arr[i]);

    System.out.println();

    String [] sarr = {"17", "4", "21", "2", "111"};
    Arrays.sort(sarr);
    for(String s : sarr)
      System.out.println(s);
  }
}