# modules are about how you structure your program
# packages are about how you distribute your program `pkg.add(package)`

# modules - partioning your code into individual functions
# Julia allows you to include modules by `#include <modules>`
# modules provide a namespace for our code

# defining the start and end of module
module modules

export f

function f(x::Int)
    return x + 1
end

function g(x:Int)
    return x - 1
end

end 