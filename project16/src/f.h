int verif(char username[],char password[]);
typedef struct date
{
  int day;
  int month;
  int year;
}date;
typedef struct fiche_perso
{
  char nom[50];
  char prenom[50];
  date ddn;
  char cin[10];
  char tel[10];
  char mail[50];
  char sexe[10];
  char goals[150];
  char adresse[150];
  char login[50];
  char mdp[50];
}fp;

typedef struct rendez_vous
{
  date drdv;
  char heure;
}rdv;
