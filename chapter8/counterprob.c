#include "csapp.h"
int counter = 0;


void handler(int sig){
    counter++;
//    sleep(1);
    return;
}


int main(){
    int i;
    Signal(SIGUSR2,handler);
    if(Fork() == 0){
        for(i=0;i<5;i++){
            int ppid = getppid();
            Kill(ppid,SIGUSR2);
            printf("%d sent SIGUSR2 to parent\n",ppid);
        }
        exit(0);
    }
    Wait(NULL);
    printf("counter=%d\n",counter);
    exit(0);
}