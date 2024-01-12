//
// Created by Benaja on 08/01/2024.
// Test: HS2022 3ib Aufgabe 6 - Lange Version

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int ago = atoi(argv[1]);
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    tm->tm_mday -= ago;
    time_t t_ago = mktime(tm);

    printf("%s\n", ctime(&t_ago));

    return 0;
}
