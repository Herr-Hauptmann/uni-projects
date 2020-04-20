#include <stdio.h>
int Periodican(const char *string){

    int vel=0;
    char *kraj=string;

    while(*kraj!='\0')kraj++;
    vel=kraj-string;
    int i=0;

    for(i=1;i<vel;i++){//gledam za svako moguce i ako je periodican
        char *pom=string;

        while(*(pom+i)!='\0'){
            if(*pom!=*(pom+i))break;//gledam ako je trenutni isto kao trenutni +i
            pom++;
        }
        if(*(pom+i)=='\0')return i;//i ako jeste onda vrati to i(da je trebalo vratit zadnje i, onda se mogla
                                                                 //obrnnuti i petlja da ide unazad

    }
    return 0;

}
int main()
{
	char a[] = "ababab", b[] = "abcabca", c[]="DanasDanasDa";
	printf("%d", Periodican(a));
	return 0;
}
