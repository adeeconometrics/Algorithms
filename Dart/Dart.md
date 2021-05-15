## Notes on Dart

Dart is a language developed by Google for client development such as web and mobile apps. It supports object-oriented programming, generic programming, and procedural programming, to name a few. 

We can compile our Dart code to either a native code under the Dart VM or JavaScript. 

The official documentation of Dart: https://dart.dev/

---

Notable features:
- [Does not support]( https://bityl.co/6qQr) `passing by reference` for safety reasons, like Java, Dart only supports pass by value. Objects, on the other hand, are passed by reference. 
- Dart supports [nullable types]( https://bityl.co/6qRB) for type safety and interoperability. We can implement this in the following syntax: `Type? TypeName`.
- During execution, the resources we accumulated piles up at runtime. Dart supports garbage collection: we don't have to worry about deallocating resources to configure whether it is properly deleted.
- Dart supports declarative style of programming which makes Dart code easier to express.