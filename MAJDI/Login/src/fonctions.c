#include <string.h>
#include <stdio.h>
#include <stdlib.h>




void ajouter(char login[],char password[], int role) {

FILE *f;

f = fopen("users.txt","a+");

fprintf(f,"%s %s %d\n",login,password,role);
fclose(f);
}

int str_to_int (char a[]) {

int i,l,n;
l = strlen(a);
n = 0;

for (i=0;i<l;i++) {
	if (a[i]<48 || a[i]>57)
		return -1;
	n = n*10 +a[i] -'0';
}

return n;
}

int verifier (char login[], char password[]) {

int role,n;
char ch[50],ch1[50];


FILE *f;

f = fopen("users.txt","r");

n = -1;
if (f != NULL) {
while (fscanf(f,"%s %s %d\n",ch,ch1,&role)!=EOF && n == -1) {

	if (strcmp(ch,login) == 0 && strcmp(ch1,password) ==0)
		return role;}
}
fclose(f);
return n;
}

void verifi_ajout (char login[] ,char password[], char role [],char msg_l [], char msg_r[], char msg_p [], char msg_pr []) {

	int i,count = 0, int_role = str_to_int(role),test = 0;
	char logi[50], pass[50], rol[50];
	FILE *f;

	if (int_role ==-1)
			strcpy(msg_r,"Le role doit être un chiffre.");
	else if (int_role == 0 || int_role>6)
			strcpy(msg_r,"Le role doit être un chiffre entre 1 et 6.");
	else
			strcpy(msg_r,"");

	if (strlen(login)<3)
			strcpy(msg_l,"Le login doit avoir au minimum 3 CHAR.");
	else
	    strcpy(msg_l,"");

  for (i=0;i<strlen(password);i++) {
		if (password[i] >= 48 && password[i] <= 57)
		 		count++;
	}
	if (count == 0)
		  strcpy(msg_p,"Le password doit avoir au minimum 1 chiffre");
	if (strlen(password)<4 && count == 0)
			strcpy(msg_p,"Le password doit avoir au minimum 4 CHAR et 1 chiffre");
	if (strlen(password)<4 && count != 0)
			strcpy(msg_p,"Le password doit avoir au minimum 4 CHAR");
  if (count !=0 && strlen(password)>=4)
		  strcpy(msg_p,"");

	f = fopen("users.txt","r");

	if (f != NULL) {
		 while (fscanf(f,"%s %s %s",logi,pass,rol) != EOF && test ==0)
		 				if (strcmp(logi,login)==0 && strcmp(pass,password)==0)
								test = 1;

	}
	if (test == 0 && strcmp(msg_p,"")==0 && strcmp(msg_r,"")==0 && strcmp(msg_l,"")==0)
		 strcpy(msg_pr,"L'ajout au fichier a été éffectué avec succéss");
	if (test == 1 && strcmp(msg_p,"")==0 && strcmp(msg_r,"")==0 && strcmp(msg_l,"")==0)
 		 strcpy(msg_pr,"La combinaison login/password existe déj.");
	if (strcmp(msg_p,"")!=0 || strcmp(msg_r,"")!=0 || strcmp(msg_l,"")!=0)
 	 	 strcpy(msg_pr,"L'ajout au fichier a échoué, veuillez vérifier les informations");


	fclose(f);
}
