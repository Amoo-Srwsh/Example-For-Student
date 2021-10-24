/* memset example */

//----------------------------------------------------//
/* http://www.cplusplus.com/reference/cstring/memset/?kw=memset */
//----------------------------------------------------//	
	
/* void * memset ( void * ptr, int value, size_t num ); */

/* Parameters
	(ptr)
	    Pointer to the block of memory to fill.
------------------------------------------------------
	(value)
	        Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
------------------------------------------------------
	(num)
	Number of bytes to be set to the value.
size_t is an unsigned integral type.
------------------------------------------------------
 Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
------------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#define LEN 10

int main(void)
{
	char arr[LEN];
	int loop;

	printf("Array elements are (before memset()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");

	//filling all blocks with 0
	memset(arr,0,LEN);
	printf("Array elements are (after memset()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");

	//filling first 3 blocks with -1
	//and second 3 blocks with -2
	//and then 3 blocks with -3
	memset(arr,-1,3);
	memset(arr+3,-2,3);
	memset(arr+6,-3,3);
	printf("Array elements are (after memset()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");

	return 0;
}
