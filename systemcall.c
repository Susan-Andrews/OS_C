//CODE

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
#include<stdlib.h>

void main(){

	printf("inside syscall \n");
	
	int stat;
		
	int pid = fork();
	if (pid == -1){
    	 	printf("\ncan't fork, error occured\n");
     	 	exit(1);
	}
	else if (pid == 0){
		printf("\nchild process created ");
		printf("\nchild process, pid = %u\n",getpid());
		
		char *binaryPath = "/bin/ls";
		char *args[] = {binaryPath, "-lh", "/home", NULL};
		execv(binaryPath, args);
		printf("\nchild EXITING...\n");
		exit(2);
	}
	else{
		 printf("\nparent process, pid = %u\n",getpid());
		 wait(&stat);
		 
	}
	
	if (WIFEXITED(stat))
        	printf("Exit status: %d\n", WEXITSTATUS(stat));
   	else if (WIFSIGNALED(stat))
        	psignal(WTERMSIG(stat), "Exit signal");
}

