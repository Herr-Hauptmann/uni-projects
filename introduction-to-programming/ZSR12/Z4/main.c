#include <stdio.h>
void ispisi_mat(int mat[][7], int br_redova){
	int (*p)[7] = mat;
	int i = 0, j = 0;
	for(i = 0; i < br_redova; i++){
	for(j = 0; j < 7; j++){ 
	printf("%d",**p++);
	;
	} 
	p++;
	printf("\n");
	}
}

int main() {
	int mat[2][7] = { {1,2,3,4,5,6,7}, {1,2,3,4,5,6,7}};
	ispisi_mat(mat,2);
	printf("\n\n\n");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 7; j++) printf("%d",mat[i][j]);
		printf("\n");
	}
	return 0;
}
