#include <stdlib.h>
#include <stdio.h>


char convert(int num){
    if(num >=0 && num <= 9){
        return '0' + 9;
    }
    if(num >= 10 && num <= 15){
        return num - 10 + 'a';
    }
    return '\0';
}

int main(int argc,char *args[]){
    if(argc < 2){
        printf("not enough values");
        exit(0);
    }
    char *val = args[1];
    int num = 0;
    printf("0x");
    for(int i=0;;i++){
        if(val[i] == '.' || val[i] == '\0'){
            printf("%02x",num);
            if(val[i] == '\0'){
                break;
            }
            num = 0;
            continue;
        }
        num = num*10 + (val[i] - '0');
    }
    printf("\n");
}