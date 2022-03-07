// Tugas Besar Pemecahan Masalah dengan C (EL2208)
/* Anggota kelompok 16:
1. Jonathan Salomo (18318045)
2. Rifda Almira F (18318043)
3. Dismas Widyanto (13218065)
4. Dzaky Fachrezi (18318040)
5. Syarifatul Lathifah (18318016)
*/

// Simulasi Rangkaian RC

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<direct.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include"datatype.h"
#include"box.h"
#include"fungsi.h"

int main(){

    int pilih_rangkaian;

    cetak_rangkaian();
    lbox();
    box();
    gotoxy(5, 23);

    printf("Pilih Rangkaian yang akan disimulasikan\n");

    gotoxy(5, 24);
    printf("1. Rangkaian RC tanpa sumber\n");

    gotoxy(5, 25);
    printf("2. Rangkaian RC dengan sumber DC\n");

    gotoxy(10, 26);
    scanf("%d",&pilih_rangkaian);

    system("cls");

    netlist(pilih_rangkaian);
    system("cls");

    solve(pilih_rangkaian);

    gotoxy(10,50);
    return 0;
}




