#include <iostream>

int fib2_0(int n, int prosli = 1, int pretprosli = 0)
{
   if(n == 0) return pretprosli;
   return fib2_0(n - 1, prosli + pretprosli, prosli);
}

int fib_petlja (int n)
{
    if (n<=1) return n; // 0 i 1
    int pretprosli(0), prosli(1), rezultat;
    for (int i(2); i<=n; i++) {
        rezultat = pretprosli+prosli;
        pretprosli = prosli;
        prosli = rezultat;
    }
    return rezultat;
}
int nzd(int x, int y)
{
 if(y == 0) return x;
 nzd(y, x % y);
}

int main()
{
    std::cout<<fib2_0(5)<<std::endl;
    std::cout<<nzd(5,7)<<std::endl;
    std::cout<<nzd(12,6)<<std::endl;
    std::cout<<fib2_0(12)<<std::endl;
    std::cout<<nzd(28,144)<<std::endl;
    return 0;
}
