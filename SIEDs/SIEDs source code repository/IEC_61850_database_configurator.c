/*********************************************IEC 61850 SERVER CONFIGURATOR*************************************************/
                         /*****************(c)Suhas Aggarwal(suhas@iitg.ernet.in)*****************/

#include<stdio.h>
#include<string.h>  
#include<stdlib.h>
#include"tlsf.h"
#include"tlsf.c" 
#define POOL_SIZE (1<<26)
#define pool_size (1<<26)
 

/********************************DATA STRUCTURES FOR HOLDING INFORMATION MODEL COMPONENTS***********************************/


 typedef struct
  {
  int *a;
  float *e;
  }analogue;


/**************************************************DATA TYPES***************************************************************/

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

/*************************************************DATA ATTRIBUTE***********************************************************/ 

  
  typedef struct 
  {
  char name[50];
  char type[20];
  char fc[10];
  char trgop[10];
  tp *value;
  char priority[50];
 }data_attribute;


/*****************************************************DATA******************************************************************/

 
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
  
 
**************************************************LOGICAL NODE**************************************************************/

 typedef struct 
 { 
 char name[20];
 char ref[50]; 
 data *a[20];
 
/*  
  Additional records
    data_set 
    BRCB 
    UBRCB 
    LCB 
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


 *************************************************LOGICAL DEVICE************************************************************/


  typedef struct 
  {
  char name[20]; 
  logical_node *a[20];
  }logical_device;


/************************************************IEC 61850 SERVER**********************************************************/ 

 
 typedef struct 
 { 
 char name[20];
 logical_device *a[20];
 }iec61850_server;
 

/*************************************************COMPONENT OBJECTS*********************************************************/

 iec61850_server *a[10];logical_device *b[20];logical_node *c[20];data *d[20];data_attribute *e[20];

/***************************************************************************************************************************/
 
 int i,j,k,l,choice,flag1,flag2,flag3,flag4,track1=0,track2=0,track3=0,track4=0,loop1=0,loop2=0,loop3=0,loop4=0,mem[20][20][20][20],free_mem,free_memb,size;
 char pool[POOL_SIZE],pool1[pool_size],max[256],marker ='\n'; 
 
/***************************************************************************************************************************/

 int main()
  
 {  
    
/******************************************SERVER CONFIGURATION FILE********************************************************/

   
    FILE *file; 
    file=fopen("IEC_61850_server_configuration_file","w");
    if (!file)
    return 1;
 

/************************************************DATABASE MEMORY***********************************************************/ 
  
    free_mem = init_memory_pool(POOL_SIZE, pool); 
                                                    //MAINTAIN MULTIPLE HEAPS - ONE FOR RECORDS AND ONE FOR DATA BUFFERS
    free_memb = init_memory_pool(pool_size, pool1); 
    
    printf ("\n\nTotal Database memory = %d bytes, used = %d bytes\n",free_mem, (int) get_used_size (pool));
   
  
/*****************************************COMMON DATA CLASSES(UNDER DEVELOPMENT)********************************************/
   
    
    for(i=0;i<20;i++)
   {
     b[i]= (logical_device *) malloc_ex (sizeof(logical_device),pool1); 
     memset(b[i],0,sizeof(logical_device)); 
     
     c[i]= (logical_node *) malloc_ex (sizeof(logical_node),pool1); 
     memset(b[i],0,sizeof(logical_node)); 

     d[i]= (data *) malloc_ex (sizeof(data),pool1);
     memset(d[i],0,sizeof(data));
    
     e[i]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
     memset(e[i],0,sizeof(data_attribute)); 
  
   }
   
   strcpy(d[0]->name,"SPS(UNDER WAY..)");
   
   d[0]->a[0]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
   memset(d[0]->a[0],0,sizeof(data_attribute));
   strcpy(d[0]->a[0]->name,"stVal");
   strcpy(d[0]->a[0]->type,"BOOLEAN");
   strcpy(d[0]->a[0]->fc,"ST");
   strcpy(d[0]->a[0]->trgop,"dchg");
   strcpy(d[0]->a[0]->priority,"M");
   
   d[0]->a[1]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
   memset(d[0]->a[1],0,sizeof(data_attribute));
   strcpy(d[0]->a[1]->name,"subENA");
   strcpy(d[0]->a[1]->type,"BOOLEAN");
   strcpy(d[0]->a[1]->fc,"SV");
   strcpy(d[0]->a[1]->trgop,"NULL");
   strcpy(d[0]->a[1]->priority,"PICS_SUBST");
   
   d[0]->a[2]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
   memset(d[0]->a[2],0,sizeof(data_attribute));
   strcpy(d[0]->a[2]->name,"subVAL");
   strcpy(d[0]->a[2]->type,"BOOLEAN");
   strcpy(d[0]->a[2]->fc,"SV");
   strcpy(d[0]->a[2]->trgop,"NULL");
   strcpy(d[0]->a[2]->priority,"PICS_SUBST");
   
   d[0]->a[3]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
   memset(d[0]->a[3],0,sizeof(data_attribute));
   strcpy(d[0]->a[3]->name,"subID");
   strcpy(d[0]->a[3]->type,"VISIBLESTRING64");
   strcpy(d[0]->a[3]->fc,"SV");
   strcpy(d[0]->a[3]->trgop,"NULL");
   strcpy(d[0]->a[3]->priority,"PICS_SUBST");
   
   d[0]->a[4]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
   memset(d[0]->a[4],0,sizeof(data_attribute));
   strcpy(d[0]->a[4]->name,"d");
   strcpy(d[0]->a[4]->type,"VISIBLESTRING255");
   strcpy(d[0]->a[4]->fc,"DC");
   strcpy(d[0]->a[4]->trgop,"NULL");
   strcpy(d[0]->a[4]->priority,"O");
   
   d[0]->a[5]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
   memset(d[0]->a[5],0,sizeof(data_attribute));
   strcpy(d[0]->a[5]->name,"cdcNs");
   strcpy(d[0]->a[5]->type,"VISIBLESTRING255");
   strcpy(d[0]->a[5]->fc,"EX");
   strcpy(d[0]->a[5]->trgop,"NULL");
   strcpy(d[0]->a[5]->priority,"AC_DLNDA_M");
   
   d[0]->a[6]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
   memset(d[0]->a[6],0,sizeof(data_attribute));
   strcpy(d[0]->a[6]->name,"cdcName");
   strcpy(d[0]->a[6]->type,"VISIBLESTRING255");
   strcpy(d[0]->a[6]->fc,"EX");
   strcpy(d[0]->a[6]->trgop,"NULL");
   strcpy(d[0]->a[6]->priority,"AC_DLNDA_M");

   d[0]->a[7]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool1);
   memset(d[0]->a[7],0,sizeof(data_attribute));
   strcpy(d[0]->a[7]->name,"dataNs");
   strcpy(d[0]->a[7]->type,"VISIBLESTRING255");
   strcpy(d[0]->a[7]->fc,"EX");
   strcpy(d[0]->a[7]->trgop,"NULL");
   strcpy(d[0]->a[7]->priority,"AC_DLN_M");


/*************************************************************************************************************************/  
 
   
   strcpy(b[0]->name,"New Device");
   strcpy(c[0]->name,"New Node");
   strcpy(d[1]->name,"New Data");
   strcpy(e[0]->name,"New Data Attribute"); 
 

/*************************************************IEC 61850 SERVER********************************************************/  
   
   
   a[0]= (iec61850_server *) malloc_ex (sizeof(iec61850_server),pool);
   memset(a[0],0,sizeof(iec61850_server));

   printf("\n***********************************Server Initialisation*****************************************\n\n");
   printf("Please choose the physical device corresponding to which you want to build an IEC 61850 server \n\n");
   printf("1)Circuit Breaker  2)Current Transformer  3)New Device \n");
   scanf("%d",&choice);        
   if (choice == 3)
   {
   printf("Please enter the name of physical device\n");
   scanf("%s",a[0]->name);

/************************************************FEED LOGICAL DEVICE*******************************************************/

   while(1)  
   {
   printf("Please choose the logical devices you want to feed into IEC 61850 server\n");
    
   for(i=0;i<20;i++)
   printf("%d%s\n",i,b[i]->name);
   loop1++;
   scanf("%d",&choice);
   flag1=choice;
   if (strcmp(b[choice]->name,"New Device")==0)
   {
   printf("Please enter the name of the logical device\n");
   a[0]->a[track1]= (logical_device *) malloc_ex (sizeof(logical_device),pool);
   memset(a[0]->a[track1],0,sizeof(logical_device));
   scanf("%s",a[0]->a[track1]->name);
   fwrite(a[0]->a[track1]->name,sizeof(a[0]->a[track1]->name),1,file);
  
/**********************************************FEED LOGICAL NODE***********************************************************/
 
   
   while(1)
   {
   printf("Please choose the logical nodes you wish to enter into logical device\n");
   for(i=0;i<20;i++)
   printf("%d%s\n",i,c[i]->name);
   loop2++;
   scanf("%d",&choice);
   flag2=choice;
   if (strcmp(c[choice]->name,"New Node")==0)
   {
   printf("Please enter the name of logical node\n"); 
   a[0]->a[track1]->a[track2]= (logical_node *) malloc_ex (sizeof(logical_node),pool);
   memset(a[0]->a[track1]->a[track2],0,sizeof(logical_node));
   scanf("%s",a[0]->a[track1]->a[track2]->name);   
   fwrite(a[0]->a[track1]->a[track2]->name,sizeof(a[0]->a[track1]->a[track2]->name),1,file);
  

/************************************************FEED DATA*****************************************************************/
 
  
   while(1)
   {
   printf("Please choose the data you want to feed into logical nodes\n");
   for(i=0;i<20;i++)   
   printf("%d%s\n",i,d[i]->name);
   loop3++;
   scanf("%d",&choice);
   flag3=choice;
   if(strcmp(d[choice]->name,"New Data")==0)
   {
    printf("Please enter the name of data you want to feed in the logical node\n");        
    a[0]->a[track1]->a[track2]->a[track3]= (data *) malloc_ex (sizeof(data),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3],0,sizeof(data));   
    scanf("%s",a[0]->a[track1]->a[track2]->a[track3]->name);   
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->name,sizeof(a[0]->a[track1]->a[track2]->a[track3]->name),1,file);
	


/*******************************************FEED DATA ATTRIBUTE*************************************************************/

    while(1)
   {
   printf("Please choose the data attribute you want to feed into logical node\n");
   for(i=0;i<20;i++)
   printf("%d%s\n",i,e[i]->name);
   loop4++;
   scanf("%d",&choice);
   flag4=choice;
   
    if(strcmp(e[choice]->name,"New Data Attribute")==0)
   {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]= (data_attribute *) malloc_ex (sizeof(data_attribute),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4],0,sizeof(data_attribute));
    printf("Please enter the name of new data attribute\n");
    scanf("%s",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->name);   
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->name,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->name),1,file);
	
    printf("Please enter the functional constraint\n");
    scanf("%s",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->fc);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->fc,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->fc),1,file);
    printf("Please enter the trigger option\n");
    scanf("%s",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->trgop);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->trgop,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->trgop),1,file);
    printf("Please enter the value in M/O/C field\n");
    scanf("%s",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->priority);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->priority,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->priority),1,file);
     printf("Please enter the type of data attribute\n");
     scanf("%s",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type),1,file);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value=(tp *) malloc_ex (sizeof(tp),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value,0,sizeof(tp));
    
    
    
   if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT32")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a=(int *) malloc_ex (sizeof(int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a,0,sizeof(int));
    printf("Please enter the value \n");   
    scanf("%d",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a),1,file);
    }
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT32U")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b=(unsigned int *) malloc_ex (sizeof(unsigned int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b,0,sizeof(unsigned int));
    printf("Please enter the value \n");   
    scanf("%d",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b),1,file);
    } 
    
   
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT16")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c=(short int *) malloc_ex (sizeof(short int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c,0,sizeof(short int));
    printf("Please enter the value \n");   
    scanf("%d",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c); 
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c),1,file);
    }
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT16U")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d=(unsigned short int *) malloc_ex (sizeof(unsigned short int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d,0,sizeof(unsigned short int));
    printf("Please enter the value \n");   
    scanf("%d",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d);  
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d),1,file);
    }
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"FLOAT32")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e=(float *) malloc_ex (sizeof(float),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e,0,sizeof(float));
    printf("Please enter the value \n");   
    scanf("%f",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e); 
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e),1,file);
    }
    
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"BOOLEAN")==0)
    { 
    printf("Please enter the value \n");  
    scanf("%s",max);
    size=strlen(max);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f=(char *) malloc_ex (sizeof(char[size]),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f,0,sizeof(char[size]));
    strcpy(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f,max);
    fwrite(&size,sizeof(int),1,file);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f,sizeof(char[size]),1,file);
    }
    
   
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"VISIBLESTRING64")==0)
    { 
    printf("Please enter the value \n");   
    scanf("%s",max);
    size=strlen(max);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h=(char *) malloc_ex (sizeof(char[size]),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h,0,sizeof(char[size]));
    strcpy(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h,max);
    fwrite(&size,sizeof(int),1,file);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h,sizeof(char[size]),1,file);
    }
    
   
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"VISIBLESTRING255")==0)
    { 
    printf("Please enter the value \n");   
    scanf("%s",max);
    size=strlen(max);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i=(char *) malloc_ex (sizeof(char[size]),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i,0,sizeof(char[size]));
    strcpy(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i,max);
    fwrite(&size,sizeof(int),1,file);
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i,sizeof(char[size]),1,file);
    }
   
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"ANALOGUE")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g=(analogue *) malloc_ex (sizeof(analogue),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g,0,sizeof(analogue));
    
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a=(int *) malloc_ex (sizeof(int),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a,0,sizeof(int));
    
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e=(float *) malloc_ex (sizeof(float),pool);
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e,0,sizeof(float));
    
    printf("Please enter the integer value \n");   
    scanf("%d",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a); 
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a),1,file);
    
     printf("Please enter the float value \n");   
    scanf("%f",a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e); 
    fwrite(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e),1,file);
    }
    track4++;
    
    }
   
    printf("\nDo you want to feed more data attributes (0/1)");
    scanf("%d",&k);
    if(k==0)
    {
    fwrite(&marker,sizeof(char),1,file);
    mem[track1+1][track2+1][track3+1][0]=track4;
    track4=0;
    break;
    }
   
/**************************************************************************************************************************/

    }
     track3++;
    }
    
    printf("\nDo you want to feed more data (0/1)");
    scanf("%d",&k);
    if(k==0) 
    {
    fwrite(&marker,sizeof(char),1,file);
    mem[track1+1][track2+1][0][0]=track3;
    track3=0;
    break;
    } 
    
/***************************************************************************************************************************/

    }
    track2++;
    }
   
    printf("\nDo you want to enter more logical nodes (0/1)");
    scanf("%d",&k);
    if(k==0)
    {
    fwrite(&marker,sizeof(char),1,file);
    mem[track1+1][0][0][0]=track2;
    track2=0;
    break;
    }
    
/**************************************************************************************************************************/
   
    }
    track1++;
    }
    
     printf("\nDo you want to enter more logical devices (0/1)");
    scanf("%d",&k);
    if(k==0) 
    {
    break;
    }
    
/**************************************************************************************************************************/

    }
    }

    printf ("\n\nTotal used memory for database\n = %d bytes",(int) get_used_size (pool));
    printf ("\nTotal used memory for data buffers = %d bytes\n\n\n",(int) get_used_size (pool1));

    fclose(file);
    return 0;
}
 
/***************************************************************************************************************************/














