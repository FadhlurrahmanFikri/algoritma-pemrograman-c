#include <stdio.h>
#include <stdlib.h>


// Banner ATM
void banner() {
    int pilih;
    printf("===================================\n");
    printf("=========  ATM SEDERHANA  =========\n");
    printf("===================================\n");
}

// Struct Data
struct Data {
    int noRek;
    char nama[10];
    int pin;
    int saldo;
};


int main() {
    
    // Seluruh data Rekening
    struct Data rekening[3]= {
        {11, "AAA", 1111, 1000000},
        {22, "BBB", 2222, 2000000},
        {33, "CCC", 3333, 3000000}
    };
    banner();
    
    // Meminta input nomor Rekening
    int inputRekening, inputPin;
    printf("\nMasukkan nomor rekening : ");
    scanf("%d", &inputRekening);

    //Mengecek apakah nomor rekening ada dalam data
    int i, indexLogin = -1;
    for (i=0; i<3; i++) {
        if(inputRekening==rekening[i].noRek) {
            indexLogin = i;
            break; 
        }
    }
    if (indexLogin==-1) {
        printf("\nLogin gagal.");
        printf("\nNomor rekening tidak ditemukan.");
        return 0;
    }

    // Verifikasi PIN
    printf("\nMasukkan PIN : ");
    scanf("%d", &inputPin);
    if (inputPin==rekening[indexLogin].pin) {
        printf("\nNama : %s", rekening[indexLogin].nama);
    } else {
        printf ("\nLogin gagal.");
        printf ("\nPIN Salah.");
        return 0;
    }

    
    
    int pilihanMenu, atmJalan=1;
    while (atmJalan==1) {
        system("cls");
        banner();
        printf("\nNama : %s\n", rekening[indexLogin].nama);

        printf("\n=== MENU ATM ===\n");
        printf("1. Tarik Tunai\n");
        printf("2. Transfer\n");
        printf("3. Setor Tunai\n");
        printf("4. Cek Saldo\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihanMenu);
        
        switch (pilihanMenu) {
        case 1: //Tarik Tunai
            system("cls");
            banner();
            printf("\n=== Tarik Tunai ===\n");
            printf("\n1");
            break;
        case 2: // Transfer
            system("cls");
            banner();
            printf("\n=== Transfer ===\n");
            printf("\n2");
            break;
        case 3: // Setor Tunai
            system("cls");
            banner();
            printf("\n=== Setor Tunai ===\n");
            printf("\n2");
            break;
        case 4: // Cek Saldo
            system("cls");
            banner();
            printf("\n=== Cek Saldo ===\n");
            printf("\n4");
            break;
        default:
            system("cls");
            banner();
            printf("\nPilihan menu tidak Valid");
            break;
        }

        //Mengecek apakah user masih ingin melanjutkan
        // banner();
        printf("\n\nTransaksi lain?");
        printf("\n1. Ya");
        printf("\n2. Tidak");
        printf("\nPilihan: ");
        scanf("%d", &atmJalan);
        // system("cls");
    }

    //Program selesai
    printf("\nTerima kasih telah menggunakan ATM.\n");
    return 0;
}