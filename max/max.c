#include <string.h>
#include <printf.h>

int main(int argc, char *argv[]) {
    int maxi = 1;
    for (int i = 2; i < argc; ++i) {
        if(strlen(argv[i]) > strlen(argv[maxi])) {
            maxi = i;
        }
    }
    printf("%s", argv[maxi]);
}