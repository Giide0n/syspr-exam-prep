//
// Created by Benaja on 07/01/2024.
//Test: HS2022 3ib Aufgabe 2
//
#include <stdio.h>
#include <unistd.h>

void recursivefork(int pipe_fd, int depth){
        write(pipe_fd, &depth, sizeof(depth));
        recursivefork(pipe_fd, depth + 1);
}

int main() {
    int pipe_fd[2];
    pipe(pipe_fd);
    if (fork() == 0){
        close(pipe_fd[0]);
        recursivefork(pipe_fd[1] ,1);
        close(pipe_fd[1]);
    } else {
        close(pipe_fd[1]);
        int result;
        while(read(pipe_fd[0], (void*) &result, sizeof(result)) != 0);
        printf("%d forks until Stackoverflow\n", result);
    }

}