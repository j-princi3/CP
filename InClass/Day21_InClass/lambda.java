class myRunnable implements Runnable 
{
  public void run()
  {
    System.out.println("myRunnable");
  }
}

class lambda {
  public static void main(String[] args) 	{
    Thread t1 = new Thread(new myRunnable());
    t1.start();

    Runnable r1 = () -> System.out.println("Runnable Using lambda");
    Thread t2 = new Thread(r1);
    t2.start();
	}
}
