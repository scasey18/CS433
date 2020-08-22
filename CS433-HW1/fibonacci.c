#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){
	int first= 0, second = 0, pos = 0;
	int num, cur;
	if (argc == 1){
		printf("How many elements you want to display: ");
		char BUF[1024];
		if(fgets(BUF, 1024, stdin) != NULL){
			num = atoi(BUF);
			if (num == 0 && strcmp(BUF, "0") != 0){
				printf("invalid argument provided\n");
				return -1;
			}
		}
	}
	else if (argc == 2){
		num = atoi(argv[1]);
		if (num == 0 && strcmp(argv[1], "0") != 0){
			printf("invalid argument provided\n");
			return -1;
		}
	}
	else {
		printf("invalid number of arguments provided\n");
		return -1;
	}
	printf("The first %d values: ", num);
	while (pos < num){
		cur = first + second;
		if (pos == 1 || pos == 2){
			cur = 1;
		}
		printf("%d", cur);
		if (pos != num-1){
			printf(", ");
		}
		first = second;
		second = cur;
		pos++;
	}
	printf("\n");
	return 0;
}