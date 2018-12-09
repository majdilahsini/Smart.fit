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



/*void
on_button7s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelk1,*labelk2,*labelk3,*labelk4,*labelk5,*labelk6;
GtkWidget *output;
GtkWidget *image;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20];
FILE *f,*g;

labelk1=lookup_widget(GTK_WIDGET(button),"label1000s");
labelk2=lookup_widget(GTK_WIDGET(button),"label1004s");
labelk3=lookup_widget(GTK_WIDGET(button),"label1005s");
labelk4=lookup_widget(GTK_WIDGET(button),"label1006s");
labelk5=lookup_widget(GTK_WIDGET(button),"label1007s");
labelk6=lookup_widget(GTK_WIDGET(button),"label1008s");
image=lookup_widget(GTK_WIDGET(button),"image181s");

output =lookup_widget(GTK_WIDGET(button),"label37s");



	strcpy(type,gtk_label_get_text(GTK_LABEL(labelk1)));
	strcpy(nom,gtk_label_get_text(GTK_LABEL(labelk2)));
	strcpy(prenom,gtk_label_get_text(GTK_LABEL(labelk3)));
	strcpy(date,gtk_label_get_text(GTK_LABEL(labelk4)));
	strcpy(heure,gtk_label_get_text(GTK_LABEL(labelk5)));
	strcpy(salle,gtk_label_get_text(GTK_LABEL(labelk6)));

	f=fopen("rdv_adherent.txt","a+");
	
	if(f != NULL)
	{
		
		fprintf(f,"%s %s %s %s %s %s \n",type,nom,prenom,date,heure,salle);
		gtk_label_set_text(GTK_LABEL(output),"Rendez_vous Validés!");
		gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-ok",GTK_ICON_SIZE_BUTTON);
		/*supprimer_rdv(date,heure,salle) ;
	}
	fclose(f);

}*/

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
  /*afficher1(treeview2);*/
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



void
on_toolbutton10s_clicked               (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
GtkWidget *notebook,*treeview;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook10s");
  gtk_notebook_set_current_page(notebook,0);
   treeview=lookup_widget(GTK_WIDGET(toolbutton),"treeview10s");
  afficher_coach(treeview);
 
}



void
on_treeview10s_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
                                        
{
 GtkWidget *label0,*label1,*label2,*label3,*label4,*label5;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string0, *string1, *string2, *string3, *string4,*string5;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  
  gtk_tree_model_get(model,&iter,0,&string0,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);
  gtk_tree_model_get(model,&iter,3,&string3,-1);
  gtk_tree_model_get(model,&iter,4,&string4,-1);
  gtk_tree_model_get(model,&iter,5,&string5,-1);
  
  label0 = lookup_widget(GTK_TREE_VIEW(treeview),"label1024s");
  label1 = lookup_widget(GTK_TREE_VIEW(treeview),"label1023s");
  label2 = lookup_widget(GTK_TREE_VIEW(treeview),"label1025s");
  label3 = lookup_widget(GTK_TREE_VIEW(treeview),"label1026s");
  label4 = lookup_widget(GTK_TREE_VIEW(treeview),"label1028s");
  label5 = lookup_widget(GTK_TREE_VIEW(treeview),"label1027s");
  

  gtk_label_set_text(GTK_LABEL(label0),string0);
  gtk_label_set_text(GTK_LABEL(label1),string1);
  gtk_label_set_text(GTK_LABEL(label2),string2);
  gtk_label_set_text(GTK_LABEL(label3),string3);
  gtk_label_set_text(GTK_LABEL(label4),string4);
  gtk_label_set_text(GTK_LABEL(label5),string5);
 
}


void
on_toolbutton11s_clicked               (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook,*treeview;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook10s");
  gtk_notebook_set_current_page(notebook,2);
  treeview=lookup_widget(GTK_WIDGET(toolbutton),"treeview20s");
  afficher_diet(treeview);
}


void
on_treeview20s_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *label0,*label1,*label2,*label3,*label4;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string0, *string1, *string2, *string3, *string4;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  
  gtk_tree_model_get(model,&iter,0,&string0,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);
  gtk_tree_model_get(model,&iter,3,&string3,-1);
  gtk_tree_model_get(model,&iter,4,&string4,-1);
  
  label0 = lookup_widget(GTK_TREE_VIEW(treeview),"label558s");
  label1 = lookup_widget(GTK_TREE_VIEW(treeview),"label187s");
  label2 = lookup_widget(GTK_TREE_VIEW(treeview),"label573s");
  label3 = lookup_widget(GTK_TREE_VIEW(treeview),"label584s");
  label4 = lookup_widget(GTK_TREE_VIEW(treeview),"label606s");
  

  gtk_label_set_text(GTK_LABEL(label0),string0);
  gtk_label_set_text(GTK_LABEL(label1),string1);
  gtk_label_set_text(GTK_LABEL(label2),string2);
  gtk_label_set_text(GTK_LABEL(label3),string3);
  gtk_label_set_text(GTK_LABEL(label4),string4);
  
}


void
on_toolbutton12s_clicked               (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook,*treeview;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook10s");
  gtk_notebook_set_current_page(notebook,3);
  treeview=lookup_widget(GTK_WIDGET(toolbutton),"treeview30s");
  afficher_kine(treeview);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *label0,*label1,*label2,*label3,*label4;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string0, *string1, *string2, *string3, *string4;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  
  gtk_tree_model_get(model,&iter,0,&string0,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);
  gtk_tree_model_get(model,&iter,3,&string3,-1);
  gtk_tree_model_get(model,&iter,4,&string4,-1);
  
  label0 = lookup_widget(GTK_TREE_VIEW(treeview),"label1004s");
  label1 = lookup_widget(GTK_TREE_VIEW(treeview),"label1005s");
  label2 = lookup_widget(GTK_TREE_VIEW(treeview),"label1006s");
  label3 = lookup_widget(GTK_TREE_VIEW(treeview),"label1007s");
  label4 = lookup_widget(GTK_TREE_VIEW(treeview),"label1008s");
  

  gtk_label_set_text(GTK_LABEL(label0),string0);
  gtk_label_set_text(GTK_LABEL(label1),string1);
  gtk_label_set_text(GTK_LABEL(label2),string2);
  gtk_label_set_text(GTK_LABEL(label3),string3);
  gtk_label_set_text(GTK_LABEL(label4),string4);
}


void
on_toolbutton13s_clicked               (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook,*treeview;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook10s");
  gtk_notebook_set_current_page(notebook,1);
  treeview=lookup_widget(GTK_WIDGET(toolbutton),"treeview40s");
  afficher_med(treeview);
}


void
on_treeview40s_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *label0,*label1,*label2,*label3,*label4;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string0, *string1, *string2, *string3, *string4;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  
  gtk_tree_model_get(model,&iter,0,&string0,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);
  gtk_tree_model_get(model,&iter,3,&string3,-1);
  gtk_tree_model_get(model,&iter,4,&string4,-1);
  
  label0 = lookup_widget(GTK_TREE_VIEW(treeview),"label1013s");
  label1 = lookup_widget(GTK_TREE_VIEW(treeview),"label1014s");
  label2 = lookup_widget(GTK_TREE_VIEW(treeview),"label1015s");
  label3 = lookup_widget(GTK_TREE_VIEW(treeview),"label1016s");
  label4 = lookup_widget(GTK_TREE_VIEW(treeview),"label1017s");
  

  gtk_label_set_text(GTK_LABEL(label0),string0);
  gtk_label_set_text(GTK_LABEL(label1),string1);
  gtk_label_set_text(GTK_LABEL(label2),string2);
  gtk_label_set_text(GTK_LABEL(label3),string3);
  gtk_label_set_text(GTK_LABEL(label4),string4);
}







void
on_button110s_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelm1,*labelm2,*labelm3,*labelm4,*labelm5,*labelm6;
GtkWidget *output;
GtkWidget *image;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20],cours[10];
FILE *f,*g;

labelm1=lookup_widget(GTK_WIDGET(button),"label1009s");
labelm2=lookup_widget(GTK_WIDGET(button),"label1013s");
labelm3=lookup_widget(GTK_WIDGET(button),"label1014s");
labelm4=lookup_widget(GTK_WIDGET(button),"label1015s");
labelm5=lookup_widget(GTK_WIDGET(button),"label1016s");
labelm6=lookup_widget(GTK_WIDGET(button),"label1017s");
image=lookup_widget(GTK_WIDGET(button),"image181s");

output =lookup_widget(GTK_WIDGET(button),"label37s");



	strcpy(type,gtk_label_get_text(GTK_LABEL(labelm1)));
	strcpy(nom,gtk_label_get_text(GTK_LABEL(labelm2)));
	strcpy(prenom,gtk_label_get_text(GTK_LABEL(labelm3)));
	strcpy(date,gtk_label_get_text(GTK_LABEL(labelm4)));
	strcpy(heure,gtk_label_get_text(GTK_LABEL(labelm5)));
	strcpy(salle,gtk_label_get_text(GTK_LABEL(labelm6)));
	strcpy(cours,"check-up");
	f=fopen("rdv_adherent.txt","a+");
	
	if(f != NULL)
	{
		
		fprintf(f,"%s %s %s %s %s %s %s \n",type,nom,prenom,date,heure,salle,cours);
		gtk_label_set_text(GTK_LABEL(output),"Rendez_vous Validés!");
		gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-ok",GTK_ICON_SIZE_BUTTON);
		/*supprimer_rdv(date,heure,salle) ;*/
	}
	fclose(f);
}


void
on_button90s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labeld1,*labeld2,*labeld3,*labeld4,*labeld5,*labeld6;
GtkWidget *output;
GtkWidget *image;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20],cours[10];;
FILE *f,*g;

labeld1=lookup_widget(GTK_WIDGET(button),"label529s");
labeld2=lookup_widget(GTK_WIDGET(button),"label558s");
labeld3=lookup_widget(GTK_WIDGET(button),"label187s");
labeld4=lookup_widget(GTK_WIDGET(button),"label573s");
labeld5=lookup_widget(GTK_WIDGET(button),"label584s");
labeld6=lookup_widget(GTK_WIDGET(button),"label606s");
image=lookup_widget(GTK_WIDGET(button),"image181s");

output =lookup_widget(GTK_WIDGET(button),"label37s");



	strcpy(type,gtk_label_get_text(GTK_LABEL(labeld1)));
	strcpy(nom,gtk_label_get_text(GTK_LABEL(labeld2)));
	strcpy(prenom,gtk_label_get_text(GTK_LABEL(labeld3)));
	strcpy(date,gtk_label_get_text(GTK_LABEL(labeld4)));
	strcpy(heure,gtk_label_get_text(GTK_LABEL(labeld5)));
	strcpy(salle,gtk_label_get_text(GTK_LABEL(labeld6)));
	strcpy(cours,"check-up");
	f=fopen("rdv_adherent.txt","a+");
	
	if(f != NULL)
	{
		
		fprintf(f,"%s %s %s %s %s %s %s \n",type,nom,prenom,date,heure,salle,cours);
		gtk_label_set_text(GTK_LABEL(output),"Rendez_vous Validés!");
		gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-ok",GTK_ICON_SIZE_BUTTON);
		/*supprimer_rdv(date,heure,salle) ;*/
	}
	fclose(f);
}


void
on_button150s_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelk1,*labelk2,*labelk3,*labelk4,*labelk5,*labelk6;
GtkWidget *output;
GtkWidget *image;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20],cours[10];
FILE *f,*g;

labelk1=lookup_widget(GTK_WIDGET(button),"label1000s");
labelk2=lookup_widget(GTK_WIDGET(button),"label1004s");
labelk3=lookup_widget(GTK_WIDGET(button),"label1005s");
labelk4=lookup_widget(GTK_WIDGET(button),"label1006s");
labelk5=lookup_widget(GTK_WIDGET(button),"label1007s");
labelk6=lookup_widget(GTK_WIDGET(button),"label1008s");
image=lookup_widget(GTK_WIDGET(button),"image181s");

output =lookup_widget(GTK_WIDGET(button),"label37s");



	strcpy(type,gtk_label_get_text(GTK_LABEL(labelk1)));
	strcpy(nom,gtk_label_get_text(GTK_LABEL(labelk2)));
	strcpy(prenom,gtk_label_get_text(GTK_LABEL(labelk3)));
	strcpy(date,gtk_label_get_text(GTK_LABEL(labelk4)));
	strcpy(heure,gtk_label_get_text(GTK_LABEL(labelk5)));
	strcpy(salle,gtk_label_get_text(GTK_LABEL(labelk6)));
	strcpy(cours,"check-up");
	f=fopen("rdv_adherent.txt","a+");
	
	if(f != NULL)
	{
		
		fprintf(f,"%s %s %s %s %s %s %s \n",type,nom,prenom,date,heure,salle,cours);
		gtk_label_set_text(GTK_LABEL(output),"Rendez_vous Validés!");
		gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-ok",GTK_ICON_SIZE_BUTTON);
		/*supprimer_rdv(date,heure,salle) ;*/
	}
	fclose(f);
}


void
on_button120s_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelc1,*labelc2,*labelc3,*labelc4,*labelc5,*labelc6,*labelc7;
GtkWidget *output;
GtkWidget *image;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20],cours[50];
FILE *f,*g;

labelc1=lookup_widget(GTK_WIDGET(button),"label1019s");
labelc2=lookup_widget(GTK_WIDGET(button),"label1024s");
labelc3=lookup_widget(GTK_WIDGET(button),"label1023s");
labelc4=lookup_widget(GTK_WIDGET(button),"label1026s");
labelc5=lookup_widget(GTK_WIDGET(button),"label1028s");
labelc6=lookup_widget(GTK_WIDGET(button),"label1027s");
labelc7=lookup_widget(GTK_WIDGET(button),"label1025s");
image=lookup_widget(GTK_WIDGET(button),"image181s");

output =lookup_widget(GTK_WIDGET(button),"label37s");



	strcpy(type,gtk_label_get_text(GTK_LABEL(labelc1)));
	strcpy(nom,gtk_label_get_text(GTK_LABEL(labelc2)));
	strcpy(prenom,gtk_label_get_text(GTK_LABEL(labelc3)));
	strcpy(date,gtk_label_get_text(GTK_LABEL(labelc4)));
	strcpy(heure,gtk_label_get_text(GTK_LABEL(labelc5)));
	strcpy(salle,gtk_label_get_text(GTK_LABEL(labelc6)));
	strcpy(cours,gtk_label_get_text(GTK_LABEL(labelc7)));

	f=fopen("rdv_adherent.txt","a+");
	
	if(f != NULL)
	{
		
		fprintf(f,"%s %s %s %s %s %s %s \n",type,nom,prenom,date,heure,salle,cours);
		gtk_label_set_text(GTK_LABEL(output),"Rendez_vous Validés!");
		gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-ok",GTK_ICON_SIZE_BUTTON);
		/*supprimer_rdv(date,heure,salle) ;*/
	}
	fclose(f);
}

