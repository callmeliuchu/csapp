#include "csapp.h"


int mysystem(char* command){
    pid_t pid;
    int status;
    if((pid = Fork()) == 0){
        char* argv[4] = {"","-c",command,NULL};
        execve("/bin/bash",argv,environ);
    }
    printf("child pid: %d\n",pid);

    if(Waitpid(pid,&status,0) > 0){
        if(WIFEXITED(status)){
            return WEXITSTATUS(status);
        }
        if(WIFSIGNALED(status)){
            return WTERMSIG(status);
        }
    }
}


int main(){
    int code;
    code = mysystem("./exit-code");
    printf("normally exit: %d",code);
    fflush(stdout);

    code = mysystem("./wait-sig");
    printf("exit caused by signal,code: %d\n",code);
    fflush(stdout);

    return 0;
}
