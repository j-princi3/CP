class parent 
{
	public void m1() throws Exception	
	{
		System.out.println("parent m1 called");
 	}
	public Number m2()
	{
		System.out.println("parent m2 called");
		return 10;
	}
}

class child extends parent 
{
	// Replace void with int
	// Replace public with protected
	// Change exception order
	public void m1() throws RuntimeException 	{
		System.out.println("child1 m1 called");
 	}  

	// Change the return order
	public Integer m2()
	{
		System.out.println("child m2 called");
		return 20;
	}
}

class demo {
	public static void main(String[] args) throws Exception
	{
		parent cobj = new child(); 
		cobj.m1();
		cobj.m2();
	}
}
