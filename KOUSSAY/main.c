#include <stdio.h>
#include <stdlib.h>
typedef struct date
{
int jour;
int moin;
int annee;
}date;

typedef struct profil_coach
{char nom[10];
char prenom[10];
float taille;
float poid;
long CIN;
char ademail[50];
long num_mobile;
long code_postal;

}pf;
typedef struct cours
{date rendez-vous;
char desponiblite[20];

}
