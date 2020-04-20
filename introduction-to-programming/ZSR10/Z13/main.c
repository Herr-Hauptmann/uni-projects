#include <stdio.h>

int je_li_slovo(char c)
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))  
	{
		return 1;
	}
	else return 0;
}

char* izbaci_najcescu(char* s)
{
	char *poc = s;
	int razmak = 1, rijec = 0;
	char mat[100][100]; 
	char izbaci_rijec[100];
	int i = 0, br = 0, j = 0, k = 0 , max = 0, index;
	int brojevi[100], histogram[100] = {0};
	
	while(*s != '\0')
	{
		if(je_li_slovo(*s) == 0)
		{
			razmak = 1;
		}
		
		else if(razmak == 1)
		{
			br=0;
			while(je_li_slovo(*s) != 0)
			{
				mat[i][br] = *s;
				br++;
				s++;
			}
			mat[i][br] = '\0';
			brojevi[i]=br;
			
			s--;
			rijec++;
			razmak=0;
			i++;
		}
		s++;
	}
	int vel = i;
	
	for(k = 0; k < vel; k++)
	{
		for(i = k; i < vel; i++)
		{
			br=0;
			for(j = 0; j < brojevi[k]; j++)
			{
				if(mat[k][j] == mat[i][j]) 
				{
					br++;
				}
			}
			
			if(br == brojevi[k]) 
			{
				histogram[k]++;
			}
		}
	}
	
	for(i = 0; i < vel; i++)
	{
		if(histogram[i] > max) 
		{
			max = histogram[i];
			index = i;
		}
	}
	
	for(i = 0; i < brojevi[index]; i++)
	{
		izbaci_rijec[i] = mat[index][i];
	}
		
	for(i = 0; i < brojevi[index]; i++)
	{
		printf("%c",izbaci_rijec[i]);
	}	
		
	return poc;
}


int main() {
	char s[50] = "Ja zovem Isam Isam Isam zovem Isam.";
	izbaci_najcescu(s);
	return 0;
}
