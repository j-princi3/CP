import java.time.*;
import java.time.format.*;

class date8 {
  public static void main(String[] args) {
    /*LocalDate date1 = LocalDate.now();
    LocalTime time1 = LocalTime.now();
    LocalDateTime dateTime1 = LocalDateTime.now();

    // mm (minutes), hh (hours), ss (seconds), MM (month), dd (day), yy or yyyy (year) 
    DateTimeFormatter dtf = DateTimeFormatter.ofPattern("MM:dd:yyyy:hh:mm:ss");
    //System.out.println(dtf.format(time1));  
    System.out.println(dtf.format(dateTime1));
    //System.out.println(dtf.format(date1));*/

    DateTimeFormatter dtf1 = DateTimeFormatter.ofPattern("MM dd yyyy");
    LocalDate date2 = LocalDate.parse("01 05 2017", dtf1);
    LocalTime time2 = LocalTime.parse("11:22");
    System.out.println(date2); 
    System.out.println(time2); 
  } 
}