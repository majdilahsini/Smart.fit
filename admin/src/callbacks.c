#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include <string.h>
#include <stdio.h>
#include "ajouter.h"
#include "afficher.h"
#include "modifier.h"
#include "reservation.h"
#include "supprimer.h"
#include "affichercalen.h"


GtkWidget *window1;
GtkWidget *window2;

GtkWidget *window_ay4;
GtkWidget *calendar_add_ay5;

GtkWidget *entry2;

GtkWidget *window_ay5;
GtkWidget *window_aff_4;
GtkWidget  *listeview;
void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output;

char Username[30];
char Password[30];
input1=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");

output=lookup_widget(objet_graphique,"label3");
strcpy(Username,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(Password,gtk_entry_get_text(GTK_ENTRY(input2)));
if(verifier(Username,Password)==1)
{
window2=create_window2();
gtk_widget_show(window2);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window1")));
}
else

gtk_label_set_text(GTK_LABEL(output),"verifier vos informations");


}




void
on_button_ay2_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

 GtkWidget *output15;
 GtkWidget *input10;


 GtkWidget *input40;
 GtkWidget *input50;
 GtkWidget *combobox1;

int label;
char cin[30];


char login[30];
char password[30];
char role[50];
output15=lookup_widget(objet_graphique,"label_ay24");
input10=lookup_widget(objet_graphique,"entry40");


input40=lookup_widget(objet_graphique,"entry7");
input50=lookup_widget(objet_graphique,"entry8");
combobox1=lookup_widget(objet_graphique,"combobox_ay100");


strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input10)));


strcpy(login,gtk_entry_get_text(GTK_ENTRY(input40)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input50)));
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));


if (strcmp(role,"Admin")==0)
		{
label=ajouter(cin,login,password,1); 
listeview = lookup_widget(window_ay4,"treeview1");
     afficher(listeview,1);

		}

else if (strcmp(role,"Adhérent")==0)
		{
label=ajouter(cin,login,password,2); 
listeview = lookup_widget(window_ay4,"treeview1");
     afficher(listeview,2);
		}

else if (strcmp(role,"Coach")==0)
		{
label=ajouter(cin,login,password,3); 
listeview = lookup_widget(window_ay4,"treeview1");
     afficher(listeview,3);
		}

else if (strcmp(role,"Diététicien")==0)
		{
label=ajouter(cin,login,password,4); 
listeview = lookup_widget(window_ay4,"treeview1");
     afficher(listeview,4);
		}

else if (strcmp(role,"Medecin")==0)
		{
label=ajouter(cin,login,password,5); 
listeview = lookup_widget(window_ay4,"treeview1");
     afficher(listeview,5);
		}

else if (strcmp(role,"Kinésithérapeute")==0)
		{
label=ajouter(cin,login,password,6); 
listeview = lookup_widget(window_ay4,"treeview1");
     afficher(listeview,6);
		}

if(label==0)
{
gtk_label_set_text(GTK_LABEL(output15),"Erreur rentrer information");
}
if(label==1)
gtk_label_set_text(GTK_LABEL(output15),"Compte a été ajouté");

if(label==3)
gtk_label_set_text(GTK_LABEL(output15),"Cin trop long");

if(label==4)
gtk_label_set_text(GTK_LABEL(output15),"Cin trop petit");




}


void
on_button_ay6_clicked                  (GtkWidget       *objet_graphique,
                                       gpointer         user_data)
{ 
window2=create_window2();
gtk_widget_show(window2);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window_ay4")));
}

void
on_buttonay_3_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
window_ay4=create_window_ay4();
gtk_widget_show(window_ay4);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window2")));
}



void
on_checkbutton_show_ay1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

  GtkWidget *entry2;

  entry2= lookup_widget(GTK_WIDGET(togglebutton),"entry2");
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
  gtk_entry_set_visibility(GTK_ENTRY (entry2), TRUE);
  else
  gtk_entry_set_visibility (GTK_ENTRY (entry2), FALSE);
}








void
on_button_ay11_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
window1=create_window1();
gtk_widget_show(window1);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window2")));
}








void
on_button_ay20_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
window1=create_window1();
gtk_widget_show(window1);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window_ay5")));
}


void
on_button_ay30_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
window2=create_window2();
gtk_widget_show(window2);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window_ay5")));
}




void
on_button_ay15_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
window1=create_window1();
gtk_widget_show(window1);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window_ay4")));
}








void
on_treeview1_row_activated             (GtkWidget    *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        gint *role;
  	gchar *login;
	gchar *password;
	gchar *cin;
  
    
        GtkWidget *listeview;
	GtkWidget *input40;
   	GtkWidget *input70;
	GtkWidget *input80;
	GtkWidget *window_ay4;

 GtkTreeIter iter;
	
listeview = lookup_widget(objet_graphique,"treeview1");

GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeview1")));

  
  

   if (gtk_tree_model_get_iter(model, &iter, path))

            {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &cin,1,&login,2,&password,3,&role,-1);
	    }

	



input40 = lookup_widget(objet_graphique,"entry40");
input70=lookup_widget(objet_graphique,"entry7");
input80=lookup_widget(objet_graphique,"entry8");

gtk_entry_set_text(GTK_ENTRY(input40),cin);
gtk_entry_set_text(GTK_ENTRY(input70),login);
gtk_entry_set_text(GTK_ENTRY(input80),password);



}


void
on_button_calen_re_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
window2=create_window2();
gtk_widget_show(window2);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"calendar_add_ay5")));
}


void
on_button_decon_cal_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
window1=create_window1();
gtk_widget_show(window1);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"calendar_add_ay5")));
}


void
on_button_aycal_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
calendar_add_ay5=create_calendar_add_ay5();
gtk_widget_show(calendar_add_ay5);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"window2")));
}





void
on_button_ay201_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox_ay1; //comobox pour le choix de la salle
GtkWidget *jour; //spinbuttun pour le choix du jour
GtkWidget *mois; //spinbuttun pour le choix du mois
GtkWidget *annee; //spinbuttun pour le choix de l’année

GtkWidget *combobox_ay2; //comobox pour le choix du bloc
GtkWidget *label_ay26; 
GtkWidget *input410;//label pour confirmer la reservation
GtkWidget *listeview;

calendrier c;
// associer les objets avec des variables


jour=lookup_widget(objet_graphique, "spinbutton_ay1");
mois=lookup_widget(objet_graphique, "spinbutton_ay2");
annee=lookup_widget(objet_graphique, "spinbutton_ay3");
label_ay26=lookup_widget(objet_graphique, "label_ay26");
combobox_ay1=lookup_widget(objet_graphique, "combobox_ay1");
combobox_ay2=lookup_widget(objet_graphique, "combobox_ay2");
input410=lookup_widget(objet_graphique, "entry_ay410");

//récupérer les valeurs
c.dt_res.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
c.dt_res.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
c.dt_res.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(c.hr_resr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ay1)));
strcpy(c.hr2_resr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ay2)));
strcpy(c.evenement,gtk_entry_get_text(GTK_ENTRY(input410)));
reserver(c);

listeview = lookup_widget(objet_graphique,"treeview2");
afficher_calendrier(listeview);
//affichage d’un message
gtk_label_set_text(GTK_LABEL(label_ay26),"Reservation réusite.");


}



void
on_button_ay130_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
        GtkWidget *input111;
	GtkWidget *input444;
        GtkWidget *input555;
       	GtkWidget *window_ay4;
        GtkWidget *listeview;
         GtkWidget *combobox1;

char cin[50],login[50],password[50],role[50];



combobox1=lookup_widget(objet_graphique, "combobox_ay100");
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

window_ay4= lookup_widget(objet_graphique,"window_ay4");
input111= lookup_widget(objet_graphique,"entry40");
input444=lookup_widget(objet_graphique,"entry7");
input555=lookup_widget(objet_graphique,"entry8");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input111)));
strcpy(login,gtk_entry_get_text(GTK_ENTRY(input444)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input555)));

modifier(cin,login,password);

if (strcmp(role,"Admin")==0)
		{

listeview = lookup_widget(window_ay4,"treeview1");
    afficher(listeview,1);

		}
else if (strcmp(role,"Adhérent")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,2);
}
else if (strcmp(role,"Coach")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,3);
}
else if (strcmp(role,"Diététicien")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,4);
}
else if (strcmp(role,"Medecin")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,5);
}
else if (strcmp(role,"Kinésithérapeute")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,6);
}
}





void
on_combobox_ay100_changed              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *combobox1;
GtkWidget *window_ay4;
GtkWidget *listeview;
char role[50];


combobox1=lookup_widget(objet_graphique, "combobox_ay100");
window_ay4=lookup_widget(objet_graphique, "window_ay4");
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
listeview = lookup_widget(window_ay4,"treeview1");

if (strcmp(role,"Admin")==0)
{


afficher(listeview,1);


}
else if (strcmp(role,"Adhérent")==0)
{
afficher(listeview,2);
}
else if (strcmp(role,"Coach")==0)
{
afficher(listeview,3);
}
else if (strcmp(role,"Diététicien")==0)
{
afficher(listeview,4);
}
else if (strcmp(role,"Medecin")==0)
{
afficher(listeview,5);
}
else if (strcmp(role,"Kinésithérapeute")==0)
{
afficher(listeview,6);
}
}







void
on_button_ay14_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[50];
char role[50];
GtkWidget *input02;
GtkWidget *listeview;
GtkWidget *window_ay4;
GtkWidget *combobox1;


window_ay4=lookup_widget(objet_graphique, "window_ay4");



combobox1=lookup_widget(objet_graphique, "combobox_ay100");
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

 input02 = lookup_widget(GTK_WIDGET(objet_graphique),"entry40");
 strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input02)));


supprimer(cin);

if (strcmp(role,"Admin")==0)
		{
listeview = lookup_widget(window_ay4,"treeview1");

    afficher(listeview,1);

		}
else if (strcmp(role,"Adhérent")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,2);
}
else if (strcmp(role,"Coach")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,3);
}
else if (strcmp(role,"Diététicien")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");

afficher(listeview,4);
}
else if (strcmp(role,"Medecin")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,5);
}
else if (strcmp(role,"Kinésithérapeute")==0)
{
listeview = lookup_widget(window_ay4,"treeview1");
afficher(listeview,6);
}

}


void
on_button_ay202_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;

GtkWidget *listeview;
GtkWidget *calendar_add_ay5;
calendar_add_ay5 = lookup_widget(objet_graphique,"calendar_add_ay5");
char date[50],heure1[50],heure2[50],evenement[50];
input1 = lookup_widget(objet_graphique,"entry_ay600");
input2=lookup_widget(objet_graphique,"entry_ay601");
input3=lookup_widget(objet_graphique,"entry_ay602");
input4=lookup_widget(objet_graphique,"entry_ay603");

strcpy(date,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(heure1,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(heure2,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(evenement,gtk_entry_get_text(GTK_ENTRY(input4)));

supprimer_calendrier(date);
listeview = lookup_widget(objet_graphique,"treeview2");
afficher_calendrier(listeview);
}


void
on_button_ay604_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;

	GtkWidget *listeview;
	GtkWidget *calendar_add_ay5;

	char date[50],heure1[50],heure2[50],evenement[50];

	calendar_add_ay5 = lookup_widget(objet_graphique,"calendar_add_ay5");



input1 = lookup_widget(objet_graphique,"entry_ay600");
input2=lookup_widget(objet_graphique,"entry_ay601");
input3=lookup_widget(objet_graphique,"entry_ay602");
input4=lookup_widget(objet_graphique,"entry_ay603");

strcpy(date,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(heure1,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(heure2,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(evenement,gtk_entry_get_text(GTK_ENTRY(input4)));
modifier_calendrier(date,heure1,heure2,evenement);


listeview = lookup_widget(objet_graphique,"treeview2");
afficher_calendrier(listeview);

}


void
on_treeview2_row_activated             (GtkWidget       *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	gchar *date;
  	gchar *heure1;
	gchar *heure2;
	gchar *evenement;
   
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;	
	
	GtkWidget *calendar_add_ay5;
	GtkWidget *listeview;
        GtkTreeIter iter;


listeview = lookup_widget(objet_graphique,"treeview2");

GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeview2")));
 

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &date, 1, &heure1,2,&heure2,3,&evenement, -1);

                                                       }
calendar_add_ay5 = lookup_widget(objet_graphique,"calendar_add_ay5");
input1 = lookup_widget(calendar_add_ay5,"entry_ay600");
gtk_entry_set_text(GTK_ENTRY(input1),date);
input2 = lookup_widget(calendar_add_ay5,"entry_ay601");
gtk_entry_set_text(GTK_ENTRY(input2),heure1);
input3 = lookup_widget(calendar_add_ay5,"entry_ay602");
gtk_entry_set_text(GTK_ENTRY(input3),heure2);
input4 = lookup_widget(calendar_add_ay5,"entry_ay603");
gtk_entry_set_text(GTK_ENTRY(input4),evenement);
}

