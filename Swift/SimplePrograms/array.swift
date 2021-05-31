var IntArray = [Int]();
/*
 another way of initializing an array::
 var Array:[Int] = [1,3,4,5]
 var Array = [Int](count: 3, repeatedValue: 0) -- repeatedValue initialize the array
*/


IntArray.append(10)
IntArray += [30]

var firstElement:Int = IntArray[0]

print("Value of the first element is: \(firstElement)")
print("Value of the second element is: \(IntArray[1])")