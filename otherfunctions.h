int write_register(char desti[10], FILE** hexfile)
{
  
   if(strcmp(desti, "R0")==0) fprintf(*hexfile, "0"); 
   else if (strcmp(desti, "R1")==0) fprintf(*hexfile, "1"); 
   else if (strcmp(desti, "R2")==0) fprintf(*hexfile, "2");
   else if (strcmp(desti, "R3")==0) fprintf(*hexfile, "3"); 
   else if (strcmp(desti, "R4")==0) fprintf(*hexfile, "4");
   else if (strcmp(desti, "R5")==0) fprintf(*hexfile, "5"); 
   else if (strcmp(desti, "R6")==0) fprintf(*hexfile, "6");
   else if (strcmp(desti, "R7")==0) fprintf(*hexfile, "7"); 
   else if (strcmp(desti, "R8")==0) fprintf(*hexfile, "8");
   else if (strcmp(desti, "R9")==0) fprintf(*hexfile, "9");
   else if (strcmp(desti, "R10")==0) fprintf(*hexfile, "A"); 
   else if (strcmp(desti, "R11")==0) fprintf(*hexfile, "B");
   else if (strcmp(desti, "R12")==0) fprintf(*hexfile, "C"); 
   else if (strcmp(desti, "R13")==0) fprintf(*hexfile, "D");
   else if (strcmp(desti, "R14")==0) fprintf(*hexfile, "E"); 
   else if (strcmp(desti, "R15")==0) fprintf(*hexfile, "F");
   
      
      
     
    
    ///complete remaining statements......////
    
  return 0;
}


