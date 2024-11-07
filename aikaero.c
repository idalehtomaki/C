#include <stdio.h>
#include <math.h>

int muutaSekunneiksi(int, int, int);
int laskeAikaero(int, int);

int main(int argc, char *argv[]) {

    int tunnit = 0;
    int minuutit = 0;
    int sekunnit = 0;

    printf("Anna eka aika: ");
    printf("tunnit: ");
    scanf("%d", &tunnit);
    printf("minuutit: ");
    scanf("%d", &minuutit);
    printf("sekunnit: ");
    scanf("%d", &sekunnit);
    int sekunnit1 = muutaSekunneiksi(tunnit, minuutit, sekunnit);

    printf("Anna toka aika: ");
    printf("tunnit: ");
    scanf("%d", &tunnit);
    printf("minuutit: ");
    scanf("%d", &minuutit);
    printf("sekunnit: ");
    scanf("%d", &sekunnit);
    int sekunnit2 = muutaSekunneiksi(tunnit, minuutit, sekunnit);
    
    // muutos takaisin tunneiksi, minuuteiksi ja sekunneiksi
    int aikaero = laskeAikaero(sekunnit1, sekunnit2);
    int og_aikaero = aikaero;
    double temp = aikaero / 3600; // tunnissa on 3600 sekuntia
    if (temp >= 1) {
        tunnit = (int)(temp);
        aikaero -= tunnit * 3600;
    } else {
        tunnit = 0;
    }
    temp = aikaero / 60;
    if (temp >= 1) {
        minuutit = (int)(temp);
        aikaero -= minuutit * 60;
    } else {
        minuutit = 0;
    } 
    sekunnit = aikaero;

    printf("Aikaero on: %d sekuntia\n", og_aikaero);
    printf("Aika on %d tuntia %d minuuttia %d sekuntia", tunnit, minuutit, sekunnit);

    return 0;
}

int muutaSekunneiksi(int h, int min, int sec) {

    int sekunnit = h * pow(60, 2) + min * 60 + sec;
    return sekunnit;
}

int laskeAikaero(int sec1, int sec2) {
 
    int aikaero = 0;

    if (sec1 > sec2) {
        aikaero = sec1 - sec2;
    } else {
        aikaero = sec2 - sec1;
    }
    return aikaero;
}
