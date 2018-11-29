#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "fonction.h"


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


void verifi_ajout (fiche_diet a, char msg_a[50], char msg_b[50]) {


  int age = str_to_int(a.age);
  if (age == -1 || a.age == NULL) {
      strcpy(msg_a,"doit être un nombre");
			strcpy(msg_b,"L'ajout au fichier a échoué, veuillez vérifier les informations");
	}
  else {
      strcpy(msg_a,"");
			strcpy(msg_b,"L'ajout au fichier a été éffectué avec succéss");
	}
}
