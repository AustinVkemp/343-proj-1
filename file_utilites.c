#include <stdio.h>
#include <stdlib.h>
#include "file_utilites.h"

/*
* c file for the save and load
*
* @author Lanndon Rose
*/


/*
load file method
@param filename - the file being loaded from
@param buffer - whats being loaded from a while
*/
int read_file( char* filename, char** buffer ){

  FILE *sfile;
sfile=fopen(filename,"rb");
int size = 0;
long fsize;
fscanf(sfile,"%d", &size);

if(!sfile) {
    printf("Read Error!");
}


fseek( sfile, 0L, SEEK_END);
fsize = ftell( sfile );
rewind( sfile);

*buffer = (char*) malloc(sizeof(char)*fsize);

if( 1!=fread( *buffer,fsize, 1, sfile) )
return -1;

// while(sfile!= NULL){
//   fscanf(sfile,"%d",(int *)*buffer);
// }


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
  fprintf(sfile, "%d\n", size);

for(i=0;i<size;i++)
{
 fprintf(sfile, "%d\n",buffer[i]);
}
fclose(sfile);
return 0;
}
