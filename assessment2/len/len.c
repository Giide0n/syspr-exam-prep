//
// Created by Benaja on 06/01/2024.
// Test: FS2022 4ibb2 Aufgabe 2
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pipe_fd[2];
    pipe(pipe_fd);
    pid_t pid = fork();
    if (pid == 0) { // child
        close(pipe_fd[0]);
        dup2(pipe_fd[1], STDOUT_FILENO);
        execve(argv[1], argv + 1, 0);
        close(pipe_fd[1]); // sends EOF
    } else { // parent
        close(pipe_fd[1]);  // Close unused write end

        char buf[1];
        int len = 0;
        int r = 0;

        while ((r = read(pipe_fd[0], buf, 1)) > 0) {
            len += r;
        }
        printf("%d\n", len);
    }
}
