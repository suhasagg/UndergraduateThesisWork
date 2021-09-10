

/************************************************IEC 61850 MAIN MEMORY DATABASE*********************************************/
                            /*****************(c)Suhas Aggarwal (suhas@iitg.ernet.in)****************/
#include<stdio.h>
#include<string.h>  
#include<stdlib.h>
#include"tlsf.h"
#include"tlsf.c"
#define POOL_SIZE (1<<26)
 
/****************************************************DATA STRUCUTRES*******************************************************/ 

  typedef struct
  {
  int *a;
  float *e;
  }analogue;

/**************************************************************************************************************************/

  typedef struct 
  {   
  int *a;
  unsigned int *b;
  short int *c;
  unsigned short int *d;
  float *e;
  char *f;
  analogue *g;
  char *h;
  char *i; 
  }tp;

/***************************************************************************************************************************/

 typedef struct 
 {
  char name[50];
  char type[20];
  char fc[10];
  char trgop[10];
  tp *value;
  char priority[50];
 }data_attribute;


/**************************************************************************************************************************/ 

 typedef struct 
 {
  char name[20];
  data_attribute *a[20];
 }data;
  
/*************************************************************************************************************************** 
 
 typedef struct 
 {
  char name[20]; 
  data *a[20];
  data_attribute *b[20];
 }data_set;
  
 **************************************************************************************************************************/

 typedef struct 
 { 
 char name[20];
 char ref[50]; 
 data *a[20];
/*BRCB c[20];
  UBRCB d[20];
  LCB e[20];
*/
 }logical_node;

/***************************************************************************************************************************


 struct BRCB
 { 
  BRCBName,URCBRef
  RptID,RptEna,DatSet,ConfRev,BufTm,SqNum,Trgop,IntgPD,GI,PurgeBuf,EntryID,TimeofEntry,OptFlds
 }

 struct UBRCB
 { 
 UBRCBName,UBRCBref
 RptID,RptEna,Resv,DatSet,ConfRev,BufTm,SqNum,Trgop,IntgPD,GI,OptFlds
 }

 struct LCB
 { 
 LCBName,LCBref,LogRef
 LogEna,DatSet,Trgop,IntgPd,OptFlds 
 }

 struct LLN0
 {
 GOOSE,GSSE Control Blocks    
 }
 
 struct LPHD
 {
 }


***************************************************************************************************************************/

 
 typedef struct 
  {
  char name[20]; 
  logical_node *a[20];
  }logical_device;
 

/***************************************************************************************************************************/


 typedef struct 
 { 
 char name[20];
 logical_device *a[20];
 }iec61850_server;
 

/*****************************************************SERVER OBJECT*********************************************************/


 iec61850_server *a[10];
 

/***************************************************************************************************************************/

 
 int i,j,k,l,choice,flag1,flag2,flag3,flag4,track1=0,track2=0,track3=0,track4=0,loop1=0,loop2=0,loop3=0,loop4=0,mem[20][20][20][20],free_mem,size;
 char pool[POOL_SIZE],mark_tester; 

 int main()
  
 {  
 
/******************************CONFIGURATION FILE FROM WHICH SERVER WILL READ DATABASE IMAGE********************************/

    
    FILE *file; 
    file=fopen("IEC_61850_server_configuration_file","r");
    
    if (!file)
    return 1;


/*****************************************INITIALISE HEAP FOR THE DATABASE************************************************/
   
    
    free_mem = init_memory_pool(POOL_SIZE, pool); 


/**************************************************************************************************************************/
    
    
    a[0]= (iec61850_server *) malloc_ex (sizeof(iec61850_server),pool);
    memset(a[0],0,sizeof(iec61850_server));
    memset(mem,0,sizeof(mem));
   
 
/*************************************START TAKING INPUT FROM SERVER CONFIGURATION FILE************************************/
  

   while(1)  
   {
    
   loop1++;
   a[0]->a[track1]= (logical_device *) malloc_ex (sizeof(logical_device),pool);
   memset(a[0]->a[track1],0,sizeof(logical_device));
   fread(a[0]->a[track1]->name,sizeof(a[0]->a[track1]->name),1,file);


/*************************************************************************************************************************/  

   while(1)
   {
   
   loop2++;
    
   a[0]->a[track1]->a[track2]= (logical_node *) malloc_ex (sizeof(logical_node),pool);
   memset(a[0]->a[track1]->a[track2],0,sizeof(logical_node));
   fread(a[0]->a[track1]->a[track2]->name,sizeof(a[0]->a[track1]->a[track2]->name),1,file);

/***************************************************************************************************************************/

   while(1)
   {
  
   loop3++;
  
   a[0]->a[track1]->a[track2]->a[track3]= (data *) malloc_ex (sizeof(data),pool);
   memset(a[0]->a[track1]->a[track2]->a[track3],0,sizeof(data));   
   fread(a[0]->a[track1]->a[track2]->a[track3]->name,sizeof(a[0]->a[track1]->a[track2]->a[track3]->name),1,file);
  
/***************************************************************************************************************************/
 
   while(1)
   {
   
    loop4++;
  
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4],0,sizeof(data_attribute));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->name,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->name),1,file);
	fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->fc,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->fc),1,file);
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->trgop,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->trgop),1,file);
	fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->priority,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->priority),1,file);
	fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type),1,file);
	a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value=(tp *) malloc_ex (sizeof(tp),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value,0,sizeof(tp));

    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT32")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a=(int *) malloc_ex (sizeof(int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a,0,sizeof(int));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a),1,file);
    }
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT32U")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b=(unsigned int *) malloc_ex (sizeof(unsigned int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b,0,sizeof(unsigned int));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b),1,file);
    } 
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT16")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c=(short int *) malloc_ex (sizeof(short int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c,0,sizeof(short int));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c),1,file);
    }
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT16U")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d=(unsigned short int *) malloc_ex (sizeof(unsigned short int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d,0,sizeof(unsigned short int));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d),1,file);
    }
    
   
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"FLOAT32")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e=(float *) malloc_ex (sizeof(float),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e,0,sizeof(float));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e),1,file);
    }
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"BOOLEAN")==0)
    { 
    fread(&size,sizeof(int),1,file);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f=(char *) malloc_ex (sizeof(char[size]),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f,0,sizeof(char[size]));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f,sizeof(char[size]),1,file);
    }
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"VISIBLESTRING64")==0)
    { 
    fread(&size,sizeof(int),1,file);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h=(char *) malloc_ex (sizeof(char[size]),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h,0,sizeof(char[size]));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h,sizeof(char[size]),1,file);
    }
    
 
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"VISIBLESTRING255")==0)
    { 
    fread(&size,sizeof(int),1,file);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i=(char *) malloc_ex (sizeof(char[size]),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i,0,sizeof(char[size]));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i,sizeof(char[size]),1,file);
    }
    

    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"ANALOGUE")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g=(analogue *) malloc_ex (sizeof(analogue),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g,0,sizeof(analogue));
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a=(int *) malloc_ex (sizeof(int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a,0,sizeof(int));
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e=(float *) malloc_ex (sizeof(float),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e,0,sizeof(float));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a),1,file);
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e),1,file);
     }
    
     track4++;

     fread(&mark_tester,1,1,file);
    
     if(mark_tester == '\n')
     {
     mem[track1+1][track2+1][track3+1][0]=track4;
     track4=0;
     break;
     }
    
     else
     fseek(file,-1,SEEK_CUR);
     }
/**********************************************************************************************************************/     
    
    track3++;
     
    fread(&mark_tester,1,1,file);
    
    if(mark_tester == '\n') 
    {
     mem[track1+1][track2+1][0][0]=track3;
     track3=0;
     break;
    } 
    
    else
    fseek(file,-1,SEEK_CUR);  
    } 
    
/************************************************************************************************************************/

    track2++;
    
    fread(&mark_tester,1,1,file);
   
    if(mark_tester == '\n')
    {
    mem[track1+1][0][0][0]=track2;
    track2=0;
    break;
    }
    
    else
    fseek(file,-1,SEEK_CUR);  
    }
 
/*************************************************************************************************************************/
   
    track1++;
    
    fread(&mark_tester,1,1,file);
	
    if(mark_tester == '\n') 
    {
    break;
    }
    
    else
    fseek(file,-1,SEEK_CUR);  
    }
    
 
/***************************************************MAIN MENU*********************************************************/	
   
 
  while(1)
   {

      
   printf("**************************************IEC 61850 SERVER : %s********************************\n\n\n\n",a[0]->name);
   
   printf("******************************************Main Menu*********************************************************\n");
  
   printf("***********************************1)Display Directory Hierarchy********************************************\n");
   
   printf("****************************************2)Edit Settings*****************************************************\n");
   
   printf("****************************************3)ReInitialise******************************************************\n");
   
   printf("****************************************4)Shutdown**********************************************************\n");
   
   

    scanf("%d",&choice);


/***********************************************DISPLAY INTERFACE**********************************************************/
   
    if(choice == 1)
    { 
    
    printf("------------------------------1)View Logical Devices Directory---------------------\n");
    printf("------------------------------2)View Logical Nodes Directory-----------------------\n");
    printf("------------------------------3)View Data Directory--------------------------------\n");
    printf("------------------------------4)View Data sets-------------------------------------\n");
    scanf("%d",&choice);

/******************************************************LOGICAL DEVICE****************************************************/   
   
    if(choice == 1)
    {
    for(i=0;i<track1;i++)
    {
    printf("%d%s\n",i,a[0]->a[i]->name);
    } 
    }  

/****************************************************LOGICAL NODE***********************************************************/
   
    if(choice == 2)
    {
    for(i=0;i<track1;i++)
    {
    printf("%d%s\n",i,a[0]->a[i]->name);
     
     for(j=0;j<mem[i+1][0][0][0];j++)
     printf("%d%s\n",j,a[0]->a[i]->a[j]->name);
    }
    }
 
/*****************************************************DATA*****************************************************************/ 
  
   if(choice == 3)
    {
     for(i=0;i<track1;i++)
    { 
     printf("logical device\n");
     printf("%d%s\n",i,a[0]->a[i]->name);
     
     for(j=0;j<mem[i+1][0][0][0];j++)
    { 
     printf("logical node\n");
     printf("%d%s\n",j,a[0]->a[i]->a[j]->name);
    
      for(k=0;k<mem[i+1][j+1][0][0];k++)
    { 
     printf("data\n");
     printf("%d%s\n",k,a[0]->a[i]->a[j]->a[k]->name);
    
      for(l=0;l<mem[i+1][j+1][k+1][0];l++)
    {
     printf("data attribute\n");
     printf("%d%s\t",l,a[0]->a[i]->a[j]->a[k]->a[l]->name);
     printf("%d%s\t",l,a[0]->a[i]->a[j]->a[k]->a[l]->fc);
     printf("%d%s\t",l,a[0]->a[i]->a[j]->a[k]->a[l]->trgop);
     printf("%d%s\t",l,a[0]->a[i]->a[j]->a[k]->a[l]->priority);
     printf("%d%s\t",l,a[0]->a[i]->a[j]->a[k]->a[l]->type);
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"INT32")==0)
     printf("%d\n",*(a[0]->a[i]->a[j]->a[k]->a[l]->value->a));
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"INT32U")==0)
     printf("%d\n",*(a[0]->a[i]->a[j]->a[k]->a[l]->value->b));
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"INT16")==0)
     printf("%d\n",*(a[0]->a[i]->a[j]->a[k]->a[l]->value->c));
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"INT16U")==0)
     printf("%d\n",*(a[0]->a[i]->a[j]->a[k]->a[l]->value->d));
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"FLOAT32")==0)
     printf("%f\n",*(a[0]->a[i]->a[j]->a[k]->a[l]->value->e));
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"BOOLEAN")==0)
     printf("%s\n",a[0]->a[i]->a[j]->a[k]->a[l]->value->f);
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"VISIBLESTRING64")==0) 
     printf("%s\n",a[0]->a[i]->a[j]->a[k]->a[l]->value->h);
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"VISIBLESTRING255")==0)
     printf("%s\n",a[0]->a[i]->a[j]->a[k]->a[l]->value->i);
     if(strcmp(a[0]->a[i]->a[j]->a[k]->a[l]->type,"ANALOGUE")==0)  
     {
     printf("%d\t",*(a[0]->a[i]->a[j]->a[k]->a[l]->value->g->a));
     printf("%f\t\n",*(a[0]->a[i]->a[j]->a[k]->a[l]->value->g->e));
     }
    }
    }  
    }
    }
    }
    
  }


/******************************************************SHUTDOWN*************************************************************/


   if(choice == 4)
   exit(0);
 }
 

/***************************************************************************************************************************/
 
 fclose(file);
 return 0;

  }

/***************************************************************************************************************************/








