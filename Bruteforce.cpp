#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAX 100

void gotoxy(short x, short y){
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setConsolColor(/* you can add some parameter here*/){ //added (This will set color of text and background)
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //this method is recommendated for changing color
}

void myFlush(){ //Flush stdin //added
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //added //this is also recommendated
    // do not using fflush(stdin) btw, some people said that if fflush(stdin) is not safe
}

//Function Prototype
void prima(),bsort(),kalimatriks(),menuBF();
int bruteForce();

main(){
	setConsolColor(); //set color
    start: //if not can do other way, do not using goto
        system("cls");
        system("title Menu Penerapan Algoritma Bruteforce");
        int x;

        printf("\n \t Algoritma Brute Force\n");
        printf("\n ===================================== \n");
        printf("\n \t 1. Matching String");
        printf("\n \t 2. Soting Bilangan");
        printf("\n \t 3. Perkalian Matriks");
        printf("\n \t 4. Exit");
        printf("\n ===================================== \n");
        printf("\n Masukan Pilhan (1-4) : ");
        scanf("%d", &x);
        switch(x){
            case 1 	: menuBF();
                    goto start;
            case 2 	: bsort();
                    goto start;
            case 3 	: kalimatriks();
                    goto start;
            case 4 	: system("cls");
                    return 0;
            default : printf("\n \n \n \t \t \t Anda salah memasukan Input");
            printf("\n \t \t Program Akan Direstart Setelah Anda menekan Enter");
            getch();
            goto start;
	}
}

void prima(){
    system("cls");
	system("title Pencarian Bilangan Prima");
	int bil,j;
	printf("\t\t\t Pencarian bilangan Prima\n\n\n");
	printf("Masukan batas akhir bilangan prima yang akan dicari : \n");
    scanf("%d",&bil);
    printf("\nBerikut adalah bilangan prima kurang dari %d : \n", bil);
	for(j=2;j<=bil;j++){
		if((j%2>0)&&(j%3>0)&&(j%5>0)&&(j%7>0)||(j==2)||(j==3)||(j==5)||(j==7))
		printf("%i ",j);
	}
    printf("\n\nTekan sembarang untuk kembali ke menu awal");
    getch();
    system("cls");
}

void bsort(){
    system("cls");
	system("title Bubble Sort");
	int i,j,temp,n,bil[100];
	printf("\t\t\t Sorting Bilangan \n\n\n");
	printf("Masukan jumlah bilangan \n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Bilangan ke- %d \t: ",i+1);
		scanf("%d",&bil[i]);
	}
	printf("\n");
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(bil[i]>bil[j]){
				temp = bil[i];
				bil[i]=bil[j];
				bil[j]=temp;
			}
		}
	}
	printf("Sorting :");
	for(i=0;i<n;i++){
		printf("%d",bil[i]);
		if(i!= n-1){
			printf(",");
		}
	}
	printf("\n\nTekan sembarang untuk kembali ke menu awal");
    getch();
    system("cls");
}

void kalimatriks(){
    system("cls");
	system("title Perkalian Matriks");
	int i,j,k,x,y,temp,ordo,ma[10][10],mb[10][10],mc[10][10];
	printf("\t\t\t Perkalian Matriks\n\n\n");
	printf("Masukan Ordo Matriks : ");
	scanf("%d", &ordo);
	printf("Matriks A: ");
	for(i=0;i<ordo;i++){
		for(j=0;j<ordo;j++){
			gotoxy((j+1)*5,i+6);
			scanf("%d",&ma[i][j]);
		}
	}
	printf("\n");
	printf("Matriks B: ");
	for(i=0;i<ordo;i++){
		for(j=0;j<ordo;j++){
			gotoxy((j+1)*5,i+8+ordo);
			scanf("%d",&mb[i][j]);
		}
	}
	for(i=0;i<ordo;i++){
		for(j=0;j<ordo;j++){
			temp = 0;
			for(k=0;k<ordo;k++){
				temp+=ma[i][k]*mb[k][j];
			}
			mc[i][j] = temp;
		}
	}
	printf("\n \n");
	printf("Hasil Matriks A * Matriks B:");
	for(i=0;i<ordo;i++){
		for(j=0;j<ordo;j++){
			gotoxy((j+1)*5,i+11+ordo*2);
			printf("%d",mc[i][j]);
		}
	}
	printf("\n\nTekan sembarang untuk kembali ke menu awal");
    getch();
    system("cls");
}

void menuBF() { //boyfriend ? wkwkw // here is your code from main
    system("cls");
    myFlush();
    char searchStr[MAX], pattern[MAX];
    int reps;
    printf("masukan kalimat pertama:");
    fgets(searchStr, MAX, stdin);
    printf("masukan kalimat ke dua:");
    fgets(pattern, MAX, stdin);
    searchStr[strlen(searchStr) - 1] = '\0';
    pattern[strlen(pattern) - 1] = '\0';
    reps = bruteForce(searchStr, pattern, strlen(searchStr), strlen(pattern));
    if (reps == -1) {
            printf("tidak ada yang sama\n");
    } else {
            printf("jumlah huruf yang sama ada %d\n", reps);
    }
    getch();
    system("cls");
    return;
}

int bruteForce(char *search, char *pattern, int slen, int plen) { //BruteForce algo added
    int i, j, k;

    for (i = 0; i <= slen - plen; i++) {
            for (j = 0, k = i; (search[k] == pattern[j]) &&
                    (j < plen); j++, k++);
            if (j == plen)
                    return j;
    }
    return -1;
}
