using System;

//abstract class - may contain non abstract method.
abstract class Abstract{
    public abstract string AbstractMethod();
    public string PredefinedMethod(){
        return "this is a predefined method from abstract class.";
    }
}

class Base: Abstract{
    private string name = "Base class method.";
    public Base(){
        Console.WriteLine("Base class constructor is called.");
    }
    // to mark as override-able function
    public virtual string StringMethod(){
        return this.name;
    }
    // override AbstractMethod
    public override string AbstractMethod(){
        return "AbstractMethod is called from class Abstract";
    }
}
// inheritance 
class Derived: Base{
    private string name = "Derived class method.";
    public Derived(){
        Console.WriteLine("Derived constructor is called.");
    }
    //compile-time polymorphism (function overloading)
    public Derived(string name){
        Console.WriteLine("Second variant of constructor is called containing " + name);
    }
    //runtime polymorphism (function overriding)
    public override string StringMethod(){
        return this.name;
    }
    //implementation of AbstractMethod
    public override string AbstractMethod(){
        return "AbstractMethod is called from class Derived";
    }
}

class MainClass{
    public static void Main(string [] args){
        Base b = new Base(); //instantiates base class
        Console.WriteLine(b.StringMethod());
        Console.WriteLine(b.AbstractMethod());
        Console.WriteLine(b.PredefinedMethod());
        Derived d = new Derived(); //instatiates derived class
        Console.WriteLine(d.StringMethod());
        Console.WriteLine(d.AbstractMethod());
        Console.WriteLine(d.PredefinedMethod());
    }
}