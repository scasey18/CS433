#include<stdio.h>
// include other libraries if needed

//made to easily print out array
void printArray(int* test, int length){
	int i;
	for (i = 0; i < length; i++){
		printf("%d", test[i]);
		if (i != length-1){
			printf(",");
		}
	}
	printf("\n");
}

int main() {
	int testArray[] = {29, 17, 8, 17, 9, 17, 29,9};
	//expected output
	// 29,17,8,9

	//implement your code here
	int i, j, a;
	//find the number of elements in the array
	int length = sizeof(testArray) / sizeof(testArray[0]);
	//iterate through the array to check
	for (i = 0; i < length; i++){
		//check the rest of the array to check if there are more in the array
			for (j = i+1; j < length; j++){
				//if the two match the start replacing the j index
				if (testArray[i] == testArray[j]){
					//iterate down length since a duplicate has been found
					for (a = j; a < length; a++){
						testArray[a] = testArray[a+1];
					}
					length = length-1;
				}
			}
		}
	printArray(testArray, length);
	return 0;   
}