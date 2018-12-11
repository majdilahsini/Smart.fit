
#include "f.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <gtk/gtk.h>

int verif (char login[], char password[], char cin[20])
 {
   int role,test =0,x;
   char ch[50],ch1[50],ch2[20];
   FILE *f;
   f = fopen("users.txt","r");
   x=-1;
   if (f != NULL)
   {
     while ((fscanf(f,"%s %s %s %d\n",ch2,ch,ch1,&role)!=EOF) && (x==-1))
     {
       if ((strcmp(ch,login) == 0) && (strcmp(ch1,password) ==0)) {
         fclose(f);
         strcpy(cin,ch2);
         return role;
       }
     }
   }
fclose(f);
return 0;

 }



int verifier_pass(char new_password[],char conf_password[])
{
  if (strcmp(new_password,conf_password) == 0)
      return 1;
  else
      return -1;
}


/*void enregistrer(  char nom[50],char prenom[50],date ddn,
  char cin[10],char tel[10],char mail[50],char adresse[],char sexe[10],
  char goals[150])
{
FILE *f ;
	f=fopen("adherents.txt","a+");
	if(f != NULL)
	{
		fprintf(f,"%s %s %d %d %d %s %s %s %s %s %s\n",nom,prenom,ddn.day,
ddn.month, ddn.year,cin,tel,mail,adresse,sexe,goals);
  }
fclose(f);
}


void enregistre_new_mdp(char username[], char new_pass[])
{
	FILE *f1, *f2;
	char ch2[50],ch1[50];
	int role;
	f1=fopen("users.txt","r");
	f2=fopen("users1.txt","w+");
	if (f1 != NULL)
   	{
		while ((fscanf(f1,"%s %s %d\n",ch1,ch2,&role)!=EOF) )
     		{
			if(strcmp(ch1,username) == 0)
			{
				strcpy(ch2,new_pass);
				fprintf(f2,"%s %s %d \n",ch1,ch2,role);
			}
			fclose(f2);
		}
		fclose(f1);
	}
	rename(f2,f1);
	remove(f1);
}*/



void enregistrer_rdv( char date[50])
{
FILE *f ;
	f=fopen("rdv_adherent.txt","a+");
	if(f != NULL)
	{
		fprintf(f,"%s \n",date);
        }
fclose(f);
}

void create_tmp( char ch[50])
{
FILE *f ;
	f=fopen("tmp.txt","w");
	if(f != NULL)
	{
		fprintf(f,"%s \n",ch);
        }
fclose(f);
}

enum
{
  AVEC,
  NOM,
  PRENOM,
  DATE,
  HEURE,
  LOCAL,
  COURS,
  COLUMN
};

void afficher_rdv(GtkWidget *list)
{
  GtkCellRenderer *renderer,*toggle;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  char avec[40];
  char date[50];
  char local[20];
  char nom[50];
  char prenom[50];
  char heure[50];
  char cours[50];
  FILE *f;
  store=NULL;
  store=gtk_tree_view_get_model(list);
  if (store == NULL)
  {
    
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" avec",renderer,"text",AVEC,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" heure",renderer,"text",HEURE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" local",renderer,"text",LOCAL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" cours",renderer,"text",COURS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


  }
  store=gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("rdv_adherent.txt","r");
  if(f == NULL)
  {
    return;
  }
  else
  {
    f=fopen("rdv_adherent.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s %s",avec,nom,prenom,date,heure,local,cours) != EOF)
    {
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter, NOM,nom,PRENOM,prenom,AVEC,avec,DATE,date,HEURE,heure,LOCAL,local,COURS, cours,-1);

    }
    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
    g_object_unref(store);
  }

}



/*void supprimer(char date[])
{
  FILE *f1 ,*f2 ;
  char ch[50];
  f1= fopen("dispo_coach.txt","r");
  f2=fopen("dispo_coach","w+");
  if (f1 != NULL && f2!= NULL)
  {
    while (fscanf(f1,"%s ",ch)!=EOF)
    {
      if (strcmp(date,ch)==0)
      fprintf(f2," ");
      else
      fprintf(f2,"%s %s %s\n",ch);
    }
  }
  fclose(f1);
  fclose(f2);
  remove(f1);
  rename("f1","f2");
}



void ajouter(char username[],char new_pass[], int role) {

FILE *f;

f = fopen("users.txt","w+");

fprintf(f,"%s %s %d\n",username,new_pass,role);

fclose(f);

}

int str_to_int (char a[])
{

int i,l,n;
l = strlen(a);
n = 0;

for (i=0;i<l;i++) {
	if (a[i]<48 || a[i]>57)
		return NULL;
	n = n*10 +a[i] -'0';
}

return n;
}*/


/*void enregistrer1( char cin[10], char nom[50],char prenom[50],date ddn,char tel[10],char sexe[10])
{
FILE *f ;
	f=fopen("adherents.txt","a+");
	if(f != NULL)
	{
		fprintf(f,"%s %s %d %d %d %s %s %s \n",nom,prenom,ddn.day,
ddn.month, ddn.year,cin,tel,sexe);
  }
fclose(f);
}
*/

void enregistrer( char cin[10] ,char nom[50],char prenom[50],date ddn,char tel[10],char mail[50],char sexe[20])
{
FILE *f ;
	f=fopen("adherents.txt","a+");
	if(f != NULL)
	{
		fprintf(f,"%s %s %s %d %d %d  %s %s %s\n",cin,nom,prenom,ddn.day,ddn.month,ddn.year,tel,mail,sexe);
  }
fclose(f);
}

/*enum
{
  NOMS,
  PRENOMS,
  SPECIALITES,
  TELS,
  COLUMNS
};

void afficher_staff(GtkWidget *list)
{
  GtkCellRenderer *renderer,*toggle;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  char nom[10];
char prenom[50];
char specialite[100];
char cin[30],tel[30],sexe[30];
char date[30];
  FILE *f,*g,*k,*i;
  store=NULL;
  store=gtk_tree_view_get_model(list);
  if (store == NULL)
  {
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOMS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);



    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text", PRENOMS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" specialite",renderer,"text",SPECIALITES,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" tel",renderer,"text",TELS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("dieteticien.txt","r");
  if(f == NULL)
  {
    return;
  }
  else
  {
    f=fopen("dietetitien.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s",nom,prenom,cin,tel,date,sexe) != EOF)
    {
      strcpy(specialite,"diététicien");
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOMS,nom, PRENOMS,prenom,SPECIALITES,specialite,TELS,tel,-1);

    }
    fclose(f);
   } 
    g=fopen("medecin.txt","r");
    if(g == NULL)
  {
    return;
  }
  else
  {
    g=fopen("medecin.txt","a+");
    while(fscanf(g,"%s %s %s %s %s %s",nom,prenom,cin,tel,date,sexe) != EOF)
    {
      strcpy(specialite,"medecin");
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOMS,nom, PRENOMS,prenom,SPECIALITES,specialite,TELS,tel,-1);

    }
    fclose(g);
    }
    k=fopen("kine.txt","r");
    if(k == NULL)
  {
    return;
  }
  else
  {
    k=fopen("kine.txt","a+");
    while(fscanf(k,"%s %s %s %s %s %s",nom,prenom,cin,tel,date,sexe) != EOF)
    {
      strcpy(specialite,"Kinésitherapeute");
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOMS,nom, PRENOMS,prenom,SPECIALITES,specialite,TELS,tel,-1);

    }
    fclose(k);
    }
    i=fopen("coach.txt","r");
    if(i == NULL)
  {
    return;
  }
  else
  {
    i=fopen("coach.txt","a+");
    while(fscanf(i,"%s %s %s %s %s %s",nom,prenom,cin,tel,date,sexe) != EOF)
    {
      strcpy(specialite,"coach");
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOMS,nom, PRENOMS,prenom,SPECIALITES,specialite,TELS,tel,-1);

    }
    fclose(i);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
    g_object_unref(store);
  }

}*/

/*enum
{
  NOM2,
  PRENOM2,
  COURS,
  DATE,
  HEURE,
  COLUMN2
};


void afficher2(GtkWidget *list)
{
  GtkCellRenderer *renderer,*toggle;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  char nom[10], nom1[50];
char prenom[50],prenom1[50];
char cours[20];
char date[50];
char heure[50];
char cin[20], cin1[20],cinn[30];
char tel[30],ddn[50],sexe[10];
char salle[30];
  FILE *f,*g,*k;
  
 g=fopen("dispo_coach.txt","r");
  if (g!=NULL)
      fscanf(g,"%s %s %s %s %s",cin,date,heure,salle,cours);

  k=fopen("coach.txt","r");



  while(fscanf(k,"%s %s %s %s %s %s",nom1,prenom1,cin1,tel,ddn,sexe)!=EOF)
  {
      if (strcmp(cin1,cin) == 0)
        { 
		strcpy(nom,nom1);
		strcpy(prenom,prenom1);
	}
  }
  fclose(g);
  fclose(k);
  
  store=NULL;
  store=gtk_tree_view_get_model(list);
  if (store == NULL)
  {
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text", PRENOM2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" heure",renderer,"text",HEURE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
   
   renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" cours",renderer,"text",COURS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
  store=gtk_list_store_new(COLUMN2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("dispo_coach.txt","r");
  if(f == NULL)
  {
    return;
  }
  
  else
  {
  
  g=fopen("dispo_coach.txt","r");
  if (g!=NULL)
      fscanf(g,"%s %s %s %s %s",cin,date,heure,salle,cours);

  k=fopen("coach.txt","r");

if (k != NULL)
 {

  while(fscanf(k,"%s %s %s %s %s %s",nom1,prenom1,cin1,tel,ddn,sexe)!=EOF)
  {
      if (strcmp(cin1,cin) == 0)
        { 
		f=fopen("dispo_coach.txt","a+");
    		while(fscanf(f,"%s %s %s %s %s ",cin,date,heure,salle,cours) != EOF)
    		{
     
     			 gtk_list_store_append(store,&iter);
     			 gtk_list_store_set(store,&iter,NOM,nom, PRENOM,prenom,COURS ,cours,DATE,date,HEURE,heure,-1);
      

   		 }
	}
  }
  
  }
  
  
    
    fclose(f);
     fclose(g);
  fclose(k);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
    g_object_unref(store);
  }

}*/


enum
{
  NOMC,
  PRENOMC,
  COURSC,
  DATEC,
  HEUREC,
  SALLEC,
  COLUMNC
};

/*void afficher_coach(GtkWidget *list) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

  char nom[50], nom1[50];
char prenom[50],prenom1[50];
char cours[50];
char date[50];
char heure[50];
char cin[30], cin2[30],cinn[30];
char tel[50],ddn[50],sexe[30];
char salle[30];
FILE *f, *f2;

f = fopen("coach.txt","r");
f2 = fopen("dispo_coach.txt","r");

store = gtk_tree_view_get_model(list);
if (store == NULL) {

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOMC,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text", PRENOMC,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" cours",renderer,"text",COURSC,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATEC,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" heure",renderer,"text",HEUREC,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" salle",renderer,"text",SALLEC,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
}


store = gtk_list_store_new(COLUMNC,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL && f2!=NULL) {
  while (fscanf(f2,"%s %s %s %s %s ",cin2,date,heure,salle,cours) != EOF) {
   rewind(f);
      while (fscanf(f,"%s %s %s %s %s %s\n",nom,prenom,cin,tel,ddn,sexe) != EOF) {
        if (strcmp(cin2,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMC,nom,PRENOMC,prenom,COURSC,cours,DATEC,date,HEUREC,heure,SALLEC,salle,-1);
      }
    }
  }
}
fclose(f);fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);
}
 */
 
 enum
{
  NOMD,
  PRENOMD,
  DATED,
  HEURED,
  SALLED,
  COLUMND
};

void afficher_diet(GtkWidget *list) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

  char nom[50], nom1[50];
char prenom[50],prenom1[50];
char cours[50];
char date[50];
char heure[50];
char cin[30], cin2[30],cinn[30];
char tel[50],ddn[50],sexe[30];
char salle[30];
FILE *f, *f2;

f = fopen("dieteticiens.txt","r");
f2 = fopen("dispo_diet.txt","r");

store = gtk_tree_view_get_model(list);
if (store == NULL) {

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOMD,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text", PRENOMD,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATED,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" heure",renderer,"text",HEURED,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" salle",renderer,"text",SALLED,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
}


store = gtk_list_store_new(COLUMND,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL && f2!=NULL) {
  while (fscanf(f2,"%s %s %s %s",cin2,date,heure,salle) != EOF) {
   rewind(f);
      while (fscanf(f,"%s %s %s %s %s %s",nom,prenom,cin,tel,ddn,sexe) != EOF) {
        if (strcmp(cin2,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMD,nom,PRENOMD,prenom,DATED,date,HEURED,heure,SALLED,salle,-1);
      }
    }
  }
}
fclose(f);fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);
}
 


 enum
{
  NOMK,
  PRENOMK,
  DATEK,
  HEUREK,
  SALLEK,
  COLUMNK
};

void afficher_kine(GtkWidget *list) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[50], nom1[50];
char prenom[50],prenom1[50];
char cours[50];
char date[50];
char heure[50];
char cin[30], cin2[30],cinn[30];
char tel[50],ddn[50],sexe[30];
char salle[30];

FILE *f, *f2;

f = fopen("kine.txt","r");
f2 = fopen("dispo_kiné.txt","r");

store = gtk_tree_view_get_model(list);
if (store == NULL) {

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOMK,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text", PRENOMK,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATEK,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" heure",renderer,"text",HEUREK,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" salle",renderer,"text",SALLEK,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
}


store = gtk_list_store_new(COLUMNK,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL && f2!=NULL) {
  while (fscanf(f2,"%s %s %s %s",cin2,date,heure,salle) != EOF) {
   rewind(f);
      while (fscanf(f,"%s %s %s %s %s %s",nom,prenom,cin,tel,ddn,sexe) != EOF) {
        if (strcmp(cin2,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMK,nom,PRENOMK,prenom,DATEK,date,HEUREK,heure,SALLEK,salle,-1);
      }
    }
  }
}
fclose(f);fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);
}
 



enum
{
  NOMM,
  PRENOMM,
  DATEM,
  HEUREM,
  SALLEM,
  COLUMNM
};

void afficher_med(GtkWidget *list) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

  char nom[50], nom1[50];
char prenom[50],prenom1[50];
char cours[50];
char date[50];
char heure[50];
char cin[30], cin2[30],cinn[30];
char tel[50],ddn[50],sexe[30];
char salle[30];
FILE *f, *f2;

f = fopen("medecin.txt","r");
f2 = fopen("dispo_med.txt","r");

store = gtk_tree_view_get_model(list);
if (store == NULL) {

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOMM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text", PRENOMM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATEM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" heure",renderer,"text",HEUREM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" salle",renderer,"text",SALLEM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
}


store = gtk_list_store_new(COLUMNM,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL && f2!=NULL) {
  while (fscanf(f2,"%s %s %s %s",cin2,date,heure,salle) != EOF) {
   rewind(f);
      while (fscanf(f,"%s %s %s %s %s %s",nom,prenom,cin,tel,ddn,sexe) != EOF) {
        if (strcmp(cin2,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMM,nom,PRENOMM,prenom,DATEM,date,HEUREM,heure,SALLEM,salle,-1);
      }
    }
  }
}
fclose(f);fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);
}
 

/*void annuler_rdv(char date[30],char heure[30], char salle[30]) 
{
  FILE *f2, *f1;
  char date1[30],heure1[30], cin [20],salle1[20],cour1[20],nom1[50],prenom1[50];
 char type1[50];


  f2 = fopen("rdv_adherent.txt","r");
  f1 = fopen("rdv_adherent2.txt","w");

  if (f2 != NULL && f1 != NULL)
   {
    while (fscanf(f2,"%s %s %s %s %s %s %s",nom1,prenom1,type1,date1,heure1,salle1,cour1) != EOF) 
    {
          if ((strcmp(date,date1) == 0) && (strcmp(heure,heure1)==0) && (strcmp(salle,salle1)==0))
              fprintf(f1,"");
          else
              fprintf(f1,"%s %s %s %s %s %s %s\n",nom1,prenom1,type1,date1,heure1,salle1,cour1);
    }
  }
  fclose(f2);
  fclose(f1);
  remove("rdv_adherents.txt");
  rename("rdv_adherent2.txt","rdv_adherent.txt");
}*/
				
	
void mod_profil_adh (fp a, char cin[10]) 
{
  FILE *f, *g;
  char nom [20],prenom [20], cin1[20], tel [20], sexe [20],mail[50];
  int day,month,year;


  f = fopen("adherents.txt","r");
  g = fopen("adherents2.txt","w+");

  if (f != NULL && g != NULL) {
    while (fscanf(f,"%s %s %s %d %d %d %s %s %s",cin1,nom,prenom,&day, &month, &year,tel,mail, sexe) != EOF) {
          if (strcmp(cin1,cin) == 0)
              fprintf(g,"%s %s %s %d %d %d %s %s %s\n",a.cin,a.nom,a.prenom,a.ddn.day,a.ddn.month,a.ddn.year,a.tel,a.mail,a.sexe);
          else
              fprintf(g,"%s %s %s %d %d %d %s %s %s\n",cin1,nom,prenom,day,month,year,tel,mail,sexe);
    }
  }
  fclose(f);
  fclose(g);
remove("adherents.txt");
rename("adherents2.txt","adherents.txt");
}	
	
	
void tmp_cin (char cin[10])
{
  FILE *f;
  char a[10];

  f = fopen("tmp.txt","r");

  if (f != NULL)
  fscanf(f,"%s",cin);

    fclose(f);
}	
	
void actualiser_dispo_diet(char date[30],char heure[30], char salle[30]) 
{
  FILE *f2, *f1;
  char date1[30],heure1[30], cin1 [20],salle1[20],cour1[20],nom1[50],prenom1[50];
 char type1[50];


  f2 = fopen("dispo_diet.txt","r");
  f1 = fopen("dispo_diet2.txt","w");

  if (f2 != NULL && f1 != NULL)
   {
    while (fscanf(f2,"%s %s %s %s",cin1,date1,heure1,salle1) != EOF) 
    {
          if ((strcmp(date,date1) == 0) && (strcmp(heure,heure1)==0) && (strcmp(salle,salle1)==0))
              fprintf(f1,"");
          else
              fprintf(f1,"%s %s %s %s \n",cin1,date1,heure1,salle1);
    }
  }
  fclose(f2);
  fclose(f1);
  remove("dispo_diet.txt");
  rename("dispo_diet2.txt","dispo_diet.txt");
}


void actualiser_dispo_med(char date[30],char heure[30], char salle[30]) 
{
  FILE *f2, *f1;
  char date1[30],heure1[30], cin1 [20],salle1[20],cour1[20],nom1[50],prenom1[50];
 char type1[50];


  f2 = fopen("dispo_med.txt","r");
  f1 = fopen("dispo_med2.txt","w");

  if (f2 != NULL && f1 != NULL)
   {
    while (fscanf(f2,"%s %s %s %s",cin1,date1,heure1,salle1) != EOF) 
    {
          if ((strcmp(date,date1) == 0) && (strcmp(heure,heure1)==0) && (strcmp(salle,salle1)==0))
              fprintf(f1,"");
          else
              fprintf(f1,"%s %s %s %s \n",cin1,date1,heure1,salle1);
    }
  }
  fclose(f2);
  fclose(f1);
  remove("dispo_med.txt");
  rename("dispo_med2.txt","dispo_med.txt");
  
}

void actualiser_dispo_kine(char date[30],char heure[30], char salle[30]) 
{
  FILE *f2, *f1;
  char date1[30],heure1[30], cin1 [20],salle1[20],cour1[20],nom1[50],prenom1[50];
 char type1[50];


  f2 = fopen("dispo_kiné.txt","r");
  f1 = fopen("dispo_kiné2.txt","w");

  if (f2 != NULL && f1 != NULL)
   {
    while (fscanf(f2,"%s %s %s %s",cin1,date1,heure1,salle1) != EOF) 
    {
          if ((strcmp(date,date1) == 0) && (strcmp(heure,heure1)==0) && (strcmp(salle,salle1)==0))
              fprintf(f1,"");
          else
              fprintf(f1,"%s %s %s %s \n",cin1,date1,heure1,salle1);
    }
  }
  fclose(f2);
  fclose(f1);
  remove("dispo_kiné.txt");
  rename("dispo_kiné2.txt","dispo_kiné.txt");
  
}

/*void actualiser_dispo_coach(char date[30],char heure[30], char salle[30]) 
{
  FILE *f2, *f1;
  char date1[30],heure1[30], cin1 [20],salle1[20],cour1[20],nom1[50],prenom1[50];
 char type1[50]; char cours1[50];


  f2 = fopen("dispo_coach.txt","r");
  f1 = fopen("dispo_coach2.txt","w");

  if (f2 != NULL && f1 != NULL)
   {
    while (fscanf(f2,"%s %s %s %s %s",cin1,date1,heure1,salle1,cours1) != EOF) 
    {
          if ((strcmp(date,date1) == 0) && (strcmp(heure,heure1)==0) && (strcmp(salle,salle1)==0))
              fprintf(f1,"");
          else
              fprintf(f1,"%s %s %s %s %s \n",cin1,date1,heure1,salle1,cours1);
    }
  }
  fclose(f2);
  fclose(f1);
  remove("dispo_coach.txt");
  rename("dispo_coach2.txt","dispo_coach.txt");
  
}*/

 enum
{
  NOMC2,
  PRENOMC2,
  DATEC2,
  HEUREC2,
  SALLEC2,
  COURSC2,
  COLUMNC2
};

void afficher_coach(GtkWidget *list) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

  char nom[50], nom1[50];
char prenom[50],prenom1[50];
char cours[50];
char date[50];
char heure[50];
char cin[30], cin2[30],cinn[30];
char tel[50],ddn[50],sexe[30];
char salle[30];
int capacite;
FILE *f, *f2;

f = fopen("coach.txt","r");
f2 = fopen("dispo_coach.txt","r");

store = gtk_tree_view_get_model(list);
if (store == NULL) {

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOMC2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text", PRENOMC2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATEC2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" heure",renderer,"text",HEUREC2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" salle",renderer,"text",SALLEC2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" cours",renderer,"text",COURSC2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
  


store = gtk_list_store_new(COLUMNC2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL && f2!=NULL) {
  while (fscanf(f2,"%s %s %s %s %s %d",cin2,date,heure,salle,cours,&capacite) != EOF) {
   rewind(f);
      while (fscanf(f,"%s %s %s %s %s %s",nom,prenom,cin,tel,ddn,sexe) != EOF) {
        if (strcmp(cin2,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMC2,nom,PRENOMC2,prenom,DATEC2,date,HEUREC2,heure,SALLEC2,salle,COURSC2,cours,-1);
      }
    }
  }
}
fclose(f);fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

void actualiser_dispo_coach2(char date[30],char heure[30], char salle[30]) 
{
  FILE *f2, *f1;
  char date1[30],heure1[30], cin1 [20],salle1[20],cours1[20],nom1[50],prenom1[50];
 char type1[50];
int capacite1;

  f2 = fopen("dispo_coach.txt","r");
  f1 = fopen("dispo_coach2.txt","w");

  if (f2 != NULL && f1 != NULL)
   {
    while (fscanf(f2,"%s %s %s %s %s %d",cin1,date1,heure1,salle1,cours1,&capacite1) != EOF) 
    {
          if ((strcmp(date,date1) == 0) && (strcmp(heure,heure1)==0) && (strcmp(salle,salle1))==0) 
            {
              
         
              capacite1=capacite1-1;
              fprintf(f1,"%s %s %s %s %s %d \n",cin1,date1,heure1,salle1,cours1,capacite1);
    
            }
          else
              fprintf(f1,"%s %s %s %s %s %d \n",cin1,date1,heure1,salle1,cours1,capacite1);
    }
  }
  fclose(f2);
  fclose(f1);
  remove("dispo_coach.txt");
  rename("dispo_coach2.txt","dispo_coach.txt");
  
}

void annuler_rdv2(char date[30],char heure[30], char salle[30]) 
{
  FILE *f2, *f1;
  char date1[30],heure1[30], cin1 [20],salle1[20],cour1[20],nom1[50],prenom1[50];
 char type1[50];
char cours1[50];

  f2 = fopen("rdv_adherent.txt","r");
  f1 = fopen("rdv_adherent2.txt","w");

  if (f2 != NULL && f1 != NULL)
   {
    while (fscanf(f2,"%s %s %s %s %s %s %s",type1,nom1,prenom1,date1,heure1,salle1,cours1) != EOF) 
    {
          if ((strcmp(date,date1) == 0) && (strcmp(heure,heure1)==0) && (strcmp(salle,salle1)==0))
              fprintf(f1,"");
          else
              fprintf(f1,"%s %s %s %s %s %s %s \n",type1,nom1,prenom1,date1,heure1,salle1,cours1);
    }
  }
  fclose(f2);
  fclose(f1);
  remove("rdv_adherent.txt");
  rename("rdv_adherent2.txt","rdv_adherent.txt");
}






 enum
{
  EVENT,
  COLUMNE
};
void afficher_calendrier(GtkWidget *list)
{
  GtkCellRenderer *renderer,*toggle;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  
  char date[50];
  char heure_mat[50];
  char heure_soir[50];
  char event[50];
  FILE *f;
  store=NULL;
  store=gtk_tree_view_get_model(list);
  if (store == NULL)
  {
    
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" event",renderer,"text",EVENT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


  }
  store=gtk_list_store_new(COLUMNE,G_TYPE_STRING);
  f=fopen("calendrier.txt","r");
  if(f == NULL)
  {
    return;
  }
  else
  {
    f=fopen("calendrier.txt","a+");
    while(fscanf(f,"%s %s %s %s",date,heure_mat,heure_soir,event) != EOF)
    {
      if(strcmp(event,"none") != 0)
      {
	      gtk_list_store_append(store,&iter);
	      gtk_list_store_set(store,&iter, EVENT,event,-1);
	}

    }
    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
    g_object_unref(store);
  }

}


 
 enum
{
  NOMS,
  PRENOMS,
  SPECIALITES,
  TELS,
  COLUMNS
};

void afficher_staff2(GtkWidget *list)
{
  GtkCellRenderer *renderer,*toggle;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char prenom[50];
char specialite[100];
char cin[30],tel[30],sexe[30];
char date[30];
char nom[50];
  FILE *f,*g,*k,*i;

  store=NULL;
  store=gtk_tree_view_get_model(list);
  if (store == NULL)
  {
    
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOMS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOMS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
    
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" avec",renderer,"text",SPECIALITES,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",TELS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);



  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  
f=fopen("dieteticien.txt","r");
  if(f == NULL)
  {
    return;
  }
  else
  {
    f=fopen("dietetitien.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s",nom,prenom,cin,tel,date,sexe) != EOF)
    {
      strcpy(specialite,"diététicien");
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOMS,nom, PRENOMS,prenom,SPECIALITES,specialite,TELS,tel,-1);

    }
    fclose(f);
   } 
    g=fopen("medecin.txt","r");
    if(g == NULL)
  {
    return;
  }
  else
  {
    g=fopen("medecin.txt","a+");
    while(fscanf(g,"%s %s %s %s %s %s",nom,prenom,cin,tel,date,sexe) != EOF)
    {
      strcpy(specialite,"medecin");
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOMS,nom, PRENOMS,prenom,SPECIALITES,specialite,TELS,tel,-1);

    }
    fclose(g);
    }
    k=fopen("kine.txt","r");
    if(k == NULL)
  {
    return;
  }
  else
  {
    k=fopen("kine.txt","a+");
    while(fscanf(k,"%s %s %s %s %s %s",nom,prenom,cin,tel,date,sexe) != EOF)
    {
      strcpy(specialite,"Kinésitherapeute");
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOMS,nom, PRENOMS,prenom,SPECIALITES,specialite,TELS,tel,-1);

    }
    fclose(k);
    }
    i=fopen("coach.txt","r");
    if(i == NULL)
  {
    return;
  }
  else
  {
    i=fopen("coach.txt","a+");
    while(fscanf(i,"%s %s %s %s %s %s",nom,prenom,cin,tel,date,sexe) != EOF)
    {
      strcpy(specialite,"coach");
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOMS,nom, PRENOMS,prenom,SPECIALITES,specialite,TELS,tel,-1);

    }
    fclose(i);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
    g_object_unref(store);
  }

}

