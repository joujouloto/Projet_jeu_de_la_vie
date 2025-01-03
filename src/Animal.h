#ifndef _ANIMAL_H

#define _ANIMAL_H


#include <memory>

#include <map>

#include <set>

#include <sstream>

#include <string>

#include <random>

#include <memory>

//----------------------------------------------------------------------------


#include "Objet.h"

#include "Position.h"


//----------------------------------------------------------------------------

using _map = shared_ptr< set < shared_ptr<Objet>  > >;



class Animal: public Objet
{
	public:
	Animal();
	Animal(int pNumero_ligne, int pNumero_colonne);
	
	
	string toString();
	
	string getDeplacements();
	
	//Fonctions mouvements
	void seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille);
	void seDeplacer(Position nouvelle_position, _map grille);
	 
	void seDeplacer_aleatoirement(_map grille);
	void seDeplacer_a_gauche(_map grille);
	void seDeplacer_a_droite(_map grille);
	void seDeplacer_en_haut(_map grille);
	void seDeplacer_en_bas(_map grille);
	
	bool estOccupe(Position position, _map grille); 
	
	protected:
	static int nb_animaux;
	int id_animal;
	
	
	int nb_deplacements;
	map< int, Position> coordonnees_par_ou_passait_animal;
	
	
};







#endif