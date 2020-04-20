#include <stdio.h>
#include <math.h>

int main() {
	float x1,x2,y1,y2,z1,z2,t1,t2,d;
	
	printf("Unesite koordinate prve tacke x1,y1,z1");
	scanf("%f,%f,%f",&x1,&y1,&z1);
	printf("Unesite koordinate druge tacke x2,y2,z2");
	scanf("%f,%f,%f",&x2,&y2,&z2);
	d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
	printf("Udaljenost izmedju tacaka u 3D prostoru je %f",d);
	


	
	return 0;
}
