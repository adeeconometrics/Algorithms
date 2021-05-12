using System;

interface Interface{
    // declare abstract methods and only abstract methods
    string InterfaceMethod();
}

class A: Interface{
    public A(){
        Console.WriteLine("class A constructor is called.");
    }

    public string InterfaceMethod(){
        return "InterfaceMethod is called from class A.";
    }
}

class B: Interface{
    public B(){
        Console.WriteLine("class B constructor is called.");
    }

    public string InterfaceMethod(){
        return "InterfaceMethod is called from class B.";
    }
}

class MainInterface{
    static void print(Interface obj){
        Console.WriteLine(obj.InterfaceMethod());
    }

    public static void Main(string [] args){
        Interface a = new A();
        Interface b = new B();
        print(a);
        print(b);
    }
}