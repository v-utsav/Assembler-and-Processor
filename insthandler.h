#include "otherfunctions.h"
int NextInstruction(FILE** infile, FILE** hexfile, int * ptrPC)
{

  int i=0;
  int j=0;
  char textline[100];
  char opcode[10];
  char des[10];
  char source1[10];
  char source2[10];
  char immdata[10];
  textline[0] = '\0';
  opcode[0] = '\0';
  des[0] = '\0';
  source1[0] = '\0';
  source2[0] = '\0';
  immdata[0] = '\0';
  
  
  if(fgets(textline, sizeof(textline), *infile) == NULL)
  {
    printf("We were NOT able to read one instruction");
    return -1;
  }
  else 
  {
    printf("We were able to read one text-instruction of legnth %lu: %s", strlen(textline), textline);
    ////Lets separate the parts///////////////
    i=0; j=0;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      opcode[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    opcode[j]='\0';
    *ptrPC = *ptrPC +1;
    printf("PC = %d\n", *ptrPC);
    printf("We seperated the opcode: %s\n",opcode);
    goto labelopcodeknown;
    ////We are taking a diversion from here, and doing things as per opcode/////
  }
  
  //////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////
  //////Go here once you know the opcode////////////////
  labelopcodeknown:

  if(strcmp(opcode, "NOP")==0)
  {
    /////
      printf("We got a match to NOP, hence inserting hex code\n");
      fprintf(*hexfile, "0000000");
      fprintf(*hexfile, "\n");
		return 0;    

  }
  
  else if(strcmp(opcode, "AND")==0)
  {
    /////
      printf("We got a match to AND, hence inserting hex code\n");
      fprintf(*hexfile, "01");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source2[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source2[j] = '\0';
    printf("We seperated the source2 register: %s\n", source2);
    write_register(source2, hexfile);
    fprintf(*hexfile, "00");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "OR")==0)
  {
    /////
      printf("We got a match to OR, hence inserting hex code\n");
      fprintf(*hexfile, "02");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source2[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source2[j] = '\0';
    printf("We seperated the source2 register: %s\n", source2);
    write_register(source2, hexfile);
    fprintf(*hexfile, "00");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "ExOR")==0)
  {
    /////
      printf("We got a match to ExOR, hence inserting hex code\n");
      fprintf(*hexfile, "03");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source2[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source2[j] = '\0';
    printf("We seperated the source2 register: %s\n", source2);
    write_register(source2, hexfile);
    fprintf(*hexfile, "00");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "ADD")==0)
  {
    /////
      printf("We got a match to ADD, hence inserting hex code\n");
      fprintf(*hexfile, "04");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source2[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source2[j] = '\0';
    printf("We seperated the source2 register: %s\n", source2);
    write_register(source2, hexfile);
    fprintf(*hexfile, "00");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "ANDI")==0)
  {
    /////
      printf("We got a match to ANDI, hence inserting hex code\n");
      fprintf(*hexfile, "05");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, "0");
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "ORI")==0)
  {
    /////
      printf("We got a match to ORI, hence inserting hex code\n");
      fprintf(*hexfile, "06");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, "0");
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "ExORI")==0)
  {
    /////
      printf("We got a match to ExORI, hence inserting hex code\n");
      fprintf(*hexfile, "07");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, "0");
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "ADDI")==0)
  {
    /////
      printf("We got a match to ADDI, hence inserting hex code\n");
      fprintf(*hexfile, "08");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, "0");
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "MOV")==0)
  {
    /////
      printf("We got a match to MOV, hence inserting hex code\n");
      fprintf(*hexfile, "09");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    fprintf(*hexfile, "000");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "MOVI")==0)
  {
    /////
      printf("We got a match to MOVI, hence inserting hex code\n");
      fprintf(*hexfile, "0A");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    fprintf(*hexfile, "00");
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "LOAD")==0)
  {
    /////
      printf("We got a match to LOAD, hence inserting hex code\n");
      fprintf(*hexfile, "0B");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    fprintf(*hexfile, "00");
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "STORE")==0)
  {
    /////
      printf("We got a match to STORE, hence inserting hex code\n");
      fprintf(*hexfile, "0C");
      fprintf(*hexfile, "0");
    ///Now we begin seperating the other components...//
    j=0;
    i=i+4;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      source1[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n",source1);
    write_register(source1, hexfile);
    fprintf(*hexfile, "0");
    
    j = 0;
    i = i - 5;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }  
  
  else if(strcmp(opcode, "JMP")==0)
  {
    /////
      printf("We got a match to JMP, hence inserting hex code\n");
      fprintf(*hexfile, "0D");
      fprintf(*hexfile, "000");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "JMPZ")==0)
  {
    /////
      printf("We got a match to JMPZ, hence inserting hex code\n");
      fprintf(*hexfile, "0E");
      fprintf(*hexfile, "000");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "JMPNZ")==0)
  {
    /////
      printf("We got a match to JMPNZ, hence inserting hex code\n");
      fprintf(*hexfile, "0F");
      fprintf(*hexfile, "000");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "JMPC")==0)
  {
    /////
      printf("We got a match to JMPC, hence inserting hex code\n");
      fprintf(*hexfile, "10");
      fprintf(*hexfile, "000");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "JMPNC")==0)
  {
    /////
      printf("We got a match to JMPNC, hence inserting hex code\n");
      fprintf(*hexfile, "11");
      fprintf(*hexfile, "000");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "PUSH")==0)
  {
    /////
      printf("We got a match to PUSH, hence inserting hex code\n");
      fprintf(*hexfile, "12");
      fprintf(*hexfile, "0");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 data: %s\n", source1);
    write_register(source1, hexfile);
    fprintf(*hexfile, "000");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "POP")==0)
  {
    /////
      printf("We got a match to POP, hence inserting hex code\n");
      fprintf(*hexfile, "13");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      des[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    des[j] = '\0';
    printf("We seperated the des data: %s\n", des);
    write_register(des, hexfile);
    fprintf(*hexfile, "0000");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "IN")==0)
  {
    /////
      printf("We got a match to IN, hence inserting hex code\n");
      fprintf(*hexfile, "14");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      des[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    des[j] = '\0';
    printf("We seperated the des data: %s\n", des);
    write_register(des, hexfile);
    fprintf(*hexfile, "00");
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    des[j] = '\0';
    printf("We seperated the immdata: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    return 0; 
  }
  
  else if(strcmp(opcode, "OUT")==0)
  {
    /////
      printf("We got a match to OUT, hence inserting hex code\n");
      fprintf(*hexfile, "15");
      fprintf(*hexfile, "0");
    ///Now we begin seperating the other components...//
    j=0;
    i=i+4;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      source1[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n",source1);
    write_register(source1, hexfile);
    fprintf(*hexfile, "0");
    
    j = 0;
    i = i - 6;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  } 
  
  else if(strcmp(opcode, "LOADI")==0)
  {
    /////
      printf("We got a match to LOADI, hence inserting hex code\n");
      fprintf(*hexfile, "16");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      des[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    des[j] = '\0';
    printf("We seperated the des data: %s\n", des);
    write_register(des, hexfile);
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1: %s\n", source1);
    write_register(source1, hexfile);
    fprintf(*hexfile, "000");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "STOREI")==0)
  {
    /////
      printf("We got a match to STOREI, hence inserting hex code\n");
      fprintf(*hexfile, "17");
      fprintf(*hexfile, "0");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source2[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source2[j] = '\0';
    printf("We seperated the source2 register: %s\n", source2);
    write_register(source2, hexfile);
    fprintf(*hexfile, "00");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "SUB")==0)
  {
    /////
      printf("We got a match to SUB, hence inserting hex code\n");
      fprintf(*hexfile, "18");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source2[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source2[j] = '\0';
    printf("We seperated the source2 register: %s\n", source2);
    write_register(source2, hexfile);
    fprintf(*hexfile, "00");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "SHIFTR")==0)
  {
    /////
      printf("We got a match to SHIFTR, hence inserting hex code\n");
      fprintf(*hexfile, "19");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source2[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source2[j] = '\0';
    printf("We seperated the source2 register: %s\n", source2);
    write_register(source2, hexfile);
    fprintf(*hexfile, "00");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "SHIFTL")==0)
  {
    /////
      printf("We got a match to SHIFTL, hence inserting hex code\n");
      fprintf(*hexfile, "1A");
    ///Now we begin seperating the other components...///
    j=0;
    i=i+1;
    while(textline[i]!=',' && textline[i]!=';' && textline[i]!='\0')
    {
      des[j] = textline[i];
      i=i+1;
      j=j+1;
    }
    des[j] = '\0';
    printf("We seperated the destination register: %s\n",des);
    write_register(des, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source1[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source1[j] = '\0';
    printf("We seperated the source1 register: %s\n", source1);
    write_register(source1, hexfile);
    
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      source2[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    source2[j] = '\0';
    printf("We seperated the source2 register: %s\n", source2);
    write_register(source2, hexfile);
    fprintf(*hexfile, "00");
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else if(strcmp(opcode, "JMPPCRZ")==0)
  {
    /////
      printf("We got a match to JMPPCRZ, hence inserting hex code\n");
      fprintf(*hexfile, "1B");
      fprintf(*hexfile, "000");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  } 
  
  else if(strcmp(opcode, "JMPPCRNZ")==0)
  {
    /////
      printf("We got a match to JMPPCRNZ, hence inserting hex code\n");
      fprintf(*hexfile, "1C");
      fprintf(*hexfile, "000");
    ///Now we begin seperating the other components...//
    
    j = 0;
    i = i + 1;
    while(textline[i] != ',' && textline[i] != ';' && textline[i] != '\0')
    {
      immdata[j] = textline[i];
      i = i+1;
      j = j+1;
    }
    immdata[j] = '\0';
    printf("We seperated the immediate data: %s\n", immdata);
    fprintf(*hexfile, immdata);
    fprintf(*hexfile, "\n");
    
    return 0;
  }
  
  else
  {
      printf("No such %s opcode, exiting this function\n", opcode);
    	return -1;
  }
  
  
 
  
  
  
 
  
}
