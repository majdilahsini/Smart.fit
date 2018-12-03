#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "f.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int verif (char login[], char password[]) {

int role,test =0,x;
char ch[50],ch1[50];


FILE *f;

f = fopen("users.txt","r");



x=-1;
if (f != NULL)
{
while ((fscanf(f,"%s %s %d\n",ch,ch1,&role)!=EOF) && (x==-1))
{

	if ((strcmp(ch,login) == 0) && (strcmp(ch1,password) ==0))
			x= role;
	else if ((strcmp(ch,login) == 0) && (strcmp(ch1,password) !=0))
		return 0;
	
}
fclose(f);
}
return x;
}

void enregistrer(  char nom[50],char prenom[50],date ddn,
  char cin[10],char tel[10],char mail[50],char adresse[],char sexe[10],
  char goals[150])
{
FILE *f ;
	f=fopen("adherents.txt","a+");
	if(f != NULL)
	{
		fprintf(f,"%s %s %d %d %d %s %s %s %s %s %s\n",nom,prenom,ddn.day,
ddn.month, ddn.year,cin,tel,mail,adresse,sexe,goals);
  }
fclose(f);
}
