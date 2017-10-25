#include <stdio.h>
#include <stdbool.h>//added
//#include<conio.h> //For Windows

int a[100];
int max,min;

void maxmin(int i, int j) {
     int max1,min1,mid;
     if(i == j) {
         max=min=a[i];
     }
     else if(i == j-1) {
         if(a[i] > a[j]) {
             max = a[i];
             min = a[j];
         }
         else {
             max = a[j];
             min = a[i];
         }
     } else {
         mid = (i+j)/2;
         maxmin(i, mid);
         max1 = max;
         min1 = min;
         maxmin(mid+1, j);
         if(max < max1) max = max1;
         if(min > min1) min = min1;
     }
}

int main(int argc, char *argv[]){
     int i, banyak;
     char term; //Edited : Term of Input
     bool again = true;

     do{//added
         printf("\n\t\t\tMaximum Dengan Minimum\n\n");
         printf("Masukkan Banyak Angka: ");
         if(scanf("%d%c", &banyak, &term) != 2 || term != '\n'){ //edited : satu input masukin ke dua variabel dengan tipe berbeda, gk tau gimana kalo input bukan numeric maka term akan keisi dengan data.
             printf("[!]Anda tidak memasukan angka[!]\n");
             int c; while ((c = getchar()) != '\n' && c != EOF); //added
             //fflush(stdin);
         }else{
             if(banyak < 1){//added
                 printf("[!]Anda memasukan 0[!]\n");//added
                 int c; while ((c = getchar()) != '\n' && c != EOF); //added
                 //fflush(stdin);//added
             }else{//added
                 printf("\nMasukkan Angka-angkanya: \n");

                 for(i=0; i<banyak; i++) {
                     printf("Masukan angka ke- %i:", i+1);
                     scanf("%i", &a[i]);
                 }
                 printf("\nAngka-angkanya adalah: \n");
                 for(i=0; i<banyak; i++)
                 {
                     printf("%i ", a[i]);
                 }

                 maxmin(0, banyak-1);
                 printf("\nMaksimum Angka: %i\n", max);
                 printf("Minimum Angka: %i", min);
             }//ditambahkan
         }

         printf("\n\n\nIngin mengulangi [1/0]? ");scanf("%d", &again);//ditambahkan
         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//ditambahkan
     }while(again == true);//added
     //getch(); //For Windows and some compiler
     return 0;
}
