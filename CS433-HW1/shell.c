#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "commands.h"
#include "forkexec.h"
#include "helper.h"

#define BUFSIZE 1024

void commandops(char** command, int argc){
	if (strcmp(command[0], "help") == 0){
		help(command, argc);
	}
	else if (strcmp(command[0], "list") == 0){
		list(command, argc);
	}
	else if (strcmp(command[0], "cd") == 0){
		cd(command, argc);
	}
	else if (strcmp(command[0], "quit") == 0){
		quit(command, argc);
	}
	else {
		forkexec(command, argc);
	}
}

int emptyLine(char* BUFFER){
	//This will figure out if the input line is blank or not
	//This will also trim away the excess spaces at the end of the string
	//this will return the position text actually starts at or -1 to indicate it is a blank line
	int i, max = strlen(BUFFER)-1, begin = -1;
	for (i = 0; i < max; i++){
		if (BUFFER[i] != ' ' && BUFFER[i] != '\t'){
			begin = i;
			break;
		}
	}
	if (begin != -1){
		for (i = max-1; i > begin; i--){
			if (BUFFER[i] != ' ' && BUFFER[i] != '\t'){
				BUFFER[i+1] = '\0';
				return begin;
			}
		}
	}
	return begin;
}

void commandtok(char* BUFFER){
	int arg = 1, begin;
	//see if the line is empty
	if ((begin = emptyLine(BUFFER)) == -1){
		return;
	}
	//parse the line for tokenizing the command
	char** command = parseLine(&BUFFER[begin], &arg, ' ');
	//perform the appropriate action based on the command
	commandops(command, arg);
	free(command);
}

int main(int argc, char** argv) {
	//Allocate line for storing command
	char BUFFER[BUFSIZE];
	//repeat infinitely until the user quits
	for(;;){
		printf("uab_sh>"); //print prompt for command
		if (fgets(BUFFER, BUFSIZE, stdin) != NULL){
			//fgets keeps the newline character
			commandtok(BUFFER);
		}
		
	}
	return 0;
}