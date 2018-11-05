Typedef struct Date 
{
int jj ;
int mm ;
int aaaa ;
} date ;


Typedef struct Time
{
int HH ;
int MM ;
} time ;

Typedef struct fiche_personnelle
{
char nom[30] ;
char prenom[30] ;
date date_de_naissance ;
char cin[10] ;
char tel[10] ;
char e_mail[30] ;
int taille ;
int poids ;
char decrire[100] ;
} fp ;

Typedef struct rendez-vous
{
date date ;
time heure ;
} rdv ;

