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

on_toolbutton6s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
}



on_toolbutton1s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook,*treeview;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook1s");
  treeview= lookup_widget(GTK_WIDGET(toolbutton),"treeview350s");
  gtk_notebook_set_current_page(notebook,0);
  afficher_calendrier(treeview);
}


/*void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  GtkWidget *entry2s;

        entry2s = lookup_widget(GTK_WIDGET(togglebutton),"entry2s");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
        gtk_entry_set_visibility (GTK_ENTRY (entry2s), TRUE);
        else
        gtk_entry_set_visibility (GTK_ENTRY (entry2s), FALSE);
}*/

void
on_toolbutton3s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
  GtkWidget *notebook;
  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook1s");
  gtk_notebook_set_current_page(notebook,2);

}



void
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
		/*supprimer_rdv(date,heure,salle) ;*/
	}
	fclose(f);

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
  afficher_rdv(treeview1);

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
afficher_rdv(treeview1);


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
  
	GtkWidget *input1 , *input2, *input3 ,  *input4,*input5;
	GtkWidget *combobox1;
	GtkWidget *day , *month, *year;
	GtkWidget *input6,*input7,*input8,*input9;
	date ddn;
	fp x;
char cin[30];
char nom[50],nom1[50],prenom[50],prenom1[50],age[10],taille[10],pouls[10],psys[10],pdia[10];
  input1=lookup_widget(GTK_WIDGET(toolbutton),"entry100s");
  input2=lookup_widget(GTK_WIDGET(toolbutton),"entry200s");
  input3=lookup_widget(GTK_WIDGET(toolbutton),"entry800s");
  input4=lookup_widget(GTK_WIDGET(toolbutton),"entry400s");
  input5=lookup_widget(GTK_WIDGET(toolbutton),"entry1000s");
  input6=lookup_widget(GTK_WIDGET(toolbutton),"entry3000s");
  input7=lookup_widget(GTK_WIDGET(toolbutton),"entry3001s");
  input8=lookup_widget(GTK_WIDGET(toolbutton),"entry3002s");
  input9=lookup_widget(GTK_WIDGET(toolbutton),"entry3003s");

  combobox1=lookup_widget(GTK_WIDGET(toolbutton),"combobox13s");

  day=lookup_widget(GTK_WIDGET(toolbutton),"spinbutton10s");
  month=lookup_widget(GTK_WIDGET(toolbutton),"spinbutton20s");
  year=lookup_widget(GTK_WIDGET(toolbutton),"spinbutton30s");

  FILE *f,*g;
tmp_cin(cin);
  	
  f=fopen("adherents.txt","r");
  if(f != NULL)
  {
    while ((fscanf(f,"%s %s %s %d %d %d %s %s %s",x.cin,x.nom,x.prenom,&ddn.day,
    &ddn.month,&ddn.year,x.tel,x.mail,x.sexe)!=EOF))
    {
    	if(strcmp(cin,x.cin)==0)
    	{
    		gtk_entry_set_text(GTK_ENTRY(input1),x.nom);
    		gtk_entry_set_text(GTK_ENTRY(input2),x.prenom);
		gtk_entry_set_text(GTK_ENTRY(input3),x.cin);
		gtk_entry_set_text(GTK_ENTRY(input4),x.tel);
		gtk_entry_set_text(GTK_ENTRY(input5),x.mail);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(day),x.ddn.day);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(month),x.ddn.month);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(year),x.ddn.year);
		if (strcmp(x.sexe,"Femme")==0)
			gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1),1);
		else
			gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1),0);	
	}

    }
  }
fclose(f);

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));

g=fopen("fiche_med.txt","r");
if(g != NULL){
while(fscanf(g,"%s %s %s %s %s %s %s",nom1,prenom1,age,taille,pouls,psys,pdia) != EOF)
{
	if((strcmp(nom1,nom)==0) && (strcmp(prenom1,prenom)==0))
	{
		
		gtk_entry_set_text(GTK_ENTRY(input6),taille);
    		gtk_entry_set_text(GTK_ENTRY(input9),pouls);
		gtk_entry_set_text(GTK_ENTRY(input8),psys);
		gtk_entry_set_text(GTK_ENTRY(input7),pdia);
	}
}
		
}
fclose(g);
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
    

    input1=lookup_widget(GTK_WIDGET(button),"entry100s");
    input2=lookup_widget(GTK_WIDGET(button),"entry200s");
    input3=lookup_widget(GTK_WIDGET(button),"entry800s");
    input4=lookup_widget(GTK_WIDGET(button),"entry400s");
    input5=lookup_widget(GTK_WIDGET(button),"entry1000s");
    
    combobox1=lookup_widget(GTK_WIDGET(button),"combobox13s");

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

tmp_cin(cin);
mod_profil_adh (x, cin);


}

void
on_toolbutton5s_clicked                (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
GtkWidget *notebook, *treeview2;

  notebook = lookup_widget(GTK_WIDGET(toolbutton),"notebook1s");
  gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),4);
  treeview2=lookup_widget(GTK_WIDGET(toolbutton),"treeview2s");
 afficher_staff2(treeview2);
}

void
on_window3s_show                       (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget *input1 , *input2, *input3 ,  *input4,*input5;
GtkWidget *combobox1;
GtkWidget *day , *month, *year;
date ddn;
fp x;
char cin[30];
  input1=lookup_widget(GTK_WIDGET(widget),"entry100s");
  input2=lookup_widget(GTK_WIDGET(widget),"entry200s");
  input3=lookup_widget(GTK_WIDGET(widget),"entry800s");
  input4=lookup_widget(GTK_WIDGET(widget),"entry400s");
  input5=lookup_widget(GTK_WIDGET(widget),"entry1000s");

  combobox1=lookup_widget(GTK_WIDGET(widget),"combobox13s");

  day=lookup_widget(GTK_WIDGET(widget),"spinbutton10s");
  month=lookup_widget(GTK_WIDGET(widget),"spinbutton20s");
  year=lookup_widget(GTK_WIDGET(widget),"spinbutton30s");

  FILE *f,*g;
  g=fopen("tmp.txt","r");
  	scanf(g,"%s",cin);
  	
  f=fopen("adherents.txt","r");
  if(f != NULL)
  {
    while ((fscanf(f,"%s %s %s %d %d %d %s %s ",x.cin,x.nom,x.prenom,&ddn.day,
    &ddn.month,&ddn.year,x.tel,x.mail)!=EOF))
    {
    	if(strcmp(cin,x.cin)==0)
    	{
    		gtk_entry_set_text(GTK_ENTRY("entry100s"),x.nom);
    		gtk_entry_set_text(GTK_ENTRY("entry200s"),x.prenom);
		gtk_entry_set_text(GTK_ENTRY("entry800s"),x.cin);
		gtk_entry_set_text(GTK_ENTRY("entry400s"),x.tel);
		gtk_entry_set_text(GTK_ENTRY("entry1000s"),x.mail);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(day),ddn.day);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(month),ddn.month);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(year),ddn.year);
		gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1),x.sexe);
	}

    }
  }
fclose(f);

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
  
  label0 = lookup_widget(GTK_TREE_VIEW(treeview),"label161");
  label1 = lookup_widget(GTK_TREE_VIEW(treeview),"label162");
  label2 = lookup_widget(GTK_TREE_VIEW(treeview),"label163");
  label3 = lookup_widget(GTK_TREE_VIEW(treeview),"label164");
  label4 = lookup_widget(GTK_TREE_VIEW(treeview),"label165");
  label5 = lookup_widget(GTK_TREE_VIEW(treeview),"label160");
  

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
GtkWidget *treeview;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20],cours[10];
 char type1[30], nom1[50], prenom1[50],date1[30],heure1[30],salle1[20],cours1[10];
FILE *f,*g;

labelm1=lookup_widget(GTK_WIDGET(button),"label1009s");
labelm2=lookup_widget(GTK_WIDGET(button),"label1013s");
labelm3=lookup_widget(GTK_WIDGET(button),"label1014s");
labelm4=lookup_widget(GTK_WIDGET(button),"label1015s");
labelm5=lookup_widget(GTK_WIDGET(button),"label1016s");
labelm6=lookup_widget(GTK_WIDGET(button),"label1017s");
image=lookup_widget(GTK_WIDGET(button),"image181s");

output =lookup_widget(GTK_WIDGET(button),"label37s");
treeview=lookup_widget(GTK_WIDGET(button),"treeview40s");


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
			actualiser_dispo_med(date,heure,salle) ;
			afficher_med(treeview);
			
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
GtkWidget *treeview;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20],cours[10];;
FILE *f,*g;

labeld1=lookup_widget(GTK_WIDGET(button),"label529s");
labeld2=lookup_widget(GTK_WIDGET(button),"label558s");
labeld3=lookup_widget(GTK_WIDGET(button),"label187s");
labeld4=lookup_widget(GTK_WIDGET(button),"label573s");
labeld5=lookup_widget(GTK_WIDGET(button),"label584s");
labeld6=lookup_widget(GTK_WIDGET(button),"label606s");
treeview=lookup_widget(GTK_WIDGET(button),"treeview20s");
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
		actualiser_dispo_diet(date,heure,salle) ;
		afficher_diet(treeview);
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
GtkWidget *treeview;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20],cours[10],cin1[10],cin2[50],nom2[50],prenom2[50],date2[30],tel[30],sexe[20];
FILE *f,*g,*k;




labelk1=lookup_widget(GTK_WIDGET(button),"label1000s");
labelk2=lookup_widget(GTK_WIDGET(button),"label1004s");
labelk3=lookup_widget(GTK_WIDGET(button),"label1005s");
labelk4=lookup_widget(GTK_WIDGET(button),"label1006s");
labelk5=lookup_widget(GTK_WIDGET(button),"label1007s");
labelk6=lookup_widget(GTK_WIDGET(button),"label1008s");
image=lookup_widget(GTK_WIDGET(button),"image181s");

output =lookup_widget(GTK_WIDGET(button),"label37s");
treeview=lookup_widget(GTK_WIDGET(button),"treeview30s");


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
		actualiser_dispo_kine(date,heure,salle) ;
		afficher_kine(treeview);
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
GtkWidget *treeview;
char type[30], nom[50], prenom[50],date[30],heure[30],salle[20],cours[50],cin1[10],cin2[50],nom2[50],prenom2[50],date2[30],tel[30],sexe[20];
FILE *f,*g,*k;
labelc1=lookup_widget(GTK_WIDGET(button),"label1019s");
labelc2=lookup_widget(GTK_WIDGET(button),"label161");
labelc3=lookup_widget(GTK_WIDGET(button),"label162");
labelc4=lookup_widget(GTK_WIDGET(button),"label163");
labelc5=lookup_widget(GTK_WIDGET(button),"label164");
labelc6=lookup_widget(GTK_WIDGET(button),"label165");
labelc7=lookup_widget(GTK_WIDGET(button),"label160");
image=lookup_widget(GTK_WIDGET(button),"image181s");

output =lookup_widget(GTK_WIDGET(button),"label37s");
treeview=lookup_widget(GTK_WIDGET(button),"treeview10s");


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
		actualiser_dispo_coach2(date,heure,salle) ;
		/*afficher_coach(treeview);*/
	}
	fclose(f);
	
}


void
on_treeview1s_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *label0,*label1,*label2,*label3,*label4,*label5,*label6;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string0, *string1, *string2, *string3, *string4,*string5,*string6;

  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  
  gtk_tree_model_get(model,&iter,0,&string0,-1);
  gtk_tree_model_get(model,&iter,1,&string1,-1);
  gtk_tree_model_get(model,&iter,2,&string2,-1);
  gtk_tree_model_get(model,&iter,3,&string3,-1);
  gtk_tree_model_get(model,&iter,4,&string4,-1);
  gtk_tree_model_get(model,&iter,5,&string5,-1);
  gtk_tree_model_get(model,&iter,6,&string6,-1);
  
  label0 = lookup_widget(GTK_TREE_VIEW(treeview),"label2001s");
  label1 = lookup_widget(GTK_TREE_VIEW(treeview),"label2002s");
  label2 = lookup_widget(GTK_TREE_VIEW(treeview),"label2004s");
  label3 = lookup_widget(GTK_TREE_VIEW(treeview),"label2006s");
  label4 = lookup_widget(GTK_TREE_VIEW(treeview),"label2008s");

  

  gtk_label_set_text(GTK_LABEL(label0),string1);
  gtk_label_set_text(GTK_LABEL(label1),string2);
  gtk_label_set_text(GTK_LABEL(label2),string3);
  gtk_label_set_text(GTK_LABEL(label3),string4);
  gtk_label_set_text(GTK_LABEL(label4),string5);
 
}


void
on_button10s_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *label0,*label1,*label2,*label3,*label4,*label5,*label6;
GtkWidget *image;
char date[30];
char heure[30];
char salle[30];
char nom[50];
char prenom[50];
GtkWidget *treeview1;

  label2 = lookup_widget(GTK_TREE_VIEW(button),"label2004s");
  label3 = lookup_widget(GTK_TREE_VIEW(button),"label2006s");
  label4 = lookup_widget(GTK_TREE_VIEW(button),"label2008s");
  label0 = lookup_widget(GTK_TREE_VIEW(button),"label2009s");
  image=lookup_widget(GTK_WIDGET(button),"image2250s");
treeview1=lookup_widget(GTK_WIDGET(button),"treeview1s");
        strcpy(date,gtk_label_get_text(GTK_LABEL(label2)));
	strcpy(heure,gtk_label_get_text(GTK_LABEL(label3)));
	strcpy(salle,gtk_label_get_text(GTK_LABEL(label4)));

	

	gtk_label_set_text(GTK_LABEL(label0),"Rendez_vous annulé\n   avec succés");
	gtk_image_set_from_stock(GTK_IMAGE(image),"gtk-ok",GTK_ICON_SIZE_BUTTON);
	annuler_rdv2(date,heure,salle) ;
        afficher_rdv(treeview1);
  
	
}


void
on_treeview350s_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *string0;
  GtkWidget *cal;
  char event[70];
  int day1,month1,year1,day,month,year;
  char heure1[30],heure2[30],event1[70];
  FILE *f;
  model = gtk_tree_view_get_model(treeview);
  gtk_tree_model_get_iter(model,&iter,path);
  cal=lookup_widget(GTK_WIDGET(treeview),"calendar1s");
  gtk_tree_model_get(model,&iter,0,&string0,-1);
  strcpy(event,string0);
   f=fopen("calendrier.txt","r");
   if(f != NULL)
   {
   while(fscanf(f,"%d/%d/%d %s %s %s",&day1,&month1,&year1,heure1,heure2,event1) != EOF)
   {
   	if(strcmp(event,event1)==0)
   	{
   		day=day1;
   		month=month1-1;
   		year=year1;
   	}
   }
   fclose(f);
   }
  gtk_calendar_select_day(GTK_CALENDAR(cal),day);  
  gtk_calendar_select_month(GTK_CALENDAR(cal),month,year);

 
 }

