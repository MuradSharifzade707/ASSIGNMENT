#include <stdio.h>


void swapStrings(char *destination, char *source);           

int main(){
	char str1[] = "Hello";    // define and initialize str1
   	char str2[] = "World";    // define and initialize str2

    printf("str1: %s, str2: %s\n",str1,str2);
    swapStrings(str1,str2);
    printf("str1: %s, str2: %s\n",str1,str2);

    return 0;
}


void swapStrings(char *destination, char *source)
{
    destination = "apple";
    source = "banana";

	char *temp = destination;    
	destination = source;        // swaps contents of two strings
	source = temp; 		     // implement this function without using any built in functions

	return destination;
}


