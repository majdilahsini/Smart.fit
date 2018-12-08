
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
  DATE_ET_HEURE,
  LOCAL,
  COLUMN
};

void afficher(GtkWidget *list)
{
  GtkCellRenderer *renderer,*toggle;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  char avec[10];
char date_et_heure[50];
char local[20];
  FILE *f;
  store=NULL;
  store=gtk_tree_view_get_model(list);
  if (store == NULL)
  {
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" avec:",renderer,"text",AVEC,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);



    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" date_et_heure",renderer,"text", DATE_ET_HEURE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" local",renderer,"text",LOCAL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);




  }
  store=gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("rdv_adherent.txt","r");
  if(f == NULL)
  {
    return;
  }
  else
  {
    f=fopen("rdv_adherent.txt","a+");
    while(fscanf(f,"%s %s %s",avec,date_et_heure,local) != EOF)
    {
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,AVEC,avec, DATE_ET_HEURE,date_et_heure,LOCAL,local,-1);

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


void enregistrer1(  char nom[50],char prenom[50],date ddn,
  char cin[10],char tel[10],char sexe[10])
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


void enregistrer(  char nom[50],char prenom[50],date ddn,
  char cin[10],char tel[10],char mail[50],char adresse[],char sexe[10],
  char goals[150])
{
FILE *f ;
	f=fopen("adherents2.txt","a+");
	if(f != NULL)
	{
		fprintf(f,"%s %s %d %d %d %s %s %s %s %s %s\n",nom,prenom,ddn.day,
ddn.month, ddn.year,cin,tel,mail,adresse,sexe,goals);
  }
fclose(f);
}

/*enum
{
  NOM,
  PRENOM,
  SPECIALITE,
  COLUMN1
};

void afficher1(GtkWidget *list)
{
  GtkCellRenderer *renderer,*toggle;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  char nom[10];
char prenom[50];
char specialite[20];
  FILE *f;
  store=NULL;
  store=gtk_tree_view_get_model(list);
  if (store == NULL)
  {
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);



    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text", PRENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes(" specialite",renderer,"text",SPECIALITE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);




  }
  store=gtk_list_store_new(COLUMN1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("staff.txt","r");
  if(f == NULL)
  {
    return;
  }
  else
  {
    f=fopen("staff.txt","a+");
    while(fscanf(f,"%s %s %s",nom,prenom,specialite) != EOF)
    {
      gtk_list_store_append(store,&iter);
      gtk_list_store_set(store,&iter,NOM,nom, PRENOM,prenom,SPECIALITE,specialite,-1);

    }
    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
    g_object_unref(store);
  }

}

enum
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
  NOM2,
  PRENOM2,
  COURS,
  DATE,
  HEURE,
  COLUMN2
};

void afficher1(GtkWidget *list) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

  char nom[10], nom1[50];
char prenom[50],prenom1[50];
char cours[20];
char date[50];
char heure[50];
char cin[20], cin2[20],cinn[30];
char tel[30],ddn[50],sexe[10];
char salle[30];
FILE *f, *f2;

f = fopen("coach.txt","r");
f2 = fopen("dispo_coach.txt","r");

store = gtk_tree_view_get_model(list);
if (store == NULL) {

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
}

store = gtk_list_store_new(COLUMN2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (f!=NULL && f2!=NULL) {
  while (fscanf(f2,"%s %s %s %s %s ",cin2,date,heure,salle,cours) != EOF) {
   rewind(f);
      while (fscanf(f,"%s %s %s %s %s %s",nom,prenom,cin,tel,ddn,sexe) != EOF) {
        if (strcmp(cin2,cin) == 0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOM2,nom,PRENOM2,prenom,COURS,cours,DATE,date,HEURE,heure,-1);
      }
    }
  }
}
fclose(f);fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);
}
 

