
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

}fp;
void enregistrer( char cin[10] ,char nom[50],char prenom[50],date ddn,char tel[10],char mail[50],char sexe[20]);

void enregistrer1(  char nom[50],char prenom[50],date ddn,char cin[10],char tel[10],char sexe[10]);

void afficher_coach(GtkWidget *list) ;
 void afficher_diet(GtkWidget *list);
 void afficher_kine(GtkWidget *list);
 void afficher_med(GtkWidget *list);
 void afficher_rdv(GtkWidget *list);

void supprimer_rdv(char date[30],char heure[30], char salle[20]) ;
void mod_profil_adh (fp a, char cin[10]);
void tmp_cin (char cin[10]);
void afficher_staff(GtkWidget *list);
void annuler_rdv(char date[30],char heure[30], char salle[30]) ;
void actualiser_dispo_diet(char date[30],char heure[30], char salle[30]) ;
void actualiser_dispo_med(char date[30],char heure[30], char salle[30]);
void actualiser_dispo_kine(char date[30],char heure[30], char salle[30]) ;
void actualiser_dispo_coach(char date[30],char heure[30], char salle[30]) ;
void actualiser_dispo_coach2(char date[30],char heure[30], char salle[30]) ;
void annuler_rdv2(char date[30],char heure[30], char salle[30]) ;
void afficher_staff2(GtkWidget *list);





