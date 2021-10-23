#include<stdio.h>  
#include<string.h>  

int main()  
{  
    	typedef struct student  
    	{  
        	char *name;  
        	int id;  
        	int age;  
    	}std;  
 
    	std student1; // Declare student1 of type std  
    	std student2; // Declare student2 of type std  
     
    	// Assigning the value of sudent1  
    	student1.name = "Bamdev Ghosh";  
    	student1.id = 1105;  
    	student1.age = 30;  
 
    	printf("Student1:\n\tName : %s\n\tid : %d\n\tage : %d\n",student1.name,
    	student1.id,student1.age);  
     
    	// Copy student1 to student2      
    	memcpy(&student2, &student1, sizeof(student1));  
     
    	printf("\n\nAfter memcpy:");  
    	printf("\n\nStudent2:\n\tName : %s\n\tid : %d\n\tage : %d\n",
    	student2.name,student2.id,student2.age);  

	return 0;  
}
