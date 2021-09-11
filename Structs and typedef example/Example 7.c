#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct pixle
{
	int horz;
	int vert;
	char color;
} center;

void show_pixle(struct pixle p);

int main()
{
	center.horz = 320; 
	center.vert = 240;
	center.color = 'r';
	show_pixle(center);

	return 0;
}

void show_pixle(struct pixle p)
{
	printf("%i     %i     %c\n", p.horz, p.vert, p.color);
}
