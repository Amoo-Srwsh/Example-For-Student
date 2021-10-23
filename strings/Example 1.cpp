/* memcpy example */
/* void * memcpy ( void * destination, const void * source, size_t num ); */

/* Parameters
	(destination)
	Pointer to the destination array where the content is to be copied,  type-casted to a pointer of type void*.
----------------------------------------------------
	(source)
	Pointer to the source of data to be copied,  type-casted to a pointer of type const void*.
----------------------------------------------------
	(num)
	Number of bytes to copy.  size_t is an unsigned integral type
----------------------------------------------------


The function does not check for any terminating null character in source - it always copies exactly num bytes.


----------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
	
int main()
{
	
	cout << "\n......\n"; 
	
	char a1[10] = "abcd";
	char a2[10] = "hij";
	memcpy(a1,a2,3);
	cout << a1;

	cout << "\n.....\n";
}
