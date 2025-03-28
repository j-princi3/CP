package InClass.Day12_Inclass;
class Test{
	int val;
	Test(int x){
		val = x;
	}
	
	@Override
	public boolean equals(Object o){
		return true;
	}
	public static void main(String args[]) {
		Test t1 = new Test(10);
		Test t2 = new Test(10);
		System.out.println(t1.equals(t2));
	}
}