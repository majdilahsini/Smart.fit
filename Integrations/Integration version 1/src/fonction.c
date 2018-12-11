#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fonction.h"

enum {
  CINA,
  NOMA,
  PRENOMA,
  TELA,
  COLUMNA
};

enum {
  NOMM,
  PRENOMM,
  CIIN,
  POID,
  TAILLE,
  ICM,
  TOURTAILLE,
  REGIME,
  COLUMN
};

enum {
  NOM_,
  PRENOM_,
  CIN_,
  AGE_,
  TAILLE_,
  POULS_,
  PRESSSYS_,
  PRESSDI_,
  COLMN_
};

enum {
  JOUR,
  HEURE,
  CABINET,
  COL
};

int str_to_int (char a[]) {

int i,l,n;
l = strlen(a);
n = 0;

for (i=0;i<l;i++) {
	if (a[i]<48 || a[i]>57)
		return -1;
	n = n*10 +a[i] -'0';
}

return n;
}

void tmp_cin (char cin[10]){
  FILE *f;
  char a[10];

  f = fopen("tmp.txt","r");

  if (f != NULL)
  fscanf(f,"%s",cin);

    fclose(f);
}
int ver_modprofil_diet(p_diet a, char T[][20]) {

int i,count=0;

  if (verif_longeur(a.nom,3) == -1 || verif_type(a.nom,1) == -1)
      strcpy(T[0],"gtk-dialog-warning");
  else {
      strcpy(T[0],"gtk-ok");
      count++;
      }

  if (verif_longeur(a.prenom,3) == -1 || verif_type(a.prenom,1) == -1)
      strcpy(T[1],"gtk-dialog-warning");
  else{
      strcpy(T[1],"gtk-ok");
      count++;
      }

  if (verif_longeur(a.tel,8) == -1 || verif_type(a.tel,0) == -1)
      strcpy(T[2],"gtk-dialog-warning");
  else{
      strcpy(T[2],"gtk-ok");
      count++;
      }
return count;

}
void modprofil_diet (p_diet a, char cin[10]) {
  FILE *f, *f1;
  char nom [20],prenom [20], CIN [20], tel [20], sexe [20];
  int jour,mois,annee;


  f = fopen("dieteticiens.txt","r");
  f1 = fopen("dieteticiens2.txt","w+");

  if (f != NULL && f1 != NULL) {
    while (fscanf(f,"%s %s %s %s %d %d %d %s",nom,prenom,CIN, tel, &jour, &mois, &annee, sexe) != EOF) {
          if (strcmp(CIN,cin) == 0)
              fprintf(f1,"%s %s %s %s %d %d %d %s\n",a.nom,a.prenom,a.CIN,a.tel,a.dt.jour,a.dt.mois,a.dt.annee,a.sexe);
          else
              fprintf(f1,"%s %s %s %s %d %d %d %s\n",nom,prenom,CIN,tel,jour,mois,annee,sexe);
    }
  }
  fclose(f);
  fclose(f1);
remove("dieteticiens.txt");
rename("dieteticiens2.txt","dieteticiens.txt");
}


int verif_longeur (char ch[20],int length) {
  if (strlen(ch)>=length)
      return 1;
  else
      return -1;
}

int verif_type (char ch[20],int type) {

int i,count = 0;

if (type == 0) {
for (i=0;i<strlen(ch);i++) {
    if (ch[i] > 47 && ch[i] < 58)
      count++;
    }
}

else if (type == 1) {
for (i=0;i<strlen(ch);i++) {
    if ((ch[i] >= 97 && ch[i] <= 122) || (ch[i] >= 65 && ch[i] <= 90))
      count++;
  }
}

if (count == strlen(ch))
    return 1;
else
    return -1;
}

void affichage1 (GtkWidget *liste) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

int test;
char nom[20], prenom[20],cin[20],sexe[20], jour[20],mois[20],annee[20],tel[20],mail[20];
char cin2[20], taille[20], poid[20],imc [20],tdt[20],regime[20];

FILE *f, *f2;

f = fopen("adhérents.txt","r");
f2 = fopen("Fiche_diet.txt","r");

store = gtk_tree_view_get_model(liste);
if (store == NULL) {
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CINA,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOMA,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOMA,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("TEL",renderer,"text",TELA,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}


store = gtk_list_store_new(COLUMNA,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL) {
  while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",cin,nom,prenom,jour,mois,annee,sexe,tel,mail) != EOF) {
    test = 0;
    rewind(f2);
      while (fscanf(f2,"%s %s %s %s %s %s\n",cin2,poid,taille,imc,tdt,regime) != EOF && test == 0) {
        if (strcmp(cin2,cin)==0)
           test=1;
      }
      if (test==0){
        gtk_list_store_append(store,&iter);
        gtk_list_store_set(store,&iter,CINA,cin,NOMA,nom,PRENOMA,prenom,TELA,tel,-1);
      }
    }
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

void affichage2 (GtkWidget *liste) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

f_diet a;

char nom[20], prenom[20],cin[20],sexe[20], jour[20],mois[20],annee[20],tel[20],mail[20];

FILE *f, *f2;

f = fopen("adhérents.txt","r");
f2 = fopen("Fiche_diet.txt","r");

store = gtk_tree_view_get_model(liste);
if (store == NULL) {

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOMM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOMM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIIN,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Poid",renderer,"text",POID,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Taille",renderer,"text",TAILLE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("ICM",renderer,"text",ICM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("TdT",renderer,"text",TOURTAILLE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Type de régime",renderer,"text",REGIME,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store = gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL && f2!=NULL) {
  while (fscanf(f2,"%s %s %s %s %s %s\n",a.cin,a.poid,a.taille,a.icm,a.tdt,a.regime) != EOF) {
      rewind(f);
      while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",cin,nom,prenom,jour,mois,annee,sexe,tel,mail) != EOF) {
        if (strcmp(a.cin,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMM,nom,PRENOMM,prenom,CIIN,a.cin,POID,a.poid,TAILLE,a.taille,ICM,a.icm,TOURTAILLE,a.tdt,REGIME,a.regime,-1);
      }
    }
  }
}
fclose(f);fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


void affichage3 (GtkWidget *liste) {

  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;

  f_diet a;
  char nom_med[20], prenom_med[20], age[20], taille[20], pouls[20], presssys[20], pressdia[20];

  FILE *f;

  f = fopen("Fiche_med.txt","r");


  store = gtk_tree_view_get_model(liste);
  if (store == NULL) {

      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM_,NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM_,NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Age",renderer,"text",AGE_,NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Taille",renderer,"text",TAILLE_,NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Pouls",renderer,"text",POULS_,NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Pression\nsystolique",renderer,"text",PRESSSYS_,NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Pressionn\ndiastolique",renderer,"text",PRESSDI_,NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  }

  store = gtk_list_store_new(COLMN_,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

  if (f!=NULL) {
    while (fscanf(f,"%s %s %s %s %s %s %s",nom_med,prenom_med,age,taille,pouls,presssys,pressdia) != EOF) {
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOM_,nom_med,PRENOM_,prenom_med,AGE_,age,TAILLE_,taille,POULS_,pouls,PRESSSYS_,presssys,PRESSDI_,pressdia,-1);
    }
  }

  fclose(f);
  gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
  g_object_unref(store);
}

void ajoufich_diet (f_diet a) {
  FILE *f;

  f = fopen("Fiche_diet.txt","a");

  if (f!=NULL)
  fprintf(f,"%s %s %s %s %s %s\n",a.cin,a.poid,a.taille,a.icm,a.tdt,a.regime);

  fclose(f);
}

void suprfich_diet (char a[20]) {
  FILE *f, *f1;

  f_diet b;


  f = fopen("Fiche_diet.txt","r");
  f1 = fopen("a22.txt","w+");

  if (f != NULL && f1 != NULL) {
    while (fscanf(f,"%s %s %s %s %s %s\n",b.cin,b.poid,b.taille,b.icm,b.tdt,b.regime) != EOF) {
          if (strcmp(b.cin,a) == 0)
              fprintf(f1,"");
          else
              fprintf(f1,"%s %s %s %s %s %s\n",b.cin,b.poid,b.taille,b.icm,b.tdt,b.regime);
    }
  }
  fclose(f);
  fclose(f1);
  remove("Fiche_diet.txt");
  rename("a22.txt","Fiche_diet.txt");
}

void modfich_diet (f_diet a) {
  FILE *f, *f1;

  f_diet b;

  f = fopen("Fiche_diet.txt","r");
  f1 = fopen("a22.txt","w+");

  if (f != NULL && f1 != NULL) {
    while (fscanf(f,"%s %s %s %s %s %s\n",b.cin,b.poid,b.taille,b.icm,b.tdt,b.regime) != EOF) {
          if (strcmp(b.cin,a.cin) == 0)
              fprintf(f1,"%s %s %s %s %s %s\n",a.cin,a.poid,a.taille,a.icm,a.tdt,a.regime);
          else
              fprintf(f1,"%s %s %s %s %s %s\n",b.cin,b.poid,b.taille,b.icm,b.tdt,b.regime);
    }
  }
  fclose(f);
  fclose(f1);
  remove("Fiche_diet.txt");
  rename("a22.txt","Fiche_diet.txt");
}

void ver_remp (char a[],int type, int length, char T[][20], int indice,int *count) {

  if (verif_longeur(a,length) == -1 || verif_type(a,type) == -1)
      strcpy(T[indice],"gtk-dialog-warning");
  else {
      strcpy(T[indice],"gtk-ok");
      *count = *count + 1;
      }
}

int verifi_fichediet(char nom[20], char prenom[20], f_diet a, char T[][20]) {

int count=0;

ver_remp(nom,1,1,T,0,&count);
ver_remp(prenom,1,1,T,1,&count);
ver_remp(a.cin,0,1,T,2,&count);
ver_remp(a.poid,0,1,T,3,&count);
ver_remp(a.taille,0,1,T,4,&count);
ver_remp(a.icm,0,1,T,5,&count);
ver_remp(a.tdt,0,1,T,6,&count);
ver_remp(a.regime,1,4,T,7,&count);

return count;
}

int verifsipassexiste (char cin[],char password[]) {

FILE *f;
char login[20],pass[20],role[20],cin2[20],etat[20];

f = fopen("users.txt","r");

if (f!=NULL){
  while(fscanf(f,"%s %s %s %s %s",login,pass,role,cin2,etat) != EOF) {
    if (strcmp(cin2,cin) == 0 && strcmp(password,pass) == 0) {
        fclose(f);
        return 1;
    }
  }
}
fclose(f);
return -1;
}

int verif_pass_finale (char cin[], char pass1[], char pass2[], char pass3[], char T[][20]) {
int count=0;

  if (verif_longeur(pass1,1) == -1 || verifsipassexiste(cin,pass1) == -1)
      strcpy(T[0],"gtk-dialog-warning");
  else {
      strcpy(T[0],"gtk-ok");
      count++;
  }

  if (verif_longeur(pass2,4) == -1)
      strcpy(T[1],"gtk-dialog-warning");
  else {
      strcpy(T[1],"gtk-ok");
      count++;
    }

  if (verif_longeur(pass3,4) == -1 || strcmp(pass2,pass3) != 0)
     strcpy(T[2],"gtk-dialog-warning");
  else {
     strcpy(T[2],"gtk-ok");
     count++;

  return count;
  }
}

void modifier_pass_diet(char cin[20], char pass[20]){
  FILE *f, *f1;

  char login [20], pas [20], role [20], CIN [20], etat [20];

  f = fopen("users.txt","r");
  f1 = fopen("users2.txt","w");

  if (f != NULL && f1 != NULL)
      while (fscanf(f,"%s %s %s %s %s\n",login,pas,role,CIN,etat) != EOF) {
        if (strcmp(cin,CIN)==0)
            fprintf(f1,"%s %s %s %s %s\n",login,pass,role,CIN,etat);
        else
            fprintf(f1,"%s %s %s %s %s\n",login,pas,role,CIN,etat);
      }
  fclose(f); fclose(f1);
  remove("users.txt");
  rename("users2.txt","users.txt");
}

float calcul_imc(int a,int b){

  b = (float) b/100;

  return a/(b*b);
}


int verif_si_fichediet_existe(char cin[8]){
    FILE *f;

    f_diet a;

    f = fopen("Fiche_diet.txt","r");

    if (f!=NULL){
      while (fscanf(f,"%s %s %s %s %s %s",a.cin,a.poid,a.taille,a.icm,a.tdt,a.regime) !=EOF) {
        if (strcmp(a.cin,cin)==0){
          fclose(f);
          return 1;
        }
      }
    }
   fclose(f);
   return 0;
}

void mod_cal_diet(char jour[],char heure[]){

char jourr[20];
char heure1, heure2, cabinet1, cabinet2;
FILE *f1, *f2;

f1 = fopen("cal_diet.txt","r");
f2 = fopen("cal_diet2.txt","w");

if (f1 != NULL && f2 != NULL){
  while (fscanf(f1,"%s %c %c %c %c",jourr,&heure1,&heure2,&cabinet1,&cabinet2) != EOF) {
        if (strcmp(jourr,jour)==0) {
            if(strcmp(heure,"8-12")==0)
                fprintf(f2,"%s 0 %c 0 %c\n",jourr,heure2,cabinet2);
            else if (strcmp(heure,"14-16")==0)
                fprintf(f2,"%s %c 0 %c 0\n",jourr,heure1,cabinet1);
                }
        else
            fprintf(f2,"%s %c %c %c %c\n",jourr,heure1,heure2,cabinet1,cabinet2);
        }
    }
fclose(f1);
fclose(f2);
remove("cal_diet.txt");
rename("cal_diet2.txt","cal_diet.txt");
}


void affichage4_rdv_diet (GtkWidget *liste) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

FILE *f, *f2;
char jour[20], heure[20], cabinet[20],cin[20];
char A[2];
f = fopen("rdv_diet.txt","r");

store = gtk_tree_view_get_model(liste);
if (store == NULL) {
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Cabinet",renderer,"text",CABINET,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}


store = gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL) {
    while (fscanf(f,"%s %s %s %s %s",cin,jour,heure,cabinet,A) != EOF){
      strcat(cabinet," ");
      strcat(cabinet,A);
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,JOUR,jour,HEURE,heure,CABINET,cabinet,-1);
    }
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

void sup_rdv_diet(){

char jour[20], heure[20],cabinet[20], a[20];
char jour1[20],heure1[20],cabinet1[20], a1[20];

char cin[8];
FILE *f1, *f2, *f3;

f1 = fopen("rdv_diet.txt","r");
f2 = fopen("rdv_diet2.txt","w");
f3 = fopen("rdv_tmp.txt","r");

if (f3 != NULL)
fscanf(f3,"%s %s %s %s",jour1,heure1,cabinet1,a1);

if (f1 != NULL && f2 != NULL){
  while (fscanf(f1,"%s %s %s %s %s",cin,jour,heure,cabinet,a) != EOF) {
      if (strcmp(jour,jour1)==0 && strcmp(heure,heure1)==0)
          fprintf(f2,"");
      else
          fprintf(f2,"%s %s %s %s %s\n",cin,jour,heure,cabinet,a);
      }
    }

fclose(f1);
fclose(f2);
fclose(f3);

remove("rdv_diet.txt");
rename("rdv_diet2.txt","rdv_diet.txt");
}

void mod_cal_diet_sup(char jour[],char heure[]){

char jourr[20];
char heure1, heure2, cabinet1, cabinet2;
FILE *f1, *f2;

f1 = fopen("cal_diet.txt","r");
f2 = fopen("cal_diet2.txt","w");

if (f1 != NULL && f2 != NULL){
  while (fscanf(f1,"%s %c %c %c %c",jourr,&heure1,&heure2,&cabinet1,&cabinet2) != EOF) {
        if (strcmp(jourr,jour)==0) {
            if(strcmp(heure,"8-12")==0)
                fprintf(f2,"%s 1 %c 1 %c\n",jourr,heure2,cabinet2);
            else if (strcmp(heure,"14-16")==0)
                fprintf(f2,"%s %c 1 %c 1\n",jourr,heure1,cabinet1);
                }
        else
            fprintf(f2,"%s %c %c %c %c\n",jourr,heure1,heure2,cabinet1,cabinet2);
        }
    }
fclose(f1);
fclose(f2);
remove("cal_diet.txt");
rename("cal_diet2.txt","cal_diet.txt");
}
