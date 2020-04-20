#include <stdio.h>

int main() {
	int D,M;
	printf("Dan: ");
	scanf("%d", &D);
	printf("Mjesec: ");
	scanf("%d", &M);
	if(D<1||D>31){
		printf("Vrijednost dana nije ispravna");
	}
else if (M<1||M>12){
	printf("Vrijednost mjeseca nije ispravna");
}
else {
	if((M==1&&D>=20)||(M==2&&D<=18)){
		printf("Vas znak je Vodolija!");
	}
if((M==2&&D>=19)||(M==3&&D<=20)){
	printf("Vas znak je Ribe!");
}
if((M==3&&D>=21)||(M==4&&D<=19)){
	printf("Vas znak je Ovan!");
}
if((M==4&&D>=20)||(M==5&&D<=20)){
	printf("Vas znak je Bik!");
}
if((M==5&&D>=21)||(M==6&&D<=20)){
	printf("Vas znak je Blizanci!");
}
if((M==6&&D>=21)||(M==7&&D<=22)){
	printf("Vas znak je Ral!");
}
if((M==7&&D>=23)||(M==8&&D<=22)){
	printf("Vas znak je Lav!");
}
if((M==8&&D>=23)||(M==9&&D<=22)){
	printf("Vas znak je Djevica!");
}
if((M==9&&D>=23)||(M==10&&D<=22)){
	printf("Vas znak je Vaga!");
}
if((M==10&&D>=23)||(M==11&&D<=21)){
	printf("Vas znak je Skorpija!");
}
if((M==11&&D>=22)||(M==12&&D<=21)){
	printf("Vas znak je Strijelac!");
}
if((M==12&&D>=22)||(M==1&&D<=19)){
	printf("Vas znak je Jarac!");
}
}
	return 0;
}
