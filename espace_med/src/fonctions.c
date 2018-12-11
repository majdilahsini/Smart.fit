#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

enum
{

        NOM,
	PRENOM,
        AGE,
        TAILLE,
        POULS,
        PRESSION_SYS,
        PRESSION_DIA,
        COLUMNS
};



void afficher_fiche(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom [30];
	char prenom [30];
	char age [30];
	char taille [30];
        char pouls [30];
        char pression_sys[30];
        char pression_dia[30];
        store=NULL;

       FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  age", renderer, "text",AGE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  taille", renderer, "text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  pouls", renderer, "text",POULS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  pression_sys", renderer, "text",PRESSION_SYS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  pression_dia", renderer, "text",PRESSION_DIA, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);




	}


	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("fiche_med.txt", "r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("fiche_med.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s \n",nom,prenom,age,taille,pouls,pression_sys,pression_dia)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom,AGE,age,TAILLE,taille,POULS,pouls,PRESSION_SYS,pression_sys,PRESSION_DIA,pression_dia, -1);
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}



enum   
{       
  
        JOUR,
	HEURE,
        SALLE,
   
        COLUMN
};

void afficher_rendez_vous(GtkWidget *liste)
{
     
   GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char jour [30];
	char heure[30];
	char salle [30];
        char cin[50],cin_tmp[50];
        store=NULL;

       FILE *f,*g;
	g=fopen("tmp.txt","r");
        fscanf(g,"%s \n",cin_tmp);
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" heure", renderer, "text",HEURE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  salle", renderer, "text",SALLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}

	
	store=gtk_list_store_new (COLUMN, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("rendez_vous.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{
              while(fscanf(f,"%s %s %s %s \n",cin,jour,heure,salle)!=EOF)
		{
                    if(strcmp(cin,cin_tmp)==0)
                       {
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, JOUR, jour, HEURE, heure,SALLE,salle, -1); 
		       }
                }
		fclose(f);
                fclose(g);
        }
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
        g_object_unref (store);
	


}
