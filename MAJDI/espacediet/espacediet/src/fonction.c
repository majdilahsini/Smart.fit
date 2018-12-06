#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fonction.h"

enum {
  NOM,
  PRENOM,
  CIN,
  TEL,
  COLUMNS
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
  NM,
  PRENM,
  CN,
  AGE,
  COLMN
};



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
    if (ch[i] >= 97 && ch[i] <= 122)
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
char nom[20], prenom[20],cin[20],tel[20],sexe[20];
char cin2[20], taille[20], poid[20];

FILE *f, *f2;

f = fopen("a.txt","r");
f2 = fopen("a2.txt","r");

store = gtk_tree_view_get_model(liste);
if (store == NULL) {

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("tel",renderer,"text",TEL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL) {
  while (fscanf(f,"%s %s %s %s",nom,prenom,cin,tel) != EOF) {
    test = 0;
    rewind(f2);
      while (fscanf(f2,"%s %s %s",cin2,poid,taille) != EOF && test == 0) {
        if (strcmp(cin2,cin)==0)
           test=1;
      }
      if (test==0){
        gtk_list_store_append(store,&iter);
        gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,TEL,tel,-1);
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

char nom[20], prenom[20],cin[20],tel[20],sexe[20],poid[20],taille[20],cin2[20];
char icm[20], regime[20], tour[20];
FILE *f, *f2;

f = fopen("a.txt","r");
f2 = fopen("a2.txt","r");

store = gtk_tree_view_get_model(liste);
if (store == NULL) {

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
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
  while (fscanf(f2,"%s %s %s %s %s %s",cin2,poid,taille,icm,tour,regime) != EOF) {
      rewind(f);
      while (fscanf(f,"%s %s %s %s",nom,prenom,cin,tel) != EOF) {
        if (strcmp(cin2,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMM,nom,PRENOMM,prenom,CIIN,cin,POID,poid,TAILLE,taille,ICM,icm,TOURTAILLE,tour,REGIME,regime,-1);
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

char nom[20], prenom[20],cin[20],tel[20],sexe[20],age[20],taille[20],cin2[20];

FILE *f, *f2;

f = fopen("a.txt","r");
f2 = fopen("a3.txt","r");

store = gtk_tree_view_get_model(liste);
if (store == NULL) {

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CN,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Age",renderer,"text",AGE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}

store = gtk_list_store_new(COLMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL && f2!=NULL) {
  while (fscanf(f2,"%s %s",cin2,age) != EOF) {
      rewind(f);
      while (fscanf(f,"%s %s %s %s",nom,prenom,cin,tel) != EOF) {
        if (strcmp(cin2,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NM,nom,PRENM,prenom,CN,cin,AGE,age,-1);
      }
    }
  }
}
fclose(f);fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

void ajoufich_diet (f_diet a) {
  FILE *f;

  f = fopen("a2.txt","a");

  if (f!=NULL)
  fprintf(f,"%s %s %s %s %s %s\n",a.cin,a.poid,a.taille,a.icm,a.tdt,a.regime);

  fclose(f);
}

void suprfich_diet (char a[20]) {
  FILE *f, *f1;
  char nom [20],prenom [20], CIN [20], poid [20], taille [20];
  int jour,mois,annee;


  f = fopen("a2.txt","r");
  f1 = fopen("a22.txt","w+");

  if (f != NULL && f1 != NULL) {
    while (fscanf(f,"%s %s %s",CIN, poid, taille) != EOF) {
          if (strcmp(CIN,a) == 0)
              fprintf(f1,"");
          else
              fprintf(f1,"%s %s %s\n",CIN, poid, taille);
    }
  }
  fclose(f);
  fclose(f1);
  remove("a2.txt");
  rename("a22.txt","a2.txt");
}

void modfich_diet (f_diet a) {
  FILE *f, *f1;
  char nom [20],prenom [20], CIN [20], poid [20], taille [20];
  int jour,mois,annee;


  f = fopen("a2.txt","r");
  f1 = fopen("a22.txt","w+");

  if (f != NULL && f1 != NULL) {
    while (fscanf(f,"%s %s %s",CIN, poid, taille) != EOF) {
          if (strcmp(CIN,a.cin) == 0)
              fprintf(f1,"%s %s %s\n",a.cin, a.poid, a.taille);
          else
              fprintf(f1,"%s %s %s\n",CIN, poid, taille);
    }
  }
  fclose(f);
  fclose(f1);
  remove("a2.txt");
  rename("a22.txt","a2.txt");
}
