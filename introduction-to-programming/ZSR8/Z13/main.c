#include <stdio.h>
int* istecifre(int* niz, int vel, int* p)
{
	int niz1[1000], niz2[1000],i,vel1,vel2,j,min,temp,flag=0;
	int *p2=niz;
	int *ret=p;
	int tmp1,tmp2,zbir=0,zbir2=0;
	tmp1 = *p;
	i=0;
	while(tmp1!=0) {
		tmp2=tmp1%10;
		niz1[i]=tmp2;
		tmp1=tmp1/10;
		i++;
	}
	vel1=i;


	for (i=0; i<vel1; i++) {
		min=i;
		for (j=i+1; j<vel1; j++)
			if (niz1[j] < niz1[min]) min = j;

		temp = niz1[i];
		niz1[i] = niz1[min];
		niz1[min] = temp;
	}

	while(p2<niz+vel) {
		flag=0;
		tmp2=0;
		tmp1=*p2;
		vel2=0;
		for(i=0; i<100; i++) niz2[i]=0;
		i=0;
		while(tmp1!=0) {
			tmp2=tmp1%10;
			niz2[i]=tmp2;
			tmp1=tmp1/10;
			i++;
		}
		vel2=i;
		for (i=0; i<vel2; i++) {
			min=i;
			for (j=i+1; j<vel2; j++)
				if (niz2[j] < niz2[min]) min = j;

			temp = niz2[i];
			niz2[i] = niz2[min];
			niz2[min] = temp;
		}
			
	//	printf("br%d\n",vel2);

		if(vel1==vel2) {
			flag=1;
			for(i=0; i<vel1; i++){ 
			//	printf("%dA %dB",niz1[i],niz2[i]);
				printf("\n");
				if(niz1[i]!=niz2[i]) flag=0;}
		}
//	printf("%d ff\n",flag);
		if(flag==1 && p2!=p && vel1==vel2) {
		//	printf("%d\n",*p2);
			ret = p2;}
		
		p2++;
	}
	if(ret!=p) return ret;
	return p;
}

int main()
{
	int niz[] = {1, 114, 3, 411, 4, 321, 144, 4141, 441, 6};
	int*p = istecifre(niz, 10, niz+3);
	printf("Broj %d pozicija %d", *p, (int)(p-niz));
	return 0;
}
