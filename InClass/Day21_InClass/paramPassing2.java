// Shadowing concept

class circle {
	public double radius = 2.2;
}
class paramPassing2 {
	public void m1(){
		circle cirObj = new circle();
		System.out.println("Before: circle radius is " + cirObj.radius);
		System.out.println(cirObj);
		modifyData(cirObj);
		System.out.println("After: circle radius is " + cirObj.radius);
	}
	public void modifyData(circle cirObj){
		cirObj.radius = 5.5;
		System.out.println(cirObj);
		cirObj = new circle();
		cirObj.radius = 7.7;
		System.out.println(cirObj);
	}	
	public static void main(String[] args) 	{
		paramPassing2 Obj = new paramPassing2();
		Obj.m1();
	}
}