#ifndef GAULOIS_H
#define GAULOIS_H

//------------------------------------------------
#include <iostream>

#include <string>

#include <memory>

#include <random>

#include <set>

#include <map>


//------------------------------------------------


//------------------------------------------------

#include "Position.h"


#include "Objet.h"

#include "Animal.h"


//------------------------------------------------

using _map = shared_ptr< set < shared_ptr<Objet> > >;



class Gaulois : public Objet, enable_shared_from_this<Gaulois>
{
	public:
	
	//Contructeurs
	Gaulois();
	Gaulois(char pSexe);
	
	Gaulois(char pSexe, int pNumero_ligne, int pNumero_colonne);
	
    Gaulois(char pSexe, Position pPosition);
	
	
	
	
	
	//>-----------------------------------------------Getters
	char getSexe();
	int getAge();
	int get_nb_gaulois_crees();
	
	int getIdGaulois();
	
    int getPortee();	
	
	//>---------------------Parents
	string getPere();
	string getMere();
	string getEnfants();
	//<----------------------Parents
	
	
	//Méthodes autres
	string toString();
	string getDeplacements();
	
	//<-----------------------------------------------Getters
	
	
	
	
	//>------------------------------------Age
	void setAge(int pAge);
	void vieillir();
	//<------------------------------------Age
        
	
	//>------------------------------Fonctions mouvements
	void seDeplacer(int pNumero_ligne, int pNumero_colonne, _map grille);
	void seDeplacer(Position nouvelle_position, _map grille);
	 
	void seDeplacer_aleatoirement(_map grille);
	void seDeplacer_a_gauche(_map grille);
	void seDeplacer_a_droite(_map grille);
	void seDeplacer_en_haut(_map grille);
	void seDeplacer_en_bas(_map grille);
	
	
	bool estOccupe(Position position, _map grille); 
	
        
		
	//<------------------------------Fonctions mouvements
	
	
	//>------------------------------Fonctions reproduction
	shared_ptr < Gaulois > recherche_partenaire_masculin( _map grille);
	
	void seReproduire(shared_ptr < Gaulois > pPartenaire_masculin);
	
	void fecondite_qui_baisse();
	
	
	void ajouter_pere(string nom_gaulois);
	void ajouter_mere(string nom_gauloise);
	void ajouter_enfant(string nom_enfant);
	
	//<------------------------------Fonctions reproduction
	
	
	//>------------------------------Fonctions manger
	
	string getAnimauxManges();
	
	int getNbAnimauxManges();
	
	void manger(_map grille);

    //>------------------------------Fonction manger

    
	
	
	
	//>-----------------------------------------Attributs
	
	protected:
	
	int age;
	char sexe;
	int portee;
	
	string pere;
	string mere;
	string enfants;
	
	static int nb_gaulois ;
	int id_gaulois;
	
	int nb_deplacements;
	map< int, Position> coordonnees_par_ou_passait_gaulois;
	
	int nb_animaux_manges;
	map< int, shared_ptr<Animal> > animaux_manges;
	
	
	//<-----------------------------------------Attributs
	
	
	
};





#endif
