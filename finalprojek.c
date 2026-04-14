#include <mega8535.h>
#include <delay.h>

// Definisi macro pin
#define U_Merah  PORTC.0
#define U_Kuning PORTC.1
#define U_Hijau  PORTC.2

#define S_Merah  PORTC.3
#define S_Kuning PORTC.4
#define S_Hijau  PORTC.5

#define T_Merah  PORTD.0
#define T_Kuning PORTD.1
#define T_Hijau  PORTD.2

#define B_Merah  PORTD.3
#define B_Kuning PORTD.4
#define B_Hijau  PORTD.5

// Matikan semua lampu
void mati_semua() {
    PORTC = 0x00;
    PORTD = 0x00;
}

// Nyalakan hijau satu arah, lainnya merah
void nyalakan_arah(char arah) {
    mati_semua();

    switch (arah) {
        case 'U':
            U_Hijau = 1;
            S_Merah = T_Merah = B_Merah = 1;
            break;
        case 'S':
            S_Hijau = 1;
            U_Merah = T_Merah = B_Merah = 1;
            break;
        case 'T':
            T_Hijau = 1;
            U_Merah = S_Merah = B_Merah = 1;
            break;
        case 'B':
            B_Hijau = 1;
            U_Merah = S_Merah = T_Merah = 1;
            break;
    }
}

// Nyalakan kuning transisi
void transisi_kuning(char arah) {
    switch (arah) {
        case 'U':
            U_Hijau = 0;
            U_Kuning = 1;
            break;
        case 'S':
            S_Hijau = 0;
            S_Kuning = 1;
            break;
        case 'T':
            T_Hijau = 0;
            T_Kuning = 1;
            break;
        case 'B':
            B_Hijau = 0;
            B_Kuning = 1;
            break;
    }
    delay_ms(2000); // 2 detik transisi kuning
}

void main(void) {
    DDRC = 0xFF; // Set PORTC output
    DDRD = 0xFF; // Set PORTD output

    while (1) {
        nyalakan_arah('U');
        delay_ms(5000); // Hijau Utara
        transisi_kuning('U');

        nyalakan_arah('S');
        delay_ms(5000);
        transisi_kuning('S');

        nyalakan_arah('T');
        delay_ms(5000);
        transisi_kuning('T');

        nyalakan_arah('B');
        delay_ms(5000);
        transisi_kuning('B');
    }
}
