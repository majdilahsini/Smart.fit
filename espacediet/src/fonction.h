typedef struct date {
  int jour;
  int mois;
  int annee;
}date;

typedef struct p_diet {
  char nom[20];
  char prenom[20];
  char CIN[20];
  char tel[20];
  date dt;
  char sexe[10];
}p_diet;

typedef struct fiche_diet {
  char cin[20];
  char poid[20];
  char taille[10];
  char icm[10];
  char tdt[10];
  char regime[10];
}f_diet;

void tmp_cin (char cin[10]);
void modprofil_diet (p_diet a, char cin[10]);
int verif_longeur (char ch[20],int length);
int verif_type (char ch[20],int type);
