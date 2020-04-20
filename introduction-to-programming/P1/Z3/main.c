#include <stdio.h>
void tabela(int brRedova, int brKolona, int sirina){
	
	int i,j;
	for(i=0; i<brRedova*2+1; i++){
		for(j=0; j<brKolona*(sirina+1)+1; j++){
			if(j%(sirina+1)==0){
				if(i%2==1) printf("|");
				else printf("+");
			}
			else{
				if(i%2==1) printf(" ");
			
			else printf("-");
				
			}
		}
		printf("\n");
	}
}
int main() {
	tabela(5,5,5);

	return 0;
}
