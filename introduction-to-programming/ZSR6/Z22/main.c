#include <stdio.h>

int main(){
    
    int A[100][100],B[100][100];
    int i,j,m,n;
    int a[100],b[100];
    int k=0,c=0;
    int dodjela[100];
    
    printf("Unesi broj redova: ");
    scanf("%d",&m);
    printf("Unesi broj kolona: ");
    scanf("%d",&n);
    
    printf("Unesi matricu A: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    
    printf("Unesi matricu B: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&B[i][j]);
        }
    }
    
    // pretvaranje matrice A u niz a
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            a[k]=A[i][j];
            dodjela[k]=a[k]; // ovjde
            k++;
        }
    }
    int x=k;
    
    // pretvaranje matrice B u niz b
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            b[c]=B[i][j];
            dodjela[x + c]=b[c]; // ovjde izmjena
            c++;
        }
    }
    
    printf("Niz matrica je: ");
    for(i=0;i<x + c;i++){
        printf("%d ",dodjela[i]);
    }
    
    return 0;
}