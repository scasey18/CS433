#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArray(char** BUFFER, int count){
	int i;
	for (i = 0; i < count; i++){
		printf("[%d] %s\n", i, BUFFER[i]);
	}
}

//remove an element from the array by overlapping the rest of the array by 1
void removeElement(char* BUFFER, int cur, int length){
	int i;
	for (i = cur; i < length; i++){
		BUFFER[i] = BUFFER[i+1];
	}
}

char** parseLine(char* BUFFER, int* argcount, char sep){
	char** command = malloc(BUFSIZ * sizeof(char *));
	int i, length = strlen(BUFFER), check = 1;
	if (BUFFER[length-1] == '\n'){
		//remove the newline if present
		BUFFER[length-1] = '\0'; 
	}
	command[0] = &BUFFER[0];
	for (i = 1; i < length; i++){
		if (BUFFER[i] == sep && check == 1){
			//create a new string by adding the null character and create a reference to it
			BUFFER[i] = '\0';
			command[*argcount] = &BUFFER[i+1];
			(*argcount)++;
		}
		//only reason this is implemented is because my filesystem has a lot of spaces in existing folders
		else if (BUFFER[i] == '"'){
			removeElement(BUFFER, i, length);
			length--;
			check = !check;
		}
	}
	//DEBUG output of the parseLine
	//printArray(command, *argcount);
	command[*argcount] = (char*)NULL;
	return command;
}