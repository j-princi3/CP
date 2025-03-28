import java.time.*;
import java.time.format.*;

class date6 {
  public static void main(String[] args) {
    LocalDate date1 = LocalDate.now();
	/*
    System.out.println(date1.getDayOfWeek());
    System.out.println(date1.getDayOfYear());
    System.out.println(date1.getMonth()); 
    System.out.println(date1.getYear()); 
    System.out.println(date1.getMonthValue());
    System.out.println(date1.isLeapYear()); 
    System.out.println(date1.lengthOfMonth());
    System.out.println(date1.lengthOfYear());
*/
    LocalDate d1 = LocalDate.of(2017, 1, 04);
    LocalDate d2 = LocalDate.of(2017, 1, 05);
    System.out.println(d1.isAfter(d2));
    System.out.println(d1.isBefore(d2));
	
  } 
}