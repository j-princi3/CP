import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class ImmutableMap {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("Apple", 10);
        map.put("Banana", 20);

        Map<String, Integer> immutableMap = Collections.unmodifiableMap(map);
        
        System.out.println(immutableMap); // {Apple=10, Banana=20}

		immutableMap.put("Mango", 30); // Throws UnsupportedOperationException
    }
}