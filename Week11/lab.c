#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  FILE* fp = fopen(argv[1], "r");

  char buf[4000];
  int N = 8;
  for(int i = 0; i < sizeof(buf); i+=N)
	  fread(&(buf[i]), 1, N, fp);  //fread makes fp advance forward everytime, so you start reading next N bytes every time

  return 0;
}
