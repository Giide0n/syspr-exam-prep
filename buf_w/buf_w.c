#include <sys/fcntl.h>
#include <unistd.h>
#include <printf.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char val = atoi(argv[2]);
    int file = open(argv[1],O_RDWR);
    lseek(file,1,SEEK_SET);
    int pos;
    read(file,&pos,1);
    int bufsize = lseek(file,0,SEEK_END)-2;
    lseek(file,pos+2,SEEK_SET);
    write(file, &val, 1);
    lseek(file,1,SEEK_SET);
    pos = (pos+1)%bufsize;
    write(file,&pos,1);
    close(file);
    return 0;
}