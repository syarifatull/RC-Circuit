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
//#include"fungsi.h"

kap C;
res R1;
vol_source v;
current_source i;
char input[10];
float t, data;

float parser(){
    int i=0;
    char* temp;
    char satuan[10];
    float data=0;

    while(isdigit(input[i])){
        //data*=10;
        temp=&input[i];
        data+=atof(temp);
        i+=1;
    }
    int awal=i;
    for(i;i<10;i++){
        satuan[i-awal]=input[i];
    }

    if(strncmp(satuan,"meg",3)==0 || strncmp(satuan,"Meg",3)==0){
        return data*1000000;
    }
    else if(input[awal]=='m' || input[awal]=='M'){
        return data/1000;
    }
    else if(input[awal]=='k' || input[awal]=='K'){
        return data*1000;
    }
    else if(input[awal]=='u' || input[awal]=='U'){
        return data/1000000;
    }
    else{
        return data;
    }
}


void netlist (int pilih_rangkaian){
    box();
    gotoxy(20,5);
    printf("NETLIST");


  if(pilih_rangkaian==1){
    gotoxy(8,6);
    printf("Masukkan Resistansi R1 (ohm) : ");
    scanf("%s", &input);
    R1.res=parser();

    gotoxy(8,7);
    printf("Masukkan Kapasitansi C (Farad): ");
    scanf("%s", &input);
    C.cap=parser();

    gotoxy(8,8);
    printf("Masukkan Tegangan Awal Kapasitor C (volt) : ");
    scanf("%s", &input);
    C.init_value=parser();
		// menerima masukan komponen - komponen yang diperlukan dalam nodal analysis
  }
  else if(pilih_rangkaian==2){
    gotoxy(8,6);
    printf("Masukkan Resistansi R1 (ohm) : ");
    scanf("%s", &input);
    R1.res=parser();

    gotoxy(8,7);
    printf("Masukkan Kapasitansi C (Farad) : ");
    scanf("%s", &input);
    C.cap=parser();

    gotoxy(8,8);
    printf("Masukkan Tegangan Awal Kapasitor C (volt) : ");
    scanf("%s", &input);
    C.init_value=parser();

    gotoxy(8,9);
    printf("Masukkan Nilai Sumber Tegangan DC (volt) : ");
    scanf("%s", &input);
    v.dc_voltage=parser();
  }
    gotoxy(5, 18);
    printf("Press any button to continue");
    getch();
}

int main () {
    int pilih_rangkaian=2;
    printf("\n*******************************T E S     F U N G S I*******************************\n\n");
    netlist(pilih_rangkaian);
    printf("\n\n\tR = %f\n", R1.res);
    printf("\tC = %f\n", C.cap);
    printf("\tVc = %f\n", C.init_value);
    printf("\tV sumber = %f\n", v.dc_voltage);
	return 0;
}
