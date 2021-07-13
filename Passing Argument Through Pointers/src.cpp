//Amoo-Srwsh
//Passing Argument through pointer : sort
#include <iostream>
using namespace std;

void swap(int * , int *);
void sort(int [] , int);

main()
{
    const int size = 6;
    int array[size] = {2,4,6,3,1,5};

    sort(array,size);

    for(int j=0; j<size; j++)   //after sort print array
        cout << array[j] << "   ";  //[1,2,3,4,5,6]


}

void sort(int array[] , int size)
{
    int i,j;
    int *pointer;
    pointer = array;

    for(i=0; i<size; i++)
        for(j=0; j<size-1; j++)
            if(*(pointer+j) > *(pointer+j+1))
                swap((pointer+j),(pointer+j+1));  //if true swap index array number
}

void swap(int *pa , int *pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
