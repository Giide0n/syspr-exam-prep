//
// Created by Benaja on 07/01/2024.
// Test: FS2022 4ibb2 Aufgabe 5
//
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <fcntl.h>

void gen() {
    struct mq_attr attr;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 50;

    mqd_t mq = mq_open("/my_mq", O_RDWR | O_CREAT, 0666, &attr);

    mq_send(mq, "Hello Andi", sizeof("Hello Andi"), 0);
    mq_send(mq, "Wasuuuuup", sizeof("Wasuuuuup"), 0);
    mq_send(mq, "fuckn syspr git mr eine", sizeof("fuckn syspr git mr eine"), 0);

    printf("Messages sent successfully\n");

    mq_close(mq);
}

int main(int argc, char *argv[]) {
    //gen();

    mqd_t mq = mq_open(argv[1], O_RDWR);

    struct mq_attr attr;
    mq_getattr(mq, &attr);

    for (int i = 0; i < attr.mq_curmsgs; ++i) {
        char buf[attr.mq_msgsize + 1];
        int prio;
        size_t r = mq_receive(mq, buf, attr.mq_msgsize, &prio);
        buf[r] = '\0';  // Null-terminate the received message
        printf("%s\n", buf);
        mq_send(mq, buf, r, prio);
    }

    mq_close(mq);
    mq_unlink(argv[1]);  // Remove the message queue from the system

    return 0;
}


