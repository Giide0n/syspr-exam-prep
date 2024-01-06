//
// Created by Benaja on 06/01/2024.
//
#include "stdio.h"
#include "unistd.h"

int main(int argc, char *argv[]) {
    execve(argv[0], argv+1, 0);
}