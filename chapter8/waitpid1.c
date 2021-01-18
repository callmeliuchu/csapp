#include "csapp.h"


#define  N 2


int main(){
    int status,i;
    pid_t pid;


    for(i=0;i<N;i++){
        if((pid = Fork()) == 0){
            char *p = NULL;
            *p = 'd';
        }
    }

    while((pid = waitpid(-1,&status,0)) > 0){
        if(WIFEXITED(status)){
            printf("child %d terminated normally with exit status=%d\n",pid,WEXITSTATUS(status));
        }else{
            printf("child %d terminated abnormally\n",pid);
        }
    }
}