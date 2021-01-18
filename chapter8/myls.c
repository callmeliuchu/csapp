#include "csapp.h"


int main(int argc,char* argv[],char* env[]){
    if(execve("/bin/ls",argv,env) == -1){
        fprintf(stderr,"executive error: %s\n",strerror(errno));
        exit(0);
    }
}