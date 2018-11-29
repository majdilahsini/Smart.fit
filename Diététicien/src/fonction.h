typedef struct date {
	int jour;
	int mois;
	int annee;
}date;


typedef struct fiche_diet {
	char nom [20];
	char prenom [20];
	date dt;
	char age [20];
	char taille [20];
}fiche_diet;

typedef struct msg{
	char msg_nom [20];
	char msg_prenom [20];
	char msg_date [20];
	char msg_age[20];
	char msg_taille [20];
	char msg_prin [20];
} msg;
