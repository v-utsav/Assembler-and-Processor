#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filehandler.h"
#include "insthandler.h"


FILE *asmFP=NULL,*hexFP=NULL;
int PC = -1;
char immdata[10];

int main()
{
  
  	int error=0;
  	error=openFiles(&asmFP,&hexFP);
  	if(error)
    {
      printf("Error while opening the files\n");
      return -1;
    }
  	while(NextInstruction(&asmFP, &hexFP, &PC)!=-1);
	
   
    // close the file
  	closeFiles(&asmFP,&hexFP);
    return 0;
}
