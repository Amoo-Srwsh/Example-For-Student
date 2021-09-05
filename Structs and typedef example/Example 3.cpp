#include <stdio.h>
#include <stdlib.h>

struct list_tag
{
  int              x;
  struct list_tag* next;
};

typedef struct list_tag list;

list* cons( int x, list* next )
{
  list* car = (list*)malloc( sizeof(list) );
  car->x = x;
  car->next = next;
  return car;
}

void print( list* xs )
{
  while (xs)
  {
    printf( "%d ", xs->x );
    xs = xs->next;
  }
  printf( "\n" );
}

int main()
{
  list* xs = cons( 2, cons( 3, cons( 5, cons( 7, NULL ) ) ) );
  print( xs );
}