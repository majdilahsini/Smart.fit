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

int str_to_int (char a[]);//convertion du CHAR à INT

void tmp_cin (char cin[10]); //Get cin from tmp.txt

int ver_modprofil_diet(p_diet a, char T[][20]);//verification informations saisies profil

void modprofil_diet (p_diet a, char cin[10]);//modification du profil_diet

int verif_longeur (char ch[20],int length);//verification longeur d'une chaîne

int verif_type (char ch[20],int type);//verification type d'une chaine

void affichage1 (GtkWidget *liste); //affichage des liste adh

void affichage2 (GtkWidget *liste); //affichage des fiches diet

void affichage3 (GtkWidget *liste); //affichage des fiches med

void ajoufich_diet (f_diet a); //ajout d'une fiche diet

void suprfich_diet (char a[20]); //supression d'une fiche diet (a = CIN)

void modfich_diet (f_diet a); //modification d'une fiche diet

void ver_remp (char a[],int type, int length, char T[][20], int indice,int *count);
/*
 * remplissage du tableau T qui sert à la verification.
 * type : si on veut vérifier que le CHAR est un "nombre" on le met égale a 0 sinon 1;
 * length : si on veut vérifier que le CHAR a AU MOIN "length" caracters;
 * indice : sert a remplir le tableau selon l'IMAGE a modifié
 * *count sert à calculer le nombre des ENTRY qui sont compatible avec les conditions
 */
int verifi_fichediet(char nom[20], char prenom[20], f_diet a, char T[][20]);
//verification des CHAR nom/prenom.. à l'aide de ver_remp (retourne count, si count = a nombre des CHAR a verifié, l'ajout va se faire sans probléme)

int verifsipassexiste (char cin[],char password[]);
//verification si le password existe (ancien password) pour le changer, utilise cin pour le chercher. retourne 1 si c'est bon.

int verif_pass_finale (char cin[], char pass1[], char pass2[], char pass3[], char T[][20]);
//meme chose que verifi_fichediet

void modifier_pass_diet(char cin[20], char pass[20]);
//modifier le password de diet
