class parent 
{
	// Remove static
	public boolean isValid() 
	{
		return false;
	}
	void m1() 	
	{
		System.out.println("parent m1 called "+ isValid());
 	}
}

class child extends parent 
{
	 public boolean isValid() 
	{
		return true;
	}
	void m2() 	
	{
		System.out.println("child1 m2 called "+ isValid());
 	}
}

class demo {
	public static void main(String[] args) throws Exception
	{
		child cobj = new child(); 
		cobj.m1();
		cobj.m2();
	}
}
