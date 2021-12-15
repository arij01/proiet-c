#include <stdio.h>
#include <gtk/gtk.h>
#include "fonction.h"
#include <string.h>

enum
{
  ID,
  NOM,
  QUANTITE,
  TYPE,
  DATE_EXP,
  

  COLUMNS
};

void AjouterProduit(Stock c)
{

FILE *f=NULL;

f=fopen("stock.txt","a+");

if(f!=NULL)
{

fprintf(f,"%s %s %s %s %d %d %d \n",c.id,c.nom,c.quantite,c.type,c.dateexp.annee,c.dateexp.mois,c.dateexp.jour);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");
}





void SupprimerProduit(char ref[30])
{
  Stock c;
  FILE*f;
  FILE*f1;


f=fopen("stock.txt","a+");
f1=fopen("stock1.txt","a+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d %d %d \n",c.id,c.nom,c.quantite,c.type,&c.dateexp.annee,&c.dateexp.mois,&c.dateexp.jour)!=EOF)
{
if(strcmp(ref,c.id)!=0)
{
fprintf(f1,"%s %s %s %s %d %d %d\n",c.id,c.nom,c.quantite,c.type,c.dateexp.annee,c.dateexp.mois,c.dateexp.jour);
}


}
}
fclose(f);
fclose(f1);
remove("stock.txt");
rename("stock1.txt","stock.txt");

}
  



void afficher_produit(GtkWidget *liste)
{
 	GtkCellRenderer *renderer;
 	GtkTreeViewColumn *column;
 	GtkTreeIter iter;
 	GtkListStore *store;
	char id[50];
	char nom[50];
	char quantite[100];
	char type[50];
	char jour[30];
	char mois[30];
	char annee[30];
	char dateexpcomp[30];
 	store=NULL;

 	FILE *f;
 	store=gtk_tree_view_get_model(liste);
 	if (store==NULL)
 	{

		renderer= gtk_cell_renderer_text_new();
    		column=
gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTITE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("dateexp",renderer,"text",DATE_EXP,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("stock.txt", "r");
	if (f==NULL)
  	{
    	return;
  	}
  	else
  	{
    	f= fopen("stock.txt", "a+");
    	while(fscanf(f,"%s %s %s %s %s %s %s ",id,nom,quantite,type,annee,mois,jour)!=EOF)
    	{
		strcpy(dateexpcomp,annee);
		strcat(dateexpcomp,"-");
		strcat(dateexpcomp,mois);
 	 	strcat(dateexpcomp,"-");
		strcat(dateexpcomp,jour);
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,ID,id,NOM,nom,QUANTITE,quantite,TYPE,type,DATE_EXP,dateexpcomp, -1);

    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
    
}}













void modifier(Stock s)
{
  Stock c;
  FILE*f;
  FILE *f1;
  f=fopen("stock.txt","a+");
  f1=fopen("stock1.txt","a+");
  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %d %d %d\n",c.id,c.nom,c.quantite,c.type,&c.dateexp.annee,&c.dateexp.mois,&c.dateexp.jour)!=EOF)
    {
      if(strcmp(c.id,s.id)==0)
      {
        fprintf(f1,"%s %s %s %s %d %d %d\n",s.id,s.nom,s.quantite,s.type,s.dateexp.annee,s.dateexp.mois,s.dateexp.jour);
      }
      else fprintf(f1,"%s %s %s %s %d %d %d\n",c.id,c.nom,c.quantite,c.type,c.dateexp.annee,c.dateexp.mois,c.dateexp.jour);
    }
  }
  fclose(f);
  fclose(f1);
  remove("stock.txt");
  rename("stock1.txt","stock.txt");
}




void ChercherProduit (GtkWidget *liste, char refe[30]) 
{
	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[50];
 	char nom[50];
 	char quantite[100];
 	char type[50];
	char jour[30];
	char mois[30];
	char annee[30];
	char dateexpcomp[30];
	 
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTITE,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
   		 renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("dateexp",renderer,"text",DATE_EXP,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("stock.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("stock.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s ",id,nom,quantite,type,annee,mois,jour)!=EOF)
			{
		 strcpy(dateexpcomp,annee);
	     	 strcat(dateexpcomp,"-");
		 strcat(dateexpcomp,mois);
 	 	 strcat(dateexpcomp,"-");
		 strcat(dateexpcomp,jour);
		if(strcmp(refe,id)==0 || strcmp(refe,nom)==0 || strcmp(refe,quantite)==0 || strcmp(refe,type)==0 || strcmp(refe,dateexpcomp)==0 || strcmp(refe,annee)==0 || strcmp(refe,mois)==0  || strcmp(refe,jour)==0)
        {
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,ID,id,NOM,nom,QUANTITE,quantite,TYPE,type,DATE_EXP,dateexpcomp, -1);

    }
 }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
}
}


}





void visualiser(GtkWidget *liste)

{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[50];
 	char nom[50];
 	char quantite[100];
 	char type[50];
	char jour[30];
	char mois[30];
	char annee[30];
	char dateexpcomp[30];
	 
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTITE,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
   		 renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("dateexp",renderer,"text",DATE_EXP,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("stock.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("stock.txt","a+");
			while (fscanf(f,"%s %s %s %s %s %s %s ",id,nom,quantite,type,annee,mois,jour)!=EOF)
			{
		 strcpy(dateexpcomp,annee);
	     	 strcat(dateexpcomp,"-");
		 strcat(dateexpcomp,mois);
 	 	 strcat(dateexpcomp,"-");
		 strcat(dateexpcomp,jour);
		if(strcmp("0",quantite)==0 )
        {
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,ID,id,NOM,nom,QUANTITE,quantite,TYPE,type,DATE_EXP,dateexpcomp, -1);

    }
 }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
}





















