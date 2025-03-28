import java.time.*;

public class date3 {
  public static void main(String[] args) {
    LocalDate date = LocalDate.now();
    System.out.println(date);
    date = date.plusDays(2);
    System.out.println(date); 
    date = date.plusWeeks(1);
    System.out.println(date);
    System.out.println(date.plusMonths(1));
    System.out.println(date.plusYears(2));
    System.out.println(date);
  }
}
