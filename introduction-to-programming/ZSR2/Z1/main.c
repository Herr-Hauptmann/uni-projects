#include <stdio.h>
#include <math.h>

int main() {
double x,k;
x=0;
k=0;
printf("Unesi broj: ");
scanf("%lf", &x);
k=sqrt(sqrt(x));
printf("4. korijen iz broja %g je %.10f", x,k);
}
