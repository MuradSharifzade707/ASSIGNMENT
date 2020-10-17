#include<stdio.h>
#include<stdbool.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int x, int y); // draws a path to the exit on the maze string

int main(){
    char mazeStr[] ="  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";

    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)		// filling the 2D char array
	maze[i]=&mazeStr[i*WD];
    
    solveMaze(maze, HT, WD, 0, 0);
    
    printMaze(maze, HT, WD);
   
    return 0;
}


int solveMaze(char **maze, const int HT, const int WD, int x, int y){
	
	if(x < 0 || x >= WD || y < 0 || y >= HT)                 return 0;  //makes sure if it is inside of the maze
        if(*(*(maze + y) + x) == '*')                            return 1;  //identifies if the path reaches the '*'
        if(*(*(maze + y) + x) == '#' || *(*(maze + y) + x)=='.') return 0;  //checks if it encounters the obstacle'#' 

    		*(*(maze + y) + x)='.';    //marks the path it travels.

    	if(solveMaze(maze, HT, WD, x, y - 1)==1) return 1; //goes North 
 	if(solveMaze(maze, HT, WD, x + 1, y)==1) return 1; //goes East
  	if(solveMaze(maze, HT, WD, x, y + 1)==1) return 1; //goes South
   	if(solveMaze(maze, HT, WD, x - 1, y)==1) return 1; //goes West
   
 		*(*(maze + y) + x)=' ';        return 0;	//unmarks the wrong path
}

void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
    }
}
