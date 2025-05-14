import java.util.*;

class binarysearch1 {
  public static void main(String args[]) 
  {
    int[] numbers = {2,4,6,8};
    System.out.println(Arrays.binarySearch(numbers, 2)); 
    System.out.println(Arrays.binarySearch(numbers, 4)); 
    System.out.println(Arrays.binarySearch(numbers, 1)); 
    System.out.println(Arrays.binarySearch(numbers, 3)); 
    System.out.println(Arrays.binarySearch(numbers, 9)); 

    System.out.println();
    int[] numbers2 = new int[] {3,2,1};
    System.out.println(Arrays.binarySearch(numbers2, 2));
    System.out.println(Arrays.binarySearch(numbers2, 3));
  }
}
