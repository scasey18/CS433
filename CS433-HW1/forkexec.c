#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void forkexec(char** args, int count){
	pid_t pid;
	int status;
	
	pid = fork();
	if (pid == 0){
		//child process being made for the desired function
		args[count] = (char *) NULL;
		execvp(args[0], args);
		//perror("execvp");
		printf("no such file or directory\n");
		exit(-1);
	}
	else if (pid > 0){
		//parent process made to wait for the child process
		wait(&status);
	}
	else {
		perror("fork");
		exit(-1);
	}
}