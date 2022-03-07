COORD coord = {0, 0};
void gotoxy(int x, int y) // mengatur kursor agar dapat dipindahkan dengan nilai x & y tertentu
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void box()
{
    int i;
   for(i=3;i<=79;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
		gotoxy(78,45);
		printf("%c",219);
		gotoxy(i,45);
		printf("%c",219);
	}

	for(i=3;i<=45;i++)
	{
		gotoxy(3,i);
		printf("%c",219);
		gotoxy(79,i);
		printf("%c",219);
	}
}

//============================ box for label ==========
void lbox() // frame / kotak untuk judul / header tiap menu / sub-menu
{
	int i;
	gotoxy(8,3);
	printf("%c",201);
	for(i=9;i<38;i++)
	{
		gotoxy(i,3);
		printf("%c",205);
	}
	gotoxy(38,3);
	printf("%c",187);
	gotoxy(8,4);
	for(i=4;i<7;i++)
	{
		gotoxy(8,i);
		printf("%c",186);
	}
	gotoxy(25,7);
	printf("%c",200);
	for(i=9;i<38;i++)
	{
		gotoxy(i,7);
		printf("%c",205);
	}
	gotoxy(38,7);
	printf("%c",188);
	gotoxy(38,3);
	for(i=4;i<7;i++)
	{
		gotoxy(38,i);
		printf("%c",186);
	}

}

//============================cetak rangkaian ===============

void cetak_rangkaian(){
    int i;
    gotoxy(10, 5);
    printf("R A N G K A I A N    R - C");

    gotoxy(41,13);
    printf("V2");
    gotoxy(5, 12);
    printf("V1");

    for (i=10 ; i<30 ; i++){
        gotoxy(i, 11);
        printf("%c", 95);
    }
    for (i=12;i<18;i++){
        gotoxy(31, i);
        printf("%c", 124);
    }
    gotoxy(30,18);
    printf("%c", 92);
    gotoxy(32,18);
    printf("%c", 47);
    gotoxy(20,12);
    printf("I");

    gotoxy(40, 9);
    for (i=9; i<21; i++)
    {
        gotoxy(40, i);
        printf("%c", 124);
    }

    gotoxy(8, 20);
    for (i = 8; i < 20; i++)
    {
        gotoxy(i, 20);
        printf("%c", 95);
    }

//============================cetak kapasitor ===================
    gotoxy(21, 18);
    printf("C");
    for (i=19; i<22; i++)
    {
        gotoxy(20, i);
        printf("%c", 124);
    }

    for (i=19; i<22; i++)
    {
        gotoxy(22, i);
        printf("%c", 124);
    }
//===============================================================
    gotoxy(23, 20);
    for (i = 23; i < 40; i++)
    {
        gotoxy(i, 20);
        printf("%c", 95);
    }

    gotoxy(8, 9);
    for (i=9; i<15; i++)
    {
        gotoxy(8, i);
        printf("%c", 124);
    }

    for (i=16; i<21; i++)
    {
        gotoxy(8, i);
        printf("%c", 124);
    }
//============================cetak sumber tegangan ===============
    for (i = 6; i < 11; i++)
    {
        gotoxy(i, 14);
        printf("%c", 95);
    }
    for (i = 7; i < 10; i++)
    {
        gotoxy(i, 15);
        printf("%c", 95);
    }
//===================================================================
    gotoxy(8, 8);
    for (i=8; i<14; i++)
    {
        gotoxy(8, i);
        printf("%c", 124);
    }

    for (i = 8; i < 19; i++)
    {
        gotoxy(i, 8);
        printf("%c", 95);
    }
//=========================Cetak resistor 1===============================
    gotoxy(21, 9);
    printf("R1");
    for (i = 19; i < 25; i++)
    {
        if (i%2 == 1)
            {
            gotoxy(i, 8);
            printf("%c", 47);
            }
        else
            {
            gotoxy(i, 8);
            printf("%c", 92);
            }
    }
//===================================================================
    for (i = 25; i < 40; i++)
    {
        gotoxy(i, 8);
        printf("%c", 95);
    }
//===================================================================

}
