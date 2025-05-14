import java.util.*;

abstract class Shape 
{
  abstract void type();
  abstract void calcArea();  
}

class Circle extends Shape 
{
  double rad, area;
  public void type() 
  {
    System.out.println("circle");
  }

  public void calcArea() 
	{
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the radius");
    rad = sc.nextDouble();
    area = Math.PI * rad * rad;
    System.out.println("area = "+area+" sq units");
	}
}

class demo 
{
  public static void main(String args[]) 
	{
    Shape shp;
    shp=new Circle();
    shp.type();
    shp.calcArea();
 	}
}
