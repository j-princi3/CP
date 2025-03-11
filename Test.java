import java.util.*;
// Package src;
// create fi called greeting, having method greet with one string arg and returntype is string
// write a program without lamdba and without lamdba to greet two user

@FunctionalInterface

interface greeting {
    String greet(String s);
}
public class Test{
    public static void main(String args[]){
        greeting g=(a)->"Hello"+a;
        System.out.println(g.getClass().getName());
        System.out.println(g.greet("princi"));

    }
}
