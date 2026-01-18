#include <stdio.h>

int main() {
    int pin = 123, inputPin;
    int menu;
    int saldo = 1000000; // saldo awal
    int nominal;
    int lanjut = 1;
    int rekTujuan;

    printf("=== SELAMAT DATANG DI ATM ===\n");
    printf("Masukkan PIN: ");
    scanf("%d", &inputPin);

    if (inputPin != pin) {
        printf("PIN salah. Transaksi dibatalkan.\n");
        return 0;
    }

    while (lanjut == 1) { //mulai MENU
        printf("\n=== MENU ATM ===\n");
        printf("1. Tarik Tunai\n");
        printf("2. Transfer\n");
        printf("3. Setor Tunai\n");
        printf("4. Cek Saldo\n");
        printf("Pilih menu (1-4): "); scanf("%d", &menu); 
        printf("\n");

        switch (menu) { 
            case 1: // Tarik tunai
                printf("Masukkan nominal penarikan: ");
                scanf("%d", &nominal);

                if (nominal > saldo) {
                    printf("Saldo tidak mencukupi.\n");
                } else {
                    saldo -= nominal;
                    printf("Transaksi berhasil.\n");
                    printf("Saldo Anda saat ini: Rp. %d\n", saldo);
                }
                break;

            case 2: // Transfer
                printf("Masukkan nomor rekening tujuan: ");
                scanf("%d", &rekTujuan);
                printf("Masukkan nominal transfer: ");
                scanf("%d", &nominal);

                if (nominal > saldo) {
                    printf("Saldo tidak mencukupi.\n");
                } else {
                    saldo -= nominal;
                    printf("Transfer ke rekening %d berhasil.\n", rekTujuan);
                }
                break;

            case 3: // Setor tunai
                printf("Masukkan nominal setoran: ");
                scanf("%d", &nominal);
                saldo += nominal;
                printf("Setor tunai berhasil.\n");
                break;

            case 4: // Cek saldo
                printf("Saldo Anda saat ini: Rp. %d\n", saldo);
                break;

            default:
                printf("Pilihan menu tidak valid.\n");
        }

        printf("\nIngin melakukan transaksi lain?\n");
        printf("1. Ya\n");
        printf("0. Tidak\n");
        printf("Pilihan: ");
        scanf("%d", &lanjut);
    }

    printf("\nTerima kasih telah menggunakan ATM.\n");
    return 0;
}