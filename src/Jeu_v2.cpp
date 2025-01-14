/*
	Nom du fichier: Jeu_nouvelle_architecture.cpp

*/

/*

//-----------------------------------------------------------------------------------------------

	Liste des includes officiels

*/
#include <iostream>

#include <string>

#include <set>

#include <random>

#include <memory>

#include <stdlib.h>

#include <set>

#include<chrono>
#include<thread>

#include <sstream>

//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------

/*
	Liste des includes que j'ai crée
*/

#include "Gaulois.h"

#include "Arbre.h"

#include "Jeu_v2.h"

#include "Animal.h"



//-----------------------------------------------------------------------------------------------

using namespace std;



enum sexe_gaulois { homme = 'M' , femme = 'F'};

Jeu_v2::Jeu_v2()
{
	nb_lignes = 15 ;
	nb_colonnes = 10;
	nb_elements_a_mettre_par_ligne_au_debut = 0;
	
	
	initialiser_grille();
	
	
	nb_total_d_elements_presents_dans_la_grille = grille->size();
}


_grille Jeu_v2::getGrille()
{
		return grille;
}


void Jeu_v2::initialiser_grille()
{
	grille = make_shared< set < shared_ptr<Objet> > > ();
	
	
	shared_ptr<Gaulois> gaulois_1,
	gaulois_2,
	gaulois_3;
	
	shared_ptr<Arbre> arbre_1,
	arbre_2,
	arbre_3;
	
	shared_ptr<Animal> animal_1;
	
	
	gaulois_1 = make_shared<Gaulois>(homme,7,5);
	grille->insert(  gaulois_1 );
	
	gaulois_2 = make_shared<Gaulois>(homme,4,3);
	grille->insert( gaulois_2 );
	
	gaulois_3 = make_shared<Gaulois>(femme,8,9);
	grille->insert( gaulois_3);
	
	arbre_1 = make_shared<Arbre>(2,5);
	grille->insert( arbre_1 );
	
	arbre_2 = make_shared<Arbre>(1,6);
	grille->insert(  arbre_2 );
	
	arbre_3 = make_shared<Arbre>(10,7);
	grille->insert( arbre_3);
	
	animal_1 = make_shared<Animal>(9,9);
	grille->insert( animal_1);
	
	
	
	
	
}

//ATTENTION le contenu n'est pas mis à jour quand on fait deplacer un element
string Jeu_v2::afficher_dans_chaine_contenu_grille()
{
	stringstream ss;
	shared_ptr<Gaulois> gaulois;
	shared_ptr<Objet> objet;
	shared_ptr<Arbre> arbre;
	shared_ptr<Animal> animal;
	
	
	ss << "-------------------------Contenu de la grille---------------------------------------------------";
	ss << "\n";
	
	for (_it_grille it=grille->begin(); it != grille->end(); ++it)
	{
		 objet = *it;
		
		
		ss << "\n";
		
		if(objet->getType()=="Gaulois")
		{
			gaulois = dynamic_pointer_cast<Gaulois> (objet);
			
			ss << gaulois->toString();
			
		}
		else if(objet->getType()=="Arbre")
		{
			
			arbre = dynamic_pointer_cast<Arbre> (objet);
			
			ss << arbre->toString();
			
		}
		else if(objet->getType()=="Animal")
		{
			animal = dynamic_pointer_cast<Animal> (objet);
			
			ss << animal->toString();
		}
		
		
		
	}
	
	
	
	ss << "\n ";
	

	
	
	
	return ss.str();
}



void Jeu_v2::faire_deplacer_elements()
{
	shared_ptr<Animal> animal;
	shared_ptr<Objet> objet;
	shared_ptr<Gaulois> gaulois;
	
	for (_it_grille it=grille->begin(); it != grille->end(); ++it)
	{
		objet = *it;
		
		if(objet->getType()=="Gaulois")
		{
			gaulois = dynamic_pointer_cast<Gaulois> (objet);
			
			gaulois->seDeplacer_aleatoirement(grille);
			
		}
		else if(objet->getType()=="Animal")
		{
			animal = dynamic_pointer_cast<Animal> (objet);
			
			
			animal->seDeplacer_aleatoirement(grille);
		}
	}
}

void Jeu_v2::faire_manger_gaulois()
{
	shared_ptr<Objet> objet;
	shared_ptr<Gaulois> gaulois;
	
	random_device rd;
	mt19937 gen(rd());
	
	uniform_int_distribution<> dis(1, 7);//distribution uniforme entre 1 et 7
	
	
	
	
	for (_it_grille it=grille->begin(); it != grille->end(); ++it)
	{
		objet = *it;
		
		if(objet->getType()=="Gaulois")
		{
			gaulois = dynamic_pointer_cast<Gaulois> (objet);
			
			if ( dis(gen)==1)
			{
				gaulois->manger(grille);
			}
			
			
			
			
			
		}
	}
}


void Jeu_v2::faire_vieillir_population_gauloise()
{
	shared_ptr<Gaulois> gaulois;
	shared_ptr<Objet> objet;
	
	random_device rd;
	mt19937 gen(rd());
	
	uniform_int_distribution<> dis(1, 10);//le nombre aléatoire peut tomber entre 1 et 10
	
	
	int variable_qui_fait_mourir = 10;
	//On initialise la variable qui récupéra le nombre aléatoire à 10


	
	shared_ptr < set < shared_ptr < Gaulois > > > gaulois_qui_doivent_mourir =
	  make_shared< set < shared_ptr< Gaulois > > > ();
	
	for ( _it_grille it=grille->begin(); it!=grille->end(); ++it) 
	{	
		objet = *it;
		if(objet->getType()=="Gaulois")
		{
			gaulois = dynamic_pointer_cast<Gaulois> (objet);
			gaulois->vieillir();
			
			variable_qui_fait_mourir = dis(gen);
			//On récupère le nombre aléatoire de la distribution uniforme
			//dans variable qui fait mourir
			
			//Si l'âge du gaulois est supérieur à 10
			//et que la variable aléatoire est égal à 3 ou moins
			//on fait mourir le gaulois
			//quand le gaulois a atteint l'âge de 10, il a 30% de chances de
			//mourir
			if(gaulois->getAge() > 10 &&  variable_qui_fait_mourir <= 3 )
			{
				//cout << variable_qui_fait_mourir << endl;
				//cout << gaulois->getAge() << endl;
				
			  //grille->erase(gaulois);
			  cout << "ajout gaulois dans set gaulois_qui_doivent_mourir" << endl;
			  gaulois_qui_doivent_mourir->insert(gaulois);
			}
			
		}
	}
   
	
	    for( set < shared_ptr < Gaulois > >:: iterator it = gaulois_qui_doivent_mourir->begin();
		 it != gaulois_qui_doivent_mourir->end();
		 it++
		 )
	      {
		objet = *it;
		grille->erase(objet);
	      }
}

void Jeu_v2::faire_reproduire_population()
{
  
}











