typedef Date {
int jj;
int mm;
int aaaa;
} date;
typedef Time {
int hour;
int minute;
} time;
typedef fiche_personnelle {
char nom[30];
char prenom[30];
date date_de_naissance ;
char cin[10];
char tel[10];
char e_mail[30];
int taille ;
int poids ;
char objctifs[100];
} f_per;
typedef rendez-vous {
date date;
time heure;
} rdv;
