#include <stdio.h>
#include <stdlib.h>
#include "game_methods.h"
#include "file_utilites.h"
#include <string.h>

int x;
int y;
/*
getter function for X
*/
int getX(){
  return x;
}
/*
getter function for Y
*/
int getY(){
  return y;
}

int read_file(char* filename, char** buffer);
int write_file(char* filename, char* buffer, int size);

/*
* The main progrma for running the life game.
* user input a board size from the command line
* then within the program user can use given commands to
* progress the game
*
*@author Lanndon Rose
*/
int main(int argc, char *argv[]){
  // takes in board size from command line
  x = (int) atoi(argv[1]);
  y = (int) atoi(argv[2]);
  int z = y * x;
  // memory allocated for board
  int** universe = malloc(sizeof(int*) * z);
  int yes = 0;
    while (1) {
      //the readin commands from the user
    char* readin = (char*) malloc(sizeof(char)*50);
    char** args = (char**) malloc(sizeof(char)*50);
    char* token;
    int i = 0;
    // this is to insure this is all said once durring running
    if (yes == 0){
    printf("\n\nWelcome to Game of Life.");
    printf("\n\nHere are some command you can enter to get things started:");
    printf("\n\n 'new' for new game. ");
    printf("\n\n 'load' to load a game. ");
    printf("\n\n'quit' to exit the game. ");
    //gets user input
    fgets(readin, 50, stdin);
    token = strtok(readin," \n");
    //checks for valid commands
    while (token == NULL){
      printf("\n New, Load, or quit.");
      fgets(readin, 50, stdin);
      token = strtok(readin, " \n");
      if (token != NULL){
        break;
      }
    }
    //sets args to the user commands
    while (token != NULL) {
      args[i] = token;
      token = strtok(NULL, " \n");
      i++;
    }
    yes++;

  }

if (yes !=1){
  //gets user input
  fgets(readin, 50, stdin);
  token = strtok(readin," \n");
  //checks to make sure user enters valid commands
  while (token == NULL){
    printf("\n invalid command: 'help' for list of commands\n");
    fgets(readin, 50, stdin);
    token = strtok(readin, " \n");
    if (token != NULL){
      break;
    }
  }

  while (token != NULL) {
    args[i] = token;
    token = strtok(NULL, " \n");
    i++;
  }
}

    //checks if user entered quit
    if(strcmp(args[0], "quit") == 0) {
      printf("\nClosing Game.\n\n");
      free(readin);
      free(args);
      free(universe);
      exit(0);
      //checks if user entered new
    }else if( strcmp(args[0], "new") == 0){

      universeSize(universe,x ,y);
      //fills some cells
      universe[0][1] = 1;
      universe[1][1] = 1;
      universe[2][1] = 1;
      universe[0][2] = 1;
      universe[1][2] = 1;
      universe[2][2] = 1;
      universe[0][3] = 1;
      universe[1][3] = 1;
      universe[2][3] = 1;


      printUniverse(universe);
      printf("\n\n type 'next' to see the next generation. ");
    free(readin);
    free(args);
      yes++;
      //checks if next was entered
    }else if(strcmp(args[0],"next") == 0){
      nextGeneration(universe,x,y);
      printUniverse(universe);
      free(readin);
      free(args);
    }else if(strcmp(args[0],"add") == 0){
      //checks if save was entered
    }else if(strcmp(args[0],"save") == 0){
      char* buffer = malloc(sizeof(char) * ((y*x) + 3));
      buffer[0] = (char) x;
      buffer[1] = (char) y;
      int b =2;
      for(int i =0; i < x;i++){
        for (int j = 0; j<y; j++){
                buffer[b] = (char) universe[i][j];
                b++;
    }
  }
     write_file("gameSaveTest.txt",buffer, ((x*y)+3));
     printf("%s\n","Game has been saved." );
free(buffer);
      //checks id load was entered

      
    }else if(strcmp(args[0],"load") == 0){
      char* tempBuffer;
      char* fileName = "gameSaveTest.txt";
      universe = malloc(sizeof(int**)* tempBuffer[1]);
      for (int u = 0; u < x; u++){
    universe[u] = malloc(sizeof(int*)* tempBuffer[2]);
  }
      read_file(fileName,&tempBuffer);
      for(int i =0; i < x;i++){
        for (int j = 0; j<y; j++){
              universe[i][j] = (int) tempBuffer[i];

    }
  }

      printf("%s\n","Game has been loaded." );

      yes++;
      //Checks to see if help was entered
  }else if(strcmp(args[0],"help") == 0){
    printf("\nYou may type:");
    printf("\n'next' for next generation\n'add'  for add cells ");
    printf("\n'save' to save current game state.\n'quit' to exit game.");

}else{
  printf("\n invalid command: 'help' for list of commands\n");
  if (yes == 1){
    yes = 0;
  }
}


  }

   return 0;
}
