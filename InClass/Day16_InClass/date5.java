import java.time.*;

class date5 {
  public static void main(String[] args) {
    LocalDate start = LocalDate.of(2015, Month.JANUARY, 1);
    LocalDate end = LocalDate.of(2015, Month.MARCH, 30);
    //Period period = Period.ofWeeks(1); // create a period
	Period period = Period.ofMonths(1);

    /* Period.ofWeeks(3); Period.ofDays(2)
    Period.of(1, 2, 5);  Period.ofYears(1); */
    sendAlerts(start, end, period); 
    System.out.println("start " + start);
  }

  private static void sendAlerts(LocalDate start, 
    LocalDate end, Period period) 
  { 
    while (start.isBefore(end)) {
      System.out.println("Reminder " + start);
      start = start.plus(period); 
    }  
  }
}