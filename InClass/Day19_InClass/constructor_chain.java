class test{
  int x, y;
  test(){
    this(10);
  }
  test(int x){
    this(x, 20);
  }
  void test(int x, int y){
    this.x = x;
    this.y = y;
  }

	public static void main(String[] args) 
	{
    test obj = new test();
    System.out.println(obj.x + " " + obj.y);
	}  
}

