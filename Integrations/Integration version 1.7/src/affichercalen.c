#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "affichercalen.h"

void afficher_calendrier(GtkWidget *pListView)
{

enum {
DATE,
HEURE_MATIN,
HEURE_SOIR,
EVENT,

N_COLUMN
};

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_tree_view_get_model(GTK_TREE_VIEW(pListView));

FILE *f;char var[50],var1[50],var2[50],var3[50];
f=fopen("salle.txt","r");

if (pListStore == NULL) {

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("date",
pCellRenderer,
"text", DATE,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);



pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("heure_matin",
pCellRenderer,
"text", HEURE_MATIN,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);



pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("heure_soir",
pCellRenderer,
"text", HEURE_SOIR,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);



pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Evenement",
pCellRenderer,
"text", EVENT,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


}


pListStore = gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


while(fscanf(f,"%s %s %s %s",var,var1,var2,var3)!=EOF)
	{



GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,DATE,var,HEURE_MATIN,var1,HEURE_SOIR,var2,EVENT,var3,-1);
	}



fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);

}
