#include <stdio.h>


void swapStrings(char **destination, char **source);           

int main(){

	char *str1 = "Hello";    // defining and initializing str1
   	char *str2 = "World";    // defining and initializing str2

    printf("str1: %s, str2: %s\n",str1, str2);

    swapStrings(&str1, &str2);

    printf("str1: %s, str2: %s\n",str1, str2);

    return 0;
}


void swapStrings(char **destination, char **source)
{
	
	//swapping contents of two strings without using any built in functions.

	char *temp = *destination;    
	*destination = *source;         
	*source = temp; 	       

}


