import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ImmutableList {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");

        List<String> immutableList = Collections.unmodifiableList(list);
        System.out.println(immutableList); // [Apple, Banana]

		//immutableList.add("Mango"); // Throws UnsupportedOperationException
    }
}