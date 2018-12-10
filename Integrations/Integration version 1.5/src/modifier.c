#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modifier.h"
void modifier(char cin[],char login[],char password[])
{
FILE *f,*f1;
char var[50];char var3[50];char var4[50];int var5;
f=fopen("/home/jbh/Projects/admin/src/user.txt","r");
f1=fopen("/home/jbh/Projects/admin/src/tmp.txt","a+");
while (fscanf(f,"%s %s %s %d",var,var3,var4,&var5)!=EOF)
{
if (strcmp(var,cin)==0)
{
fprintf(f1,"%s %s %s %d \n",cin,login,password,var5);
}
else 
fprintf(f1,"%s %s %s %d \n",var,var3,var4,var5);
}
fclose(f1);
fclose(f);
rename("/home/jbh/Projects/admin/src/tmp.txt","/home/jbh/Projects/admin/src/user.txt");
}



///////////////////////////////////////////////////////////////////////////////////////



void modifier_calendrier(char date[],char heure1[],char heure2[],char evenement[])
{
FILE *f,*f1;
char var[50];char var1[50];char var2[50];char var3[50];
f=fopen("src/salle.txt","r");
f1=fopen("src/tempttt.txt","a+");
while(fscanf(f,"%s %s %s %s",var,var1,var2,var3)!=EOF)
	{
if (strcmp(var,date)==0)
		{
fprintf(f1,"%s %s %s %s \n",date,heure1,heure2,evenement);

	
		}
else
fprintf(f1,"%s %s %s %s \n",var,var1,var2,var3);
	}
fclose(f1);
fclose(f);
rename("src/tempttt.txt","src/salle.txt");	
}
