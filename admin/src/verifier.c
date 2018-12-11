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
int x;
f=fopen("/home/jbh/Projects/admin/src/user.txt","r");
if (f !=NULL)
{
while (fscanf(f,"%s %s %s %d",cin,login,password,&x) !=EOF)
{
if((strcmp(Username,login)==0) && (strcmp(Password,password)==0))
return x;
}
return -1;
}
fclose(f);
}

