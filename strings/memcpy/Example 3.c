#include <stdio.h>
#include <string.h>
#define MAXLEN 11

//function to print array 
void printArray(unsigned char str[], int length)
{
	int i;
	for(i = 0; i < length; i++)
		printf("%02X ", str[i]);
	printf("\n");
}

int main(void)
{
	unsigned char arr1[MAXLEN] = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0x95};
	unsigned char arr2[MAXLEN] = {0};

	printf("Before copying...\n");
	printf("arr1: "); printArray(arr1, strlen(arr1));
	printf("arr2: "); printArray(arr2, strlen(arr2));

	//copying 5 bytes of arr1 to arr2
	memcpy(arr2, arr1, 5);
	printf("After copying...\n");
	printf("arr1: "); printArray(arr1, strlen(arr1));
	printf("arr2: "); printArray(arr2, strlen(arr2));
	
	return 0;
}
