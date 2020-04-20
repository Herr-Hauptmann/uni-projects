#include <stdio.h>



int is_prost(int x)
{
	int i;
	int flag=1;
	for(i=2; i<x; i++) {
		if(x%i==0) flag=0;
	}
	return flag;
}

int	daj_prost()
{
	int i;
	static int prost = 1;
	for(i=prost; i<100000; i++) {
		if(is_prost(i)) break;
	}
	prost = i;
	return i;
}

int main()
{
	int a,b,i,Suma,temp=0;
	printf("Unesite brojeve A i B: \n");
	do {
		scanf("%d %d",&a,&b);
		if(a>b || a<0 || b<0) {
			if(a>=b)printf("A nije manje od B.");
			if(a<0) printf("A nije prirodan broj.");
			if(b<0) printf("B nije prirodan broj.");
			continue;
		} else break;
	} while(a>=b || a<0 || b<0);


	do {
		temp=daj_prost();
		if(temp > a && temp < b ) Suma+=temp;

	} while(temp<b);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,Suma);
	return 0;
}
