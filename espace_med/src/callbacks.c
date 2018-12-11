#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include  "ntbook.h"
#include "fonctions.h"
#include <string.h>
#include <stdio.h>

void
on_accuei_med_clicked                  (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
select_page(toolbutton,0,"notebookmain_med");

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;

output1=lookup_widget(toolbutton,"label1_accueil_nom");
output2=lookup_widget(toolbutton,"label2_accueil_prenom");
output3=lookup_widget(toolbutton,"label3_accueil_cin");
output4=lookup_widget(toolbutton,"label4_accueil_tel");
output5=lookup_widget(toolbutton,"label5_accueil_sex");

char cin_tmp[50],cin[50],nom[50],prenom[50],tel[50],sex[50];
char nom_tmp[50],prenom_tmp[50],tel_tmp[50],sex_tmp[50];
date dat;
FILE *f,*g;

f=fopen("profil.txt","r");
g=fopen("tmp.txt","r");

if(g!=NULL)
fscanf(g,"%s \n",cin_tmp);

if(f!=NULL)
{
 while(fscanf(f,"%s %s %s %s %d %d %d %s",nom,prenom,cin,tel,&dat.jour,&dat.mois,&dat.annee,sex)!=EOF) {
    if(strcmp(cin,cin_tmp)==0) {
      strcpy(nom_tmp,nom);
      strcpy(prenom_tmp,prenom);
      strcpy(sex_tmp,sex);
      strcpy(tel_tmp,tel);
    }
 }

 gtk_label_set_text(GTK_LABEL(output1),nom_tmp);
 gtk_label_set_text(GTK_LABEL(output2),prenom_tmp);
 gtk_label_set_text(GTK_LABEL(output3),cin_tmp);
 gtk_label_set_text(GTK_LABEL(output4),tel_tmp);
 gtk_label_set_text(GTK_LABEL(output5),sex_tmp);
}
 fclose(f);
 fclose(g);

}


void
on_profil_med_clicked                  (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
select_page(toolbutton,1,"notebookmain_med");
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label4;

FILE *f,*g;
char nom[50],prenom[50],tel[20],cin[20],sex[20],cin_tmp[50];
date dat;
f=fopen("profil.txt","r");
g=fopen("tmp.txt","r");
fscanf(g,"%s \n",cin_tmp);
if (f!=NULL )
fscanf(f,"%s %s %s %s %d %d %d %s\n",nom,prenom,cin,tel,&dat.jour,&dat.mois,&dat.annee,sex);

GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;

GtkWidget *combo;

GtkWidget *spinbutton1, *spinbutton2, *spinbutton3 ;

spinbutton1 = lookup_widget(toolbutton,"pspin_med1");
spinbutton2 = lookup_widget(toolbutton,"pspin_med2");
spinbutton3 = lookup_widget(toolbutton,"pspin_med3");

label1=lookup_widget(toolbutton,"pentry_med1");
label2=lookup_widget(toolbutton,"pentry_med2");
label3=lookup_widget(toolbutton,"pentry_med3");
label4=lookup_widget(toolbutton,"pentry_med4");

combo=lookup_widget(toolbutton,"pcombo_med1");

gtk_entry_set_text(GTK_LABEL(label1),nom);
gtk_entry_set_text(GTK_LABEL(label2),prenom);
gtk_entry_set_text(GTK_LABEL(label3),cin_tmp);
gtk_entry_set_text(GTK_LABEL(label4),tel);

gtk_spin_button_set_value(spinbutton1,dat.jour);
gtk_spin_button_set_value(spinbutton2,dat.mois);
gtk_spin_button_set_value(spinbutton3,dat.annee);

if (strcmp(sex,"Homme")==0)
   gtk_combo_box_set_active(GTK_COMBO_BOX(combo),0);
else
   gtk_combo_box_set_active(GTK_COMBO_BOX(combo),1);


fclose(f);
fclose(g);
}


void
on_fichemed_med_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
select_page(toolbutton,2,"notebookmain_med");
GtkWidget *treeview3;

treeview3=lookup_widget(toolbutton,"treeview20_med");
afficher_fiche(treeview3);

}


void
on_rendez_med_clicked                  (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
select_page(toolbutton,3,"notebookmain_med");
GtkWidget *treeview2;

treeview2=lookup_widget(toolbutton,"treeview2_rendez_med");
afficher_rendez_vous(treeview2);


}


void
on_dec_med_clicked                     (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *window3;
  GtkWidget *window1;

  window3=lookup_widget(GTK_WIDGET(toolbutton),"espacemed");
  window1=create_espace_login();
  remove("tmp.txt");
  gtk_widget_hide_all(window3);
  gtk_widget_show(window1);

}


void
on_quit_med_clicked                    (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *window1;
//  FILE *f;
  window1=lookup_widget(GTK_WIDGET(toolbutton),"espacemed");
  remove("tmp.txt");
  gtk_main_quit();

}


void
on_pmodifier_med1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;



  GtkWidget *jour;
  GtkWidget *mois;
  GtkWidget *annee;

  GtkWidget *spinbutton1, *spinbutton2, *spinbutton3 ;

  GtkWidget *combo;


  char nom[50],prenom[50],cin_an[20],cin[50],tel[20],sex[20];
  char nom_tmp[50],prenom_tmp[50],cin_tmp[50],tel_tmp[20],sex_tmp[20];
  date dt,bt,ft ;

  input1=lookup_widget(GTK_WIDGET(button),"pentry_med1");
  input2=lookup_widget(GTK_WIDGET(button),"pentry_med2");
  input3=lookup_widget(GTK_WIDGET(button),"pentry_med3");
  input4=lookup_widget(GTK_WIDGET(button),"pentry_med4");



  jour=lookup_widget(GTK_WIDGET(button),"pspin_med1");
  mois=lookup_widget(GTK_WIDGET(button),"pspin_med2");
  annee=lookup_widget(GTK_WIDGET(button),"pspin_med3");


  strcpy(nom_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(prenom_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(cin_tmp,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(tel_tmp,gtk_entry_get_text(GTK_ENTRY(input4)));


  bt.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  bt.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  bt.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


combo=lookup_widget(GTK_WIDGET(button),"pcombo_med1");

strcpy(sex_tmp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));

  FILE *g ,*k;

  g=fopen("profil.txt","a+");

  k=fopen("profil_tmp.txt","a+");


  fprintf(k,"%s %s %s %s %d %d %d %s \n",nom_tmp,prenom_tmp,cin_tmp,tel_tmp,bt.jour,bt.mois,bt.annee,sex_tmp);
  while(fscanf(g,"%s %s %s %s %d %d %d %s \n",nom,prenom,cin,tel,&ft.jour,&ft.mois,&ft.annee,sex)!=EOF)
  {
      if (strcmp(cin,cin_tmp) != 0)
         {
            fprintf(k,"%s %s %s %s %d %d %d %s \n",nom,prenom,cin,tel,ft.jour,ft.mois,ft.annee,sex);
  }
  }

  fclose(g);
  fclose(k);
  remove("profil.txt");
  rename("profil_tmp.txt","profil.txt");

}


void
on_changepass_med_clicked              (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
    select_page(toolbutton,1,"profil_med_book");
}


void
on_afficher1_med_clicked               (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{

}


void
on_afficher2_med_clicked               (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{

}

void
on_treeview20_med_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *entry1;
  GtkWidget *entry3;
  GtkWidget *entry4;
  GtkWidget *entry2;
  GtkWidget *entry5;
  GtkWidget *entry6;
  GtkWidget *entry7;
  GtkTreeIter    iter;
  GtkTreeModel *model;
  gchar *string1;
  gchar *string2;
  gchar *string3;
  gchar *string4;
  gchar *string5;
  gchar *string6;
  gchar *string7;

  FILE *f;

  model =gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  gtk_tree_model_get(model,&iter,0,&string1,-1);
  gtk_tree_model_get(model,&iter,1,&string2,-1);
  gtk_tree_model_get(model,&iter,2,&string3,-1);
  gtk_tree_model_get(model,&iter,3,&string4,-1);
  gtk_tree_model_get(model,&iter,4,&string5,-1);
  gtk_tree_model_get(model,&iter,5,&string6,-1);
  gtk_tree_model_get(model,&iter,6,&string7,-1);

  entry1=lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_med1");
  entry2=lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_med2");
  entry3=lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_med3");
  entry4=lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_med4");
  entry5=lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_med5");
  entry6=lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_med6");
  entry7=lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_med7");



  gtk_entry_set_text(GTK_TREE_VIEW(entry1),string1);
  gtk_entry_set_text(GTK_TREE_VIEW(entry2),string2);
  gtk_entry_set_text(GTK_TREE_VIEW(entry3),string3);
  gtk_entry_set_text(GTK_TREE_VIEW(entry4),string4);
  gtk_entry_set_text(GTK_TREE_VIEW(entry5),string5);
  gtk_entry_set_text(GTK_TREE_VIEW(entry6),string6);
  gtk_entry_set_text(GTK_TREE_VIEW(entry7),string7);

f=fopen("fiche_med_modf.txt","w");
fprintf(f, "%s %s %s %s %s %s %s \n",string1,string2,string3,string4,string5,string6,string7 );
fclose(f);
}
void
on_treeview2_med_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkTreeIter    iter;
  GtkTreeModel *model;
  gchar *string1;
  gchar *string2;
  gchar *string3;
  char cin_tmp[50];

  model =gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  gtk_tree_model_get(model,&iter,0,&string1,-1);
  gtk_tree_model_get(model,&iter,1,&string2,-1);
  gtk_tree_model_get(model,&iter,2,&string3,-1);

  entry1=lookup_widget(GTK_TREE_VIEW(treeview),"entry3_jour_rendez_med");
  entry2=lookup_widget(GTK_TREE_VIEW(treeview),"entry4_heure_rendez_med");
  entry3=lookup_widget(GTK_TREE_VIEW(treeview),"entry5_salle_rendez_med");

  gtk_entry_set_text(GTK_TREE_VIEW(entry1),string1);
  gtk_entry_set_text(GTK_TREE_VIEW(entry2),string2);
  gtk_entry_set_text(GTK_TREE_VIEW(entry3),string3);

FILE *f,*g;
g=fopen("tmp.txt","r");
fscanf(g,"%s \n",cin_tmp);
f=fopen("fiche_rendez_modf.txt","w");
fprintf(f, "%s %s %s %s \n",cin_tmp,string1,string2,string3 );
fclose(f);

}

void
on_button_supp_rendez_med_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;

  char jour_tmp[50],heure_tmp[50],salle_tmp[50],cin_tmp[50];
  char jour[50],heure[50],salle[50],cin[50];

  input1=lookup_widget(GTK_WIDGET(button),"entry3_jour_rendez_med");
  input2=lookup_widget(GTK_WIDGET(button),"entry4_heure_rendez_med");
  input3=lookup_widget(GTK_WIDGET(button),"entry5_salle_rendez_med");

  strcpy(jour_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(heure_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(salle_tmp,gtk_entry_get_text(GTK_ENTRY(input3)));

  FILE *f, *g,*h;


    f = fopen("rendez_vous.txt","r");
    g = fopen("rendez_vous_tmp.txt","w+");
  //  fprintf(g,"%s %s %s \n",jour_tmp,heure_tmp,salle_tmp);
    h = fopen("tmp.txt","r");
  //  if ( h !=NULL)
  fscanf(h,"%s  \n",cin_tmp) ;


    if (f != NULL && g!= NULL) {
      while (fscanf(f,"%s %s %s %s \n",cin,jour,heure,salle) != EOF) {
            if (strcmp(jour,jour_tmp) == 0 && strcmp(heure,heure_tmp)== 0 && strcmp(salle,salle_tmp)==0 &&strcmp(cin,cin_tmp)==0)
                fprintf(g,"");
            else
                fprintf(g,"%s %s %s %s \n",cin,jour,heure,salle);
      }
    }
    fclose(f);
    fclose(h);
    fclose(g);
    remove("rendez_vous.txt");
    rename("rendez_vous_tmp.txt","rendez_vous.txt");
    GtkWidget *treeview2;

    treeview2=lookup_widget(GTK_WIDGET(button),"treeview2_rendez_med");
    afficher_rendez_vous(treeview2);
}

void
on_button_ajou_rendez_med_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1;

  GtkWidget *combo1;
  GtkWidget *combo2;

  char jour_tmp[50],heure_tmp[50],salle_tmp[50];
  char jour[50],heure[50],salle[50],cin[50],cin_tmp[50];

   FILE *f,*g,*h;
  combo1=lookup_widget(GTK_WIDGET(button),"combo_heure_rendez_med");
  combo2=lookup_widget(GTK_WIDGET(button),"combo_salle_rendez_med");

  input1=lookup_widget(GTK_WIDGET(button),"entry2_jour_rendez_med");

  strcpy(jour_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(heure_tmp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)));
  strcpy(salle_tmp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)));

  f=fopen("rendez_vous.txt","a+");
  g=fopen("rendez_vous_tmp.txt","a+");
  h=fopen("tmp.txt","a+");
  fscanf(h,"%s \n",cin_tmp);
  fprintf(g,"%s %s %s %s \n",cin_tmp,jour_tmp,heure_tmp,salle_tmp);
  if(f!= NULL)
  while (fscanf(f,"%s %s %s %s \n",cin,jour,heure,salle) != EOF) {
   if (strcmp(jour,jour_tmp) == 0 && strcmp(heure,heure_tmp)== 0 && strcmp(salle,salle_tmp)==0 ) {
       fprintf(g,"");
          }
    else
     {
         fprintf(g,"%s %s %s %s \n",cin,jour,heure,salle);
       }
  }

  fclose(f);
  fclose(g);
  fclose(h);
  remove("rendez_vous.txt");
  rename("rendez_vous_tmp.txt","rendez_vous.txt");
  GtkWidget *treeview2;

  treeview2=lookup_widget(GTK_WIDGET(button),"treeview2_rendez_med");
  afficher_rendez_vous(treeview2);

}

void
on_fixed_accueil_med_show              (GtkWidget       *widget,
                                        gpointer         user_data)
{/*
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *label4;
  GtkWidget *label5;

  label1=lookup_widget(widget,"label1_accueil_nom");
  label2=lookup_widget(widget,"label2_accueil_prenom");
  label3=lookup_widget(widget,"label3_accueil_cin");
  label4=lookup_widget(widget,"label4_accueil_tel");
  label5=lookup_widget(widget,"label5_accueil_sex");

char cin_tmp[50],cin[50],nom[50],prenom[50],tel[50],sex[50];
char nom_tmp[50],prenom_tmp[50],tel_tmp[50],sex_tmp[50];
date dat;
FILE *f,*g;

f=fopen("profil.txt","r");
g=fopen("tmp.txt","r");

if(g!=NULL)
fscanf(g,"%s \n",cin_tmp);

if(f!=NULL)
   while(fscanf(f,"%s %s %s %s %d %d %d %s",nom,prenom,cin,tel,&dat.jour,&dat.mois,&dat.annee,sex)!=EOF) {
      if(strcmp(cin,cin_tmp)==0) {
        strcpy(nom_tmp,nom);
        strcpy(prenom_tmp,prenom);
        strcpy(sex_tmp,sex);
        strcpy(tel_tmp,tel);
      }
   }


   gtk_label_set_text(GTK_LABEL(label1),nom_tmp);
   gtk_label_set_text(GTK_LABEL(label2),prenom_tmp);
   gtk_label_set_text(GTK_LABEL(label3),cin_tmp);
   gtk_label_set_text(GTK_LABEL(label4),tel_tmp);
   gtk_label_set_text(GTK_LABEL(label5),sex_tmp);

   fclose(f);
   fclose(g);


*/
}

void
on_notebookmain_med_show               (GtkWidget       *widget,
                                        gpointer         user_data)
{
  /*
  GtkWidget *output1;
  GtkWidget *output2;
  GtkWidget *output3;
  GtkWidget *output4;
  GtkWidget *output5;

  output1=lookup_widget(widget,"label1_accueil_nom");
  output2=lookup_widget(widget,"label2_accueil_prenom");
  output3=lookup_widget(widget,"label3_accueil_cin");
  output4=lookup_widget(widget,"label4_accueil_tel");
  output5=lookup_widget(widget,"label5_accueil_sex");

char cin_tmp[50],cin[50],nom[50],prenom[50],tel[50],sex[50];
char nom_tmp[50],prenom_tmp[50],tel_tmp[50],sex_tmp[50];
date dat;
FILE *f,*g;

f=fopen("profil.txt","r");
g=fopen("tmp.txt","r");

if(g!=NULL)
fscanf(g,"%s \n",cin_tmp);

if(f!=NULL)
   while(fscanf(f,"%s %s %s %s %d %d %d %s",nom,prenom,cin,tel,&dat.jour,&dat.mois,&dat.annee,sex)!=EOF) {
      if(strcmp(cin,cin_tmp)==0) {
        strcpy(nom_tmp,nom);
        strcpy(prenom_tmp,prenom);
        strcpy(sex_tmp,sex);
        strcpy(tel_tmp,tel);
      }
   }

   gtk_label_set_text(GTK_LABEL(output1),nom_tmp);
   gtk_label_set_text(GTK_LABEL(output2),prenom_tmp);
   gtk_label_set_text(GTK_LABEL(output3),cin_tmp);
   gtk_label_set_text(GTK_LABEL(output4),tel_tmp);
   gtk_label_set_text(GTK_LABEL(output5),sex_tmp);
   fclose(f);
   fclose(g);

*/

}

void
on_bienv_med_show                      (GtkWidget       *widget,
                                        gpointer         user_data)
{

}

void
on_espacemed_show                      (GtkWidget       *widget,
                                        gpointer         user_data)
{
/*
  GtkWidget *output1;
  GtkWidget *output2;
  GtkWidget *output3;
  GtkWidget *output4;
  GtkWidget *output5;

  output1=lookup_widget(widget,"label1_accueil_nom");
  output2=lookup_widget(widget,"label2_accueil_prenom");
  output3=lookup_widget(widget,"label3_accueil_cin");
  output4=lookup_widget(widget,"label4_accueil_tel");
  output5=lookup_widget(widget,"label5_accueil_sex");

  char cin_tmp[50],cin[50],nom[50],prenom[50],tel[50],sex[50];
  char nom_tmp[50],prenom_tmp[50],tel_tmp[50],sex_tmp[50];
  date dat;
  FILE *f,*g;

  f=fopen("profil.txt","r");
  g=fopen("tmp.txt","r");

  if(g!=NULL)
  fscanf(g,"%s \n",cin_tmp);

  if(f!=NULL)
  {
   while(fscanf(f,"%s %s %s %s %d %d %d %s",nom,prenom,cin,tel,&dat.jour,&dat.mois,&dat.annee,sex)!=EOF) {
      if(strcmp(cin,cin_tmp)==0) {
        strcpy(nom_tmp,nom);
        strcpy(prenom_tmp,prenom);
        strcpy(sex_tmp,sex);
        strcpy(tel_tmp,tel);
      }
   }

   gtk_label_set_text(GTK_LABEL(output1),nom_tmp);
   gtk_label_set_text(GTK_LABEL(output2),prenom_tmp);
   gtk_label_set_text(GTK_LABEL(output3),cin_tmp);
   gtk_label_set_text(GTK_LABEL(output4),tel_tmp);
   gtk_label_set_text(GTK_LABEL(output5),sex_tmp);
  }
   fclose(f);
   fclose(g);
*/
}

void
on_ajouterfiche_med_clicked            (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;

  FILE *f,*g;

  char nom_tmp[50],prenom_tmp[50],age_tmp[50],taille_tmp[50],pouls_tmp[50],pressionsys_tmp[50],pressiondia_tmp[50];
 char nom[50],prenom[50],age[50],taille[50],pouls[50],pressionsys[50],pressiondia[50];

  input1=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med1");
  input2=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med2");
  input3=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med3");
  input4=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med4");
  input5=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med5");
  input6=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med6");
  input7=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med7");

  strcpy(nom_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(prenom_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(age_tmp,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(taille_tmp,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(pouls_tmp,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(pressionsys_tmp,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(pressiondia_tmp,gtk_entry_get_text(GTK_ENTRY(input7)));

  f=fopen("fiche_med.txt","a+");
 g=fopen("fiche_med_tmp.txt","a+");
  fprintf(g,"%s %s %s %s %s %s %s\n",nom_tmp,prenom_tmp,age_tmp,taille_tmp,pouls_tmp,pressionsys_tmp,pressiondia_tmp);

  if (f!=NULL) {
       while (fscanf(f,"%s %s %s %s %s %s %s\n",nom,prenom,age,taille,pouls,pressionsys,pressiondia)!=EOF) {
          if (strcmp(nom_tmp,nom)==0 && strcmp(prenom,prenom_tmp)==0 && strcmp(age,age_tmp)==0 && strcmp(taille,taille_tmp)==0 && strcmp(pouls,pouls_tmp)==0 && strcmp(pressionsys,pressionsys_tmp)==0 && strcmp(pressiondia,pressiondia_tmp)==0) {
              fprintf(g,"");
          }
          else
          {
              fprintf(g,"%s %s %s %s %s %s %s\n",nom,prenom,age,taille,pouls,pressionsys,pressiondia);
         }
      }


 }

  fclose(f);
  fclose(g);
  remove("fiche_med.txt");
  rename("fiche_med_tmp.txt","fiche_med.txt");
  GtkWidget *treeview3;

  treeview3=lookup_widget(toolbutton,"treeview20_med");
  afficher_fiche(treeview3);

}


void
on_suprimerfiche_med_clicked           (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;

  FILE *f,*g;

  char nom_tmp[50],prenom_tmp[50],age_tmp[50],taille_tmp[50],pouls_tmp[50],pressionsys_tmp[50],pressiondia_tmp[50];
  char nom[50],prenom[50],age[50],taille[50],pouls[50],pressiondia[50],pressionsys[50];
  input1=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med1");
  input2=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med2");
  input3=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med3");
  input4=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med4");
  input5=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med5");
  input6=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med6");
  input7=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med7");

  strcpy(nom_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(prenom_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(age_tmp,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(taille_tmp,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(pouls_tmp,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(pressionsys_tmp,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(pressiondia_tmp,gtk_entry_get_text(GTK_ENTRY(input7)));

  f=fopen("fiche_med.txt","a+");
  g = fopen("fiche_med_tmp.txt","w+");
if (f != NULL && g!= NULL) {
    while (fscanf(f,"%s %s %s %s %s %s %s \n",nom,prenom,age,taille,pouls,pressionsys,pressiondia) != EOF) {
          if (strcmp(nom,nom_tmp) == 0 && strcmp(prenom,prenom_tmp)== 0 && strcmp(age,age_tmp)==0 && strcmp(taille,taille_tmp)==0 && strcmp(pouls,pouls_tmp)==0 && strcmp(pressionsys,pressionsys_tmp)==0&& strcmp(pressiondia,pressiondia_tmp)==0)
              fprintf(g,"");
          else
              fprintf(g,"%s %s %s %s %s %s %s \n",nom,prenom,age,taille,pouls,pressionsys,pressiondia);
    }
  }
  fclose(f);
  fclose(g);
  remove("fiche_med.txt");
  rename("fiche_med_tmp.txt","fiche_med.txt");
  GtkWidget *treeview3;

  treeview3=lookup_widget(toolbutton,"treeview20_med");
  afficher_fiche(treeview3);
  /*
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;

  FILE *f,*g;

  char nom_tmp[50],prenom_tmp[50],age_tmp[50],taille_tmp[50],pouls_tmp[50],pressionsys_tmp[50],pressiondia_tmp[50];
  input1=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med1");
  input2=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med2");
  input3=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med3");
  input4=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med4");
  input5=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med5");
  input6=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med6");
  input7=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med7");

  strcpy(nom_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(prenom_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(age_tmp,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(taille_tmp,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(pouls_tmp,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(pressionsys_tmp,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(pressiondia_tmp,gtk_entry_get_text(GTK_ENTRY(input7)));

  f=fopen("fiche_med.txt","a+");
  fprintf(f,"%s %s %s %s %s %s %s\n",nom_tmp,prenom_tmp,age_tmp,taille_tmp,pouls_tmp,pressionsys_tmp,pressiondia_tmp);
  fclose(f);
  GtkWidget *treeview3;

  treeview3=lookup_widget(toolbutton,"treeview20_med");
  afficher_fiche(treeview3);
*/
}


void
on_modifierfiche_med_clicked           (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{

  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;

  FILE *f,*g,*h;

  char nom_tmp[50],prenom_tmp[50],age_tmp[50],taille_tmp[50],pouls_tmp[50],pressionsys_tmp[50],pressiondia_tmp[50];
  char nom[50],prenom[50],age[50],taille[50],pouls[50],pressiondia[50],pressionsys[50];
  char nom_anc[50],prenom_anc[50],age_anc[50],taille_anc[50],pouls_anc[50],pressiondia_anc[50],pressionsys_anc[50];
  input1=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med1");
  input2=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med2");
  input3=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med3");
  input4=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med4");
  input5=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med5");
  input6=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med6");
  input7=lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_med7");

  strcpy(nom_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(prenom_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(age_tmp,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(taille_tmp,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(pouls_tmp,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(pressionsys_tmp,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(pressiondia_tmp,gtk_entry_get_text(GTK_ENTRY(input7)));


  f = fopen("fiche_med.txt","r");
  g = fopen("fiche_med_tmp.txt","w+");
  h= fopen("fiche_med_modf.txt","r");
  fscanf(h,"%s %s %s %s %s %s %s \n",nom_anc,prenom_anc,age_anc,taille_anc,pouls_anc,pressiondia_anc,pressionsys_anc);
  //  h = fopen("tmp.txt","r");
  //  if ( h !=NULL)
  //    while (fscanf(f,"%s  \n",cin_tmp) != EOF)


  if (f != NULL && g!= NULL) {
    while (fscanf(f,"%s %s %s %s %s %s %s \n", nom,prenom,age,taille,pouls,pressiondia,pressionsys) != EOF) {
          if (strcmp(nom,nom_anc) == 0 && strcmp(prenom,prenom_anc)== 0 && strcmp(age,age_anc)==0&& strcmp(taille,taille_anc)==0&&  strcmp(pouls,pouls_anc)==0 &&  strcmp(pressiondia,pressiondia_anc)==0 &&  strcmp(pressionsys,pressionsys_anc)==0   )
              fprintf(g,"%s %s %s %s %s %s %s \n",nom_tmp,prenom_tmp,age_tmp,taille_tmp,pouls_tmp,pressiondia_tmp,pressionsys_tmp);
          else
              fprintf(g,"%s %s %s %s %s %s %s  \n", nom,prenom,age,taille,pouls,pressiondia,pressionsys);
    }
  }
  fclose(f);
  fclose(h);
  fclose(g);
  remove("fiche_med.txt");
  rename("fiche_med_tmp.txt","fiche_med.txt");







/*
  f=fopen("fiche_med.txt","r");
  g = fopen("fiche_med_tmp.txt","w+");
//  fprintf(g,"%s %s %s %s %s %s %s \n",nom_tmp,prenom_tmp,age_tmp,taille_tmp,pouls_tmp,pressionsys_tmp,pressiondia_tmp);


  h=fopen("fiche_med_modf.txt","r");
  fscanf(h,"%s %s %s %s %s %s %s \n",nom_anc,prenom_anc,age_anc,taille_anc,pouls_anc,pressiondia_anc,pressionsys_anc);
  if (f != NULL && g!= NULL) {
    while (fscanf(f,"%s %s %s %s %s %s %s \n",nom,prenom,age,taille,pouls,pressionsys,pressiondia) != EOF) {
          if (strcmp(nom,nom_anc) == 0 && strcmp(prenom,prenom_anc)== 0 && strcmp(age,age_anc)==0 && strcmp(taille,taille_anc)==0 && strcmp(pouls,pouls_anc)==0 && strcmp(pressionsys,pressionsys_anc)==0 && strcmp(pressiondia,pressiondia_anc)==0)
            fprintf(g,"%s %s %s %s %s %s %s \n",nom_tmp,prenom_tmp,age_tmp,taille_tmp,pouls_tmp,pressionsys_tmp,pressiondia_tmp);

          else
              fprintf(g,"%s %s %s %s %s %s %s \n",nom,prenom,age,taille,pouls,pressionsys,pressiondia);
    }
  }
  fclose(f);
  fclose(g);
  fclose(h);
  remove("fiche_med.txt");
  rename("fiche_med_tmp.txt","fiche_med.txt");*/
  GtkWidget *treeview3;

  treeview3=lookup_widget(toolbutton,"treeview20_med");
  afficher_fiche(treeview3);

}

void
on_button_exit_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  remove("tmp.txt");
  gtk_main_quit();
}


void
on_button_login__clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *window3;
  GtkWidget *window1;

  window3=lookup_widget(GTK_WIDGET(button),"espace_login");
  window1=create_espacemed();
  input1=lookup_widget(GTK_WIDGET(button),"entry1_username");
  input2=lookup_widget(GTK_WIDGET(button),"entry2_password");
  FILE *f,*g;
 char username[50],password[50],cin[50],username_tmp[50],password_tmp[50],role[50],etat[50];

  strcpy(username_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(password_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  f=fopen("users.txt","r");


  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s\n",username,password,role,cin,etat)!=EOF) {
        if (strcmp(username,username_tmp)==0 && strcmp(password,password_tmp)==0)
           {
              g=fopen("tmp.txt","a+");
              fprintf(g,"%s \n",cin );

          gtk_widget_hide_all(window3);
          gtk_widget_show(window1);
          fclose(g);
           }
    }
  }
  fclose(f);
}

void
on_validerp_med_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;

  input1=lookup_widget(GTK_WIDGET(button),"pentry_med");
  input2=lookup_widget(GTK_WIDGET(button),"pentry_med6");
  input3=lookup_widget(GTK_WIDGET(button),"pentry_med7");

  char ancien_pass[50],nouv_pass1_tmp[50],nouv_pass2_tmp[50];
  char ancien_pass_tmp[50],username[50],cin[50],cin_tmp[50],role[50],etat[50];

  FILE *f ,*g ,*h;

  strcpy(ancien_pass_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(nouv_pass1_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(nouv_pass2_tmp,gtk_entry_get_text(GTK_ENTRY(input3)));

  f=fopen("users.txt","a+");
  g=fopen("login_tmp.txt","a+");
  h=fopen("tmp.txt","r");

 fscanf(h,"%s \n",cin_tmp);

  if (f!=NULL) {

     while (fscanf(f,"%s %s %s %s %S \n",username,ancien_pass,role,cin,etat)!=EOF) {

                 if (strcmp(cin,cin_tmp)==0) {
                     if (strcmp(nouv_pass2_tmp,nouv_pass1_tmp)==0 && strcmp(ancien_pass,ancien_pass_tmp)==0) {
                       fprintf(g,"%s %s %s %s %s \n",username,nouv_pass1_tmp,role,cin_tmp,etat);
                     }
                  }
                  else
                  {
                    fprintf(g, "%s %s %s %s %s \n",username,ancien_pass,role,cin,etat);
                  }
                }
              }
fclose(f);
fclose(g);
fclose(h);
remove("users.txt");
rename("login_tmp.txt","users.txt");



}
void
on_modifierprofil_med_clicked          (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
      select_page(toolbutton,0,"profil_med_book");
}

void
on_button_mod_rendez_med_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;

  char jour_tmp[50],heure_tmp[50],salle_tmp[50],cin_tmp[50];
  char jour[50],heure[50],salle[50],cin[50],cin_an[50];
  char jour_anc[50],heure_anc[50],salle_anc[50];

  input1=lookup_widget(GTK_WIDGET(button),"entry3_jour_rendez_med");
  input2=lookup_widget(GTK_WIDGET(button),"entry4_heure_rendez_med");
  input3=lookup_widget(GTK_WIDGET(button),"entry5_salle_rendez_med");

  strcpy(jour_tmp,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(heure_tmp,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(salle_tmp,gtk_entry_get_text(GTK_ENTRY(input3)));

  FILE *f, *g,*h,*k;


    f = fopen("rendez_vous.txt","r");
    g = fopen("rendez_vous_tmp.txt","w+");
   h= fopen("fiche_rendez_modf.txt","r");
   k=fopen("tmp.txt","r");
   fscanf(k,"%s",cin_tmp);
   fscanf(h,"%s %s %s %s \n",cin_an,jour_anc,heure_anc,salle_anc);
  //  h = fopen("tmp.txt","r");
  //  if ( h !=NULL)
  //    while (fscanf(f,"%s  \n",cin_tmp) != EOF)


    if (f != NULL && g!= NULL) {
      while (fscanf(f,"%s %s %s %s \n",cin,jour,heure,salle) != EOF) {
            if (strcmp(jour,jour_anc) == 0 && strcmp(heure,heure_anc)== 0 && strcmp(salle,salle_anc)==0)
                fprintf(g,"%s %s %s %s \n",cin_tmp,jour_tmp,heure_tmp,salle_tmp);
            else
                fprintf(g,"%s %s %s %s \n",cin,jour,heure,salle);
      }
    }
    fclose(f);
    fclose(h);
    fclose(g);
    fclose(k);
    remove("rendez_vous.txt");
    rename("rendez_vous_tmp.txt","rendez_vous.txt");
    GtkWidget *treeview2;

    treeview2=lookup_widget(GTK_WIDGET(button),"treeview2_rendez_med");
    afficher_rendez_vous(treeview2);
}
