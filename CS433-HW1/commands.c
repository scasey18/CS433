#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

#include "helper.h"

void list(char** args, int count){
	if (count != 1){
		printf("list: this function does not support arguments\n");
		return;
	}
	struct dirent *dirent; 
	DIR *parentDir;
	char loc[1024]; //get current directory
	getcwd(loc, 1024); 
	//open the current directory
	if ((parentDir = opendir(loc)) == NULL) { 
		printf ("Error opening directory '%s'\n", loc); 
		return;
	}
	//print all the files in the opened directory except the . and .. folders
	while((dirent = readdir(parentDir)) != NULL){
		if (strcmp((*dirent).d_name,".") && strcmp((*dirent).d_name,"..")){
			printf ("%s\n",(*dirent).d_name); 
		}
	}
	free(dirent);
	closedir(parentDir);
}

void cd(char** args, int count){
	if (count > 2){
		printf("cd: too many arguments for this function\n");
		return;
	}
	else if (count == 1){
		printf("cd: no directory provided\n");
		return;
	}
	char loc[1024];
	getcwd(loc, 1024);
	int args1 = 1, i;
	//parse the destination provided
	char** dest = parseLine(args[1], &args1, '/');
	for (i = 0; i < args1; i++){
		//for each parsed file directory, move to that location
		if (chdir(dest[i]) != 0){
			//if the directory is invalid then print an error and return to the original directory
			//invalid directory return to the original directory
			printf("invalid directory provided\n");
			chdir(loc);
		}
	}
}

void help(char** args, int count){
	if (count != 1){
		printf("help: this function does not support arguments\n");
		return;
	}
	printf("list           -- list all files in the current directory\n");
	printf("cd <directory> –- change the current directory to the <directory>\n");
	printf("help           -– display the internal commands and a short description on how to use them\n");
	printf("quit           -– quit the shell program\n");
}

void quit(char** args, int count){
	//exit the program with the status code zero
	if (count != 1){
		printf("quit: this function does not support arguments\n");
		return;
	}
	exit(0);
}