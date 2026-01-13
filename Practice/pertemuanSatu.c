#include <stdio.h>

int main () {
    
      // Luas Segitiga
    float alasSegitiga, tinggiSegitiga, luasSegitiga;
    printf("Panjang Alas = ");
    scanf("%f", &alasSegitiga);
    printf("Tinggi Segitiga = ");
    scanf("%f", &tinggiSegitiga);
    luasSegitiga = alasSegitiga*tinggiSegitiga/2;
    printf("Luas segitiga adalah %.1f", luasSegitiga);

    printf("\n\n");
    // Luas Persegi Panjang
    float panjang, lebar, luasPersegiPanjang;
    printf("Panjang = ");
    scanf("%f", &panjang);
    printf("Lebar = ");
    scanf("%f", &lebar);
    luasPersegiPanjang = panjang*lebar;
    printf("Luas Persegi Panjang = %f", luasPersegiPanjang);

    printf("\n\n");
    //Penghitung Penginapan
    float hariMenginap, hargaPerMalam, total;
    printf("Berapa hari = ");
    scanf("%f", &hariMenginap);
    printf("Harga per malam = ");
    scanf("%f", &hargaPerMalam);
    total = hariMenginap*hargaPerMalam;
    printf("Harga Total = RP. %.2f", total);

    return 0;
}

