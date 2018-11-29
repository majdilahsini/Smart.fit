#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "login.h"

int verifier (user a) {

int n = -1;
user p;

FILE *f;

f = fopen("users.txt","r");


if (f != NULL) {
while (fscanf(f,"%s %s %d\n",p.login,p.password,&p.role)!=EOF && n == -1) {

	if (strcmp(p.login,a.login) == 0 && strcmp(p.password,a.password) ==0) {
	return p.role;
	fclose(f);
	}

}
fclose(f);
return n;
}
}
