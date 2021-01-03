#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    }
    if(c >= 'a' && c <= 'f'){
        return c - 'a' + 10;
    }
    if(c >= 'A' && c <= 'F'){
        return c - 'A' + 10;
    }
    return -1;
}



int main(int argc,char *args[]){
    if(argc < 2){
        printf("not enough values");
        exit(0);
    }
    char *val = args[1];
    int slen = strlen(val);
    if(slen != 10){
        printf("not right input");
        exit(0);
    }
    for(int i=2;val[i];i+=2){
        int num = 0;
        for(int j=0;j<2;j++){
            int tmp = convert(val[i+j]);
            if(tmp == -1){
                printf("not right input");
                exit(0);
            }
            num = num*16 + tmp;
        }
        if(i == 2){
            printf("%d",num);
        }else{
            printf(".%d",num);
        }
    }
    printf("\n");
}