#include "stdio.h"
#include "stdlib.h"

void unix_error(char *msg){
    frintf(stderr,"%s: %s\n",msg,strerror(errno));
}


pid_t Fork(void){
    pid_t = pid;
    if((pid = fork()) < 0){
        unix_error("Fork error");
    }
    return pid;
}

int main(){
    pid_t = Fork();
}