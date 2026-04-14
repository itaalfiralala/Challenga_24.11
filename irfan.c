#include <mega8535.h>
#include <delay.h>

// === UTARA dan SELATAN (PORTA) ===
sbit U_Merah  = PORTA.0;
sbit U_Kuning = PORTA.1;
sbit U_Hijau  = PORTA.2;

sbit S_Merah  = PORTA.3;
sbit S_Kuning = PORTA.4;
sbit S_Hijau  = PORTA.5;

// === TIMUR dan BARAT (PORTC) ===
sbit T_Merah  = PORTC.0;
sbit T_Kuning = PORTC.1;
sbit T_Hijau  = PORTC.2;

sbit B_Merah  = PORTC.3;
sbit B_Kuning = PORTC.4;
sbit B_Hijau  = PORTC.5;

// ==== MATIKAN SEMUA ====
void mati_semua() {
    U_Merah = U_Kuning = U_Hijau = 0;
    S_Merah = S_Kuning = S_Hijau = 0;
    T_Merah = T_Kuning = T_Hijau = 0;
    B_Merah = B_Kuning = B_Hijau = 0;
}

// ==== NYALAKAN ARAH AKTIF HIJAU, LAINNYA MERAH ====
void nyalakan_arah(char arah) {
    // Semua lampu merah dulu
    U_Merah = S_Merah = T_Merah = B_Merah = 1;
    U_Hijau = S_Hijau = T_Hijau = B_Hijau = 0;
    U_Kuning = S_Kuning = T_Kuning = B_Kuning = 0;

    switch (arah) {
        case 'U':
            U_Merah = 0;
            U_Hijau = 1;
            break;
        case 'S':
            S_Merah = 0;
            S_Hijau = 1;
            break;
        case 'T':
            T_Merah = 0;
            T_Hijau = 1;
            break;
        case 'B':
            B_Merah = 0;
            B_Hijau = 1;
            break;
    }
}

// ==== TRANSISI KUNING ====
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
    delay_ms(2000);  // Kuning 2 detik
}

// ==== PROGRAM UTAMA ====
void main(void) {
    // Konfigurasi: PORTA & PORTC sebagai output
    DDRA = 0xFF; // Untuk Utara & Selatan
    DDRC = 0xFF; // Untuk Timur & Barat

    // Opsional: PORTB sebagai input tombol pedestrian
    DDRB = 0x00;

    // Semua lampu mati dulu
    mati_semua();

    while (1) {
        nyalakan_arah('U');
        delay_ms(5000);
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
