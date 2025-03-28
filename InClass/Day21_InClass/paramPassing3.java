 
class paramPassing3{
	public void m1(String s, StringBuilder sb, Integer i){
		s = s.concat("Hyderabad");
		sb.append("India");
		++i;
	}	
	public static void main(String[] args) 	{
		paramPassing3 Obj = new paramPassing3();
		String s1 = "kmit";
		StringBuilder sb1 = new StringBuilder("Genesis");
		Integer i1 = new Integer (100);
		Obj.m1(s1, sb1, i1);
		System.out.println(s1 + " " + sb1 + " " + i1);
	}
}