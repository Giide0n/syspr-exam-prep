#include <stdio.h>
#include <stdlib.h>

void swap (char **a, char **b) {
    char **temp = a;
    *a = *b;
    *b = *temp;
}

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        long rnd = (random() % (argc - 1)) + 1;
        swap(&argv[i], &argv[rnd]);
    }

    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    return 0;
}
