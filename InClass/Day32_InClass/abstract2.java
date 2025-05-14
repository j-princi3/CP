abstract class parent 
{
  abstract void mp();
}
abstract class child extends parent 
{
  abstract void mc();
  void m3()
  {
    System.out.println("child m3");
  }
}
class gc extends child {
  void mp()
  {
    System.out.println("gc mp");
  }
  void mc()
  {
    System.out.println("gc mc");
  }
  void m4()
  {
    System.out.println("gc m4");
  }
}

class demo 
{
  public static void main(String args[]) 
	{
    child obj = new gc();
    obj.mp();
    obj.mc();
	obj.m4();
 	}
}
