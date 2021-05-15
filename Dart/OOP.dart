abstract class Abstract {
  void abstractMethod();
  void defaultMethod() {
    print("defaultMethod is called from Abstract class.");
  }
}

class Base extends Abstract {
  Base() {
    print("Base class constructor is called.");
  }

  @override
  void abstractMethod() {
    print("abstractMethod is called from Base class.");
  }

  void baseMethod() {
    print("baseMethod is modified in Base class.");
  }
}

class Derived extends Base {
  Derived() {
    print("Derived class constructor is called.");
  }

  @override
  void baseMethod() {
    print("baseMethod is modified in Derived class.");
  }

  @override
  void abstractMethod() {
    print("abstractMethod is modified in Derived class.");
  }

  void derivedMethod() {
    print("derivedMethod is called from Derived class.");
  }
}

void function(Abstract obj) {
  obj.abstractMethod();
}

void main() {
  Base b = new Base();
  Derived d = new Derived();
  function(b);
  function(d);
}
