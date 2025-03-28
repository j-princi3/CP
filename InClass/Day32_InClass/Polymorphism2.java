class parent {
  public void m1() 	{
    System.out.println("parent m1 called");
 	}
}

class child extends parent {
  public void m1() 	{
    System.out.println("child m1 called");
 	}  
}

class child2 {
  public void m1() 	{
    System.out.println("child2 m1 called");
 	}  
}

class demo {
  public static void main(String[] args) {
    parent pobj = new child();  // point 1 
    pobj.m1();                  // Virtual method

    child cobj = (child)pobj;   // point 2
    cobj.m1();

    parent obj1 = new parent();
    child2 cobj2 = (child2)pobj;  // point 3

    child obj3 = (child)obj1;   // point 4

    // Correct way of writing code
    if(obj1 instanceof child) {
      child obj4 = (child)obj1;
    }
  }
}

/*

A virtual method is a method in which
the specific implementation is not determined until runtime.

Here are some basic rules to keep in mind when casting variables:

1. Casting an object from a subclass to a superclass doesn’t require 
   an explicit cast.

2. Casting an object from a superclass to a subclass requires an explicit cast.

3. The compiler will not allow casts to unrelated types.

4. Even when the code compiles without issue, an exception may be thrown at 
   runtime if the object being cast is not actually an instance of that class.
*/