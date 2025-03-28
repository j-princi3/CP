class Access {
	int i;
	private int j;
	public int k;
	protected int l;
	private void func_one() 	{
		i = j = k = l = 1;
	}
	void func_two() 	{
		i = j = k = l = 2;
	}	
	public void func_three() 	{
		i = j = k = l = 3;	
	}
}
class Demo {
	public static void main(String []args) 	{
		Access ob=new Access();
		ob.i = ob.k = ob.l=4;
		ob.j = 5;
		ob.func_one();
		ob.func_two();
		ob.func_three();
	}
}		
