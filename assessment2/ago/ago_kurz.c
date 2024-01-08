//
// Created by Benaja on 08/01/2024.
// Test: HS2022 3ib Aufgabe 6 - Kurze Version

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    time_t t = time(NULL);
    t = t - atoi(argv[1]) * 60 * 60 * 24;
    printf("%s", ctime(&t));
}
