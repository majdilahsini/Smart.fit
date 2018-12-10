#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ajouter.h"


int ajouter(char cin[],char login[], char password[], int role)
{

FILE *f;
char var[50],var3[50],var4[50];int var5;
f=fopen("users.txt","a+");

if (strlen(cin)==0)
return 0;
if (strlen(cin)>8)
return 3;
if (strlen(cin)<8)
return 4;
while(fscanf(f,"%s %s %d %s  \n",var,var3,&var4,var5)!=EOF)
	{

		for(int i=0;i<strlen(cin);i++)
		{
if((cin[i] < '0') || (cin[i] > '9') || (strlen(cin)!=8) || (strcmp(cin,var)==0) ||  (strcmp(login,var3)==0) || (strlen(password)==0))
			{
fclose(f);
return 0;	
			}
		}
	}
	
fprintf(f,"%s %s %d %s 1\n",login,password,role,cin);
fclose(f);	
return 1;
}


