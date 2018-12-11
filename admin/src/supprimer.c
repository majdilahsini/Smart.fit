#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supprimer.h"

void supprimer(char cin[])
{
  FILE *f;
  FILE *f1;

  char var[20], var1[20],var2[30];int var3;
 

  f = fopen("src/user.txt","r");
  f1 = fopen("src/temp2.txt","w+");

  
    while(fscanf(f,"%s %s %s %d",var,var1,var2,&var3) != EOF)
    {
      if (strcmp(var,cin)!=0 )
       
   
          fprintf(f1,"%s %s %s %d\n",var,var1,var2,var3);
    }


  fclose(f);
  fclose(f1);
  remove("src/user.txt");
  rename("src/temp2.txt","src/user.txt");
}

void supprimer_calendrier(char date[50])
{
FILE *f,*f1;
char var[50];char var1[50];char var2[50];char var3[50];
f=fopen("src/salle.txt","r");
f1=fopen("src/tamptt.txt","a+");
while(fscanf(f,"%s %s %s %s",var,var1,var2,var3)!=EOF)
	{
if (strcmp(var,date)!=0)

fprintf(f1,"%s %s %s %s \n",var,var1,var2,var3);

	}
fclose(f1);
fclose(f);

rename("src/tamptt.txt","src/salle.txt");	
}
