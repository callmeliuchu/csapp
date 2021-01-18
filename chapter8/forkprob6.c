#include "csapp.h"

void doit(){
    if(Fork() == 0){
        Fork();
        printf("hello\n");
        return;
    }
    return;
}

int main(){
    doit();
    printf("hello1\n");
    exit(0);
}