#include "csapp.h"


int main(int argc,char **argv){
	int n;
	rio_t  rio;
	char buf[MAXLINE];
	if(argc == 2){
		char *filename = argv[1];
		int fd = Open(filename,O_RDONLY,0);
		int ret = dup2(fd,STDIN_FILENO);
		if(ret < 0){
			perror("dup2");
			return -1;
		}
	}
	Rio_readinitb(&rio,STDIN_FILENO);
	while((n = Rio_readlineb(&rio,buf,MAXLINE)) != 0){
		Rio_writen(STDOUT_FILENO,buf,n);
	}


}