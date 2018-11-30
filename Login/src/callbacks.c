#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"


void
on_suivant_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *input, *input2;
    GtkWidget *output;

    GtkWidget *window, *window2;

    char login[50], password[50];
    int t[2];

    input = lookup_widget(GTK_WIDGET(button),"entry1");
    input2 = lookup_widget(GTK_WIDGET(button),"entry2");
    window = lookup_widget(GTK_WIDGET(button),"window1");

    strcpy(login,gtk_entry_get_text(GTK_ENTRY(input)));
    strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

    verifier(login,password,t);

    if (t[0] != -1) {
        gtk_widget_destroy(window);
        window2 = create_window2();
        gtk_widget_show(window2);
        }
}

void
on_suivant01_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
GtkWidget *notebook;
GtkWidget *progressbar;
GtkWidget *image;

output = lookup_widget(GTK_WIDGET(button),"label26");
notebook = lookup_widget(GTK_WIDGET(button),"notebook1");
progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1");
image = lookup_widget(GTK_WIDGET(button),"image7");

gtk_label_set_text(GTK_LABEL(output),"Modification du mot de passe");
gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-go-forward",GTK_ICON_SIZE_BUTTON);
gtk_notebook_next_page(notebook);
gtk_progress_bar_update(progressbar,0.33);
}


void
on_suivant02_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *output, *output2;
  GtkWidget *input1, *input2;
  GtkWidget *notebook;
  GtkWidget *progressbar;
  GtkWidget *image, *image2, *image3, *image4;

  int test;

  input1 = lookup_widget(GTK_WIDGET(button),"entry3");
  input2 = lookup_widget(GTK_WIDGET(button),"entry4");

  output = lookup_widget(GTK_WIDGET(button),"label27");
  output2 = lookup_widget(GTK_WIDGET(button),"label29");

  notebook = lookup_widget(GTK_WIDGET(button),"notebook1");

  progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1");

  image = lookup_widget(GTK_WIDGET(button),"image8");
  image2 = lookup_widget(GTK_WIDGET(button),"image7");
  image3 = lookup_widget(GTK_WIDGET(button),"image10");
  image4 = lookup_widget(GTK_WIDGET(button),"image11");

  test = verifier_pass(gtk_entry_get_text(input1),gtk_entry_get_text(input2));

  if (test == 1) {
    gtk_label_set_text(GTK_LABEL(output),"La completion des données personnelle");
    gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-go-forward",GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-ok",GTK_ICON_SIZE_BUTTON);
    gtk_notebook_next_page(notebook);
    gtk_progress_bar_update(progressbar,0.66);
  }
  else
    gtk_label_set_text(GTK_LABEL(output2),"Les mots de passe no sont pas les mêmes");
    gtk_image_set_from_stock(GTK_IMAGE(image3),"gtk-ok",GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image4),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
}

void
on_confirmer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

  GtkWidget *progressbar;
  GtkWidget *image, *image2;

  progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1");
  image = lookup_widget(GTK_WIDGET(button),"image8");
  image2 = lookup_widget(GTK_WIDGET(button),"image7");

  gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-ok",GTK_ICON_SIZE_BUTTON);
  gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-ok",GTK_ICON_SIZE_BUTTON);

  gtk_progress_bar_update(progressbar,1);
}
