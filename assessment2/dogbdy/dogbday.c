//
// Created by Benaja on 07/01/2024.
// Test: FS2022 4ibb2 Aufgabe 7
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct tm *tm;

    // Allocate memory for tm
    tm = malloc(sizeof(struct tm));

    // Use strptime to parse the input time from argv[1]
    strptime(argv[1], "%d.%m.%Y", &tm);

    time_t t_now = time(NULL);
    time_t t = mktime(tm);
    t = (t_now - t) / 7;
    time_t t_dogbd = t_now - t;

    struct tm tm_dogbd = *localtime(&t_dogbd);

    // print day month year of tm_now
    printf("The dogs birthday is %d.%d.%d\n", tm_dogbd.tm_mday, tm_dogbd.tm_mon +1, tm_dogbd.tm_year + 1900);

    // Free the allocated memory for tm
    free(tm);

    return 0;
}
