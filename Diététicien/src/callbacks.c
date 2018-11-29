#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "login.h"
#include "fonction.h"


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  GtkWidget *entry2;

    entry2 = lookup_widget(GTK_WIDGET(togglebutton),"entry2");
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
    gtk_entry_set_visibility (GTK_ENTRY (entry2), FALSE);
    else
    gtk_entry_set_visibility (GTK_ENTRY (entry2), TRUE);
}

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input, *input2;
  GtkWidget *output;

  GtkWidget *window1;
  GtkWidget *window2;

  int n;
  user a;

  input = lookup_widget(GTK_WIDGET(button),"entry1");
  input2 = lookup_widget(GTK_WIDGET(button),"entry2");
  window1 = lookup_widget(GTK_WIDGET(button),"window1");

  output = lookup_widget(GTK_WIDGET(button),"label7");

  strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(input)));
  strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(input2)));

  //Verify if login/password combination already exists return ROLE if exist, -1 if not;
  n = verifier(a);

  if (n != -1)
  {
  window2 = create_window2();
  gtk_widget_show(window2);
  gtk_widget_destroy(window1);
  }
  else
  gtk_label_set_text(GTK_LABEL(output),"Le login ou le password est incorrect");
}

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}

void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *window1, *window2;
  window2 = lookup_widget(GTK_WIDGET(button),"window2");

  window1 = create_window1();
  gtk_widget_show(window1);
  gtk_widget_destroy(window2);
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}

void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  FILE *f;
  GtkWidget *comb;
  GtkWidget *input3, *input4, *input5, *input6;
  GtkWidget *spinbutton1, *spinbutton2, *spinbutton3 ;

  char ac_text[50];
  fiche_diet a;

  input3 = lookup_widget(GTK_WIDGET(button),"entry3");
  input4 = lookup_widget(GTK_WIDGET(button),"entry4");
  input5 = lookup_widget(GTK_WIDGET(button),"entry5");
  input6 = lookup_widget(GTK_WIDGET(button),"entry6");

  spinbutton1 = lookup_widget(GTK_WIDGET(button),"spinbutton1");
  spinbutton2 = lookup_widget(GTK_WIDGET(button),"spinbutton2");
  spinbutton3 = lookup_widget(GTK_WIDGET(button),"spinbutton3");

  f = fopen("fiches.txt","r");

  comb = lookup_widget(GTK_WIDGET(button),"combobox1");
  strcpy(ac_text,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comb)));

  while (fscanf(f,"%s %s %d %d %d %s %s",a.nom, a.prenom, &a.dt.jour, &a.dt.mois,&a.dt.annee,a.age,a.taille) != EOF)
      if (strcmp(ac_text,a.nom) == 0) {
      gtk_entry_set_text(GTK_ENTRY(input3),a.nom);
      gtk_entry_set_text(GTK_ENTRY(input4),a.prenom);
      gtk_entry_set_text(GTK_ENTRY(input5),a.age);
      gtk_entry_set_text(GTK_ENTRY(input6),a.taille);

      gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton1),a.dt.jour);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton2),a.dt.mois);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton3),a.dt.annee);
      }
}

void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

    GtkWidget *comb;
    GtkWidget *input4, *input5, *input6, *input3;
    GtkWidget *spinbutton1, *spinbutton2, *spinbutton3 ;
    GtkWidget *output1, *output2;
    GtkWidget *image1, *image2;
    fiche_diet a;
    char msg_age[50], msg_prin[50];

    FILE *f;
    f = fopen("fiches.txt","a");

    comb = lookup_widget(GTK_WIDGET(button),"combobox1");

    input3 = lookup_widget(GTK_WIDGET(button),"entry3");
    input4 = lookup_widget(GTK_WIDGET(button),"entry4");
    input5 = lookup_widget(GTK_WIDGET(button),"entry5");
    input6 = lookup_widget(GTK_WIDGET(button),"entry6");

    output1 = lookup_widget(GTK_WIDGET(button),"label36");
    output2 = lookup_widget(GTK_WIDGET(button),"label40");

    image1 = lookup_widget(GTK_WIDGET(button),"image22");
    image2= lookup_widget(GTK_WIDGET(button),"image24");

    spinbutton1 = lookup_widget(GTK_WIDGET(button),"spinbutton1");
    spinbutton2 = lookup_widget(GTK_WIDGET(button),"spinbutton2");
    spinbutton3 = lookup_widget(GTK_WIDGET(button),"spinbutton3");

    strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
    strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
    strcpy(a.age,gtk_entry_get_text(GTK_ENTRY(input5)));
    strcpy(a.taille,gtk_entry_get_text(GTK_ENTRY(input6)));

    a.dt.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
    a.dt.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
    a.dt.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));

    verifi_ajout(a,msg_age, msg_prin);
    if (strcmp(msg_prin,"L'ajout au fichier a été éffectué avec succéss")==0) {
      gtk_label_set_text(GTK_LABEL(output1),msg_prin);
      gtk_label_set_text(GTK_LABEL(output2),msg_age);

      gtk_image_set_from_stock(GTK_IMAGE(image1),"gtk-ok",GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-ok",GTK_ICON_SIZE_BUTTON);
    if (f != NULL) {
      fprintf(f,"%s %s %d %d %d %s %s\n",a.nom, a.prenom, a.dt.jour, a.dt.mois,a.dt.annee,a.age,a.taille) ;
      gtk_combo_box_append_text(GTK_COMBO_BOX(comb),a.nom);
}
}
    else {
      gtk_label_set_text(GTK_LABEL(output1),msg_prin);
      gtk_label_set_text(GTK_LABEL(output2),msg_age);

      gtk_image_set_from_stock(image1,"gtk-delete",GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(image2,"gtk-delete",GTK_ICON_SIZE_BUTTON);
}
    fclose(f);
}


void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *comb;
    	FILE *f1, *f2;
    	char ch[50], ch1[50], ch2[50], ch3[50];
      int j,m,a;

    	f1 = fopen("fiches.txt","r");
    	f2 = fopen("fiches2.txt","w");

      comb = lookup_widget(GTK_WIDGET(button),"combobox1");

      if (f1 != NULL && f2 != NULL) {
    		while (fscanf(f1,"%s %s %d %d %d %s %s",ch,ch1,&j,&m,&a,ch2,ch3) != EOF) {
    			if (strcmp(ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comb)))==0)
            fprintf(f2,NULL);

    			else
    				fprintf(f2,"%s %s %d %d %d %s %s\n",ch,ch1,j,m,a,ch2,ch3);
              				}
                    }
    gtk_combo_box_remove_text(GTK_COMBO_BOX(comb),gtk_combo_box_get_active(GTK_COMBO_BOX(comb)));
    fclose(f1); fclose(f2);
    remove("fiches.txt");
    rename("fiches2.txt","fiches.txt");
}


void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_window2_show                        (GtkWidget       *widget,
                                        gpointer         user_data)
{
  FILE *f;
  GtkWidget *comb;

  int a,b,c,d;
  char ch[50],ch1[50],ch2[50];


  f = fopen("fiches.txt","r");
  comb = lookup_widget(widget,"combobox1");
  while (fscanf(f,"%s %s %d %d %d %d %s",ch,ch1,&a,&b,&c,&d,ch2) != EOF)
        gtk_combo_box_append_text(GTK_COMBO_BOX(comb),ch);
  fclose(f);
}
