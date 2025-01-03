#ifndef _JEU_V2_H
#define _JEU_V2_H


//------------------------------------------------

#include <set>

#include <map>

#include <memory>

//#include <SDL2/SDL.h>




//------------------------------------------------


//------------------------------------------------

#include "Objet.h"


//------------------------------------------------


using _grille = shared_ptr< set < shared_ptr<Objet> > >;
using _objet = shared_ptr<Objet>;

using _it_grille = set < shared_ptr<Objet> >::iterator;


class Jeu_v2
{
	public:
	Jeu_v2();


	void initialiser_grille();

	void faire_deplacer_elements();
	
	void faire_manger_gaulois();
	
	
	void faire_vieillir_population_gauloise();


	//toString
	string afficher_dans_chaine_contenu_grille();


	_grille getGrille();


	protected:
	int nb_lignes;
	int nb_colonnes;
	int nb_elements_a_mettre_par_ligne_au_debut;
	int nb_total_d_elements_presents_dans_la_grille;
	_grille grille;


};


#endif
