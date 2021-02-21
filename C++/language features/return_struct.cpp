// struct functions
# include <iostream>
# include <stdio.h>
using namespace  std;

typedef struct a {
   int i;
}B;

B f(B x)
{
   B r;
   return r;
}

// pointer 
B* g(B x){
	B r;
   return r;
}

int main(void)
{
   B x = { 12 };
   B y = f(x);
   printf("%d\n", y.i);
   return 0;
}
