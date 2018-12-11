#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int verifier (char login[], char password[], int t[], char CIN[8])
{

int role,n;
char loginf[50],passwordf[50],CINf[50];

FILE *f;

f = fopen("users.txt","r");


if (f != NULL) {
while (fscanf(f,"%s %s %d %s %d",loginf,passwordf,&role,CINf,&n)!=EOF)
	if (strcmp(loginf,login) == 0 && strcmp(passwordf,password) ==0) {
    t[0] = n;
		strcpy(CIN,CINf);
		fclose(f);
		return role;
  }
}

fclose(f);
return -1;
}

int verifier_pass(char new_password[],char conf_password[]) {

if (strcmp(new_password,conf_password) == 0)
    return 1;
else
    return -1;

}

void creation_tmp(char cin[8]) {
	FILE *f;

	f= fopen("tmp.txt","w");
	if (f!=NULL)
			fprintf(f,"%s",cin);
fclose (f);
}

void mod_mdp_firsttime(char pass[],char cin[]) {
	char logg[20],passw[20],role[20],cinn[20],etat[20];
	FILE *f1, *f2;

	f1 = fopen("users.txt","r");
	f2 = fopen("users2.txt","w");

	if (f1 != NULL && f2 != NULL){
		while (fscanf(f1,"%s %s %s %s %s\n",logg,passw,role,cinn,etat)!= EOF) {
			if (strcmp(cin,cinn)==0)
					fprintf(f2,"%s %s %s %s 0\n",logg,pass,role,cinn);
			else
					fprintf(f2,"%s %s %s %s %s\n",logg,passw,role,cinn,etat);
		}
	}
fclose(f1);
fclose(f2);
remove("users.txt");
rename("users2.txt","users.txt");
}

int cherche_role(){
	char login[20],pass[20],cinn[20],etat[20];
	int role;
	char cin[8];
  FILE *f;

  f = fopen("tmp.txt","r");
	if (f != NULL)
	fscanf(f,"%s",cin);

	FILE *f2;
f2 = fopen("users.txt","r");
if(f2 != NULL) {
	while(fscanf(f2,"%s %s %d %s %s",login,pass,&role,cinn,etat) !=EOF) {
		if (strcmp(cinn,cin)==0){
			fclose(f);
			return role;
		}
	}
}
fclose(f);
return -1;
}
