#include "Arbre.h"

#include <sstream>


int Arbre::nb_arbres = 0;

//Constructeurs
Arbre::Arbre(): Objet("Arbre")
{
	setType("Arbre");
	
	nb_arbres++;
	
	id_arbre = nb_arbres;
	
	setNom("Arbre "+to_string(nb_arbres));
	
	age=1;
	
	
	
}


Arbre::Arbre(int pNumero_ligne, int pNumero_colonne) : Objet("Arbre",pNumero_ligne, pNumero_colonne)
{
	setType("Arbre");
	
	
	nb_arbres++;
	
	id_arbre = nb_arbres;
	
	
	setNom("Arbre "+to_string(nb_arbres));
	
	age=1;
	
}

void Arbre::setNom(string pNom)
{
		nom = pNom;
}

int Arbre::getIdArbre()
{
		return id_arbre;
}



string Arbre::toString()
{
	stringstream ss;
	
	ss << "id_objet:";
	ss << id_objet;
	ss << "\n";
	
	ss << "id_arbre:";
	ss << id_arbre;
	ss << "\n";
	
	
	ss << nom;
	ss << "\n";
	
	ss << to_string(this->getPosition().getAbscisse());
	ss << "x";
	ss << to_string(this->getPosition().getOrdonnee());
	ss << "\n";
	
	ss << "age:";
	ss << age;
	ss << "\n";

	return ss.str();
	
	
	
	
}