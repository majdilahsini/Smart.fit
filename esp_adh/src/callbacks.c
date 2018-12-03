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
on_button1s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1 , *input2;
    GtkWidget *output;
    GtkWidget *login;
    GtkWidget *window2s;
    GtkWidget *image4s, *image3s;

    char username[50],password[50],cin[20];
    int v;
    input1=lookup_widget(GTK_WIDGET(button),"entry1s");
    input2=lookup_widget(GTK_WIDGET(button),"entry2s");
    output=lookup_widget(GTK_WIDGET(button),"label5s");
    image3s = lookup_widget(GTK_WIDGET(button),"image3s");
    image4s= lookup_widget(GTK_WIDGET(button),"image4s");
    login=lookup_widget(GTK_WIDGET(button),"window1s");
    window2s=create_window2s();


    strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
    v=verif(username,password,cin);
    if (v == 2)
    {
      gtk_widget_show(window2s);
      gtk_label_set_text(GTK_LABEL(output),"Réussi!");
      gtk_widget_hide(login);
      create_tmp(cin);
    }

    else if (v == 0)
    {
    gtk_label_set_text(GTK_LABEL(output),"mot de passe incorrect!");
    gtk_image_set_from_stock(GTK_IMAGE(image3s),"gtk-yes",GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image4s),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
    }

    else
    {
        gtk_label_set_text(GTK_LABEL(output),"Réesseyer!");
        gtk_image_set_from_stock(GTK_IMAGE(image3s),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image4s),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
    }
}


void
on_button2s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button3s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *output;
  GtkWidget *notebook;
  GtkWidget *progressbar;
  GtkWidget *image;

  output = lookup_widget(GTK_WIDGET(button),"label6s");
  notebook = lookup_widget(GTK_WIDGET(button),"notebook1s");
  progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1s");
  image = lookup_widget(GTK_WIDGET(button),"image5s");

  gtk_label_set_text(GTK_LABEL(output),"Modification du\n mot de passe");
  gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-go-forward",GTK_ICON_SIZE_BUTTON);
  gtk_notebook_next_page(notebook);
  gtk_progress_bar_update(progressbar,0.33);
}


void
on_button4s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *output1, *output2;
    GtkWidget *input1, *input2, *input3;
    GtkWidget *notebook;
    GtkWidget *progressbar;
    GtkWidget *image1, *image2, *image3, *image4;
    char username[50], new_pass[50];
    int test;


    input1 = lookup_widget(GTK_WIDGET(button),"entry3s");
    input2 = lookup_widget(GTK_WIDGET(button),"entry4s");
    /*input3 = lookup_widget(GTK_WIDGET(button),"entry1s");*/

    output1 = lookup_widget(GTK_WIDGET(button),"label7s");
    output2 = lookup_widget(GTK_WIDGET(button),"label17s");

    notebook = lookup_widget(GTK_WIDGET(button),"notebook1s");

    progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1s");

    image1 = lookup_widget(GTK_WIDGET(button),"image5s");
    image2 = lookup_widget(GTK_WIDGET(button),"image6s");
    image3 = lookup_widget(GTK_WIDGET(button),"image8s");
    image4 = lookup_widget(GTK_WIDGET(button),"image9s");
    int r=2;

    /*strcpy(username,gtk_entry_get_text(GTK_ENTRY(input3)));*/
    strcpy(new_pass,gtk_entry_get_text(GTK_ENTRY(input2)));
    test = verifier_pass(gtk_entry_get_text(input1),gtk_entry_get_text(input2));

    if (test == 1)
    {
      gtk_label_set_text(GTK_LABEL(output1),"La completion des\ndonnées personnelles");
      gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-go-forward",GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image1),"gtk-ok",GTK_ICON_SIZE_BUTTON);
      gtk_notebook_next_page(notebook);
      gtk_progress_bar_update(progressbar,0.66);
      FILE *g ,*f,*k;
  char cin1[50],login[50],pass[50],role[50],cin[50];



  f=fopen("user2.txt","w");

  g=fopen("tmp.txt","r");
  if (g!=NULL)
      fscanf(g,"%s",cin);

  k=fopen("users.txt","r");



  while(fscanf(k,"%s %s %s %s",cin1,login,pass,role)!=EOF)
  {
      if (strcmp(cin1,cin) == 0)
         {
          fprintf(f,"%s %s %s %s\n",cin1,login,new_pass,role);
          }
      else
          fprintf(f,"%s %s %s %s\n",cin1,login,pass,role);
  }

  fclose(f);
  fclose(g);
  fclose(k);
  remove("users.txt");
  rename("user2.txt","users.txt");



    }
    else
    {
      gtk_label_set_text(GTK_LABEL(output2),"Les mots de passe ne sont pas les mêmes");
      gtk_image_set_from_stock(GTK_IMAGE(image3),"gtk-ok",GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image4),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
    }


}


void
on_button5s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *progressbar;
    GtkWidget *image1, *image2;
    GtkWidget *input1 , *input2 , *input3 , *input4;
    GtkWidget *combobox1;
    GtkWidget *day , *month, *year;

    progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1s");
    image1 = lookup_widget(GTK_WIDGET(button),"image5s");
    image2 = lookup_widget(GTK_WIDGET(button),"image6s");

    gtk_image_set_from_stock(GTK_IMAGE(image1),"gtk-ok",GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-ok",GTK_ICON_SIZE_BUTTON);

    gtk_progress_bar_update(progressbar,1);

    date ddn;
    fp1 x;

    char nom[50];char prenom[50];
    char cin[10];char tel[10];char sexe[10];


    input1=lookup_widget(GTK_WIDGET(button),"entry5s");
    input2=lookup_widget(GTK_WIDGET(button),"entry6s");
    input3=lookup_widget(GTK_WIDGET(button),"entry7s");
    input4=lookup_widget(GTK_WIDGET(button),"entry8s");

    combobox1=lookup_widget(GTK_WIDGET(button),"combobox1s");

    day=lookup_widget(GTK_WIDGET(button),"spinbutton1s");
    month=lookup_widget(GTK_WIDGET(button),"spinbutton2s");
    year=lookup_widget(GTK_WIDGET(button),"spinbutton3s");

    x.ddn.day= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
    x.ddn.month= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
    x.ddn.year= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));

    strcpy(x.sexe, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
    strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(x.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
    strcpy(x.cin, gtk_entry_get_text(GTK_ENTRY(input3)));
    strcpy(x.tel, gtk_entry_get_text(GTK_ENTRY(input4)));

    enregistrer1(x.nom, x.prenom,ddn,x.cin,x.tel,x.sexe);
    /*FILE *f;
    f=fopen("adherents.txt","r");
    if(f != NULL)
    {
      while ((fscanf(f,"%s %s %s %d %d %d %s %s %s ",x.nom,x.prenom,ddn.day,
      ddn.month,ddn.year,x.cin,x.tel,x.sexe)!=EOF))
      {
      gtk_entry_set_text(GTK_ENTRY("entry100s")),x.nom);
      gtk_entry_set_text(GTK_ENTRY("entry200s")),x.prenom);
      gtk_entry_set_text(GTK_ENTRY("entry800s")),x.cin);
      gtk_entry_set_text(GTK_ENTRY("entry400s")),x.tel);
      gtk_spin_button_set_value_as_int(GTK_SPIN_BUTTON(day)),ddn.day);
      gtk_spin_button_set_value_as_int(GTK_SPIN_BUTTON(month)),ddn.month);
      gtk_spin_button_set_value_as_int(GTK_SPIN_BUTTON(year)),ddn.year);
      gtk_combo_box_set_active_text(GTK_COMBO_BOX(combobox1)),x.sexe);

      }
    }
  fclose(f);*/


}


void
on_button6s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2s,*window3s;

window2s=lookup_widget(GTK_WIDGET(button),"window2s");
window3s=create_window3s();
gtk_widget_show(window3s);
gtk_widget_hide(window2s);
}


void
on_toolbutton1s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook1s");
  gtk_notebook_set_current_page(notebook,0);
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
on_toolbutton3s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook1s");
  gtk_notebook_set_current_page(notebook,2);

}


void
on_checkbutton1s_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *combo1;

  FILE *f;
  char date[50];char salle[30];




  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  {
    f=fopen("dispo_coach.txt","r");
    combo1=lookup_widget(GTK_WIDGET(togglebutton),"combobox3s");
    /*output=lookup_widget(GTK_WIDGET(togglebutton),"label39s");*/

    while (fscanf(f,"%s %s",date,salle) != EOF)
    {
      gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),date);
      /*gtk_label_set_text(GTK_LABEL(output),salle);*/
    }
    fclose(f);

  }
}




void
on_checkbutton3s_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *combo1;

  FILE *f;
  char date[50];char salle[30];

  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  {
    f=fopen("dispo_kiné.txt","r");
    combo1=lookup_widget(GTK_WIDGET(togglebutton),"combobox5s");
    /*output=lookup_widget(GTK_WIDGET(togglebutton),"label39s");*/

    while (fscanf(f,"%s %s",date,salle) != EOF)
    {
      gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),date);
      /*gtk_label_set_text(GTK_LABEL(output),salle);*/
    }
    fclose(f);
 }
}


void
on_checkbutton4s_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *combo1 , *output;

  FILE *f;
  char date[50];
char salle[30];


  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  {
    f=fopen("dispo_med.txt","r");
    combo1=lookup_widget(GTK_WIDGET(togglebutton),"combobox2s");
    /*output=lookup_widget(GTK_WIDGET(togglebutton),"label39s");*/

    while (fscanf(f,"%s %s",date,salle) != EOF)
    {
      gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),date);
      /*gtk_label_set_text(GTK_LABEL(output),salle);*/
    }
    fclose(f);
}
}


void
on_button7s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combo3,*combo6,*combo2,*combo5;
GtkWidget *check1,*check6,*check3,*check4;
GtkWidget *output;
 char ch1[50];
  char ch2[50];
  char local[30];
FILE *f2,*g;



    f2=fopen("rdv_adherent.txt","a+");
    combo3=lookup_widget(GTK_WIDGET(button),"combobox3s");
    combo2=lookup_widget(GTK_WIDGET(button),"combobox2s");
    combo6=lookup_widget(GTK_WIDGET(button),"combobox6s");
    combo5=lookup_widget(GTK_WIDGET(button),"combobox5s");

    check4=lookup_widget(GTK_WIDGET(button),"checkbutton4s");
    check1=lookup_widget(GTK_WIDGET(button),"checkbutton1s");
    check6=lookup_widget(GTK_WIDGET(button),"checkbutton6s");
    check3=lookup_widget(GTK_WIDGET(button),"checkbutton3s");
    output=lookup_widget(GTK_WIDGET(button),"label38s");

	if(f2 != NULL)
	{
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check6)))
		{
			strcpy(ch1,"Diététicien");
			strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo6)));
      g=fopen("dispo_diet.txt","a+");
      char a[100] , b[30];
      if(g !=NULL)
      {
        while(fscanf(g,"%s %s",a,b) != EOF)
        {
          strcpy(local,b);
        }
        fclose(g);
      }
			gtk_label_set_text(GTK_LABEL(output),"Rendez-vous validé(s)!");
			fprintf(f2,"%s %s %s \n",ch1,ch2,local);


		}
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check1)))
		{
			strcpy(ch1,"Coach");
			strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo3)));
      g=fopen("dispo_coach.txt","r");
      char a[100] , b[30];
      if(g !=NULL)
      {
        while(fscanf(g,"%s %s",a,b) != EOF)
        {
          strcpy(local,b);
        }
        fclose(g);
      }
			gtk_label_set_text(GTK_LABEL(output),"Rendez-vous validé(s)!");
			fprintf(f2,"%s %s %s \n",ch1,ch2,local);

		}
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check4)))
		{
			strcpy(ch1,"Medecin");
			strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)));
      g=fopen("dispo_med.txt","r");
      char a[100] , b[30];
      if(g !=NULL)
      {
        while(fscanf(g,"%s %s",a,b) != EOF)
        {
          strcpy(local,b);
        }
        fclose(g);
      }
			gtk_label_set_text(GTK_LABEL(output),"Rendez-vous validé(s)!");
			fprintf(f2,"%s %s %s \n",ch1,ch2,local);
		}
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check3)))
		{
			strcpy(ch1,"Kinésitherapeute");
			strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo5)));
        g=fopen("dispo_kiné.txt","r");
        char a[100] , b[30];
        if(g !=NULL)
        {
          while(fscanf(g,"%s %s",a,b) != EOF)
          {
            strcpy(local,b);
          }
          fclose(g);
        }
			gtk_label_set_text(GTK_LABEL(output),"Rendez-vous validé(s)!");
			fprintf(f2,"%s %s %s \n",ch1,ch2,local);
		}
        }

    fclose(f2);
}


void
on_checkbutton6s_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 GtkWidget *combo1;

  FILE *f;
  char date[50];char salle[30];

  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  {
    f=fopen("dispo_diet.txt","r");
    combo1=lookup_widget(GTK_WIDGET(togglebutton),"combobox6s");
    /*output=lookup_widget(GTK_WIDGET(togglebutton),"label39s");*/

    while (fscanf(f,"%s %s",date,salle) != EOF)
    {
      gtk_combo_box_append_text(GTK_COMBO_BOX(combo1),date);
      /*gtk_label_set_text(GTK_LABEL(output),salle);*/
    }
    fclose(f);
}

  }


void
on_toolbutton4s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook;
  GtkWidget *treeview1;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook1s");
  gtk_notebook_set_current_page(GTK_WIDGET(notebook),3);
  treeview1=lookup_widget(GTK_WIDGET(toolbutton),"treeview1s");
  afficher(treeview1);

}


void
on_button8s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *notebook;

notebook = lookup_widget(GTK_WIDGET(button),"notebook1s");
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),3);
treeview1=lookup_widget(GTK_WIDGET(button),"treeview1s");
afficher(treeview1);
}


void
on_toolbutton6s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  FILE *f;
GtkWidget *window1s,*window3s;
window3s=lookup_widget(GTK_WIDGET(toolbutton),"window3s");
window1s=create_window1s();
gtk_widget_show(window1s);
gtk_widget_hide(window3s);
f=fopen("tmp.txt","r");
fclose(f);
remove("tmp.txt");

}


void
on_toolbutton7s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
gtk_main_quit();
}




void
on_toolbutton2s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook;

  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook1s");
  gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),1);
}

void
on_button100s_clicked                  (GtkButton       *button,
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

    input1=lookup_widget(GTK_WIDGET(button),"entry100s");
    input2=lookup_widget(GTK_WIDGET(button),"entry200s");
    input3=lookup_widget(GTK_WIDGET(button),"entry800s");
    input4=lookup_widget(GTK_WIDGET(button),"entry400s");
    input5=lookup_widget(GTK_WIDGET(button),"entry500s");
    input6=lookup_widget(GTK_WIDGET(button),"entry600s");
    input7=lookup_widget(GTK_WIDGET(button),"entry700s");
    combobox1=lookup_widget(GTK_WIDGET(button),"combobox10s");

    day=lookup_widget(GTK_WIDGET(button),"spinbutton10s");
    month=lookup_widget(GTK_WIDGET(button),"spinbutton20s");
    year=lookup_widget(GTK_WIDGET(button),"spinbutton30s");

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
/*FILE *g ,*f;
f=fopen("adherents2.txt","w");
g=fopen("adherents.txt","w");
fclose(f);
fclose(g);
remove("adherents.txt");
rename("adherents2.txt","adherents.txt");*/


}

void
on_toolbutton5s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
GtkWidget *notebook, *treeview2;

  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook1s");
  gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),4);
  treeview2=lookup_widget(GTK_WIDGET(toolbutton),"treeview2s");
  afficher1(treeview2);
}

void
on_window3s_show                       (GtkWidget       *widget,
                                        gpointer         user_data)
{

/*GtkWidget *input1 , *input2, *input3 ,  *input4;
GtkWidget *combobox1;
GtkWidget *day , *month, *year;
date ddn;
fp1 x;
  input1=lookup_widget(GTK_WIDGET(widget),"entry100s");
  input2=lookup_widget(GTK_WIDGET(widget),"entry200s");
  input3=lookup_widget(GTK_WIDGET(widget),"entry800s");
  input4=lookup_widget(GTK_WIDGET(widget),"entry400s");

  combobox1=lookup_widget(GTK_WIDGET(widget),"combobox10s");

  day=lookup_widget(GTK_WIDGET(widget),"spinbutton10s");
  month=lookup_widget(GTK_WIDGET(widget),"spinbutton20s");
  year=lookup_widget(GTK_WIDGET(widget),"spinbutton30s");

  FILE *f;
  f=fopen("adherents.txt","r");
  if(f != NULL)
  {
    while ((fscanf(f,"%s %s %s %d %d %d %s %s ",x.nom,x.prenom,ddn.day,
    ddn.month,ddn.year,x.cin,x.tel)!=EOF))
    {
    gtk_entry_set_text(GTK_ENTRY("entry100s"),x.nom);
    gtk_entry_set_text(GTK_ENTRY("entry200s"),x.prenom);
    gtk_entry_set_text(GTK_ENTRY("entry800s"),x.cin);
    gtk_entry_set_text(GTK_ENTRY("entry400s"),x.tel);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(day),ddn.day);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(month),ddn.month);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(year),ddn.year);
    /*gtk_combo_box_set_active_text(GTK_COMBO_BOX(combobox1),x.sexe);

    }
  }
fclose(f);*/

}
