#include <stdio.h>
char* IzbaciViskaRazmake(char *Str)
{
    char *p = Str;
    char *p2 = Str;
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            if (*p != *Str) // Not begining
            {
                *p2 = *p; // adding the first ' '
                p2++;
                p++;
            }
            while (*p == ' ') // skipping the rest ' '
            {
                p++;
            }
        }
        else
        {
            *p2 = *p;
            p2++;
            p++;
        }
    }
    if (*(p2 - 1) == ' ') //ends with space
    {
        p2--;
    }
    *p2 = '\0';

    return Str;
}

int main()
{
    char tekst[] = "        volim      OR    je jajajsjaj jjajaj ddd  ";
    IzbaciViskaRazmake(tekst);
    printf("%s", tekst);
    return 0;
}