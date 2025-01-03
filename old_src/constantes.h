/*
	Nom du fichier: Constantes.h


*/

#ifndef CONSTANTES_H
#define CONSTANTES_H

#define LIMITE_GAUCHE 1
#define LIMITE_HAUT 1



#include <map>



using _map = shared_ptr<map<string,shared_ptr<Objet>>>;
using _multimap = shared_ptr<multimap<string,shared_ptr<Objet>>>;
using _objet = shared_ptr<Objet>;

using _it_map = map<string,shared_ptr<Objet>>::iterator;
using _it_multimap = multimap<string,shared_ptr<Objet>>::iterator;



enum type_Objet { type_Arbre = 1, type_Gaulois = 2, type_Gauloise = 3 };

enum type_Deplacement { gauche = 1, droite = 2, haut = 3, bas = 4};

enum sexe_gaulois { homme = 'M' , femme = 'F'};

bool ne_deborde_pas_par_la_gauche(Gaulois * gaulois_ou_gauloise);
bool ne_deborde_pas_par_la_droite(Gaulois * gaulois_ou_gauloise, int nb_lignes);
bool ne_deborde_pas_par_le_haut(Gaulois * gaulois_ou_gauloise);
bool ne_deborde_pas_par_le_bas(Gaulois * gaulois_ou_gauloise, int nb_cases_par_ligne);

bool case_a_gauche_n_est_pas_occupee_par_un_arbre (_map ancienne_grille , Gaulois * gaulois_ou_gauloise);
bool case_a_droite_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , Gaulois * gaulois_ou_gauloise);
bool case_en_haut_n_est_pas_occupee_par_un_arbre ( _map ancienne_grille , Gaulois * gaulois_ou_gauloise);
bool case_en_bas_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , Gaulois * gaulois_ou_gauloise);


#endif