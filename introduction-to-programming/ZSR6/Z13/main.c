#include <stdio.h>

int main() {
	int k = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(j == k){
			for(int r = j; r < 3 - 1; r++) mat[i][r] = mat[i][r + 1];
			k++;
			}
		}
	}
	printf("ZSR 6, Zadatak 13");
	return 0;
}
