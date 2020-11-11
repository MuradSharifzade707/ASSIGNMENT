#include<stdio.h>
void function(char *source, char *integers, char *nonIntegers)
{
int a = 0;
int b = 0; 
int i = 0;

  for(; source[i] != '\0'; i++)
    {
    if (source[i] >= 48 && source[i] <= 57)
        {
		integers[a] = source[i];
		a++;}
	else{
		nonIntegers[b] = source[i];
		b++;}
	}
	integers[a]='\0';
    nonIntegers[b]='\0';
}

int main()
{
char source[] = "qwer123tyui456}|?"; 
char integers[256];
char nonIntegers[256];

function(source, integers, nonIntegers);
printf("%s\n", source);
printf("%s\n", integers);
printf("%s\n", nonIntegers);

return 0;}
