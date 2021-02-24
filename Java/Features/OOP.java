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
    
}
// child class 
class ChildRight extends Base{

}
// child 2 class
class ChildLeft extends Base{

}
// multiple inheritance through interfaces

// main class
public class OOP{
    public static void main(String args[]){

    }
}