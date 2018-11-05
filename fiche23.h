typedef struct medecin{
char nom [50];
char prenon [50];
int CIN ;
char email [50];
int numero ;
char paw[50],login[50];
char specialite[50];
rendez_vous tr[50];
}medecin;

typedef struct date {
int annee ;
int mois ;
int jour ;
}date ;

typedef struct rendez_vous {

date debut;
date fin;
char note [50];
char participant[4][50];
int nb_part;
}rendez_vous;

/*typedef struct fiche {
char nom [50];
char prenom [50];
date d_ajout ;
float age ;
char maladies_problemes [150];
}fiche;*/

/*typedef struct cal_med {
date D;
char heure[50] ;
int capaciter; 
}cal_med;*/

/*gestion des fiches médicale*/
void  affiche_fiche( char nomfich[50]);
void supprimer_fiche ( );
void  modifier_fiche ( fiche tab[], int n );
void creer_fiche ( fiche tab[], int n );
/* modifier profile*/
void  affiche_profile(char nomfich[50]);
void modifier_profile(char nomfich[50]);
void supprimer_profile(char nomfich[50]);

