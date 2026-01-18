#include <stdio.h>
#include <stdlib.h>


// Banner ATM
void banner() {
    int pilih;
    printf("===================================\n");
    printf("=========  ATM SEDERHANA  =========\n");
    printf("===================================\n\n");
}

// Struct Data
struct Data {
    int noRek;
    char nama[10];
    int pin;
    int saldo;
};


int main() {
    
    
    struct Data rekening[3]= {
        {11, "aaa", 1111, 1000000},
        {22, "bbb", 2222, 2000000},
        {33, "ccc", 3333, 3000000}
    };
    
    banner();
    
    int inputRekening;
    printf("Masukkan nomor rekening : ");
    scanf("%d", &inputRekening);

    int i;
    for (i=0; i<3; i++) {
        if(inputRekening==rekening[i].noRek) {
        } 
        else {
            printf("Nomor rekening tidak ditemukan");
            break;
            return 0;
        }

    }

    return 0;
}