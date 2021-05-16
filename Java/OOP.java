// this will serve as our base class

abstract class Abstract{
    public Abstract(){
        System.out.println("Abstract class is constructed.");
    }
    public abstract void abstractMethod();
}

class Base extends Abstract{
    private String baseString;

    public Base(){
        System.out.println("Base class is constructed.");
    }

    @Override
    public void abstractMethod(){
        System.out.println("abstractMethod is implemented in Base class");
    }

    public void baseMehod(){
        System.out.println("baseMethod is called in Base class.");
    }

    public String getBaseString(){
        return this.baseString;
    }

    public void setBaseString(String str){
        this.baseString = str;
    }
}

class Derived extends Base{
    private String derivedString;

    public Derived(){
        System.out.println("Derived class is constructed.");
    }
    @Override
    public void abstractMethod(){
        System.out.println("abstractMethod is implemented in Derived class");
    }

    public String getDerivedString(){
        return this.derivedString;
    }

    public void setDerivedString(String str){
        this.derivedString = str;
    }

    @Override
    public void baseMehod(){
        System.out.println("baseMethod is modified in Derived class.");
    }
    public void derivedMethod(){
        System.out.println("derivedMethod is implemented in Derived class.");
    }
}

public class OOP{
    public static void main(String [] args){

    }
}