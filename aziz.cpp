#include<stdio.h>
#include<stdbool.h>//Ditambahkan
//#include<conio.h>

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
    char term; //Editer : peratrutan input
    bool again = true; 

    do{//ditambahkan
        printf("\n\t\t\tMaksimum Dengan Minimum\n\n");
        printf("Masukkan Banyak Angka: ");
        if(scanf("%d%c", &banyak, &term) != 2 || term != '\n'){ //ditambahkan
            printf("Input Ditolak! Masukan Bilangan Real ^_^");
            getchar();
        }else{
            if(banyak <= 1){//ditambahkan
                printf("Input Ditolak! Masukan Bilangan >=0 ^_^");
            }else{//ditambahkan
                printf("\nMasukkan Angka-angkanya: \n");

                for(i=0; i<banyak; i++) {
                    printf("Masukan angka ke- %i:", i+1);
                    scanf("%i", &a[i]);
                }
                printf("\nAngka-angkanya adalah: \n");
                for(i=0; i<banyak; i++)
                {
                    printf("%i \n", a[i]);
                }

                maxmin(0, banyak-1);
                printf("\nAngka Maksimum : %i\n", max);
                printf("Angka Minimum : %i", min);
            }//ditambahkan
        }

        printf("\n\n\nIngin mengulangi [1/0]? "); scanf("%d", &again);//ditambahkan
printf("\n\n\n");//ditambahkan
    }while(again == true);//ditambahkan
    return 0;
}
