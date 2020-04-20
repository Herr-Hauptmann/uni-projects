#include <stdio.h>


char* ukloni_komentare(char *string)
{
    char* p = string;
    while(*p!='\0') {
        if(*p=='/' && *(p+1)=='*') {
            char* k = p;
            char* j=p+2;
            while (*j!='*' && *(j+1)!='/' && *j!='\0') j++;
            if(*j =='*') {
                j=j+2;
                printf("\nOVO %c",*j);
                while(*j!='\0') {
                    *k++=*j++;
                }
                *k='\0';
                p--;
            }
        }

        if(*p!='\0' && *p=='/' && *(p+1)=='/') {
            char* k = p;
            char* j = p+2;
            while(*j!='\0') {
                if(*j=='\n') break;
                j++;
            }

            while(*j!='\0') {
                *k++=*j++;
            }
            *k='\0';
        }


        p++;
    }
    return string;

}

int main()
{
    char recenica[100]="aa* /****/ * /**/ * /*/*/ bb";

    /*Ispis promijenjene recenice*/
    printf("\nRecenica: %s",ukloni_komentare(recenica));
    return 0;
}
