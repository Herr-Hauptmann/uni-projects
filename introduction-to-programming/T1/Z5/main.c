#include <stdio.h>

int main()
{
	float VT,MT,cijenaVT,cijenaMT,racun,ukupna;
	printf("Unesite VT: \n");
	scanf("%f",&VT);
	printf("Unesite MT: \n");
	scanf("%f",&MT);
	printf("Unesite cijenu VT: \n");
	scanf("%f",&cijenaVT);
	printf("Unesite cijenu MT: \n");
	scanf("%f",&cijenaMT);
	ukupna = VT + MT;
	printf("Ukupna potrosnja je %.2f kWh.\n",ukupna);
	printf("Udio veike tarife u ukupnoj potrosnji je %.f%%.\n",VT/ukupna*100);
	printf("Udio male tarife u ukupnoj potrosnji je %.f%%.\n",MT/ukupna*100);
	racun = VT*cijenaVT + MT*cijenaMT;
	printf("Iznos racuna je %.2f KM.",racun);



	return 0;
}
