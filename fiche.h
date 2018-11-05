typedef struct fiche_utilisateur {
char nom [50];
char prenon [50];
int CIN ;
char email [50];
int numero ;
} fi_op;

typedef struct date {
int annee ;
int mois ;
int jour ;
}date ;

typedef struct vendez_vous {
char nom [50];
char prenom [50];
date d1 ;
}vendez_vous;

typedef struct fiche {
char nom [50];
char prenom [50];
date d_ajout ;
float taille ;
float poids ;
char maladies_problemes [150];
}fiche;
