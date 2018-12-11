#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "verifier.h"

int verifier (char Username[],char Password[])
{
FILE *f;
char cin[30];
char login[30];
char password[30];
int x,etat;
f=fopen("/home/jbh/Projects/admin/src/users.txt","r");
if (f !=NULL)
{
while (fscanf(f,"%s %s %d %s %d",login,password,&x,cin,&etat) !=EOF)
{
if((strcmp(Username,login)==0) && (strcmp(Password,password)==0))
return x;
}
return -1;
}
fclose(f);
}

