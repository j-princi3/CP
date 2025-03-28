interface IShape{
  default double getDouble(){
    return 10;
  }
  double area();
}

class Circle implements IShape{
  public double area(){
    double radius = getDouble();
    return (Math.PI * radius * radius);
  }
}

class test 
{   	  
  public static void main(String[] args)
  {
    Circle obj = new Circle();
    System.out.println(obj.area());
  }
}
