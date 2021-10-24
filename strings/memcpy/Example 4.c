#include <stdio.h>
#include <string.h>
#define MAX_CHAR 50

int main(void)
{
	char str1[MAX_CHAR] = "Hello World!";
	char str2[MAX_CHAR] = "Nothing is impossible";

	printf("Before copying...\n");
	printf("str1: %s\n",str1);
	printf("str2: %s\n",str2);

	//copying all bytes of str2 to str1
	memcpy(str1, str2, strlen(str2));

	printf("After copying...\n");
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	
	return 0;
}
