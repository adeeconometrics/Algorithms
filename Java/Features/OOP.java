import java.util.Scanner;

// abstract class 
abstract class AbstractBase{
    abstract void abstractBaseMethod();
}

// extending abstract class
abstract class AbstractChild extends AbstractBase{
    abstract void abstractChildMethod();
}

// interfaces
interface BaseInterface{
    default void baseMethod(){
        System.out.println("Base method from BaseInterface");
    }
}
// extending interfaces
interface ChildInterface extends BaseInterface{
    default void childMethod(){
        System.out.println("Child method from ChildInterface");
    }
}

// base class
class Base implements ChildInterface{
    private String name = "Base";

    public Base(){
        System.out.println("I have no method here; only the standards.");
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }
}
// child class 
class ChildRight extends Base{
    private String name = "ChildRight";

    public ChildRight(){
        System.out.println("I have no method here; only the standards.");
    }
    @Override
    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }
}
// child 2 class
class ChildLeft extends Base{
    private String name = "ChildLeft";

    public ChildLeft(){
        System.out.println("I have no method here; only the standards.");
    }
    public void setName(String name){
        Base b = new Base();
        b.setName(name); // disambiguate call from super class; establish reference first
        //super.setName(name) -- can also be used if you don't need to disambiguate method calls
    }

    public String getName(){
        return name;
    }
}
// multiple inheritance through interfaces

// main class
public class OOP{
    public static void main(String args[]){

    }
}