import 'dart:core';
import "dart:io";

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else {
    print(a.toString() +
        " = " +
        (b).toString() +
        "*" +
        (a ~/ b).toString() +
        "+" +
        (a % b).toString());

    return gcd(b, a % b);
  }
}

void main() {
  print("Enter two numbers: ");
  int? a = int.parse(stdin.readLineSync()!);
  int? b = int.parse(stdin.readLineSync()!);
  print("---------------------------------");
  int result = gcd(a, b);
  print("gcd: $result");
}
