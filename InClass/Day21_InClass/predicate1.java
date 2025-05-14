import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

class predicate1 {
	public static void main(String args[]){
		List<Integer> list = Arrays.asList(1, 12, 3, 24, 5, 6, 37, 58, 9);

		// Creating predicate
		Predicate<Integer> lesserthan = i -> (i < 20); 

		// Calling Predicate method
		System.out.println(lesserthan.test(10)); 
		
		// Predicate<Integer> predicate = n -> true
		// n is passed as parameter to test method of Predicate interface
		// test method will always return true no matter what value n has.

		System.out.println("Print all numbers less than 20:");

		Predicate<Integer> ptrue = i -> (i < 20); 
		//pass n as parameter
		eval(list, ptrue);

		// Predicate<Integer> predicate1 = n -> n%2 == 0
		// test method will return true if n%2 is zero

		System.out.println("\nPrint even numbers:");
		eval(list, n -> n % 2 == 0 );

		// Predicate<Integer> predicate2 = n -> n > 10
		// test method will return true if n is greater than 10.

		System.out.println("\nPrint numbers greater than 10:");
		eval(list, n -> n > 10 );
	}
	
	public static void eval(List<Integer> list, Predicate<Integer> predicate) {
		for(Integer n: list) {		
			if(predicate.test(n)) {
				System.out.print(n + " ");
			}
		}
	}
}