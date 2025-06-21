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


/*
	Constantes
*/

#define AGE_ADULTE_GAULOIS 10


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

int Jeu_v2::get_nb_lignes()
{
	return nb_lignes;
}

int Jeu_v2::get_nb_colonnes()
{
	return nb_colonnes;
}


void Jeu_v2::initialiser_grille()
{
	grille = make_shared< set < shared_ptr<Objet> > > ();
	
	
	shared_ptr<Gaulois> gaulois_1,
	gaulois_2,
	gaulois_3,
	
	gaulois_4,
	gaulois_5,
	gaulois_6;
	
	
	
	
	shared_ptr<Arbre> arbre_1,
	arbre_2,
	arbre_3;
	
	shared_ptr<Animal> animal_1;
	
	
	gaulois_1 = make_shared<Gaulois>(homme,9,9);
	gaulois_1->setAge(AGE_ADULTE_GAULOIS);
	grille->insert(  gaulois_1 );
	
	
	
	
	gaulois_2 = make_shared<Gaulois>(homme,8,10);
	gaulois_2->setAge(AGE_ADULTE_GAULOIS);
	grille->insert( gaulois_2 );
	
	gaulois_3 = make_shared<Gaulois>(femme,8,9);
	gaulois_3->setAge(AGE_ADULTE_GAULOIS);
	grille->insert( gaulois_3);
	
	gaulois_4 = make_shared<Gaulois>(femme,2,3);
	grille->insert( gaulois_4);
	
	gaulois_5 = make_shared<Gaulois>(femme,4,7);
	grille->insert( gaulois_5);
	
	gaulois_6 = make_shared<Gaulois>(homme,4,2);
	grille->insert( gaulois_6);
	
	arbre_1 = make_shared<Arbre>(2,5);
	grille->insert( arbre_1 );
	
	arbre_2 = make_shared<Arbre>(1,6);
	grille->insert(  arbre_2 );
	
	arbre_3 = make_shared<Arbre>(10,7);
	grille->insert( arbre_3);
	
	animal_1 = make_shared<Animal>(3,3);
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
			//quand le gaulois a atteint l'âge de 30, il a 30% de chances de
			//mourir
			if(gaulois->getAge() > 30 &&  variable_qui_fait_mourir <= 3 )
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
  shared_ptr<Objet> objet;
  shared_ptr<Gaulois> gaulois;

  random_device rd;
  mt19937 gen(rd());
	
  uniform_int_distribution<> dis(1, 2);
  shared_ptr<Gaulois> enfant;


  Position position_enfant;
  bool trop_de_monde_autour = false;


  //On a besoin de cette variable booléenne pour
  //On va checker à gauche à droite ...etc si y a un partenaire masculin
  //Des que l'on a trouvé on sort des if (on fait pas de boucles car y a que 4 cas)
	
  //Si on ne met ps cette condition de vérifier que les femmes, les gaulois(es) vont
  //se reproduire 2 fois


  shared_ptr < Gaulois > partenaire_masculin = nullptr;

  shared_ptr <  set < shared_ptr < Gaulois > > > gaulois_crees = make_shared < set < shared_ptr< Gaulois > > >  ();
  
  for ( _it_grille it = grille ->begin() ; it!= grille->end() ; it++ )
    {

      objet = *it;

      if( objet -> getType()=="Gaulois" )
		{
		  gaulois = dynamic_pointer_cast<Gaulois> (objet);

		
			if( gaulois->getSexe()== femme && gaulois->getAge() > 10 &&
				gaulois->getPortee() > 0 )
			  {
				
					//Doit chercher un partenaire masculin
					 partenaire_masculin = gaulois->recherche_partenaire_masculin(grille);

					if(partenaire_masculin != nullptr && partenaire_masculin->getAge() > 10  )
					{
					
						cout << " Partenaire masculin " << partenaire_masculin->getNom() << endl;
						
							if(!gaulois->estOccupe( gaulois->getPosition().a_gauche(), grille ) )
						  {
							position_enfant = gaulois->getPosition().a_gauche();
						  }
						else if(
							   !gaulois->estOccupe ( gaulois->getPosition().a_droite(), grille ) )
						  {
							position_enfant = gaulois->getPosition().a_droite();
						  }
						else if (
						  ! gaulois->estOccupe ( gaulois->getPosition().en_haut(), grille ))
						  {
							position_enfant = gaulois->getPosition().en_haut();
						  }
						else if ( ! gaulois->estOccupe ( gaulois->getPosition().en_bas(), grille))
						  {
							position_enfant = gaulois->getPosition().en_bas();
						  }
						else
						  {
							trop_de_monde_autour = true;
						  }


						if(!trop_de_monde_autour)
						{	
							if( dis(gen) == 1 )
							{
									enfant = make_shared<Gaulois>(homme,position_enfant);
							}else
							{
									enfant = make_shared<Gaulois>(femme,position_enfant);
							}

							//grille->insert(enfant);
							gaulois->seReproduire(partenaire_masculin);
							
							gaulois->ajouter_enfant(enfant->getNom());
							
							enfant->ajouter_pere(partenaire_masculin->getNom());
							enfant->ajouter_mere(gaulois->getNom());
							
							partenaire_masculin->ajouter_enfant(enfant->getNom());
							
							gaulois_crees->insert(enfant);
							cout << "Reproduction en cours " << endl;

						}
					}
			  
			  
				}

			}
    }
  
  shared_ptr < Objet > gaulois_enfant_ne;
  for (  set < shared_ptr < Gaulois > >::iterator it = gaulois_crees->begin();
	 it != gaulois_crees->end();
	 it++)
    {
      gaulois_enfant_ne = *it;

      grille->insert(gaulois_enfant_ne);
      
    }
 
}
