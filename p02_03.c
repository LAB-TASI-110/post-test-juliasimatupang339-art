#include <stdio.h>
#include <string.h>

int main() {
    // Definisi data menu
    char menu[5][20] = {"PKL", "Tahu Isi", "Bakwan", "Tempe Goreng", "Roti Isi Ayam"};
    int harga[5] = {15000, 10000, 10000, 10000, 15000};
    
    int pilihan, jumlah, total_harga, metode;
    int bayar, kembalian;

    printf("=== SISTEM KAFETARIA IT DEL ===\n");
    printf("Daftar Menu Hari Ini:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d. %-15s : Rp %d\n", i + 1, menu[i], harga[i]);
    }
    printf("-------------------------------\n");

    // Input Pesanan
    printf("Pilih nomor menu (1-5): ");
    scanf("%d", &pilihan);
    
    // Validasi input menu
    if(pilihan < 1 || pilihan > 5) {
        printf("Pilihan tidak valid!\n");
        return 1;
    }

    printf("Masukkan jumlah porsi: ");
    scanf("%d", &jumlah);

    // Perhitungan
    total_harga = harga[pilihan - 1] * jumlah;
    printf("\nTotal yang harus dibayar: Rp %d\n", total_harga);

    // Metode Pembayaran
    printf("Pilih Metode Pembayaran:\n");
    printf("1. Cash (Tunai)\n");
    printf("2. Transfer E-Banking\n");
    printf("Pilihan (1/2): ");
    scanf("%d", &metode);

    printf("\n===============================\n");
    printf("       STRUK PEMBAYARAN        \n");
    printf("===============================\n");
    printf("Pesanan   : %s\n", menu[pilihan - 1]);
    printf("Jumlah    : %d porsi\n", jumlah);
    printf("Total     : Rp %d\n", total_harga);

    if (metode == 1) {
        printf("Metode    : Cash\n");
        printf("Bayar     : Rp ");
        scanf("%d", &bayar);
        
        if (bayar >= total_harga) {
            kembalian = bayar - total_harga;
            printf("Kembalian : Rp %d\n", kembalian);
        } else {
            printf("Maaf, uang Anda tidak cukup.\n");
        }
    } else if (metode == 2) {
        printf("Metode    : Transfer E-Banking\n");
        printf("Status    : BERHASIL [***]\n");
        printf("Kembalian : Rp 0 (Saldo Pas)\n");
    } else {
        printf("Metode tidak valid.\n");
    }

    printf("===============================\n");
    printf("   Terima Kasih, Horas IT Del! \n");
    printf("===============================\n");

    return 0;
}