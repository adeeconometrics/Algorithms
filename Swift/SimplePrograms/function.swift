func function(a:Int)->Int{
    let a = 3;
    return a;
}

print(function(a:5));

func minmax(array:[Int])->(min:Int, max:Int){ // you can name return types and refer to them
    var min = array[0];
    var max = array[0];
    for i in array{
        if i < min {
            min = i;
        }
        else if i > max{
            max = i;
        }
    }
    return (min, max)
}

let result = minmax(array:[1,2,3,4,5,6])
print("min: \(result.min), max: \(result.max)")

let array:[Int] = [1,2,3,4];

for i in array[1..<array.count]{ // iterating over an array
    print(i);
}
/*
equivalently:
var i:Int = 0;
while(i < array.count){
    print("\(array[i])");
    i += 1;
}
*/

print("\(array.count)");

// higher order functions: a simple example
func one()->Int{
    return 1;
}

func second_order(times:Int, f:Int)->String{
    var i:Int = 0;
    while(i < times){
        print(f);
        i += 1;
    }
    return "done";
}

print(second_order(times:3, f:one()))