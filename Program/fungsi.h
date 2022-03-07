kap C;
res R1;
vol_source v;
current_source i;
char input[10];
float t;

float parser(){
    int i=0;
    char* temp;
    char satuan[10];
    float data=0;

    temp=&input[i];
    data+=atof(temp);
    while(isdigit(input[i])){
        //data*=10;
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
    system("cls");
}

void solve (int pilih_rangkaian){
// menyajikan nilai - nilai komponen dalam matriks (?)
// melakukan penghitungan tegangan & arus menggunakan matriks
  lbox();
  box();
  gotoxy(15, 5);
  printf("S O L U S I");
  gotoxy(6,10);
  printf("Masukkan waktu yang diinginkan (t) : ");
  scanf("%s", &input);
  t=parser();

  if(pilih_rangkaian==1){
    float v, i; // tegangan dan arus
    float w=C.cap*R1.res; // konstanta waktu

    v=C.init_value*exp(-t/w);
    i=C.init_value*exp(-t/w)/w;

    gotoxy(6,11);
    printf("V= %.8f V\n",v);
    gotoxy(6,12);
    printf("I= %.8f A",i);
  }
  else if(pilih_rangkaian==2){
    float v1,v2, i,eksponen,selisih;
    float w=C.cap*R1.res; // konstanta waktu

    v1=v.dc_voltage;

    selisih=v.dc_voltage-C.init_value;
    eksponen=selisih*exp(-t/w);
    v2=v.dc_voltage-eksponen;
    i=eksponen/w;

    gotoxy(6,11);
    printf("V1= %.8f V\n",v1); // tegangan sumber
    gotoxy(6,12);
    printf("V2= %.8f V\n",v2); // beda tegangan pada kapasitor
    gotoxy(6,13);
    printf("I= %.8f A",i);
  }
}

