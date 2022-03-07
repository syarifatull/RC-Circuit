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
    printf("hayo input\n");
    gets(input);					//ceritanya user masukin input 5k/7meg/10m dll

    while(isdigit(input[i])){		//ini buat misahin mana angka mana huruf
        //data*=10;
        temp=&input[i];
        data+=atof(temp);			//kalo udah dapet angka disimpen di variabel data, atof buat ngubah string ke float
        i+=1;						//ini counter buat masuk ke selanjutnya
    }
    printf("data: ", data);
    int awal=i;						//ini i dari while(jumlah angka ada brp di input)
    for(i;i<10;i++){				//inti dari for ini buat bikin variabel namanya satuan
        satuan[i-awal]=input[i];	//satuan ini diisi sama bagian input yang bukan angka(10-i)
    }

//satuan dipake di if else ini buat nentuin dia tuh sebenernya angka brp
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


int main () {
	printf("tes fungsi\n\n");
	parser();
	printf("%f", data);
	return 0;
}
