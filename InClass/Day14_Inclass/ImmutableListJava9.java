import java.util.List;

public class ImmutableListJava9 {
    public static void main(String[] args) {
        List<String> list = List.of("Apple", "Banana", "Cherry");

        System.out.println(list); // [Apple, Banana, Cherry]
	
         list.set(1,"Mango"); // Throws UnsupportedOperationException

    }
}