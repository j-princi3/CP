import java.time.*;

public class date4 {
  public static void main(String[] args) {
    LocalDate date = LocalDate.now();
    LocalTime time = LocalTime.of(5, 15);
    System.out.println(date);
    System.out.println(time);

    LocalDateTime dateTime = LocalDateTime.of(date,  
      time).minusDays(1).minusHours(10).minusSeconds(30);
    System.out.println(dateTime);

	//date = date.plusDays(2).plusMinutes(30);
    System.out.println(date);

  }
}
