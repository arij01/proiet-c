#include <gtk/gtk.h>
#include "callbacks.h"
#include "support.h"
#include "interface.h"
#include "login.h"
#include <string.h>
#include <stdio.h>


typedef struct Date
{

	int jour;
	int mois;
	int annee;
	
}Date;


typedef struct  
{
	char id[50];
	char nom[50];
	char quantite[100];
	char type[50];
	Date dateexp;
}Stock;

void AjouterProduit(Stock s);
void ModifierProduit(Stock s);
void SupprimerProduit(char ref[30]);
void afficher_produit(GtkWidget *liste);
void ChercherProduit (GtkWidget *liste, char refe[30]);

void visualiser(GtkWidget *liste);




