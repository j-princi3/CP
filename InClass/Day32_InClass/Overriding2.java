class parent 
{
	private void m1() 	
	{
		System.out.println("parent m1 called");
 	}
}

class child extends parent 
{
	private int m1() 	
	{
		System.out.println("child1 m1 called");
		return 1;
 	}
}

class demo {
	public static void main(String[] args) throws Exception
	{
		parent cobj = new child(); 
		cobj.m1();
	}
}
