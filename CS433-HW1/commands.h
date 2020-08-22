#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

#include "helper.h"

void list(char** args, int count);
void cd(char** args, int count);
void help(char** args, int count);
void quit(char** args, int count);