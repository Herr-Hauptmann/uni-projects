#include <stdio.h>
typedef struct {
	double x, y, z;
} Vektor3d;

Vektor3d vektorski_proizvod(Vektor3d v1, Vektor3d v2){
	Vektor3d ret;
	ret.x = v1.y*v2.z-v1.z*v2.y;
	ret.y = v1.z*v2.x - v1.x*v2.z;
	ret.z = v1.x*v2.y - v1.y*v2.x;
	return ret;
}
int main() {
	printf("ZSR 11, Zadatak 9");
	return 0;
}
