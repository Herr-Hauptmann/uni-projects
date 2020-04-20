//TP 2018/2019: ZSR 4, Zadatak 2
#include <iostream>
#include <vector>

int main ()
{
    std::vector<int> v (10,5);
    auto i = v.begin();
    decltype(i) a;
	return 0;
}