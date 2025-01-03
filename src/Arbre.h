#ifndef _ARBRE_H
#define _ARBRE_H

#include "Objet.h"

#include <string>

using namespace std;

class Arbre : public Objet
{
	public:
	
	//Constructeur
	Arbre();
	Arbre(int pNumero_ligne, int pNumero_colonne);
	
	
	
	//Get
	int getIdArbre();
	
	
	
	//Méthode qui renvoie une description de l'objet
	string  toString();
	
	
	//set
	void setNom(string pNom);
	
	
	
	
	protected:
	static int nb_arbres;
	int id_arbre;
	int age;
	
	
};


#endif