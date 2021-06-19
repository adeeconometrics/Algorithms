class A{
  init(){ print("class A constructor is called");}
  
  func method(){ print("method in class A is called");}
  
  deinit{ print("class A destructor is called");}
}

class B: A{
  override init(){ 
    print("class B constructor is called");
    // super.init();
  }
  
  override func method(){ print("method in class B is called");}
  
  func super_method(){
      super.method();
  }
  
  deinit{print("class B destructor is called");}
}

var b:B? = B(); // let is immutable and non-nullable
b!.method();
b!.super_method();

b = nil;

/**
output:
class B constructor is called
class A constructor is called
method in class B is called
method in class A is called
class B destructor is called
class A destructor is called
*/