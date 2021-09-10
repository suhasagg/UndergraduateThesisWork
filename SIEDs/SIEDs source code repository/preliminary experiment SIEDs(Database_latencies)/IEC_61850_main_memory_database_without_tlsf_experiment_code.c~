#include<stdio.h>
#include<string.h>  
#include<stdlib.h>
#include<time.h>


 
 typedef struct
  {
  int *a;
  float *e;
  }analogue;

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

 typedef struct 
 {
  char name[50];
  char type[20];
  char fc[10];
  char trgop[10];
  tp *value;
  char priority[50];
 }data_attribute;

 typedef struct 
 {
  char name[20];
  data_attribute *a[20];
 }data;
  
  
 typedef struct 
 {
  char name[20]; 
  data *a[20];
  data_attribute *b[20];
 }data_set;
  
 
 typedef struct 
 { 
 char name[20];
 char ref[50]; 
 data *a[20];
 data_set *b[20];
/*BRCB c[20];
  UBRCB d[20];
  LCB e[20];
*/
 }logical_node;

 /*struct BRCB
 { char BRCBName[20],URCBRef[50];
  data_attribute RptID,RptEna,DatSet,ConfRev,BufTm,SqNum,Trgop,IntgPD,GI,PurgeBuf,EntryID,TimeofEntry;
  bool OptFlds[8];
 };

 struct UBRCB
 { char UBRCBName[20],UBRCBref[50];
   data_attribute RptID,RptEna,Resv,DatSet,ConfRev,BufTm,SqNum,Trgop,IntgPD,GI;
   bool OptFlds[8];
 };

 struct LCB
 { char LCBName[20],LCBref[50],LogRef[50];
   data_attribute LogEna,DatSet,Trgop,IntgPd; 
   bool OptFlds[2]; 
 };


  struct LLN0
{
 objects for goose,gsse,group,multicast,unicast,control blocks    
}
 
 struct LPHD
{
}*/

 typedef struct 
  {
  char name[20]; 
  logical_node *a[20];
  }logical_device;
 

 typedef struct 
 { 
 char name[20];
 logical_device *a[20];
 }iec61850_server;
 
 iec61850_server *a[10];
 
 int i,j,k,l,choice,flag1,flag2,flag3,flag4,track1=0,track2=0,track3=0,track4=0,loop1=0,loop2=0,loop3=0,loop4=0,mem[20][20][20][20],free_mem,c1,c2,size;
 double t;
 char mark_tester; 

 int main()
  
 {  
    

    FILE *file; 
    file=fopen("IEC_61850_server_configuration_file","r");
    
    if (!file)
    return 1;
    
    memset(mem,0,sizeof(mem));
    c1=clock();
 
/**********************************************CODE FRAGMENT BEING TIMED****************************************************/
     
    a[0]= (iec61850_server *) malloc (sizeof(iec61850_server));
    memset(a[0],0,sizeof(iec61850_server));
    
   
/*-------------------------------------------------Information Model-------------------------------------------------------*/
  

  
   
   while(1)  
   {
    
   loop1++;
   a[0]->a[track1]= (logical_device *) malloc (sizeof(logical_device));
   memset(a[0]->a[track1],0,sizeof(logical_device));
   fread(a[0]->a[track1]->name,sizeof(a[0]->a[track1]->name),1,file);
   while(1)
   {
   
   loop2++;
    
   a[0]->a[track1]->a[track2]= (logical_node *) malloc (sizeof(logical_node));
   memset(a[0]->a[track1]->a[track2],0,sizeof(logical_node));
   fread(a[0]->a[track1]->a[track2]->name,sizeof(a[0]->a[track1]->a[track2]->name),1,file);
   while(1)
   {
  
   loop3++;
  
   a[0]->a[track1]->a[track2]->a[track3]= (data *) malloc (sizeof(data));
   memset(a[0]->a[track1]->a[track2]->a[track3],0,sizeof(data));   
   fread(a[0]->a[track1]->a[track2]->a[track3]->name,sizeof(a[0]->a[track1]->a[track2]->a[track3]->name),1,file);
   
   while(1)
   {
   
    loop4++;
  
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]= (data_attribute *) malloc (sizeof(data_attribute));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4],0,sizeof(data_attribute));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->name,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->name),1,file);
	fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->fc,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->fc),1,file);
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->trgop,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->trgop),1,file);
	fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->priority,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->priority),1,file);
	fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type),1,file);
	a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value=(tp *) malloc (sizeof(tp));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value,0,sizeof(tp));
    
    if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT32")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a=(int *) malloc (sizeof(int));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a,0,sizeof(int));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->a),1,file);
    }
    
	if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT32U")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b=(unsigned int *) malloc (sizeof(unsigned int));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b,0,sizeof(unsigned int));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->b),1,file);
    } 
    
	if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT16")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c=(short int *) malloc (sizeof(short int));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c,0,sizeof(short int));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->c),1,file);
    }
    
	if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"INT16U")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d=(unsigned short int *) malloc (sizeof(unsigned short int));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d,0,sizeof(unsigned short int));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->d),1,file);
    }
    
	if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"FLOAT32")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e=(float *) malloc (sizeof(float));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e,0,sizeof(float));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e,sizeof(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->e),1,file);
    }
    
	if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"BOOLEAN")==0)
    { 
    fread(&size,sizeof(int),1,file);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f=(char *) malloc (sizeof(char[size]));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f,0,sizeof(char[size]));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->f,sizeof(char[size]),1,file);
    }
    
	if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"VISIBLESTRING64")==0)
    { 
    fread(&size,sizeof(int),1,file);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h=(char *) malloc (sizeof(char[size]));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h,0,sizeof(char[size]));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->h,sizeof(char[size]),1,file);
    }
    
	if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"VISIBLESTRING255")==0)
    { 
    fread(&size,sizeof(int),1,file);
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i=(char *) malloc (sizeof(char[size]));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i,0,sizeof(char[size]));
    fread(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->i,sizeof(char[size]),1,file);
    }
    
      if(strcmp(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->type,"ANALOGUE")==0)
    {
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g=(analogue *) malloc (sizeof(analogue));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g,0,sizeof(analogue));
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a=(int *) malloc (sizeof(int));
    memset(a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->a,0,sizeof(int));
    a[0]->a[track1]->a[track2]->a[track3]->a[track4]->value->g->e=(float *) malloc (sizeof(float));
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
    
    track1++;
    
    fread(&mark_tester,1,1,file);
	
    if(mark_tester == '\n') 
    {
    break;
    }
    
    else
    fseek(file,-1,SEEK_CUR);  
    }
 
/***************************************************************************************************************************/
   
    c2=clock();
    t=c2-c1;
    
    printf ("Time in ticks = %d \n", t );
 
  
    fclose(file);
    return 0;

  }










