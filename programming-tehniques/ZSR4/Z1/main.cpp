//TP 2018/2019: ZSR 4, Zadatak 1
#include <iostream>
#include <cmath>
const double eps = 0.00001;
void NijeTrocifren(int x){
	if(log(100)-log(abs(x))>eps  || log(abs(x))-log(999) > eps) std::cout<<" "<<x;
}

int main ()
{
    NijeTrocifren(666);
	return 0;
}