class Employee {
  public String getName() {
    return "Employee";
  }
}
class Manager extends Employee {
  public String getName() {
    return "Manager";
  }
}
class Analyst extends Employee {
  public String getName() {
    return "Analyst";
  }
}
// If we change parameter Employee to Manager what do you think will happen?
class test {
  public static void getInfo(Employee Employee) {
    System.out.println("Employee " + Employee.getName());
  }

  public static void main(String[] args) {
    getInfo(new Manager());
    getInfo(new Analyst());
    getInfo(new Employee());
  }
}