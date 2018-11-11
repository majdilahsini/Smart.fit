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
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input, *input2, *input3;
  GtkWidget *output_prin , *output_login, *output_pass, *output_role;

  int  int_role;
  char login[50], password[50],role[50];
  char msg_role[50], msg_pass[50], msg_login[50], msg_prin[100];

  input = lookup_widget(GTK_WIDGET(button),"entry1");
  input2 = lookup_widget(GTK_WIDGET(button),"entry2");
  input3 = lookup_widget(GTK_WIDGET(button),"entry3");

  output_prin = lookup_widget(GTK_WIDGET(button),"Messageprincipale");
  output_login = lookup_widget(GTK_WIDGET(button),"Messagelogin");
  output_pass = lookup_widget(GTK_WIDGET(button),"Messagepass");
  output_role = lookup_widget(GTK_WIDGET(button),"Messagerole");

  strcpy(login,gtk_entry_get_text(GTK_ENTRY(input)));
  strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(role,gtk_entry_get_text(GTK_ENTRY(input3)));

// Verify (Ajouter)
  verifi_ajout(login,password,role,msg_login,msg_role,msg_pass,msg_prin);
  int_role = str_to_int(role);

  if (strcmp(msg_prin,"L'ajout au fichier a été éffectué avec succéss")==0) {
    ajouter(login,password,int_role);
    gtk_label_set_text(GTK_LABEL(output_prin),msg_prin);
    gtk_label_set_text(GTK_LABEL(output_pass),msg_pass);
    gtk_label_set_text(GTK_LABEL(output_role),msg_role);
    gtk_label_set_text(GTK_LABEL(output_login),msg_login);
  }
  else {
    gtk_label_set_text(GTK_LABEL(output_prin),msg_prin);
    gtk_label_set_text(GTK_LABEL(output_pass),msg_pass);
    gtk_label_set_text(GTK_LABEL(output_role),msg_role);
    gtk_label_set_text(GTK_LABEL(output_login),msg_login);
  }

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input, *input2;
  GtkWidget *output;

  GtkWidget *main_window;


  int n;
  char login[50], password[50],ch[50],ch2[50] = "Bienvenue dans l'espace ";

  input = lookup_widget(GTK_WIDGET(button),"entry1");
  input2 = lookup_widget(GTK_WIDGET(button),"entry2");
  main_window = lookup_widget(GTK_WIDGET(button),"window1");

  output = lookup_widget(GTK_WIDGET(button),"Messageprincipale");

  strcpy(login,gtk_entry_get_text(GTK_ENTRY(input)));
  strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

//Verify if login/password combination already exists return ROLE if exist, -1 if not;
  n = verifier(login,password);

// ch will be created, depending on the return value n.
  switch(n) {
    case -1: gtk_label_set_text(GTK_LABEL(output),"Le login ou le password est incorrect");
    case 1: strcpy(ch,"Admin") ;break;
    case 2: strcpy(ch,"Adhérent") ;break;
    case 3: strcpy(ch,"Médecin ") ;break;
    case 4: strcpy(ch,"Diététicien") ;break;
    case 5: strcpy(ch,"Coach") ;break;
    case 6: strcpy(ch,"Kiné") ;break;
  }

// if n != -1 (login/password dosen't exist.. login_button will create a new window)
if (n!=-1) {
  strcat(ch2,ch);
  GtkWidget *window1;
  GtkWidget *fixed1;
  GtkWidget *button1;
  GtkWidget *label1;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (window1, 300, 300);
  gtk_window_set_title (GTK_WINDOW (window1), _("window1"));
  gtk_window_set_position (GTK_WINDOW (window1), GTK_WIN_POS_CENTER);

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (window1), fixed1);

  if (n == 1) {
  button1 = gtk_button_new_with_mnemonic (_("Afficher la liste"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 100, 240);
  gtk_widget_set_size_request (button1, 100, 29);
  }

  label1 = gtk_label_new (_(ch2));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed1), label1, 25, 120);
  gtk_widget_set_size_request (label1, 250, 17);

  button1 = gtk_button_new_with_mnemonic (_("Quitter"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 249, 270);
  gtk_widget_set_size_request (button1, 50, 29);

  gtk_widget_show_all(window1);

  gtk_widget_hide_all(main_window);
}

}

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}
