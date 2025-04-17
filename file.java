import java.util.*;
class sorting implements Runnable{

    @Override
    public void run() {
        // TODO Auto-generated method stub
        // throw new UnsupportedOperationException("Unimplemented method 'run'");
    }

}

class search implements Runnable{

    @Override
    public void run() {
        // TODO Auto-generated method stub
        // throw new UnsupportedOperationException("Unimplemented method 'run'");
    }

}

class printing implements Runnable{

    @Override
    public void run() {
        // TODO Auto-generated method stub
        // throw new UnsupportedOperationException("Unimplemented method 'run'");
    }

}

public class file{
    public static void main(String args[]){
        search s1=new search();
        printing p1=new printing();
        sorting s2= new sorting();
        s1.run();
        p1.run();
        s2.run();
    }
}

// call start method to have control on thread