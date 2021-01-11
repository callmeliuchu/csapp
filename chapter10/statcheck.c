#include "csapp.h"

int main(int argc,char **argv){
	struct stat stat;
	char *type,*readok;
	int fd = atoi(argv[1]);
	// if (Fork() == 0) { /* Child */
 //    /* The Shell may be run these code? */
 //        printf("fork\n");
	//     fd = Open("foo.txt", O_RDONLY, 0); /* fd == 3 */
	//     Dup2(fd, STDIN_FILENO);
	//     Close(fd);
	//  }
    fstat(fd,&stat);
	if(S_ISREG(stat.st_mode)){
		type = "regular";
	}else if(S_ISDIR(stat.st_mode)){
		type = "directory";
	}else{
		type = "other";
	}
	if((stat.st_mode & S_IRUSR)){
		readok = "yes";
	}else{
		readok = "no";
	}
	printf("type: %s.read: %s\n",type,readok);
	exit(0);
}