#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "ntbook.h"

void select_page (GtkToolButton *button,int page, char name[20]) {

  GtkWidget *notebook;

  notebook = lookup_widget(GTK_WIDGET(button),name);

  gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),page);
}
