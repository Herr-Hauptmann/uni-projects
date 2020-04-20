#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void zamijeni_string_ubaci(char* s, const char* pretraga, const char*
zamjena, int pomak) {
 char* pozicija = strstr(s, pretraga);
 while (pozicija) {
 char* kraj = pozicija;
 while (*kraj != '\0') kraj++;
 while (kraj > pozicija) {
 *(kraj+pomak) = *kraj;
 kraj--;
 }
 strcpy(pozicija, zamjena);
 pozicija = strstr(s, pretraga);
 }
 }
 void zamijeni_string_izbaci(char* s, const char* pretraga, const char*
zamjena, int pomak) {
 char* pozicija = strstr(s, pretraga);
 while (pozicija) {
 char* tmp = pozicija;
 while (*tmp != '\0') {
 *tmp = *(tmp+pomak);
 tmp++;
 }
 strcpy(pozicija, zamjena);
 pozicija = strstr(s, pretraga);
 }
 }
 void zamijeni_string(char* s, const char* pretraga, const char* zamjena) {
 int pomak = strlen(zamjena) - strlen(pretraga);
 if (pomak > 0)
 zamijeni_string_ubaci(s, pretraga, zamjena, pomak);
 else
 zamijeni_string_izbaci(s, pretraga, zamjena, -pomak);
 }
 void zamijeni1(char* s) {
 zamijeni_string(s, "1", "jedan");
 }

int main() {
	char string[10000]="Jedan je 1 broj u 11111.";
	zamijeni_string(string,"1","jedan");
	printf("%s", string);
	
	
	return 0;
}