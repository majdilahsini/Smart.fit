
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <gtk/gtk.h>

int verif (char login[], char password[], char cin[20]);
int verifier_pass(char new_password[],char conf_password[]);
void enregistre_new_mdp(char username[], char new_pass[]);
void enregistrer_rdv( char date[]);
void afficher(GtkWidget *list);
void supprimer(char a[]);
void ajouter(char username[],char new_pass[], int role);


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
void enregistrer(  char nom[50],char prenom[50],date ddn,
  char cin[10],char tel[10],char mail[50],char adresse[],char sexe[10],
  char goals[150]);

typedef struct fiche_perso1
{
  char nom[50];
  char prenom[50];
  date ddn;
  char cin[10];
  char sexe[10];
  char tel[10];
}fp1;
void enregistrer1(  char nom[50],char prenom[50],date ddn,
  char cin[10],char tel[10],char sexe[10]);

 void afficher_coach(GtkWidget *list);
 void afficher_diet(GtkWidget *list);
 void afficher_kine(GtkWidget *list);
 void afficher_med(GtkWidget *list);
  void afficher2(GtkWidget *list);
void supprimer_rdv(char date[30],char heure[30], char salle[20]) ;
