#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void verifier (char login[], char password[], int t[])
{

int role,n, test = 0;
char loginf[50],passwordf[50],CINf[50];

FILE *f;

f = fopen("users.txt","r");


if (f != NULL) {
while (fscanf(f,"%s %s %d %s %d",loginf,passwordf,&role,CINf,&n)!=EOF && test == 0)
	if (strcmp(loginf,login) == 0 && strcmp(passwordf,password) ==0) {
    t[0] = role;
    t[1] = n;
    test = 1;
  }
}

if (test == 0)
    t[0] = -1;
fclose(f);
}

int verifier_pass(char new_password[],char conf_password[]) {

if (strcmp(new_password,conf_password) == 0)
    return 1;
else
    return -1;

}
