#include <stdio.h>
#include <stdlib.h>
#include "game_methods.h"
/*c file for the functions of the
*
*
*
*@author Lanndon Rose
*@author Austin Van Kempen
*
*/






/*
Method for allocting size for the array

source
https://github.com/derrikfleming/
CIS343/blob/master/Projects/connect-X/game.c
referenced his allocation method.
*/
int universeSize(int** tempUniv, int x, int y){
//allocate memory for universe
int z = y * x;
 *tempUniv =  malloc(sizeof(int**)* z);
 if (tempUniv == NULL){
   printf("%s\n","malloc error  1" );
 }
  for (int u = 0; u < x; u++){
tempUniv[u] = malloc(sizeof(int*)*y);
  if (tempUniv == NULL){
    printf("%s\n","malloc error  2" );
  }

  }

  for (int i = 0; i <  x; i++){
      for (int j = 0; j < y; j++){
         tempUniv[i][j] = 0;
}
}
  return 0;

}
/*
prints the 2d array to the terminal
@param tempUniv - the 2d board to be printed
source
https://github.com/derrikfleming/CIS343/
blob/master/Projects/connect-X/connectx.c

referenced his print method.
*/
void printUniverse(int** tempUniv){
  int y = getY();
  int x = getX();
  for (int d = 0; d < x; d++){
    printf(" ");
    for (int p = 0; p < y; p++){
     printf("A %d ", tempUniv[d][p]);
    }
    //spacing
    printf(" \n");
  }
  //spacing
  printf("\n\n");
}
/*
the determines the fate of the cell in the board
@param tempUnix - array of cells
@param x - x of the board
@param y - y of the board

source
http://www.cs.utexas.edu/users/djimenez/utsa/cs1713-3/c/life.txt
*/
void nextGeneration (int** tempUniv, int x, int y) {

	int	l, h, c;
  int** Upboard;
  Upboard = tempUniv;
	/* for each cell, apply the rules of Life */

	for (l=0; l<x; l++) for (h=0; h<y; h++) {
		c = hasNeighbors(tempUniv, l, h);
		if (c == 2) {
       Upboard[l][h] = tempUniv[l][h];
     }
     //checks number of neighbor cells
		if (c == 3) {
      Upboard[l][h] = 1;
    }
    //checks number of neighbor cells
		if (c < 2) {
      Upboard[l][h] = 0;
    }
    //checks number of neighbor cells
		if (c > 3) {
      Upboard[l][h] = 0;
    }
	}

	/* copy the new board back into the old board */

	for (l=0; l<x; l++) for (h=0; h<y; h++) {
		tempUniv[l][h] = Upboard[l][h];
	}
}
/*
determines if a live cell has other live cells around it

@param tempUnix - array of cells
@param x - x of the cell being checked
@param y - y of the cell being checked

source
http://www.cs.utexas.edu/users/djimenez/utsa/cs1713-3/c/life.txt
*/
int hasNeighbors(int** tempUniv, int x, int y) {
	int	a, o, add;
	add = 0;
	/* go around the cell */
	for (a=-1; a<=1; a++) for (o=-1; o<=1; o++)
		/* only count if at least one of a,o isn't zero */
		if (a || o)
			if (tempUniv[xadd(x,a)][yadd(y,o)]){
         add++;
       }
	return add;
}

/*
adds a living cell to the board
@param i
@param h
source
http://www.cs.utexas.edu/users/djimenez/utsa/cs1713-3/c/life.txt
*/
int xadd (int i, int h) {
	i += h;
	while (i < 0) {
  i += getX();
}
	while (i >= getX()) {
     i -= getX();
  }
	return i;
}

/*
adds a living cell to the board
@param i
@param h
source
http://www.cs.utexas.edu/users/djimenez/utsa/cs1713-3/c/life.txt
*/
int yadd (int i, int h) {
	i += h;
	while (i < 0) i += getY();
	while (i >= getY()) i -= getY();
	return i;
}
