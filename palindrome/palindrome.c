#include <string.h>
#include <printf.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *sen = malloc(sizeof(char));

    for (int i = 1; i < argc; ++i) {
        strcat(sen, argv[i]);
    }

    int i = 0;
    int j = strlen(sen) - 1;

    while(i <= j && sen[i] == sen[j]) {
        i++; j--;
    }

    if(i > j) {
        printf("yes");
    } else {
        printf("no");
    }
}