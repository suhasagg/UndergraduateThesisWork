/****************************************Preliminary Prototype of Scan Schedular*******************************************/ 
                      /******************(c)Suhas Aggarwal(suhas@iitg.ernet.in)*****************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<time.h>
#include<string.h>
#define MAX 3

/*********************************************** Application buffer********************************************************/

typedef struct {
           
        int App_id;
        char *path;

}App_info;       


typedef struct {
         
        App_info *front,*tail; 
        App_info *container[MAX];

}Application_queue;


Application_queue *aqt,*aqt0; 


/*************************************************************************************************************************/

void set_app_queue()
{


int i=0;
char max_path[100];

aqt = (Application_queue *) malloc (sizeof(Application_queue));

while(i<MAX)
       
        {
        
        printf("Please enter the path of application program\n");
        scanf("%s",max_path);
        aqt->container[i]= (App_info *) malloc (sizeof(App_info));  
        aqt->container[i]->path = (char *) malloc (strlen(max_path));
        strcpy(aqt->container[i]->path,max_path);
        aqt->container[i]->App_id=i;
        i++;
        
        }
     
       aqt->front=(App_info *) malloc (sizeof(App_info)); 
       aqt->front=aqt->container[0];
       aqt->tail=(App_info *) malloc (sizeof(App_info));       
       aqt->tail=aqt->container[MAX-1];
 
     
}
 

/**************************************************************************************************************************/

void reset_app_queue()
{

int i;
App_info *temp;
temp=(App_info *) malloc (sizeof(App_info)); 
temp=aqt->front;
for(i=0;i<MAX-1;i++)
aqt->container[i]=aqt->container[i+1];
aqt->container[2]=temp;
aqt->front=aqt->container[0];
aqt->tail=temp;

}

/***************************************************************************************************************************/


/* void storestate()
  {

  } */


/****************************************Application-schedular interaction interface****************************************/


#define PATHNAME_FTOK	"/etc/services"
#define PERMISSION	0666


typedef struct Message{

	long mtype;
	int data; // message_code

}Message;


/*********************************************Message Queue API*************************************************************/

int CreateMessageQueue(int a)
{
	int messageQ;
	key_t key;

	if((key = ftok(PATHNAME_FTOK,a)) == -1)
	{
		perror("FTOK() failed ! - exiting \n");
		exit(-1);
	}
		
	


	if((messageQ = msgget(key, PERMISSION | IPC_CREAT)) == -1)
	{
		perror("msgget() failed - Exiting\n");
		exit(-1);
	}
        
	
        return messageQ;
}

/***************************************************************************************************************************/

SendMessage(int messageQ, Message buf)
{
	if((msgsnd(messageQ, &buf, sizeof(Message), 0)) == -1)
	{
		perror("Message send failed\n");
	}
}

/***************************************************************************************************************************/

Message *ReceiveMessage(int messageQ)
{
	Message *buf = (Message *)malloc(sizeof(Message));
	
	
        if((msgrcv(messageQ, buf, sizeof(Message), 0, 0)) == -1)
	{
		perror("Receive failed");
		free(buf);
		buf = NULL;
	}

	return buf;
}

/***************************************************************************************************************************/


DestroyMessageQueue(int messageQ)
{

	if((msgctl(messageQ, IPC_RMID, NULL)) == -1)
	{
	    perror("Could not destroy Message Queue\n");
	}

}

/***************************************************************************************************************************/


int messageQueue1,messageQueue2,messageQueue3,messageQueue4;


/***************************************************************************************************************************/


int round = 0;


/************************************************Application threads*******************************************************/

void *application1_thread(void *arg)
{
	
	Message *m;

      
        while(1)
	{   
                
        if((m = ReceiveMessage(messageQueue1)) != NULL  )
	{
            
        if(m->data == 100)
        system("/home/suhas/Desktop/Anti_Virus/avast4workstation-1.3.0/bin/./avast /home/suhas/Desktop/test >>flag10"); 
  
       
        if(m->data == 101)
        system("pkill -SIGSTOP avast");
 
   
        if(m->data == 110)
        system("pkill -SIGCONT avast");
                
        free(m);
        
        }  
        
        }
       
	return;

}


/***************************************************************************************************************************/

	
	

void *application2_thread(void *arg)
{
   	
	Message *m;
	 
	while(1)
	{   
	   
        if((m = ReceiveMessage(messageQueue2)) != NULL )
        {
    
        
        if(m->data == 100)
        system("/home/suhas/Desktop/Anti_Virus/vascan-1.5.6-5.0.27-Linux-i386/./vascan /home/suhas/Desktop/test >>flag00");  
        
        
        if(m->data == 101)
        system("pkill -SIGSTOP vascan");
        
        
        if(m->data == 110)
        system("pkill -SIGCONT vascan");



        free(m);
               
        }

        } 
	 
        return;
		
	
	
}

/**************************************************************************************************************************/


void *application3_thread(void *arg)
{
	
	Message *m;
	
	while(1)
	{
	    
        if((m = ReceiveMessage(messageQueue3)) != NULL )
	{
 
        if(m->data == 100)
        system("clamscan -r /home/suhas/Desktop/test >>flag20");   
        

        if(m->data == 101)
        system("pkill -SIGSTOP clamscan");
 

        if(m->data == 110)
        system("pkill -SIGCONT clamscan");
       
               
        free(m);
               
        }   
             
	}	
	return;

}

/***************************************************************************************************************************


void *application4_thread(void *arg)
{
	
	Message *m;
	
        while(1)
	{         
             	
        if((m = ReceiveMessage(messageQueue4)) != NULL )
	printf("Application4 %d\n",m->data);
        free(m);
           
        }
	
        return;

}


/************************************************Schedular Thread*******************************************************/ 
  

   void *schedular_thread(void *arg)

 {
        
/*************************************************Round Robin Scheduling***********************************************/ 

       int a,b,choice,time_quanta=40000000,counter=0; //time quanta is specified in microseconds
       Message m;

       m.mtype = 1;
       
       printf("***************************** Select a scheduling algorithm ************************************\n\n"); 
       printf("1)FIFO\n");
       printf("2)Round Robin\n\n"); 
    
                                

      scanf("%d",&choice);

      if(choice == 1)
      {
        
      usleep(60000000);

      m.data = 100;
      SendMessage(messageQueue1,m);
      usleep(600000000);                
      
      m.data = 101;
      SendMessage(messageQueue1,m);
      usleep(60000000);

      m.data = 100;
      SendMessage(messageQueue2,m);
      usleep(600000000);
      
      m.data = 101;
      SendMessage(messageQueue2,m);
      usleep(60000000);

      m.data = 100;
      SendMessage(messageQueue3,m);
      usleep(600000000);
      
      m.data = 101;
      SendMessage(messageQueue3,m);
      usleep(60000000);

      m.data = 100;
      SendMessage(messageQueue4,m);
      usleep(600000000);
      
      m.data = 101;
      SendMessage(messageQueue4,m);
      usleep(60000000);

      }

 
      if(choice == 2)
     {   

        
       while(1)
      {
       
       usleep(time_quanta);                  // time quanta of an application expires 
       
       printf("Round - %d\n",round);
       
       
       if(round == 0)
      {
       
       if(counter == 0) 
       {
       m.data = 100;
       SendMessage(messageQueue1, m); 
       usleep(1000000);
       
       }
       
       if(counter == 1)
       {
       m.data = 101;
       SendMessage(messageQueue1, m);
       usleep(1000000);
       m.data = 100;
       SendMessage(messageQueue2, m);
       }
       
       if(counter == 2)
       {
       m.data = 101;
       SendMessage(messageQueue2, m);
       usleep(1000000);
       m.data = 100;
       SendMessage(messageQueue3, m);
       }
 
      
 																			  
      }
     
      
       else 
     { 
       
       
      a=aqt->tail->App_id; 
      m.data=101;
       
      

      if(a==0)
      SendMessage(messageQueue1, m);


      else if(a==1)
      SendMessage(messageQueue2, m);
       
       
       
      else if(a==2)
      SendMessage(messageQueue3, m);
       
        
    

      
    
      b=aqt->front->App_id;
      m.data=110;
       
      usleep(1000000);
      
      if(b==0)
      SendMessage(messageQueue1, m);
   
     
      else if(b==1)
      SendMessage(messageQueue2, m);
      

      else if(b==2)
      SendMessage(messageQueue3, m);
      
    
     

      }     
  
      if(counter == MAX-1)
       {
       round++;                               // Increment to next round 
       counter=-1;  
       }
     
       counter++;
       reset_app_queue();	    
       
      }
     
      }

/***************************************************************************************************************************/
      
      return;
}




/****************************************************** main **************************************************************/


main(int argc, char **argv)
{
	
        
/****************************************************** The Thread Ids*****************************************************/


	pthread_t application_1;
	pthread_t application_2;
        pthread_t application_3;
        pthread_t schedular;


/************************************************ Initialise application buffer *******************************************/
         
        
        set_app_queue();
	

/************************************************* Store buffer's state at t=0 ******************************************/   


	aqt0 = (Application_queue *) malloc (sizeof(Application_queue));
        

/**************************************************************************************************************************
 
        
       storestate(); 
 

*********************************************** Initialise message buffers ************************************************/
	

        messageQueue1 = CreateMessageQueue(1);
	messageQueue2 = CreateMessageQueue(2);	
        messageQueue3 = CreateMessageQueue(3);
	messageQueue4 = CreateMessageQueue(4);


/*********************************************** Start the Application threads ********************************************/



	if((pthread_create(&application_1, NULL, application1_thread, NULL )) != 0)
	{
		printf("Error creating application_1 thread - Exiting\n");
		exit(-1);
	}

	if((pthread_create(&application_2, NULL, application2_thread, NULL )) != 0)
	{
		printf("Error creating application_2 thread - Exiting\n");
		exit(-1);
	}

	if((pthread_create(&application_3, NULL, application3_thread, NULL )) != 0)
	{
		printf("Error creating application_3 thread - Exiting\n");
		exit(-1);
	}

                
        if((pthread_create(&schedular, NULL, schedular_thread, NULL )) != 0)
	{
		printf("Error creating schedular thread - Exiting\n");
		exit(-1);
	}

       
/***************************************************** Wait for the threads to exit*****************************************/

	pthread_join(application_1);
	pthread_join(application_2);
        pthread_join(application_3);
        pthread_join(schedular);
        
/********************************************************* Cleanup code ****************************************************/

	DestroyMessageQueue(messageQueue1);
        DestroyMessageQueue(messageQueue2);
	DestroyMessageQueue(messageQueue3);
       
       

        return 0;


}
/***************************************************************************************************************************/
