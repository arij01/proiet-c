#include <gtk/gtk.h>


void
on_button_AKlogin_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKquitter1_clicked           (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKstock_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKrupture_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKlogout_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKajouter_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKafficher_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKretourajout_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKmodif1_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKsuppr_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview_AKstock_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_AKretourstock_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKrech_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKmodif2_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_AKannuler_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview_AKrupt_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_AKretourrupt_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_button_confirmersuppr_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_AKconfirm1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_AKconfirm2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_AKactualiser_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
