interface I1{
	void m1();
}
interface I2{
	void m1(int x);
}
class Test implements I1,I2{
	public void m1(){
	}
	public static void main(String[] args){
		Test obj = new Test();
		obj.m1();
	}
}