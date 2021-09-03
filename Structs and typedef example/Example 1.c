#include <stdio.h>
#include <math.h>

/*
To define a new type name with typedef, follow these steps:
1. Write the statement as if a variable of the desired type were being declared.
2. Where the name of the declared variable would normally appear, substitute the new type name.
3. In front of everything, place the keyword typedef.
*/

// typedef a primitive data type
typedef double distance;

// typedef struct
typedef struct{
    int x;
    int y;
} point;

//typedef an array
typedef point points[100];

points ps = {0}; // ps is an array of 100 point

// typedef a function
typedef distance (*distanceFun_p)(point,point) ; // TYPE_DEF distanceFun_p TO BE int (*distanceFun_p)(point,point)

// prototype a function
distance findDistance(point, point);

int main(int argc, char const *argv[])
{
    // delcare a function pointer
    distanceFun_p func_p;

    // initialize the function pointer with a function address
    func_p = findDistance;

    // initialize two point variables
    point p1 = {0,0} , p2 = {1,1};

    // call the function through the pointer
    distance d = func_p(p1,p2);

    printf("the distance is %f\n", d );

    return 0;
}

distance findDistance(point p1, point p2)
{
    distance xdiff =  p1.x - p2.x;
    distance ydiff =  p1.y - p2.y;

    return sqrt( (xdiff * xdiff) + (ydiff * ydiff) );
}
