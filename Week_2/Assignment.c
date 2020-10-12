// C program to swap two variables
#include <stdio.h>

     int main()
{
	int a, b;
    	printf("Enter Value of a: ");
    	scanf("%d", &a);
     	printf("\nEnter Value of b: ");
     	scanf("%d", &b);
  
      	int temp = a;
      	a= b;
      	b = temp;
  
      	printf("\nAfter Swapping: a= %d, b = %d\n", a, b);
      	return 0;
  }
