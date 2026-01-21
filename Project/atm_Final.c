#include <stdio.h>
#include <stdlib.h> //clear terminal
#include <unistd.h> //sleep


// Banner ATM
void banner() {
    printf("===================================\n");
    printf("=========  ATM SEDERHANA  =========\n");
    printf("===================================\n");
}

void anggotaKelompok() {
    printf("\nProjek Program Bahasa C");
    printf("\n\nKelompok 2");
    printf("\nFadhlurrahman Fikri - 40125308");   
    printf("\nHafiz Izzudin - 40125397"); 
    printf("\nMuhammad Shafa Triyaskhary - 40125731");
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
        {11, "Hafiz", 1111, 1000000},
        {22, "Fikri", 2222, 2000000},
        {33, "Shafa", 3333, 3000000}
    };

    //Untuk Presentasi
    anggotaKelompok();
    sleep(3); 

    system("cls");
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
    //bila login gagal
    if (indexLogin==-1) {
        printf("\nLogin gagal.");
        printf("\nNomor rekening tidak ditemukan.");
        return 0;
    }

    // Verifikasi PIN
    printf("\nMasukkan PIN : ");
    scanf("%d", &inputPin);
    if (inputPin!=rekening[indexLogin].pin) {
        // printf("\nNama : %s", rekening[indexLogin].nama);
        printf ("\nLogin gagal.");
        printf ("\nPIN Salah.");
        return 0;
    } // else {}

    //Variabel menjalankan menu
    int atmJalan=1, pilihanMenu;

    //Variabel Tarik Tunai
    int pilihanTarik, nominalTarik;

    //Variabel Setor Tunai
    int nominalSetor = 0;
    
    //Variabel Transfer
    int rekTujuan, indexTujuan, nominalTransfer;

    //ATM
    while (atmJalan==1) {
        system("cls");
        banner();
        printf("\nNama : %s\n", rekening[indexLogin].nama);

        printf("\n=== MENU ATM ===\n");
        printf("1. Tarik Tunai\n");
        printf("2. Transfer\n");
        printf("3. Setor Tunai\n");
        printf("4. Cek Saldo\n");
        printf("5. Cancel\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihanMenu);
        
        //User memilih transaksi
        switch (pilihanMenu) {

            //Tarik Tunai
            case 1:
                system("cls");
                banner();

                printf("\n=== Tarik Tunai ===\n");
                printf("1. Rp. 50.000\n");
                printf("2. Rp. 100.000\n");
                printf("3. Rp. 250.000\n");
                printf("4. Rp. 500.000\n");
                printf("5. Nominal lain\n");
                printf("Pilih: ");
                scanf("%d", &pilihanTarik);

                nominalTarik = 0;
                switch (pilihanTarik) {
                    case 1: nominalTarik = 50000; break;
                    case 2: nominalTarik = 100000; break;
                    case 3: nominalTarik = 250000; break;
                    case 4: nominalTarik = 500000; break;
                    case 5: //Nominal lain
                        printf("Masukkan nominal (Kelipatan Rp. 50.000): ");
                        scanf("%d", &nominalTarik);

                        //Tidak valid jika nominalTarik=0 atau bukan pecahan 50.000
                        if (nominalTarik <= 0 || nominalTarik % 50000 != 0) {
                            printf("\nNominal tidak valid.");
                            nominalTarik = 0;
                        }
                    break;
                    default:
                        printf("\nPilihan tidak valid.");
                        break;
                }
                // Proses penarikan tunai
                if (nominalTarik > 0) {
                    if (nominalTarik > rekening[indexLogin].saldo) {
                        printf("\nSaldo tidak mencukupi.");
                    } else {
                        rekening[indexLogin].saldo -= nominalTarik;
                        printf("\nPenarikan berhasil.");
                        printf("\nJumlah: Rp. %d", nominalTarik);
                        printf("\nSisa Saldo: Rp. %d", rekening[indexLogin].saldo);
                    }
                }
                break;

            // Transfer
            case 2: 
                system("cls");
                banner();
                printf("\n=== Transfer ===\n");

                printf("\nMasukkan Nomor Rekening Tujuan: ");
                scanf("%d", &rekTujuan);

                // Cari rekening tujuan
                indexTujuan = -1;
                for (i = 0; i < 3; i++) {
                    if (rekTujuan==rekening[i].noRek) {
                        indexTujuan = i;
                        break;
                    }
                }

                // Rekening tujuan tidak ditemukan
                if (indexTujuan == -1) {
                    printf("\nRekening tujuan tidak ditemukan.");
                    break;
                }

                // Tidak boleh transfer ke rekening sendiri
                if (indexTujuan == indexLogin) {
                    printf("\nTidak dapat transfer ke rekening sendiri.");
                    break;
                }

                printf("\nNama Penerima : %s", rekening[indexTujuan].nama);
                printf("\nMasukkan Nominal Transfer: ");
                scanf("%d", &nominalTransfer);

                // Validasi nominal
                if (nominalTransfer <= 0) {
                    printf("\nNominal tidak valid.");
                    nominalTransfer=0;
                    break;
                }

                // Cek saldo
                if (nominalTransfer > rekening[indexLogin].saldo) {
                    printf("\nSaldo tidak mencukupi.");
                    break;
                }

                // Proses transfer
                rekening[indexLogin].saldo -= nominalTransfer;
                rekening[indexTujuan].saldo += nominalTransfer;

                printf("\nTransfer berhasil.");
                printf("\nJumlah Transfer : Rp. %d", nominalTransfer);
                printf("\nSisa Saldo Anda : Rp. %d", rekening[indexLogin].saldo);
                break;
            
            //Setor Tunai
            case 3:
                system("cls");
                banner();
                printf("\n=== Setor Tunai ===\n");
                printf("\nMasukkan nominal Setor (Kelipatan Rp. 50.000): ");
                scanf("%d", &nominalSetor);
                //Hanya bisa setor nominal pecahan 50000
                if (nominalSetor <= 0 || nominalSetor % 50000 != 0){
                    printf("\nNominal tidak valid");
                    nominalSetor = 0;
                } else {
                    printf("\nSetor tunai berhasil.");
                    printf("\nJumlah = Rp. %d", nominalSetor);
                    rekening[indexLogin].saldo+=nominalSetor;
                    printf("\nSaldo anda saat ini: Rp. %d", rekening[indexLogin].saldo);
                }
                break;

            // Cek Saldo
            case 4:
                system("cls");
                banner();
                printf("\n=== Cek Saldo ===\n");
                printf("\nSaldo anda saat ini: Rp. %d", rekening[indexLogin].saldo);
                break;

            //Untuk langsung menyelesaikan ATM
            case 5:
                printf("\nTerima kasih telah menggunakan ATM.\n");
                return 0;

            //Pilihan menu tidak valid
            default:
                system("cls");
                banner();
                printf("\nPilihan menu tidak Valid.");
                break;
        }

        //Mengecek apakah user masih ingin melanjutkan
        printf("\n\nTransaksi lain?");
        printf("\n1. Ya");
        printf("\n2. Tidak");
        printf("\nPilihan: ");
        scanf("%d", &atmJalan);
    }

    //Program selesai
    printf("\nTerima kasih telah menggunakan ATM.\n");
    return 0;
}