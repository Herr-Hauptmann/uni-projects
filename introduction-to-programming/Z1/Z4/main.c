#include <stdio.h>

int main() {
	int x1,y2,xp,yp,m,n,b,M=0;
	printf("Unesite brojeve x1 y2 xp i yp: ");
	double k1,n1,k2,n2,x
	scanf("%d %d %d %d",&x1, &y2, &xp, &yp);
	printf("Unesite n i m: ");
	scanf("%d %d", &n, &m);
	if((xp==0&&yp==0)||(xp==m&&yp==0)||(xp==0&&yp==n)||(xp==m&&yp==n)){
		printf("-1 %d",M);
		return 0;
	}
	else { 
		k1=(xp-x1)/(yp-y1);
		n1=y1-k1*x1;
		k2=-k1;
		n2=yp-k2*xp;
		
		if(k1==k2&&n1==n2){
			M=1;
			printf("0 %D",M);
			return 0;
			}
		else if{
				
				// prvi slučaj y=0
				x=-n2/k2;
				y=0;
				if((x<m)&&(y==0))
				countinue;
				
				
			}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	

	
	return 0;
}
