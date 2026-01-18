#include <stdio.h>

struct Rekening {
    int noRek;
    int pin;
    int saldo;
};

int main() {
    struct Rekening data[3] = {
        {1111, 1234, 1000000},
        {2222, 2345, 2000000},
        {3333, 3456, 1500000}
    };

    int noRek, pin;
    int i, idx = -1;
    int menu, nominal, lanjut = 1;
    int rekTujuan;

    printf("Masukkan nomor rekening: ");
    scanf("%d", &noRek);
    printf("Masukkan PIN: ");
    scanf("%d", &pin);

    // Proses login
    for (i = 0; i < 3; i++) {
        if (data[i].noRek == noRek && data[i].pin == pin) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Login gagal. Nomor rekening atau PIN salah.\n");
        return 0;
    }

    // Menu ATM
    while (lanjut == 1) {
        printf("\n=== MENU ATM ===\n");
        printf("1. Tarik Tunai\n");
        printf("2. Transfer\n");
        printf("3. Setor Tunai\n");
        printf("4. Cek Saldo\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Masukkan nominal tarik tunai: ");
                scanf("%d", &nominal);
                if (nominal > data[idx].saldo) {
                    printf("Saldo tidak mencukupi.\n");
                } else {
                    data[idx].saldo -= nominal;
                    printf("Tarik tunai berhasil.\n");
                }
                break;

            case 2:
                printf("Masukkan rekening tujuan: ");
                scanf("%d", &rekTujuan);
                printf("Masukkan nominal transfer: ");
                scanf("%d", &nominal);

                if (nominal > data[idx].saldo) {
                    printf("Saldo tidak mencukupi.\n");
                } else {
                    for (i = 0; i < 3; i++) {
                        if (data[i].noRek == rekTujuan) {
                            data[i].saldo += nominal;
                            data[idx].saldo -= nominal;
                            printf("Transfer berhasil.\n");
                            break;
                        }
                    }
                }
                break;

            case 3:
                printf("Masukkan nominal setoran: ");
                scanf("%d", &nominal);
                data[idx].saldo += nominal;
                printf("Setor tunai berhasil.\n");
                break;

            case 4:
                printf("Saldo Anda: Rp %d\n", data[idx].saldo);
                break;

            default:
                printf("Menu tidak valid.\n");
        }

        printf("\nTransaksi lain? (1=Ya, 0=Tidak): ");
        scanf("%d", &lanjut);
    }

    printf("\nTerima kasih telah menggunakan ATM.\n");
    return 0;
}
