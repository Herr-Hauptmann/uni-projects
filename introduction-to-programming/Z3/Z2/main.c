#include <stdio.h>
#define EPSILON 0.0001

/* pomocna funkicija za odredjivanje veceg broja */
double max(double x, double y)
{
	return (x - y > EPSILON ) ? x : y;
}


double parallel_max(double* p1, double* p2 )
{
	int r;
	/* ako su pokazivaci susjedni oonda vracamo vrijednost prvog */
	if (p2==(p1+1)) {
		return *p1;
	}
	/* redni broj srednjeg clana niza */
	r=(p2-p1)/2;

	return max(parallel_max(p1,p1+r),parallel_max(p1+r,p2));
}


/* main za provjeru funkcije */
int main()
{
	double niz[10000]= {25, 44, 123.45, 789.4546, 4, 121.11, 100.78};
	double *p;
	double max;
	p = &niz[7];
	max = parallel_max(niz,p);
	printf("%g",max);

	return 0;
}
