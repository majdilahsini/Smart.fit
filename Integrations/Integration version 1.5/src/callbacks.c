#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include "ntbook.h"
#include "fonction.h"
#include "ajouter.h"
#include "afficher.h"
#include "modifier.h"
#include "reservation.h"
#include "supprimer.h"
#include "affichercalen.h"

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
    gtk_label_set_text(GTK_LABEL(output),"Termes et les conditions");
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
on_button1_login_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input, *input2;
  GtkWidget *output;
  FILE* f;

  GtkWidget *window, *window2, *espacediet, *espaceaymen;

  char login[50], password[50], cin[50],test[50];
  int t[2];

  input = lookup_widget(GTK_WIDGET(button),"entry1_login");
  input2 = lookup_widget(GTK_WIDGET(button),"entry2_login");
  window = lookup_widget(GTK_WIDGET(button),"login");

  strcpy(login,gtk_entry_get_text(GTK_ENTRY(input)));
  strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
  if (verifier_login(login,password,t,cin) == 2 && t[0]==1) {
    strcpy(test,cin);
    creation_tmp(cin);
    window2 = create_firs_time();
    gtk_widget_show(window2);
    gtk_widget_destroy(window);
  }
  if (verifier_login(login,password,t,cin) == 2 && t[0]==0){
    espacediet = create_espacediet();
    strcpy(test,cin);
    creation_tmp(cin);
    gtk_widget_show(espacediet);
    gtk_widget_destroy(window);
  }
  if (verifier_login(login,password,t,cin) == 1) {
    strcpy(test,cin);
    creation_tmp(cin);
    espaceaymen = create_window2();
    gtk_widget_destroy(window);
    gtk_widget_show(espaceaymen);
  }
}

void
on_suivant01_login_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *output;
  GtkWidget *notebook;
  GtkWidget *progressbar;
  GtkWidget *image;

  output = lookup_widget(GTK_WIDGET(button),"label26_login");
  notebook = lookup_widget(GTK_WIDGET(button),"notebook1_login");
  progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1_login");
  image = lookup_widget(GTK_WIDGET(button),"image7_login");

  gtk_label_set_text(GTK_LABEL(output),"Modification du mot de passe");
  gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-go-forward",GTK_ICON_SIZE_BUTTON);
  gtk_notebook_next_page(notebook);
  gtk_progress_bar_update(progressbar,0.33);
}

void
on_suivant02_login_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *output, *output2;
  GtkWidget *input1, *input2;
  GtkWidget *notebook;
  GtkWidget *progressbar;
  GtkWidget *image, *image2, *image3, *image4;

  char cin[8];

  int test;

  input1 = lookup_widget(GTK_WIDGET(button),"entry3_login");
  input2 = lookup_widget(GTK_WIDGET(button),"entry4_login");

  output = lookup_widget(GTK_WIDGET(button),"label27_login");
  output2 = lookup_widget(GTK_WIDGET(button),"label29_login");

  FILE *f;

  f = fopen("tmp.txt","r");
  fscanf(f,"%s",cin);

  notebook = lookup_widget(GTK_WIDGET(button),"notebook1_login");

  progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1_login");

  image = lookup_widget(GTK_WIDGET(button),"image8_login");
  image2 = lookup_widget(GTK_WIDGET(button),"image7_login");
  image3 = lookup_widget(GTK_WIDGET(button),"image10_login");
  image4 = lookup_widget(GTK_WIDGET(button),"image11_login");

  test = verifier_pass(gtk_entry_get_text(input1),gtk_entry_get_text(input2));

  if (test == 1 && strlen(gtk_entry_get_text(input1))>0 && strlen(gtk_entry_get_text(input2))>0) {
    gtk_label_set_text(GTK_LABEL(output),"Termes et les conditions");
    gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-go-forward",GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-ok",GTK_ICON_SIZE_BUTTON);
    gtk_notebook_next_page(notebook);
    gtk_progress_bar_update(progressbar,0.66);

    mod_mdp_firsttime(gtk_entry_get_text(input1),cin);
}
}

void
on_confirmer_login_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *progressbar;
    GtkWidget *image, *image2;
    GtkWidget *combo;

    progressbar = lookup_widget(GTK_WIDGET(button),"progressbar1_login");
    image = lookup_widget(GTK_WIDGET(button),"image8_login");
    image2 = lookup_widget(GTK_WIDGET(button),"image7_login");
    combo = lookup_widget(GTK_WIDGET(button),"checkbutton1_login");

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(combo))) {

    gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-ok",GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image2),"gtk-ok",GTK_ICON_SIZE_BUTTON);

    gtk_progress_bar_update(progressbar,1);
    }
}

void
on_valider_login_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *check;

GtkWidget *window2, *espacediet;

check = lookup_widget(GTK_WIDGET(button),"checkbutton1_login");
window2 = lookup_widget(GTK_WIDGET(button),"firs_time");

if (gtk_toggle_button_get_active(check) && cherche_role() == 4) {

    espacediet = create_espacediet();
    gtk_widget_show(espacediet);
    gtk_widget_destroy(window2);

  }
}


void
on_button3_login_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}



void
on_accuei_diet_clicked                 (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
select_page(toolbutton,0,"notebookmain_diet");
}


void
on_profil_diet_clicked                 (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
GtkWidget *entry1, *entry2 ,*entry3, *entry4;
GtkWidget *spin1, *spin2 ,*spin3;
GtkWidget *combo;
char cin[10];
p_diet a;

FILE *f;

select_page(toolbutton,1,"notebookmain_diet");

entry1 = lookup_widget(GTK_WIDGET(toolbutton),"pentry_diet1");
entry2 = lookup_widget(GTK_WIDGET(toolbutton),"pentry_diet2");
entry3 = lookup_widget(GTK_WIDGET(toolbutton),"pentry_diet3");
entry4 = lookup_widget(GTK_WIDGET(toolbutton),"pentry_diet4");

spin1 = lookup_widget(GTK_WIDGET(toolbutton),"pspin_diet1");
spin2 = lookup_widget(GTK_WIDGET(toolbutton),"pspin_diet2");
spin3 = lookup_widget(GTK_WIDGET(toolbutton),"pspin_diet3");

combo = lookup_widget(GTK_WIDGET(toolbutton),"pcombo_diet1");

f = fopen("dieteticiens.txt","r");

tmp_cin(cin);

if (f != NULL) {
    while (fscanf(f,"%s %s %s %s %d %d %d %s",a.nom,a.prenom,a.CIN,a.tel,&a.dt.jour,&a.dt.mois,&a.dt.annee,a.sexe) != EOF) {
      if (strcmp(a.CIN,cin)==0){
      gtk_entry_set_text(GTK_ENTRY(entry1),a.nom);
      gtk_entry_set_text(GTK_ENTRY(entry2),a.prenom);
      gtk_entry_set_text(GTK_ENTRY(entry3),a.CIN);
      gtk_entry_set_text(GTK_ENTRY(entry4),a.tel);

      gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin1),a.dt.jour);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin2),a.dt.mois);
      gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin3),a.dt.annee);
      if (strcmp(a.sexe,"Homme")==0)
          gtk_combo_box_set_active(GTK_COMBO_BOX(combo),0);
      else
          gtk_combo_box_set_active(GTK_COMBO_BOX(combo),1);
      }
    }
  }
fclose(f);
}


void
on_fchdiet_diet_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
select_page(toolbutton,2,"notebookmain_diet");
}


void
on_fichemed_diet_clicked               (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{

GtkWidget *liste;
liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview3_diet");

select_page(toolbutton,3,"notebookmain_diet");
affichage3(liste);
}


void
on_rendez_diet_clicked                 (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *liste;
  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview15_dd");
select_page(toolbutton,4,"notebookmain_diet");

affichage4_rdv_diet(liste);
}


void
on_dec_diet_clicked                    (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
GtkWidget *window, *window2;

window2 = lookup_widget(GTK_WIDGET(toolbutton),"espacediet");

window=create_login();
gtk_widget_show(window);
gtk_widget_destroy(window2);


}


void
on_quit_diet_clicked                   (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
gtk_main_quit();
}

void
on_modifierprofil_diet_clicked         (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
select_page(toolbutton,0,"profil_diet_book");
}


void
on_changepass_diet_clicked             (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
select_page(toolbutton,1,"profil_diet_book");
}

void
on_pmodifier_diet1_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *entry1, *entry2 ,*entry3, *entry4;
  GtkWidget *spin1, *spin2 ,*spin3;
  GtkWidget *image1, *image2, *image3, *image4 ;
  GtkWidget *combo;

  int c;
  char cin[10], T[4][20];
  p_diet a;

  entry1 = lookup_widget(GTK_WIDGET(button),"pentry_diet1");
  entry2 = lookup_widget(GTK_WIDGET(button),"pentry_diet2");
  entry3 = lookup_widget(GTK_WIDGET(button),"pentry_diet3");
  entry4 = lookup_widget(GTK_WIDGET(button),"pentry_diet4");

  spin1 = lookup_widget(GTK_WIDGET(button),"pspin_diet1");
  spin2 = lookup_widget(GTK_WIDGET(button),"pspin_diet2");
  spin3 = lookup_widget(GTK_WIDGET(button),"pspin_diet3");

  combo = lookup_widget(GTK_WIDGET(button),"pcombo_diet1");

  image1 = lookup_widget(GTK_WIDGET(button),"imagenom_diet");
  image2 = lookup_widget(GTK_WIDGET(button),"imageprenom_diet");
  image3 = lookup_widget(GTK_WIDGET(button),"imagecin_diet");
  image4 = lookup_widget(GTK_WIDGET(button),"imagetel_diet");

  strcpy (a.nom,gtk_entry_get_text(GTK_ENTRY(entry1)));
  strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(entry2)));
  strcpy(a.CIN,gtk_entry_get_text(GTK_ENTRY(entry3)));
  strcpy(a.tel,gtk_entry_get_text(GTK_ENTRY(entry4)));

  a.dt.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
  a.dt.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
  a.dt.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3));

  strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));


  c = ver_modprofil_diet(a,T);
  if (c == 3) {
    tmp_cin(cin);
    modprofil_diet(a,cin);

    gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image3),"gtk-ok",GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image4),T[2],GTK_ICON_SIZE_BUTTON);
  }
  else
  {
    gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image3),"gtk-ok",GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image4),T[2],GTK_ICON_SIZE_BUTTON);
  }
}


void
on_validerp_diet_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entry, *entry2, *entry3;
GtkWidget *image1, *image2, *image3;
char cin[20], password[20] , nouveau_password[20], conf_password[20];
char T[3][20];

entry = lookup_widget(GTK_WIDGET(button),"pentry_diet");
entry2 = lookup_widget(GTK_WIDGET(button),"pentry_diet6");
entry3 = lookup_widget(GTK_WIDGET(button),"pentry_diet7");

image1 = lookup_widget(GTK_WIDGET(button),"imagepass1_diet");
image2 = lookup_widget(GTK_WIDGET(button),"imagepass2_diet");
image3 = lookup_widget(GTK_WIDGET(button),"imagepass3_diet");

strcpy(password,gtk_entry_get_text(GTK_ENTRY(entry)));
strcpy(nouveau_password,gtk_entry_get_text(GTK_ENTRY(entry2)));
strcpy(conf_password,gtk_entry_get_text(GTK_ENTRY(entry3)));

tmp_cin(cin);

if (verif_pass_finale(cin,password,nouveau_password,conf_password,T) == 3){
    modifier_pass_diet(cin,nouveau_password);

    gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image3),T[2],GTK_ICON_SIZE_BUTTON);
}
else
    gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
    gtk_image_set_from_stock(GTK_IMAGE(image3),T[2],GTK_ICON_SIZE_BUTTON);
}

void
on_afficher1_diet_clicked              (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
GtkWidget *liste;
liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview1_diet");

select_page(toolbutton,1,"affichagebook_diet");
affichage1(liste);
}


void
on_afficher2_diet_clicked              (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *liste;
  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview2_diet");

  select_page(toolbutton,2,"affichagebook_diet");
  affichage2(liste);
}

void
on_treeview1_diet_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

  GtkWidget *entry, *entry2, *entry3, *entry4, *entry5, *entry6, *entry7, *entry8;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string, *string1, *string2, *string3;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  gtk_tree_model_get(model,&iter,0,&string,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);


  entry = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet1");
  entry2 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet2");
  entry3 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet3");
  entry4 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet4");
  entry5 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet5");
  entry6 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet6");
  entry7 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet7");
  entry8 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet8");


  gtk_entry_set_text(GTK_ENTRY(entry),string1);
  gtk_entry_set_text(GTK_ENTRY(entry2),string2);
  gtk_entry_set_text(GTK_ENTRY(entry3),string);
  gtk_entry_set_text(GTK_ENTRY(entry4),"");
  gtk_entry_set_text(GTK_ENTRY(entry5),"");
  gtk_entry_set_text(GTK_ENTRY(entry6),"");
  gtk_entry_set_text(GTK_ENTRY(entry7),"");
  gtk_entry_set_text(GTK_ENTRY(entry8),"");
}


void
on_treeview2_diet_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *entry, *entry2, *entry3, *entry4, *entry5, *entry6, *entry7, *entry8;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string, *string1, *string2, *string3, *string4, *string5, *string6, *string7;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  gtk_tree_model_get(model,&iter,0,&string,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);
  gtk_tree_model_get(model,&iter,3,&string3,-1);
  gtk_tree_model_get(model,&iter,4,&string4,-1);
  gtk_tree_model_get(model,&iter,5,&string5,-1);
  gtk_tree_model_get(model,&iter,6,&string6,-1);
  gtk_tree_model_get(model,&iter,7,&string7,-1);

  entry = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet1");
  entry2 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet2");
  entry3 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet3");
  entry4 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet4");
  entry5 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet5");
  entry6 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet6");
  entry7 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet7");
  entry8 = lookup_widget(GTK_TREE_VIEW(treeview),"entryfiche_diet8");

  gtk_entry_set_text(GTK_ENTRY(entry),string);
  gtk_entry_set_text(GTK_ENTRY(entry2),string1);
  gtk_entry_set_text(GTK_ENTRY(entry3),string2);
  gtk_entry_set_text(GTK_ENTRY(entry4),string3);
  gtk_entry_set_text(GTK_ENTRY(entry5),string4);
  gtk_entry_set_text(GTK_ENTRY(entry6),string5);
  gtk_entry_set_text(GTK_ENTRY(entry7),string6);
  gtk_entry_set_text(GTK_ENTRY(entry8),string7);
}

void
on_ajouterfiche_diet_clicked           (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *entry1, *entry2, *entry3, *entry4, *entry5, *entry6, *entry7, *entry8;
  GtkWidget *output;
  GtkWidget *liste;
  GtkWidget *image1, *image2, *image3, *image4, *image5, *image6, *image7, *image8;
  GtkWidget *imgprin;

  char nom[20], prenom[20], T[8][20];
  f_diet a;

  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview2_diet");

  entry1 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet1");
  entry2 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet2");
  entry3 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet3");
  entry4 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet4");
  entry5 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet5");
  entry6 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet6");
  entry7 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet7");
  entry8 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet8");

  output = lookup_widget(GTK_WIDGET(toolbutton),"msgfiche_diet");

  image1 = lookup_widget(GTK_WIDGET(toolbutton),"image1_diet");
  image2 = lookup_widget(GTK_WIDGET(toolbutton),"image2_diet");
  image3 = lookup_widget(GTK_WIDGET(toolbutton),"image3_diet");
  image4 = lookup_widget(GTK_WIDGET(toolbutton),"image4_diet");
  image5 = lookup_widget(GTK_WIDGET(toolbutton),"image5_diet");
  image6 = lookup_widget(GTK_WIDGET(toolbutton),"image6_diet");
  image7 = lookup_widget(GTK_WIDGET(toolbutton),"image7_diet");
  image8 = lookup_widget(GTK_WIDGET(toolbutton),"image8_diet");

  imgprin = lookup_widget(GTK_WIDGET(toolbutton),"imgmsgfiche_diet");

  strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry2)));
  strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(entry2)));
  strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(entry3)));
  strcpy(a.poid,gtk_entry_get_text(GTK_ENTRY(entry4)));
  strcpy(a.taille,gtk_entry_get_text(GTK_ENTRY(entry5)));
  strcpy(a.icm,gtk_entry_get_text(GTK_ENTRY(entry6)));
  strcpy(a.tdt,gtk_entry_get_text(GTK_ENTRY(entry7)));
  strcpy(a.regime,gtk_entry_get_text(GTK_ENTRY(entry8)));

  if (verifi_fichediet(nom,prenom,a,T) == 8) {
      if (verif_si_fichediet_existe(a.cin) == 1) {
        gtk_label_set_text(GTK_LABEL(output),"Une fiche qui a le même nom existe déja, voulez-vous modifier la fiche?");
        gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
      }
      else {
        ajoufich_diet(a);
        affichage2(liste);
        select_page(toolbutton,2,"affichagebook_diet");

        gtk_label_set_text(GTK_LABEL(output),"L'ajout a été éffectuté avec succés");

        gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image3),T[2],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image4),T[3],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image5),T[4],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image6),T[5],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image7),T[6],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image8),T[7],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-ok",GTK_ICON_SIZE_BUTTON);
        }
      }
  else
      {
      gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image3),T[2],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image4),T[3],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image5),T[4],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image6),T[5],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image7),T[6],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image8),T[7],GTK_ICON_SIZE_BUTTON);
      gtk_label_set_text(GTK_LABEL(output),"L'ajout a échoué veuillez verifier les données saisies");
      gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
      }
}

void
on_suprimerfiche_diet_clicked          (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *entry1, *entry2, *entry3, *entry4, *entry5, *entry6, *entry7, *entry8;
  GtkWidget *output;
  GtkWidget *liste;
  GtkWidget *image1, *image2, *image3, *image4, *image5, *image6, *image7, *image8;
  GtkWidget *imgprin;

  char nom[20], prenom[20], T[8][20];
  f_diet a;

  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview2_diet");

  entry1 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet1");
  entry2 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet2");
  entry3 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet3");
  entry4 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet4");
  entry5 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet5");
  entry6 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet6");
  entry7 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet7");
  entry8 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet8");

  output = lookup_widget(GTK_WIDGET(toolbutton),"msgfiche_diet");

  image1 = lookup_widget(GTK_WIDGET(toolbutton),"image1_diet");
  image2 = lookup_widget(GTK_WIDGET(toolbutton),"image2_diet");
  image3 = lookup_widget(GTK_WIDGET(toolbutton),"image3_diet");
  image4 = lookup_widget(GTK_WIDGET(toolbutton),"image4_diet");
  image5 = lookup_widget(GTK_WIDGET(toolbutton),"image5_diet");
  image6 = lookup_widget(GTK_WIDGET(toolbutton),"image6_diet");
  image7 = lookup_widget(GTK_WIDGET(toolbutton),"image7_diet");
  image8 = lookup_widget(GTK_WIDGET(toolbutton),"image8_diet");

  imgprin = lookup_widget(GTK_WIDGET(toolbutton),"imgmsgfiche_diet");

  strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry2)));
  strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(entry2)));
  strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(entry3)));
  strcpy(a.poid,gtk_entry_get_text(GTK_ENTRY(entry4)));
  strcpy(a.taille,gtk_entry_get_text(GTK_ENTRY(entry5)));
  strcpy(a.icm,gtk_entry_get_text(GTK_ENTRY(entry6)));
  strcpy(a.tdt,gtk_entry_get_text(GTK_ENTRY(entry7)));
  strcpy(a.regime,gtk_entry_get_text(GTK_ENTRY(entry8)));

  if (verifi_fichediet(nom,prenom,a,T) == 8) {
      if (verif_si_fichediet_existe(a.cin) == 0){
          gtk_label_set_text(GTK_LABEL(output),"La fiche que vous voulez suprimer n'existe pas, veuillez vérfier que vous avez ajouter la fiche avant de la suprimer.");
          gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
      }
      else {
      suprfich_diet(a.cin);
      affichage2(liste);
      select_page(toolbutton,2,"affichagebook_diet");

      gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image3),T[2],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image4),T[3],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image5),T[4],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image6),T[5],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image7),T[6],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image8),T[7],GTK_ICON_SIZE_BUTTON);
      gtk_label_set_text(GTK_LABEL(output),"La supression a été effectué avec succés.");
      gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-ok",GTK_ICON_SIZE_BUTTON);
       }
      }
  else
      {
      gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image3),T[2],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image4),T[3],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image5),T[4],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image6),T[5],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image7),T[6],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image8),T[7],GTK_ICON_SIZE_BUTTON);
      gtk_label_set_text(GTK_LABEL(output),"La supression a été échoué.");
      gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
      }
}

void
on_modifierfiche_diet_clicked          (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *entry1, *entry2, *entry3, *entry4, *entry5, *entry6, *entry7, *entry8;
  GtkWidget *output;
  GtkWidget *liste;
  GtkWidget *image1, *image2, *image3, *image4, *image5, *image6, *image7, *image8;
  GtkWidget *imgprin;

  char nom[20], prenom[20], T[8][20];
  f_diet a;

  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview2_diet");

  entry1 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet1");
  entry2 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet2");
  entry3 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet3");
  entry4 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet4");
  entry5 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet5");
  entry6 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet6");
  entry7 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet7");
  entry8 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet8");

  output = lookup_widget(GTK_WIDGET(toolbutton),"msgfiche_diet");

  image1 = lookup_widget(GTK_WIDGET(toolbutton),"image1_diet");
  image2 = lookup_widget(GTK_WIDGET(toolbutton),"image2_diet");
  image3 = lookup_widget(GTK_WIDGET(toolbutton),"image3_diet");
  image4 = lookup_widget(GTK_WIDGET(toolbutton),"image4_diet");
  image5 = lookup_widget(GTK_WIDGET(toolbutton),"image5_diet");
  image6 = lookup_widget(GTK_WIDGET(toolbutton),"image6_diet");
  image7 = lookup_widget(GTK_WIDGET(toolbutton),"image7_diet");
  image8 = lookup_widget(GTK_WIDGET(toolbutton),"image8_diet");

  imgprin = lookup_widget(GTK_WIDGET(toolbutton),"imgmsgfiche_diet");

  strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry2)));
  strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(entry2)));
  strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(entry3)));
  strcpy(a.poid,gtk_entry_get_text(GTK_ENTRY(entry4)));
  strcpy(a.taille,gtk_entry_get_text(GTK_ENTRY(entry5)));
  strcpy(a.icm,gtk_entry_get_text(GTK_ENTRY(entry6)));
  strcpy(a.tdt,gtk_entry_get_text(GTK_ENTRY(entry7)));
  strcpy(a.regime,gtk_entry_get_text(GTK_ENTRY(entry8)));

  if (verifi_fichediet(nom,prenom,a,T) == 8) {
    if (verif_si_fichediet_existe(a.cin) == 0){
        gtk_label_set_text(GTK_LABEL(output),"La fiche que vous voulez modifier n'existe pas.");
        gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
      }
      else {
        modfich_diet(a);
        affichage2(liste);
        select_page(toolbutton,2,"affichagebook_diet");

        gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image3),T[2],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image4),T[3],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image5),T[4],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image6),T[5],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image7),T[6],GTK_ICON_SIZE_BUTTON);
        gtk_image_set_from_stock(GTK_IMAGE(image8),T[7],GTK_ICON_SIZE_BUTTON);
        gtk_label_set_text(GTK_LABEL(output),"La modification a été effectué avec succés.");
        gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-ok",GTK_ICON_SIZE_BUTTON);
       }
      }
  else
      {
      gtk_image_set_from_stock(GTK_IMAGE(image1),T[0],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image2),T[1],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image3),T[2],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image4),T[3],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image5),T[4],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image6),T[5],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image7),T[6],GTK_ICON_SIZE_BUTTON);
      gtk_image_set_from_stock(GTK_IMAGE(image8),T[7],GTK_ICON_SIZE_BUTTON);
      gtk_label_set_text(GTK_LABEL(output),"La modification a été échoué.");
      gtk_image_set_from_stock(GTK_IMAGE(imgprin),"gtk-dialog-warning",GTK_ICON_SIZE_BUTTON);
      }
}

on_treeview3_diet_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

void
on_treeview4_diet_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *entry, *entry2, *entry3, *entry4, *entry44, *entry5, *entry6, *entry7;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string, *string1, *string2, *string3, *string4;
  gchar *string5, *string6, *string7;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  gtk_tree_model_get(model,&iter,0,&string,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);
  gtk_tree_model_get(model,&iter,3,&string3,-1);
  gtk_tree_model_get(model,&iter,4,&string4,-1);
  gtk_tree_model_get(model,&iter,5,&string5,-1);
  gtk_tree_model_get(model,&iter,6,&string6,-1);
  gtk_tree_model_get(model,&iter,7,&string7,-1);

  entry = lookup_widget(GTK_TREE_VIEW(treeview),"entry1_diet");
  entry2 = lookup_widget(GTK_TREE_VIEW(treeview),"entry2_diet");
  entry3 = lookup_widget(GTK_TREE_VIEW(treeview),"entry3_diet");
  entry4 = lookup_widget(GTK_TREE_VIEW(treeview),"entry70_diet");
  entry44 = lookup_widget(GTK_TREE_VIEW(treeview),"entry4_d");
  entry5 = lookup_widget(GTK_TREE_VIEW(treeview),"entry5_d");
  entry6 = lookup_widget(GTK_TREE_VIEW(treeview),"entry1_dd");
  entry7 = lookup_widget(GTK_TREE_VIEW(treeview),"entry2_dd");

  gtk_entry_set_text(GTK_ENTRY(entry),string);
  gtk_entry_set_text(GTK_ENTRY(entry2),string1);
  gtk_entry_set_text(GTK_ENTRY(entry3),string2);
  gtk_entry_set_text(GTK_ENTRY(entry4),string3);
  gtk_entry_set_text(GTK_ENTRY(entry44),string4);
  gtk_entry_set_text(GTK_ENTRY(entry5),string5);
  gtk_entry_set_text(GTK_ENTRY(entry6),string6);
  gtk_entry_set_text(GTK_ENTRY(entry7),string7);
}


void
on_afficher_fichesmeddiet_clicked      (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *liste;
  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview4_diet");

  select_page(toolbutton,1,"notebook1_diet");
  affichage3(liste);
}

void
on_affichercommun_diet_clicked         (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *liste;
  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview3_diet");


  /*affichage4(liste);
  select_page(toolbutton,2,"notebook1_diet");*/
}

void
on_chargerrendez_diet_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  FILE *f;
    GtkComboBox *combo1, *combo3, *combo2;
    int i,j, TH[2],TH1[2],TH2[2];
    char jour [20];
    char HEURE[3][20], CABINET[2][20];

    strcpy(HEURE[0],"8-12");
    strcpy(HEURE[1],"14-16");

    strcpy(CABINET[0],"Cabinet A");
    strcpy(CABINET[1],"Cabinet B");

    combo3 = lookup_widget(GTK_WIDGET(button),"combobox3_d");
    combo1 = lookup_widget(GTK_WIDGET(button),"combobox1_d");
    combo2 = lookup_widget(GTK_WIDGET(button),"combobox2_d");

    f = fopen("cal_diet.txt","r");

    for (i=0;i<8;i++)
        gtk_combo_box_remove_text(combo3,i);

    if (f != NULL &&  gtk_combo_box_get_active(combo2) != -1) {

      while (fscanf(f,"%s %d %d %d %d",jour,&TH[0],&TH[1],&TH1[0],&TH2[0]) != EOF){
            if (strcmp(gtk_combo_box_get_active_text(combo1),jour)==0) {
                if (strcmp(gtk_combo_box_get_active_text(combo2),"14-16")==0 && TH2[0]==1)
                    gtk_combo_box_append_text(GTK_COMBO_BOX(combo3),"Cabinet A");
                if (strcmp(gtk_combo_box_get_active_text(combo2),"8-12")==0 && TH1[0]==1)
                    gtk_combo_box_append_text(GTK_COMBO_BOX(combo3),"Cabinet A");

                }
              }
            }
    fclose(f);

}


void
on_validerrend_diet_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combo1, *combo2, *combo3;

GtkWidget *liste;
char cin[8];
int i;

liste = lookup_widget(GTK_WIDGET(button),"treeview15_dd");

combo1 = lookup_widget(GTK_WIDGET(button),"combobox1_d");
combo2 = lookup_widget(GTK_WIDGET(button),"combobox2_d");
combo3 = lookup_widget(GTK_WIDGET(button),"combobox3_d");


FILE *f;

f = fopen("rdv_diet.txt","a+");
tmp_cin(cin);
if (gtk_combo_box_get_active(combo1) != -1 && gtk_combo_box_get_active(combo2) != -1 && gtk_combo_box_get_active(combo3) != -1) {
  if (f != NULL) {
      fprintf(f,"%s %s %s %s\n",cin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)),gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)),gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo3)));
      mod_cal_diet(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)),gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)));
    }
    for (i=0;i<8;i++) {
        gtk_combo_box_remove_text(combo2,i);
        gtk_combo_box_remove_text(combo3,i);
        }
}
fclose(f);

affichage4_rdv_diet(liste);

}


void
on_combobox1_d_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
  FILE *f;
  GtkComboBox *combo, *combo3;
  int i, TH[2],TH1[2],TH2[2];
  char jour [20];
  char HEURE[3][20];

  strcpy(HEURE[0],"8-12");
  strcpy(HEURE[1],"14-16");

  combo = lookup_widget(combobox,"combobox2_d");
  combo3 = lookup_widget(combobox,"combobox3_d");

  f = fopen("cal_diet.txt","r");

  for (i=0;i<8;i++) {
      gtk_combo_box_remove_text(combo,i);
      gtk_combo_box_remove_text(combo3,i);
      }

  if (f != NULL) {
    while (fscanf(f,"%s %d %d %d %d",jour,&TH[0],&TH[1],&TH1[0],&TH1[1],&TH2[0],&TH2[1]) != EOF){
      if (strcmp(gtk_combo_box_get_active_text(combobox),jour) == 0) {

        for (i=0;i<8;i++) {
            gtk_combo_box_remove_text(combo,i);
            gtk_combo_box_remove_text(combo3,i);
            }

        for (i=0;i<2;i++) {
            if (TH[i]==1)
            gtk_combo_box_append_text(combo,HEURE[i]);
         }
       }
     }
   }
  fclose(f);
}

void
on_treeview15_dd_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  gchar *string, *string1, *string2, *string3;
  GtkTreeIter iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  gtk_tree_model_get(model,&iter,0,&string,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);

  FILE *f = fopen("rdv_tmp.txt","w");

  if (f != NULL)
  fprintf(f,"%s %s %s",string,string1,string2);
  fclose(f);
}


void
on_suprimerrdv_dd_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f;
char jour1[20],heure1[20],cabinet1[20], a1[20];
sup_rdv_diet();
f = fopen("rdv_tmp.txt","r");
if (f!=NULL);
fscanf(f,"%s %s %s %s",jour1,heure1,cabinet1,a1);
mod_cal_diet_sup(jour1,heure1);


GtkWidget *liste;
liste = lookup_widget(GTK_WIDGET(button),"treeview15_dd");

affichage4_rdv_diet(liste);
}

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
input10=lookup_widget(objet_graphique,"entry8");


input40=lookup_widget(objet_graphique,"entry7");
input50=lookup_widget(objet_graphique,"entry40");
combobox1=lookup_widget(objet_graphique,"combobox_ay100");



strcpy(password,gtk_entry_get_text(GTK_ENTRY(input10)));


strcpy(login,gtk_entry_get_text(GTK_ENTRY(input40)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input50)));
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
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter,3, &cin,0,&login,1,&password,2,&role,-1);
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
