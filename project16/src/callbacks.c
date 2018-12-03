#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "f.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void
on_button1s_enter                      (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button2s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1 , *input2;
  GtkWidget *output;
  GtkWidget *login;
  GtkWidget *window2s;
  GtkWidget *image2, *image3;

  char username[50],password[50];
  int v;
  input1=lookup_widget(GTK_WIDGET(button),"entry1s");
  input2=lookup_widget(GTK_WIDGET(button),"entry2s");
  output=lookup_widget(GTK_WIDGET(button),"label4");
  image2 = lookup_widget(GTK_WIDGET(button),"image2");
  image3= lookup_widget(GTK_WIDGET(button),"image3");
  login=lookup_widget(GTK_WIDGET(button),"window1s");
  window2s=create_window2s();


  strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
  v=verif(username,password);
  if (v == 2)
  {
    gtk_widget_show(window2s);
    gtk_label_set_text(GTK_LABEL(output),"Réussi!");
    gtk_widget_hide(login);
  }

  else if (v == 0)
{
  gtk_label_set_text(GTK_LABEL(output),"mot de passe incorrect!");
  gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-yes",GTK_ICON_SIZE_BUTTON);
  gtk_image_set_from_stock(GTK_IMAGE(image3),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
}

else
    {
      gtk_label_set_text(GTK_LABEL(output),"Réesseyer!");
      gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image3),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
    }

}
void
on_button6s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button3s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *accueil;
  GtkWidget *window3s;
  accueil=lookup_widget(GTK_WIDGET(button),"window2s");
  window3s=create_window3s();
  gtk_widget_show_all(window3s);
  gtk_widget_hide_all(accueil);
}

void
on_button8s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *votre_profil;
  GtkWidget *window4s;

  votre_profil=lookup_widget(GTK_WIDGET(button),"window3s");
  window4s=create_window4s();
  gtk_widget_show(window4s);
  gtk_widget_hide_all(votre_profil);

}

void
on_button18s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1 , *input2, *input3 ,  *input4,  *input5,  *input6,*input7;
  GtkWidget *combobox1;
  GtkWidget *day , *month, *year;
  GtkWidget *label9s;
  
  date ddn;
  fp x;
  
  char nom[50];char prenom[50];
  char cin[10];char tel[10];char mail[50];char sexe[10];
  char goals[150]; char adresse[150];

  input1=lookup_widget(GTK_WIDGET(button),"entry9s");
  input2=lookup_widget(GTK_WIDGET(button),"entry10s");
  input3=lookup_widget(GTK_WIDGET(button),"entry11s");
  input4=lookup_widget(GTK_WIDGET(button),"entry12s");
  input5=lookup_widget(GTK_WIDGET(button),"entry13s");
  input6=lookup_widget(GTK_WIDGET(button),"entry15s");
  input7=lookup_widget(GTK_WIDGET(button),"entry14s");
  combobox1=lookup_widget(GTK_WIDGET(button),"combobox1");

  day=lookup_widget(GTK_WIDGET(button),"spinbutton1");
  month=lookup_widget(GTK_WIDGET(button),"spinbutton2");
  year=lookup_widget(GTK_WIDGET(button),"spinbutton3");

  x.ddn.day= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
  x.ddn.month= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
  x.ddn.year= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));

  strcpy(x.sexe, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
  strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(x.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(x.cin, gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(x.tel, gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(x.mail, gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(x.goals, gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(x.adresse, gtk_entry_get_text(GTK_ENTRY(input7)));

  enregistrer(x.nom, x.prenom,x.ddn,x.cin,x.tel,x.mail,x.adresse,x.sexe,x.goals);

}

void
on_button16s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window1s;
  GtkWidget *window4s;
  window4s=lookup_widget(GTK_WIDGET(button),"window4s");
  window1s=create_window1s();
  gtk_widget_show(window1s);
  gtk_widget_hide_all(window4s);
}


void
on_button15s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button17s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window3s;
  GtkWidget *window4s;
  window4s=lookup_widget(GTK_WIDGET(button),"window4s");
  window3s=create_window3s();
  gtk_widget_show(window3s);
  gtk_widget_hide_all(window4s);
}


void
on_button14s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window2s;
  GtkWidget *window4s;
  window4s=lookup_widget(GTK_WIDGET(button),"window4s");
  window2s=create_window2s();
  gtk_widget_show(window2s);
  gtk_widget_hide_all(window4s);
}

void
on_button7s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window1s;
  GtkWidget *window2s;
  window2s=lookup_widget(GTK_WIDGET(button),"window2s");
  window1s=create_window1s();
  gtk_widget_show(window1s);
  gtk_widget_hide_all(window2s);
}


void
on_button11s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}

void
on_button12s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window2s;
  GtkWidget *window3s;
  window3s=lookup_widget(GTK_WIDGET(button),"window3s");
  window2s=create_window2s();
  gtk_widget_show(window2s);
  gtk_widget_hide_all(window3s);
}


void
on_button10s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window1s;
  GtkWidget *window3s;
  window3s=lookup_widget(GTK_WIDGET(button),"window3s");
  window1s=create_window1s();
  gtk_widget_show(window1s);
  gtk_widget_hide_all(window3s);
}

void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  GtkWidget *entry2s;

      entry2s = lookup_widget(GTK_WIDGET(togglebutton),"entry2s");
      if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
      gtk_entry_set_visibility (GTK_ENTRY (entry2s), TRUE);
      else
      gtk_entry_set_visibility (GTK_ENTRY (entry2s), FALSE);
}

void
on_button19s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window2s;
  GtkWidget *window5s;
  window5s=lookup_widget(GTK_WIDGET(button),"window5s");
  window2s=create_window2s();
  gtk_widget_show(window2s);
  gtk_widget_hide_all(window5s);
}


void
on_button20s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window1s;
  GtkWidget *window5s;
  window5s=lookup_widget(GTK_WIDGET(button),"window5s");
  window1s=create_window1s();
  gtk_widget_show(window1s);
  gtk_widget_hide_all(window5s);
}


void
on_button21s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button23s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button22s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton1s_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  GtkWidget *combo1, *combo2;

  FILE *f;
  char date[50];

  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  {
    f=fopen("dispo1.txt","r");
    combo1=lookup_widget(GTK_WIDGET(togglebutton),"combobox5s");

    while (fscanf(f,"%s",date)
     != EOF)
    {
      gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),date);
    }
    fclose(f);
  }

}


void
on_checkbutton2s_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  GtkWidget *combo1, *combo2;

  FILE *f;
  char date[50];

  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  {
    f=fopen("dispo2.txt","r");
    combo1=lookup_widget(GTK_WIDGET(togglebutton),"combobox4s");

    while (fscanf(f,"%s",date)
     != EOF)
    {
      gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),date);
    }
    fclose(f);
  }

}


void
on_checkbutton3s_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  GtkWidget *combo1, *combo2;

  FILE *f;
  char date[50];

  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  {
    f=fopen("dispo3.txt","r");
    combo1=lookup_widget(GTK_WIDGET(togglebutton),"combobox6s");

    while (fscanf(f,"%s",date)
     != EOF)
    {
      gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),date);
    }
    fclose(f);
  }

}


void
on_checkbutton4s_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  GtkWidget *combo1, *combo2;

  FILE *f;
  char date[50];

  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  {
    f=fopen("dispo4.txt","r");
    combo1=lookup_widget(GTK_WIDGET(togglebutton),"combobox7s");

    while (fscanf(f,"%s",date)
     != EOF)
    {
      gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),date);
    }
    fclose(f);
  }

}

void
on_button4s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *accueil;
  GtkWidget *window5s;
  accueil=lookup_widget(GTK_WIDGET(button),"window2s");
  window5s=create_window5s();
  gtk_widget_show_all(window5s);
  gtk_widget_hide_all(accueil);
}
