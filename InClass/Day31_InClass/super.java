class parent 
{
	int i;
	parent(int i) 
	{
		this.i = i;
	}
	void square() 
	{
		System.out.println("Square of " + i + " is "+ (i*i));
	}
	void display()
	{
		System.out.println("value of i is " +i);
	}
}

class child extends parent 
{
	int i, j;
	child(int i,int j) 
	{
		super(i);  		// calls superclass constructor
		this.j = j;
	}

	void display()
	{
		super.i = 40;
		super.display();
		System.out.println("value of j is " +j);
	}

	void product() 
	{
		System.out.println("Product of "+super.i+" and "+j+" is "+(super.i * j));
	}
}

class Demo 
{
	public static void main(String []args) 
	{
		parent pob = new parent(10);
		pob.square();

		child cob = new child(20,30);
		cob.square();
		cob.display();
		cob.product();
	}
}		