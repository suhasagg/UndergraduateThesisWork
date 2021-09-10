#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (void)
{
int i=0,j=0,k=0,count=0,len,str_length,random1,random2;
char a[120],b[120][120],word1[120],word2[120];
FILE *f1,*f2;
f1=fopen("sentence.txt","r+");

fgets(a,sizeof a ,f1);

printf("%s",a);
/*store string */

i=0;

len = strlen(a);
printf("%d\n",len);
for(i = 0; i < len; i++)
{

  strcpy(&b[j][k],&a[i]); 
  k++;   
  if(a[i] == ' ')
 { 
  b[j][k] = '\0';
  k=0;
  printf("%s\n",b[j]);
  j++;
  }
}


printf("%d\n",j);
/* count_words() */

random1=rand() % (j-1);
printf("%d\n",random1);
strcpy(word1,b[random1]);

random2=rand()% (j-1); 
printf("%d\n",random2);
strcpy(word2,b[random2]);

f2=fopen("/var/www/html/data.txt","w+");

fprintf(f2,"%s\n",word1);
fprintf(f2,"%s\n",word2);
fprintf(f2,"%d\n",random1);
fprintf(f2,"%d\n",random2);

for(i = 0; i < j; i++)
fprintf(f2,"%s\n",b[i]);



}

















/* select random_words() */

/*
fprintf(f1,word1);
fprintf(f2,word2);
*/
