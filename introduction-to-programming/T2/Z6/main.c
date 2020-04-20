#include <stdio.h>

int main() {
	float S1,S2,a,b,c,d;
	printf("Unesite brojeve a,b,c,d: ");
	scanf("%f %f %f %f", &a,&b,&c,&d);
	if(a==c&&b==d)
	printf("Skup S1 je sadrzan u skupu S2");
	if (a<c&&b<d&&b<c)
	printf("Skupovi se ne sijeku.");
	if(a>c&&b>d&&a>d)
	printf("Skupovi se ne sijeku.");
	if(a<c&&b>c&&a<d&&b<d)
	printf("Rezultantni interval je [%g,%g].",c,b);
	if(c<a&&b>c&&a<d&&b>d)
	printf("Rezultantni interval je [%g,%g].",a,d);
	if(a>c&&b>c&&a<d&&b<d)
	printf("Rezultantni interval je [%g,%g].",a,b);
    if(c>a&&c<b&&d>a&&d<b)
    printf("Rezultantni interval je [%g,%g].",c,d);
	
	

	
	
	return 0;
}
