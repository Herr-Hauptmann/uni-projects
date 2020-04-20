#include <stdio.h>
int main()
{
 int n, i, j;
 printf("Unesite n: ");
 scanf("%d", &n);
 
 if(n<1 || n>30) printf("Greska: n mora zadovoljavati ogranicenja (1<=n<=30)");
 else if (n%2!=0)
 {
 for (i=0; i<n; i++)
 {
 for (j=0; j<n; j++)
 {
 if(i==0 || j==0 || i==n-1 || j==n-1)
 {
 printf("*");
 }
 else if(j>=i && j<n-i-1 && i%2==0)
 {
 printf("*");
 }
 else if(i==j && i%2==0 && j%2==0)
 {
 printf("*");
 }
 else if(i%2==0 && (n-j-1)%2==0 && i==n-j-1)
 {
 printf("*");
 }
 else if(i%2==0 && i>=j && j>n-i-1)
 {
 printf("*");
 }
 else if(j%2==0 && j>i && i>n-j-1)
 {
 printf("*");
 }
 else if (j%2==0 && i>=j && i<=n-j-1)
 {
 printf("*");
 }
 else
 {
 printf(" ");
 }
 }
 printf("\n");
 }
 }
 else
 {
 for (i=1; i<=n; i++)
 {
 for (j=1; j<=n; j++)
 {
 if(i==0 || i==n)
 {
 printf("*");
 }
 else if(j==0 || j==n)
 {
 printf("*");
 }
 else if((i==j || i==n-j+1) && i%2==1 && i<=n/2)
 {
 printf("*");
 }
 else if((i==j || j==n-i+1) && i%2==0 && i>n/2)
 {
 printf("*");
 }
 else if((i>j && i<n-j+1) && j%2==1 && j<n/2)
 {
 printf("*");
 }
 else if((i<j && i>n-j+1) && j%2==0 && j>n/2)
 {
 printf("*");
 }
 else if((j>i && j<n-i+1) && i<n/2 && i%2==1)
 {
 printf("*");
 }
 else if((j<i && j>n-i+1) && i>n/2 && i%2==0)
 {
 printf("*");
 }
 else
 {
 printf(" ");
 }
 }
 printf("\n");
 }
 }
 return 0;
}