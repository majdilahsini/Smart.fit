#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ntbook.h"
#include "fonction.h"


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
select_page(toolbutton,4,"notebookmain_diet");
}


void
on_dec_diet_clicked                    (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{

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


  gtk_entry_set_text(GTK_ENTRY(entry),string);
  gtk_entry_set_text(GTK_ENTRY(entry2),string1);
  gtk_entry_set_text(GTK_ENTRY(entry3),string2);
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
on_treeview3_diet_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *entry, *entry2, *entry3, *entry4, *entry5;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string, *string1, *string2, *string3, *string4;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  gtk_tree_model_get(model,&iter,0,&string,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);
  gtk_tree_model_get(model,&iter,3,&string3,-1);


  entry = lookup_widget(GTK_TREE_VIEW(treeview),"entry1_diet");
  entry2 = lookup_widget(GTK_TREE_VIEW(treeview),"entry2_diet");
  entry3 = lookup_widget(GTK_TREE_VIEW(treeview),"entry3_diet");
  entry4 = lookup_widget(GTK_TREE_VIEW(treeview),"entry4_diet");


  gtk_entry_set_text(GTK_ENTRY(entry),string);
  gtk_entry_set_text(GTK_ENTRY(entry2),string1);
  gtk_entry_set_text(GTK_ENTRY(entry3),string2);
  gtk_entry_set_text(GTK_ENTRY(entry4),string3);
}

void
on_ajouterfiche_diet_clicked           (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *entry, *entry2, *entry3, *entry4, *entry5, *entry6, *entry7, *entry8;
  GtkWidget *liste;
  char cin[20], poid[20], taille[20];
  f_diet a;
  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview2_diet");

  entry3 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet3");
  entry4 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet4");
  entry5 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet5");
  entry6 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet6");
  entry7 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet7");
  entry8 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet8");

  strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(entry3)));
  strcpy(a.poid,gtk_entry_get_text(GTK_ENTRY(entry4)));
  strcpy(a.taille,gtk_entry_get_text(GTK_ENTRY(entry5)));
  strcpy(a.icm,gtk_entry_get_text(GTK_ENTRY(entry6)));
  strcpy(a.tdt,gtk_entry_get_text(GTK_ENTRY(entry7)));
  strcpy(a.regime,gtk_entry_get_text(GTK_ENTRY(entry8)));

  ajoufich_diet(a);

  affichage2(liste);
  select_page(toolbutton,2,"affichagebook_diet");
}

void
on_suprimerfiche_diet_clicked          (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *entry3, *entry4, *entry5;
  GtkWidget *liste;
  char cin[20], poid[20], taille[20];
  f_diet a;
  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview2_diet");

  entry3 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet3");
  strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(entry3)));

  suprfich_diet(a.cin);
  affichage2(liste);
  select_page(toolbutton,2,"affichagebook_diet");
}

void
on_modifierfiche_diet_clicked          (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *entry3, *entry4, *entry5;
  GtkWidget *liste;
  char cin[20], poid[20], taille[20];
  f_diet a;
  liste = lookup_widget(GTK_WIDGET(toolbutton),"treeview2_diet");

  entry3 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet3");
  entry4 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet4");
  entry5 = lookup_widget(GTK_WIDGET(toolbutton),"entryfiche_diet5");

  strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(entry3)));
  strcpy(a.poid,gtk_entry_get_text(GTK_ENTRY(entry4)));
  strcpy(a.taille,gtk_entry_get_text(GTK_ENTRY(entry5)));

  modfich_diet(a);
  affichage2(liste);
  select_page(toolbutton,2,"affichagebook_diet");
}
