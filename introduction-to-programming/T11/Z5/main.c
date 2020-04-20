#include <stdio.h>
#include <math.h>
#include <stdlib.h>
	struct Vrijeme {
        int sati;
        int minute;
        int sekunde;
    };

struct Vrijeme unos_Vremena() {
       struct Vrijeme v;
       scanf("%d %d %d",&v.sati,&v.minute,&v.sekunde);
       return v;
       }
       
 struct Vrijeme proteklo(struct Vrijeme v1, struct Vrijeme v2){
 	struct Vrijeme temp;
 	temp.sati=0;
 	temp.minute=0;
 	int uk1 = v1.sekunde + v1.minute*60 + v1.sati*3600;
 	int uk2 = v2.sekunde + v2.minute*60 + v2.sati*3600;
 	int res= abs(uk1-uk2);
 	while(res>=3600){
 		temp.sati++;
 		res-=3600;
 		}
 	while(res>=60){
 		temp.minute++;
 		res-=60;
 	}	
	temp.sekunde=res;
 	
 	return temp;
 }      


int main() {
	struct Vrijeme v1;
	struct Vrijeme v2;
	printf("Unesite prvo vrijeme (h m s): \n");
	v1=unos_Vremena();
	printf("Unesite drugo vrijeme (h m s): \n");
	v2=unos_Vremena();
	struct Vrijeme p = proteklo(v1,v2);
	printf("Izmedju dva vremena je proteklo %d sati, %d minuta i %d sekundi.",p.sati,p.minute,p.sekunde);
	
	


	return 0;
}
