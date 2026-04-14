#include <mega8535.h>
#include <delay.h>


// Definisi macro untuk pin
#define U_Merah PORTC.0
#define U_Kuning PORTC.1
#define U_Hijau PORTC.2


#define S_Merah PORTC.3
#define S_Kuning PORTC.4
#define S_Hijau PORTC.5



#define T_Merah PORTD.0
#define T_Kuning PORTD.1
#define T_Hijau PORTD.2



#define B_Merah PORTD.3
#define B_Kuning PORTD.4
#define B_Hijau PORTD.5


void mati_semua() {
    PORTC = 0x00;
    PORTD = 0x00;
}



void nyalakan_arah(
    char *arah // 'U', 'S', 'T', 'B'
) {
    mati_semua();

    if (*arah == 'U') {
        // Utara hijau, lainnya merah
        U_Hijau = 1;
        S_Merah = 1;
        T_Merah = 1;
        B_Merah = 1;
    }
    else if (*arah == 'S') {
        S_Hijau = 1;
        U_Merah = 1;
        T_Merah = 1;
        B_Merah = 1;
    }
    else if (*arah == 'T') {
        T_Hijau = 1;
        U_Merah = 1;
        S_Merah = 1;
        B_Merah = 1;
    }
    else if (*arah == 'B') {
        B_Hijau = 1;
        U_Merah = 1;
        S_Merah = 1;
        T_Merah = 1;
    }
}

void transisi_kuning(char *arah) {
    if (*arah == 'U') {
        U_Hijau = 0;
        U_Kuning = 1;
        delay_ms(200); // Kuning Utara 5 detik
        U_Kuning = 0;
    }
    else if (*arah == 'S') {
        S_Hijau = 0;
        S_Kuning = 1;
        delay_ms(200); // Kuning Selatan 5 detik
        S_Kuning = 0;
    }
    else if (*arah == 'T') {
        T_Hijau = 0;
        T_Kuning = 1;
        delay_ms(200); // Kuning Timur 5 detik
        T_Kuning = 0;
    }
    else if (*arah == 'B') {
        B_Hijau = 0;
        B_Kuning = 1;
        delay_ms(200); // Kuning Barat 5 detik
        B_Kuning = 0;
    }
}

void main(void) {
    // Set PORTC dan PORTD sebagai output
    DDRC = 0xFF;
    DDRD = 0xFF;

    while (1) {
        // Urutan nyala: Utara -> Selatan -> Timur -> Barat

        nyalakan_arah("U");
        delay_ms(400); // Hijau Utara 10 detik
        transisi_kuning("U");

        nyalakan_arah("S");
        delay_ms(400); // Hijau Selatan 10 detik
        transisi_kuning("S");

        nyalakan_arah("T");
        delay_ms(400); // Hijau Timur 10 detik
        transisi_kuning("T");

        nyalakan_arah("B");
        delay_ms(400); // Hijau Barat 10 detik
        transisi_kuning("B");
    }
}