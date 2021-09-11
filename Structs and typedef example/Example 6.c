#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	struct pixle
	{
		int horz;
		int vert;
		char color;
	};
	struct pixle box[2];

	box[0].horz = 100;
	box[0].vert = 50;
	box[0].color = 'r';
	box[1].horz = 200; 
	box[1].vert = 50;
	box[1].color = 'b';

	for (int i = 0; i < 2; i++)
		printf("%i     %i     %c\n", box[i].horz, box[i].vert, box[i].color);
}
