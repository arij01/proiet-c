#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "login.c"
#include <string.h>
#include <stdio.h>
#include "fonction.c"
 int choix = 0 ;

void
on_button_AKlogin_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

  int n=150,check = -1;
     char b[70]="Bienvenue dans l'space de gestion de stock: ";
     char c[50]="mot de passe ou login incorrect";
     GtkWidget *input1;
     GtkWidget *input2;
     GtkWidget *output1;
     GtkWidget *output2;
     GtkWidget *Login_bienvenue;
     GtkWidget *Login_gestionstock;


     Login_bienvenue=create_Login_bienvenue();
     input1=lookup_widget(objet_graphique, "entry_AKusername");
     input2=lookup_widget(objet_graphique, "entry_AKpassword");
     output1=lookup_widget(objet_graphique, "label4");
     Login_gestionstock=lookup_widget(objet_graphique,"Login_gestionstock");
     char nom[20];
     strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
     char pass[20];
     strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input2)));
     check = check_user(nom,pass,n);
     if (check==0){
      gtk_widget_hide(Login_gestionstock);
     strcat(b,nom);
     gtk_widget_show(Login_bienvenue);
     output2=lookup_widget(Login_bienvenue, "label_AKbienvenue");
     gtk_label_set_text(GTK_LABEL(output2),b);
     }else{
     gtk_label_set_text(GTK_LABEL(output1),c);
     }

}


void
on_button_AKquitter1_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button_AKstock_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Login_bienvenue;
  GtkWidget *Ajout_produit;
  Ajout_produit=create_Ajout_produit();
  Login_bienvenue=lookup_widget(objet_graphique,"Login_bienvenue");
  gtk_widget_hide(Login_bienvenue);
  gtk_widget_show(Ajout_produit);
}


void
on_button_AKrupture_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *Login_bienvenue;
	GtkWidget *rupture;
	GtkWidget *treeview_AKrupt;
	Login_bienvenue=lookup_widget(objet_graphique,"Login_bienvenue");
	gtk_widget_destroy(Login_bienvenue);
	rupture=lookup_widget(objet_graphique,"rupture");
	rupture=create_rupture();
	gtk_widget_show(rupture);
	treeview_AKrupt=lookup_widget(rupture,"treeview_AKrupt");
	visualiser(treeview_AKrupt);



}


void
on_button_AKlogout_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Login_gestionstock;
  GtkWidget *Login_bienvenue;
  Login_gestionstock=create_Login_gestionstock();
  Login_bienvenue=lookup_widget(objet_graphique,"Login_bienvenue");
  gtk_widget_hide(Login_bienvenue);
  gtk_widget_show(Login_gestionstock);
}


void
on_button_AKajouter_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


	Stock p;
	GtkWidget *id,*nom,*quantite,*type,*jour, *mois, *annee, *ajouter ;
	

	id=lookup_widget(objet_graphique,"entry_AKid");
	nom=lookup_widget(objet_graphique,"entry_AKnom");
	quantite=lookup_widget(objet_graphique,"entry_AKquantite");
	type=lookup_widget(objet_graphique, "combobox_AKtype");
	jour=lookup_widget(objet_graphique, "spinbutton_AKjour");
	mois=lookup_widget(objet_graphique, "spinbutton_AKmois");
	annee=lookup_widget(objet_graphique, "spinbutton_AKannee");





	
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)));
	strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	
	p.dateexp.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	p.dateexp.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateexp.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));


	AjouterProduit(p);




}









void
on_button_AKafficher_clicked           (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajout_produit;
GtkWidget *Stock;
GtkWidget *treeview_AKstock;
Ajout_produit=lookup_widget(objet_graphique,"Ajout_produit");
gtk_widget_destroy(Ajout_produit);
Stock=lookup_widget(objet_graphique,"Stock");
Stock=create_Stock();
gtk_widget_show(Stock);
treeview_AKstock=lookup_widget(Stock,"treeview_AKstock");
afficher_produit(treeview_AKstock);

}


void
on_button_AKretourajout_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Ajout_produit;
  GtkWidget *Login_bienvenue;
  Login_bienvenue=create_Login_bienvenue();
  Ajout_produit=lookup_widget(objet_graphique,"Ajout_produit");
  gtk_widget_hide(Ajout_produit);
  gtk_widget_show(Login_bienvenue);
}


void
on_button_AKmodif1_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id[50];
  Stock s;
  FILE*f;
  GtkWidget *input;
  GtkWidget *Stock;
  GtkWidget *Modification;
  GtkWidget *output1;
  GtkWidget *output2;
  GtkWidget *output3;
  GtkWidget *output4;
  GtkWidget *output5;
  GtkWidget *output6;
  GtkWidget *output7;
  



  input=lookup_widget(objet_graphique,"entry_AKidmodif");
  strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
  Modification=create_Modification();
  Stock=lookup_widget(objet_graphique,"Stock");
  gtk_widget_hide(Stock);
  gtk_widget_show(Modification);
  output1=lookup_widget(Modification,"entry_AKid1");
  output2=lookup_widget(Modification,"entry_AKnom1");
  output3=lookup_widget(Modification,"entry_AKquantite1");
  output4=lookup_widget(Modification,"combobox_AKtype1");
  output5=lookup_widget(objet_graphique, "spinbutton_AKjour1");
  output6=lookup_widget(objet_graphique, "spinbutton_AKmois1");
  output7=lookup_widget(objet_graphique, "spinbutton_AKannee1");
  
  f=fopen("stock.txt","a+");
  if(f!=NULL)
  {
  while(fscanf(f,"%s %s %s %s %d %d %d\n",s.id,s.nom,s.quantite,s.type,&s.dateexp.annee,&s.dateexp.mois,&s.dateexp.jour
)!=EOF)
    {
      if(strcmp(id,s.id)==0)
      {
        gtk_entry_set_text(GTK_ENTRY(output1),s.id);
        gtk_entry_set_text(GTK_ENTRY(output2),s.nom);
        gtk_entry_set_text(GTK_ENTRY(output3),s.quantite);
        gtk_combo_box_set_title(GTK_COMBO_BOX(output4),s.type);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7),s.dateexp.annee);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6),s.dateexp.mois);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5),s.dateexp.jour);
        
      }
    }
    fclose(f);
  }



}


void
on_button_AKsuppr_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


  



  GtkWidget *input;
  GtkWidget *treeview_AKstock;
  GtkWidget *Stock;
  GtkWidget *output;
  GtkWidget *confirmer_suppr;

  /*char ref[30];
  input=lookup_widget(objet_graphique,"entry_AKidsuppr");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));  
  confirmer_suppr=create_confirmer_suppr();
  
  
  gtk_widget_show(confirmer_suppr);*/
  
  char c[]="suppression";
  output=lookup_widget(objet_graphique,"label_messagesuppr");
  Stock=(objet_graphique,"Stock");
  char ref[30];
  input=lookup_widget(objet_graphique,"entry_AKidsuppr");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
  SupprimerProduit(ref);
  treeview_AKstock=lookup_widget(objet_graphique,"treeview_AKstock");
  afficher_produit(treeview_AKstock);
  gtk_label_set_text(GTK_LABEL(output),c);

}


void
on_treeview_AKstock_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


}


void
on_button_AKretourstock_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Stock;
  GtkWidget *Ajout_produit;
  Ajout_produit=create_Ajout_produit();
  Stock=lookup_widget(objet_graphique,"Stock");
  gtk_widget_hide(Stock);
  gtk_widget_show(Ajout_produit);
}


void
on_button_AKrech_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 


	
	GtkWidget *afficher,*w1,*search, *treeview;
	char ss[30];
	search = lookup_widget(objet_graphique, "entry_AKidrech") ;
	w1=lookup_widget(objet_graphique,"Stock");

	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_Stock();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview_AKstock") ;
	ChercherProduit(treeview,ss);


}


void
on_button_AKmodif2_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

  GtkWidget*input1;
  GtkWidget*input2;
  GtkWidget*input3;
  GtkWidget*input4;
  GtkWidget*input5;
  GtkWidget*output;
  GtkWidget*input6;
  GtkWidget*input7;
  FILE*f;
  char c[]="modification terminee";
  output=lookup_widget(objet_graphique,"label_messagemodif");
  Stock s;
  input1=lookup_widget(objet_graphique,"entry_AKid1");
  input2=lookup_widget(objet_graphique,"entry_AKnom1");
  input3=lookup_widget(objet_graphique,"entry_AKquantite1");
  input4=lookup_widget(objet_graphique,"combobox_AKtype1");
  input5=lookup_widget(objet_graphique, "spinbutton_AKjour1");
  input6=lookup_widget(objet_graphique, "spinbutton_AKmois1");
  input7=lookup_widget(objet_graphique, "spinbutton_AKannee1");





	

	

  
  strcpy(s.id,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(s.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
  
  s.dateexp.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
  s.dateexp.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
  s.dateexp.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
  
  modifier(s);
  gtk_label_set_text(GTK_LABEL(output),c);


}


void
on_button_AKannuler_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Stock;
  GtkWidget *Modification;
  GtkWidget *treeview_AKstock;
  Stock=create_Stock();
  Modification=lookup_widget(objet_graphique,"Modification");
  gtk_widget_hide(Modification);
  gtk_widget_show(Stock);
treeview_AKstock=lookup_widget(Stock,"treeview_AKstock");
afficher_produit(treeview_AKstock);
}


void
on_treeview_AKrupt_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


}


void
on_button_AKretourrupt_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *rupture;
  GtkWidget *Login_bienvenue;
  Login_bienvenue=create_Login_bienvenue();
  rupture=lookup_widget(objet_graphique,"rupture");
  gtk_widget_hide(rupture);
  gtk_widget_show(Login_bienvenue);
}



void
on_button_confirmersuppr_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{




/*GtkWidget *Stock, *confirmer_suppr, *treeview_AKstock, *input, *togglebutton1, *togglebutton2, *entry_AKidsuppr;


char ref[30];
confirmer_suppr=lookup_widget(objet_graphique,"confirmer_suppr");
togglebutton1 = lookup_widget(objet_graphique,"checkbutton_AKconfirm1");
togglebutton2 = lookup_widget(objet_graphique,"checkbutton_AKconfirm2");

if (choix == 1)
	{
		
confirmer_suppr=lookup_widget(objet_graphique,"confirmer_suppr");
gtk_widget_destroy(confirmer_suppr);		
Stock=lookup_widget(objet_graphique,"Stock");
Stock=create_Stock ();
gtk_widget_show(Stock);



entry_AKidsuppr=lookup_widget(objet_graphique,"entry_AKidsuppr");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(entry_AKidsuppr)));
SupprimerProduit(ref);

treeview_AKstock=lookup_widget(treeview_AKstock,"treeview_AKstock");

afficher_produit(treeview_AKstock);
	}

if (choix == 0)
	{
		confirmer_suppr=lookup_widget(objet_graphique,"confirmer_suppr");
gtk_widget_destroy(confirmer_suppr);


	}*/


}




void
on_checkbutton_AKconfirm1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{choix = 1 ;}

}


void
on_checkbutton_AKconfirm2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{choix = 0 ;}

}


void
on_button_AKactualiser_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*Stock, *treeview;
	
	
	Stock=lookup_widget(objet_graphique,"Stock");
	afficher = create_Stock();
	gtk_widget_show (afficher);
	gtk_widget_hide (Stock);

	treeview = lookup_widget(afficher, "treeview_AKstock") ;
	afficher_produit(treeview);

}

