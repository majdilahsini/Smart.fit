#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "afficher.h"

void afficher(GtkWidget *pListView,int role)
{

enum {

LOGIN,
PASSWORD,
ROLE,
CIN,
ETAT,
N_COLUMN
};


GtkWidget  *window_ay4;

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_tree_view_get_model(GTK_TREE_VIEW(pListView));

FILE *f;char var[50],var1[50],var3[50];int var2,etat;
f=fopen("users.txt","r");


if (pListStore == NULL) {



pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("login",
pCellRenderer,
"text", LOGIN,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("password",
pCellRenderer,
"text", PASSWORD,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("role",
pCellRenderer,
"text", ROLE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();

pColumn = gtk_tree_view_column_new_with_attributes("cin",pCellRenderer,"text", CIN,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);
}

pListStore=gtk_list_store_new(N_COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT, G_TYPE_STRING,G_TYPE_UINT);


while(fscanf(f,"%s %s %d %s %d",var,var1,&var2,var3,&etat)!=EOF)
	{

if (role!=var2)
continue;

GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,LOGIN,var,PASSWORD,var1,ROLE,var2,CIN,var3,ETAT,etat,-1);
	}



fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);	

}
