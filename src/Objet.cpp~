#include "Objet.h"



int Objet::nb_objets = 0;

//Constructeurs
Objet::Objet()
{
	nom = "Objet";
	position = Position(0,0);
	
	type = "Objet";
	
	nb_objets++;
	
	id_objet = nb_objets;
	
	
}

Objet::Objet(string pNom)
{
	nom = pNom;
	position = Position(0,0);
	
	type = "Objet";
	
	nb_objets++;
	
	id_objet = nb_objets;
}

Objet::Objet(int pNumero_ligne, int pNumero_colonne)
{
	nom = "Objet";
	
	
	type = "Objet";
	
	position = Position(pNumero_ligne,pNumero_colonne);
	
	nb_objets++;
	
	id_objet = nb_objets;
}

Objet::Objet(string pNom, int pNumero_ligne, int pNumero_colonne)
{
	nom = pNom;
	
	position = Position(pNumero_ligne,pNumero_colonne);
	
	type = "Objet";
	
	nb_objets++;
	
	id_objet = nb_objets;
	
	
	
}


//Getters
string Objet::getNom()
{
	return nom;
}

string Objet::getType()
{
	return type;
}
	
Position Objet::getPosition()
{
	return position;
}

int Objet::getNbObjets()
{
	return nb_objets;
}

int Objet::getIdObjet()
{
	return id_objet;
}

//Setters

void Objet::setType(string pType)
{
	type = pType;
}


void Objet::setNom(string pNom)
{
	nom = pNom;
}

void Objet::setPosition(Position pPosition)
{	
	position = pPosition;
}



//Destructeur
Objet::~Objet()
{
	
}













