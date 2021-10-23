/* memset example */
/* void * memset ( void * ptr, int value, size_t num ); */

/* Parameters
	(ptr)
	Pointer to the block of memory of fill.
----------------------------------------------------
	(value)
Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
----------------------------------------------------
	(num)
	Number of bytes to be set value.
	size_t is an unsigned integral type.
----------------------------------------------------
*/
#include <stdio.h>
#include <string.h>

int main ()
{
  	char str[] = "almost every programmer should know memset!";
  	memset (str,'-',6);
  	puts (str);
  	return 0;
}
