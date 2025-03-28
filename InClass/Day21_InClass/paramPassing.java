class circle {
	public float radius = (float)10.0;
}

class paramPassing {
	public void m1(){
		circle cirObj = new circle();
	   float localradius = (float)15.0;

		System.out.println("Before: local radius is " + localradius);
		System.out.println("Before: circle radius is " + cirObj.radius);

		modifyData(localradius, cirObj);

		System.out.println("After: local radius is " + localradius);
		System.out.println("After: circle radius is " + cirObj.radius);
	}

	public void modifyData(float lrad, circle cobj){
		lrad = (float)33.3;
		cobj.radius = (float)55.5;
	}
	
	public static void main(String[] args) 	{
		paramPassing Obj = new paramPassing();
		Obj.m1();
	}
}
