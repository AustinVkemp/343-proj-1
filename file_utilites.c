#include <stdio.h>
#include <stdlib.h>
#include "file_utilites.h"

/*
* c file for the save and load
*
* @author Lanndon Rose
* @author Austin Van Kempen
*/


/*
load file method
@param filename - the file being loaded from
@param buffer - whats being loaded from a while
*/
int read_file( char* filename, char** buffer ){

  FILE *sfile;
sfile=fopen(filename,"r");
int size = 0;
int fsize;
fscanf(sfile,"%d", &size);

if(!sfile) {
    printf("Read Error!");
}


fseek( sfile, 0L, SEEK_END);
fsize = ftell( sfile );
rewind( sfile);

  *buffer = (char*) malloc(sizeof(char)*fsize);
fgets(*buffer,fsize, sfile);






fclose(sfile);


  return 0;
}

/*
save file method
@param filename - the file being saved to
@param buffer - whats being saved to the file.
@param size - the size to make the save file.
*/
int write_file(char* filename, char* buffer, int size){

  FILE *sfile;
sfile=fopen(filename,"w");
int i;


    if(!sfile) {
        printf("Write Error!");
    }
  fprintf(sfile, "%d", size);

for(i=0;i<size -1;i++)
{
 fprintf(sfile, "%d",buffer[i]);
}
fprintf(sfile, "%d",buffer[i+1]);
fclose(sfile);
return 0;
}
