//matchingstring
#include <stdio.h>
#include <string.h>
#define MAX 100

  /* try to find the given pattern in the search string */
  int bruteForce(char *search, char *pattern, int slen, int plen) {
        int i, j, k;

        for (i = 0; i <= slen - plen; i++) {
                for (j = 0, k = i; (search[k] == pattern[j]) &&
                        (j < plen); j++, k++);
                if (j == plen)
                        return j;
        }
        return -1;
  }

  int main() {
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
        return 0;
  }

