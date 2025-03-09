#include <stdio.h>

int main(){
    char bestandsNaam[64];
    char tekst[512];

    printf("Geef een naam voor jouw bestand: ");
    fgets(bestandsNaam, sizeof(bestandsNaam), stdin);

    //bestandsNaam[sizeof(bestandsNaam) -1] = '\0';

    printf("Tekst voor in het bestand: ");
    fgets(tekst, sizeof(tekst), stdin);

    FILE *bestand;

    bestand = fopen(bestandsNaam, "w");

    fprintf(bestand, tekst);

    fclose(bestand);

    bestand = fopen(bestandsNaam, "r");

    char opgehaaldeTekst[512];

    fgets(opgehaaldeTekst, sizeof(opgehaaldeTekst), bestand);

    printf("Ingevulde tekst is: %s \n", opgehaaldeTekst);

    return 0;
}