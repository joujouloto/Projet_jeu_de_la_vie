/*
	Nom du fichier: Jeu.cpp

*/

/*

//-----------------------------------------------------------------------------------------------

	Liste des includes officiels

*/
#include <iostream>

#include <string>

#include <map>

#include <random>

#include <memory>

#include <stdlib.h>

#include <set>

#include<chrono>
#include<thread>

//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------

/*
	Liste des includes que j'ai crée
*/

#include "Gaulois.h"

#include "Arbre.h"

#include "Jeu.h"

#include "constantes.h"




//-----------------------------------------------------------------------------------------------

using namespace std;


/*
	Nom de la fonction: Jeu()
	
	Description: instancie un jeu avec des parametres
	
	Paramètres d'entrée: 	p_nb_lignes qui est de type entier qui est le nombre de lignes de la grille(map), 
							p_nb_colonnes qui est le nombre de colonnes de la grille ( une map est un tableau à 2 dimensions avec une clé qui identifie une 
							valeur ici un objet qui peut être un arbre, un gaulois ou une gauloise)
							p_nb_elements_a_mettre_par_ligne
	
	Paramètres de sortie: 	-
	
	Préconditions: 			nb_lignes et nb_cases_par_ligne doivent être positifs 
							nb_objets_a_creer_par_ligne doit être positif et nb_lignes doit être supérieur à nb_objets_a_creer_par_ligne
	
	Postconditions: rien

*/

//-------------------------------------------------------------

Jeu::Jeu(unsigned p_nb_lignes, unsigned p_nb_colonnes, unsigned p_nb_elements_a_mettre_par_ligne)
{
	
	nb_lignes = p_nb_lignes;
	nb_colonnes = p_nb_colonnes;
	nb_elements_a_mettre_par_ligne_au_debut = p_nb_elements_a_mettre_par_ligne;
	
	grille_de_transition = make_shared<multimap<string,shared_ptr<Objet>>>();
	
	multimap_contenant_que_les_elements_en_collision = make_shared<multimap<string,shared_ptr<Objet>>>();
	
	map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite = make_shared<map<string,shared_ptr<Objet>>>();
	
	
	initialiser_map();
	
	
	nb_total_d_elements_presents_dans_la_grille = grille->size();
}

/*

*/
void Jeu::initialiser_map()
{
	
	//On crée un pointeur intelligent de map qui a pour clé une chaîne de caracteres
	grille = make_shared<map<string,shared_ptr<Objet>>>();
	
	
	
	
	
	random_device rd;
	mt19937 gen(rd());
	
	random_device rd2;
	mt19937 gen2(rd2());
	
	
	uniform_int_distribution<> dis(1, nb_colonnes);//uniform distribution between 1 and 18
	uniform_int_distribution<> dis2(1, 3);//uniform distribution between 1 and 3
	//3 car il n'y a pour l'instant que 3 types d'objets gaulois , gauloise et arbre
	
	
	
	unsigned numero_ligne_nombre = 0;
	unsigned numero_colonne_nombre = 0;
	unsigned objet_genere = 0;
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	
	set<unsigned> liste_numeros_colonne_deja_tombes;
	set<unsigned>::iterator it;
	pair<set<unsigned>::iterator,bool> ret_set;
	pair< map<string,shared_ptr<Objet>>::iterator , bool >  ret_map;
	
	shared_ptr<Arbre> arbre;
	shared_ptr<Gaulois> gaulois;
	shared_ptr<Gaulois> gauloise;
	
	
	for(unsigned i = 1 ; i <= nb_lignes ; i++)
	{
		
		for (unsigned n = 1; n <= nb_elements_a_mettre_par_ligne_au_debut ; n++) 
		{
			
			/*
				Boucle necessaire pour ne pas avoir le même numero de colonne
				quand on reboucle sur la même ligne. On boucle nb_objets_a_creer_par_ligne fois
				sur la même ligne
			*/
			do
			{
				numero_colonne_nombre = dis(gen);
				numero_colonne_string = to_string(numero_colonne_nombre);
				ret_set = liste_numeros_colonne_deja_tombes.insert(numero_colonne_nombre);
				
				//cout << numero_colonne_nombre << endl;
				
				
			}while(ret_set.second==false);
			
			/*if(ret_set.second==true)
			{
				cout << numero_colonne_nombre << endl;
			}*/
			
			
			
			objet_genere = dis2(gen2);
			
			
			numero_ligne_nombre = i ;
			
			numero_ligne_string = to_string(numero_ligne_nombre);
			
			//cout << "type arbre" << type_Arbre << endl;
			
			if(objet_genere==type_Arbre)
			{
				//cout << "dans arbre " << objet_genere << endl;
				arbre = make_shared<Arbre>(numero_ligne_nombre,numero_colonne_nombre);	
				ret_map = grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,arbre));
			}
			else if(objet_genere==type_Gaulois)
			{
				//cout << "dans gaulois " << objet_genere << endl;
				gaulois = make_shared<Gaulois>(homme,numero_ligne_nombre,numero_colonne_nombre);	
				ret_map = grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,gaulois));
			}
			else if(objet_genere==type_Gauloise)
			{
				//cout << "dans gauloise " << objet_genere << endl;
				gauloise = make_shared<Gaulois>(femme,numero_ligne_nombre, numero_colonne_nombre);
				ret_map = grille->insert(pair<string,shared_ptr<Objet>>(numero_ligne_string+"x"+numero_colonne_string,gauloise));
			}
			/*else
			{
				//cout << " objet genere ni de type arbre, ni de type gaulois et ni de type gauloise " << endl;
				//cout << "nombre genere (normalement soit 1 soit 2 soit 3 :" << objet_genere << endl;
			}*/
			
			/*
			if(ret_map.second==true)
			{
				cout << "Element ajoute " << ret_map.first->second->toString() << endl;
			}*/
			
			
			
		}
		
		//On efface le contenu de la liste avant d'entrer une nouvelle ligne
		liste_numeros_colonne_deja_tombes.clear();
	}
}

void Jeu::afficher_infos_de_base_du_jeu()
{
	cout << "----------------------------------------------------------------JEU_DE_LA_VIE-----------------------" << endl;
	cout << "Nombre de lignes: "<< this->nb_lignes << endl
	<< " Nombre de colonnes: "<< this->nb_colonnes << endl
	<< " Nombre d'elements initiaux par ligne: "<< this->nb_elements_a_mettre_par_ligne_au_debut << endl
	<< " Nombre total d'elements dans la grille: "<< this->nb_total_d_elements_presents_dans_la_grille << endl;
	;
	
}

void Jeu::afficher_contenu_de_la_grille()
{
	
	shared_ptr<Gaulois> gaulois;
	
	cout << "-----------------------------------------------CONTENU_DE_LA_GRILLE---------------------------------" << endl;
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{	

		

		if(it->second->getType()=="Gaulois")
		{
			gaulois = dynamic_pointer_cast<Gaulois> (it->second);
			
			cout << it->first << endl;
			cout << gaulois->toString()<< endl;
			
		}else
		{
			cout << it->second->getNom()<< " -> "<< it->second->getNumeroLigne() << "x" << it->second->getNumeroColonne()<<endl;
			
		}
	}
	
	
	
}


unsigned Jeu::get_nb_elements_par_ligne(unsigned numero_ligne)
{
	unsigned nb_elements_par_la_ligne = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{
		if(it->second->getNumeroLigne()==numero_ligne)
		{
			nb_elements_par_la_ligne++;
		}
	}
	
	
	return nb_elements_par_la_ligne;
	
}

unsigned Jeu::get_nb_elements_par_colonne(unsigned numero_colonne)
{
	unsigned nb_elements_par_la_colonne = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{
		if(it->second->getNumeroColonne()==numero_colonne)
		{
			nb_elements_par_la_colonne++;
		}
	}
	
	
	return nb_elements_par_la_colonne;
}


unsigned Jeu::get_nb_lignes_jeu()
{
	return nb_lignes;
}

unsigned Jeu::get_nb_colonnes_jeu()
{
	return nb_colonnes;
}
	
	
void Jeu::afficher_nb_elements_par_ligne()
{
	
	
	for(unsigned i = 1 ; i <= this->nb_lignes ; i++)
	{
		cout << "numero de ligne "<< i<< " :" << this->get_nb_elements_par_ligne(i) << endl;
	}
	
	
	
}

void Jeu::afficher_nb_elements_par_colonne()
{
	
	
	for(unsigned j = 1 ; j <= this->nb_colonnes ; j++)
	{
		cout << "numero de colonne " << j << " :"<< this->get_nb_elements_par_colonne(j) << endl;
	}	
}


unsigned Jeu::get_nb_total_elements_presents_dans_la_grille()
{
	nb_total_d_elements_presents_dans_la_grille = grille->size();
	
	
	return nb_total_d_elements_presents_dans_la_grille;
}

//--------------------------------------------------------------------------------------------------

_map Jeu::get_Map_normale()
{
	return grille;
}


_multimap Jeu::get_grille_de_transition()
{
	return grille_de_transition;
}

_multimap Jeu::get_multimap_contenant_que_les_elements_en_collision()
{
	return multimap_contenant_que_les_elements_en_collision;
}



_map Jeu::get_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite()
{
	return map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite;
}


//--------------------------------------------------------------------------------------------------
void Jeu::ajouter_objet_dans_map_normale(shared_ptr<Objet> objet)
{
	grille->insert(pair<string,shared_ptr<Objet>>(objet->getPosition(),objet));
}





void Jeu::ajouter_objet_dans_grille_de_transition(shared_ptr<Objet> objet)
{
	grille_de_transition->insert(pair<string,shared_ptr<Objet>>(objet->getPosition(),objet));
}

void Jeu::ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(shared_ptr<Objet> objet)
{
	multimap_contenant_que_les_elements_en_collision->insert(pair<string,shared_ptr<Objet>>(objet->getPosition(),objet));
}

void Jeu::ajouter_objet_dans_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite(shared_ptr<Objet> objet)
{
	map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->insert(pair<string,shared_ptr<Objet>>(objet->getPosition(),objet));
}

//-------------------------------------------------------------------------------------------------------------------------------





//--------------------------------------------------------------------------------------------------

void Jeu::afficher_grille_de_transition()
{
	cout << "-----------------------------------------------CONTENU_DE_LA_GRILLE DE TRANSITION---------------------------------" << endl;
	for ( _it_multimap it=grille_de_transition->begin(); it!=grille_de_transition->end(); ++it) 
	{
    	cout << it->first << " => " << it->second->toString() << endl;
	}
}

void Jeu::afficher_multimap_qui_contient_que_les_elements_en_collision()
{
	cout << "-----------------------CONTENU_DE_LA_GRILLE QUI CONTIENT QUE LES ELEMENTS EN COLLISION---------------------------------" << endl;
	for ( _it_multimap it=multimap_contenant_que_les_elements_en_collision->begin(); it!=multimap_contenant_que_les_elements_en_collision->end(); ++it) 
	{
    	cout << it->first << " => " << it->second->toString() << endl;
	}
}

void Jeu::afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite()
{
	cout << "----------------------------------------CONTENU_DE_LA_GRILLE OU ON APPLIQUE LA PRIORITE---------------------------------" << endl;
	for ( _it_map it=map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->begin(); 
	it!=map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->end(); 
	++it) 
	{
    	cout << it->first << " => " << it->second->toString() << endl;
	}
}


void Jeu::faire_deplacer_objets_dans_grille_de_transition()
{
	//Déclaration des variables
	_it_map it;
	
	shared_ptr<Arbre> arbre;
	
	shared_ptr<Objet> objet ;
	
	shared_ptr<Gaulois> gaulois_e;
	
	
	for (_it_map it=grille->begin(); it!=grille->end(); ++it)
	{
		objet = it->second;
		
		if(objet->getType()=="Arbre")
		{
			arbre = dynamic_pointer_cast<Arbre> (objet);
			
			grille_de_transition->insert(pair<string,shared_ptr<Objet>>(arbre->getPosition(),arbre));
			
		}
		else if(objet->getType()=="Gaulois")
		{
			
			gaulois_e = dynamic_pointer_cast<Gaulois> (objet);
			
			gaulois_e->seDeplacerAleatoirement(this->get_Map_normale(),this->get_nb_lignes_jeu(),this->get_nb_colonnes_jeu());
			
			grille_de_transition->insert(
			pair<string,shared_ptr<Objet>>(gaulois_e->getPosition(),gaulois_e));
			
		}
	}
}



/*
	On appelle collision lorsque 2 gaulois veulent aller sur la même case mais les gaulois peuvent se chevaucher, c'est à dire que si un gaulois est à 1x1 et veut aller
	à 1x2 et que une gauloise est à 1x2 veut aller à 1x1 ça marche c'est pas consideré comme collision
*/

void Jeu::mettre_objets_en_collision_dans_une_multimap()
{
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	string cle = "0x0";
	
	_objet objet ;
	
	for (unsigned i = 1 ; i <= nb_lignes ; i++)
	{
		
		for(unsigned j = 1 ; j <= nb_colonnes ; j++)
		{
			numero_ligne_string = to_string(i);
			numero_colonne_string = to_string(j);
			
			cle = numero_ligne_string + "x" + numero_colonne_string;
			 
			for (_it_multimap it=grille_de_transition->equal_range(cle).first;
			it!=grille_de_transition->equal_range(cle).second; ++it)
			{
				if( grille_de_transition->count(cle) > 1)
				{
					objet = it->second;
					
					
					multimap_contenant_que_les_elements_en_collision
					->insert(pair<string,shared_ptr<Objet>>(cle,objet));
				}
				
				
				
			}
		}
	}
}

void Jeu::appliquer_les_regles_de_priorite_sur_les_collisions()
{
	
	 unsigned compteur = 1 ;
	 
	 string cle_comparaison = "0x0";
	 string cle_objet_parcouru = "0x0";
	 string cle_objets_qui_ne_gardent_pas_la_priorite = "0x0";
	 string cle_objet_qui_garde_sa_priorite = "0x0";
	 
	 string numero_ligne_string = "0";
	 string numero_colonne_string = "0";
	 
	 shared_ptr<Objet> objet ;
	 shared_ptr<Gaulois> gaulois_e ;
	 
	 string numero_ligne_objet_qui_ne_garde_pas_sa_priorite_string = "0";
	 string numero_colonne_objet_qui_ne_garde_pas_sa_priorite_string = "0";
	 
	 pair<multimap<string,shared_ptr<Objet>>::iterator,bool> ret;
	 string numero_ligne_objet_qui_gardait_sa_priorite_mais_en_collision_avec_un_element_et_qui_doit_retourner_a_son_ancienne_position_string = "0";
	 string numero_colonne_objet_qui_gardait_sa_priorite_mais_en_collision_avec_un_element_et_qui_doit_retourner_a_son_ancienne_position_string = "0";
	 
	 string cle_objet_qui_gardait_sa_priorite_mais_qui_est_en_collision_et_qui_doit_retourner_a_son_ancienne_position = "0x0";
	 
	 
	
	for (_it_multimap it=multimap_contenant_que_les_elements_en_collision->begin();
			it!=multimap_contenant_que_les_elements_en_collision->end(); ++it)
	{
		
		
		objet = it->second;
		
		/*
		affichage multimap contenant que les elements en collision 
		2x5 =>  Gaulois
		1x5 >> 2x5
		age: 1
		
		2x5 =>  Gaulois
		3x5 >> 2x5
		age: 1
		
		3x5 =>  Gauloise
		3x4 >> 3x5
		age: 1
		
		3x5 =>  Gauloise
		4x5 >> 3x5
		age: 1
		
		affichage multimap ou on applique la priorite 
		2x5 =>  Gaulois
		1x5 >> 2x5
		age: 1
		
		3x5 =>  Gaulois
		3x5 >> 3x5
		age: 1
		
		4x5 =>  Gauloise
		4x5 >> 4x5
		age: 1
		
		*/
		
		numero_ligne_string = to_string(objet->getNumeroLigne());
		numero_colonne_string = to_string(objet->getNumeroColonne());
		
		cle_objet_parcouru = numero_ligne_string + "x" + numero_colonne_string;
		
		
		
		if(cle_comparaison!=cle_objet_parcouru)
		{
			cle_comparaison = cle_objet_parcouru ;
			compteur = 1 ;
			
			cle_objet_qui_garde_sa_priorite = cle_objet_parcouru;
			
			ret = map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->insert(pair<string,shared_ptr<Objet>>(
			cle_objet_qui_garde_sa_priorite,objet));
			
			if(ret.second==false)
			{
				
				gaulois_e = dynamic_pointer_cast<Gaulois> (objet);
				
				
				gaulois_e->retournerAsonAnciennePosition();
				
				objet = gaulois_e ;
				
				numero_ligne_objet_qui_gardait_sa_priorite_mais_en_collision_avec_un_element_et_qui_doit_retourner_a_son_ancienne_position_string = to_string(objet->getNumeroLigne());
				
				numero_colonne_objet_qui_gardait_sa_priorite_mais_en_collision_avec_un_element_et_qui_doit_retourner_a_son_ancienne_position_string = to_string(objet->getNumeroColonne());
				
				cle_objet_qui_gardait_sa_priorite_mais_qui_est_en_collision_et_qui_doit_retourner_a_son_ancienne_position =	numero_ligne_objet_qui_gardait_sa_priorite_mais_en_collision_avec_un_element_et_qui_doit_retourner_a_son_ancienne_position_string+"x"+numero_colonne_objet_qui_gardait_sa_priorite_mais_en_collision_avec_un_element_et_qui_doit_retourner_a_son_ancienne_position_string;
				
				map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->insert(pair<string,shared_ptr<Objet>>(cle_objet_qui_gardait_sa_priorite_mais_qui_est_en_collision_et_qui_doit_retourner_a_son_ancienne_position,objet));
				
				
				cout << "Element priorisé qui va sur un emplacement occupé " << endl;
				cout << "Element doit retourner a son ancienne position " << endl;
				cout << "--------------------------------------------------" << endl;
				cout << objet->toString() << endl;
				cout << "--------------------------------------------------" << endl;
			}
			
			
			
			
		}
		else
		{
			compteur++;
			
			if(compteur>1)
			{
				gaulois_e = dynamic_pointer_cast<Gaulois> (objet);
				
				/*
					Attention à la fonction retourner à son ancienne position car l'element qui etait en collision a pour ancienne coordonnee la position 
					où il etait en collision. Or cela doit être sa position avant son deplacement en collision
				*/
				
				
				
				gaulois_e->retournerAsonAnciennePosition();
				
				objet = gaulois_e ;
				
				numero_ligne_objet_qui_ne_garde_pas_sa_priorite_string = to_string(objet->getNumeroLigne());
				numero_colonne_objet_qui_ne_garde_pas_sa_priorite_string = to_string(objet->getNumeroColonne());
				
				
				cle_objets_qui_ne_gardent_pas_la_priorite = numero_ligne_objet_qui_ne_garde_pas_sa_priorite_string 
				+ "x" + numero_colonne_objet_qui_ne_garde_pas_sa_priorite_string;
				
				map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->insert(
				pair<string,shared_ptr<Objet>>(cle_objets_qui_ne_gardent_pas_la_priorite,objet));
				
			}

		}
		
	}
}


void Jeu::regrouper_tous_les_elements()
{
	grille->clear();
	
	
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	string cle = "0x0";
	
	shared_ptr<Objet> objet ;
	
	for (unsigned i = 1 ; i <= nb_lignes ; i++)
	{
		
		for(unsigned j = 1 ; j <= nb_colonnes ; j++)
		{
			numero_ligne_string = to_string(i);
			numero_colonne_string = to_string(j);
			
			cle = numero_ligne_string+"x"+numero_colonne_string;
			 
			for (_it_multimap it=grille_de_transition->equal_range(cle).first;
			it!=grille_de_transition->equal_range(cle).second; ++it)
			{
				if( grille_de_transition->count(cle) == 1)
				{
					objet = it->second;
					
					
					grille
					->insert(pair<string,shared_ptr<Objet>>(cle,objet));
				}
				
				
				
			}
		}
	}
	
	
	for( _it_map it = map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->begin();
		it!=map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->end(); 
		++it
	)
	{
		grille->insert(pair<string,shared_ptr<Objet>>(it->first,it->second));
	}
	
	grille_de_transition->clear();
	multimap_contenant_que_les_elements_en_collision->clear();
	map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->clear();
		
}

void Jeu::faire_deplacer_objets()
{
	faire_deplacer_objets_dans_grille_de_transition();
	mettre_objets_en_collision_dans_une_multimap();
	appliquer_les_regles_de_priorite_sur_les_collisions();
	regrouper_tous_les_elements();
}


void Jeu::SDL()
{
	SDL_Window *win;
    SDL_Renderer *renderer;
	

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout <<  "SDL_Init Error: %s\n" <<  SDL_GetError() << endl;
        return;
    }

    win = SDL_CreateWindow("Jeu de la vie!", 200, 50, 1300, 900, SDL_WINDOW_SHOWN);
    if (win == NULL)
    {
       
		cout <<  "SDL_CreateWindow Error: %s\n" <<  SDL_GetError() << endl;
        return;
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
    if (renderer == NULL)
    {
		cout <<  "SDL_CreateRenderer Error: %s\n" <<  SDL_GetError() << endl;
		
        SDL_DestroyWindow(win);
        SDL_Quit();
        return;
    }
	
	initialiser_map();
	afficher_grille_SDL(renderer);
	
	
	boucle_SDL(renderer);
	
	
	fermeture_SDL(win,renderer);
	
}

void Jeu::afficher_grille_SDL(SDL_Renderer *renderer)
{
    SDL_Rect single_rect;
	
	/*int nb_lignes = 14 ;
	int nb_cases_par_ligne = 18;*/
	
	int pos_x = 40;
	int pos_y = 40;
	int espace = 20 ;
	
	single_rect.w = 50;
	single_rect.h = 50;
	
	single_rect.x = pos_x + espace ;
	single_rect.y = pos_y;
	
	
	//Images
		
	SDL_Surface * image_vide = SDL_LoadBMP("../../images/vide.bmp");
	
	SDL_Surface * image_arbre = SDL_LoadBMP("../../images/arbre.bmp");
	
	SDL_Surface * image_gaulois = SDL_LoadBMP("../../images/gaulois.bmp");
	
	SDL_Surface * image_gauloise = SDL_LoadBMP("../../images/gauloise.bmp");
		
		
	//Textures
	SDL_Texture * texture_vide = SDL_CreateTextureFromSurface(renderer, image_vide);
	
	SDL_Texture * texture_arbre = SDL_CreateTextureFromSurface(renderer, image_arbre);
	
	SDL_Texture * texture_gaulois = SDL_CreateTextureFromSurface(renderer, image_gaulois);
	
	SDL_Texture * texture_gauloise = SDL_CreateTextureFromSurface(renderer, image_gauloise);
	
	//169*221
	
	
	string numero_ligne_string = "0";
	string numero_colonne_string = "0";
	
	
	
	map<string,shared_ptr<Objet>>::iterator it;
	
	
	for(int i = 1 ; i <= nb_lignes ; i++)
	{
		
		for( int j = 1 ; j <= nb_colonnes ; j++)
		{
			single_rect.x +=  pos_x + espace ;
			
			numero_ligne_string = to_string(i);
			numero_colonne_string = to_string(j);
			
			it = grille->find(numero_ligne_string+"x"+numero_colonne_string);
			
			if(it!=grille->end())
			{
				if(it->second->getNom()=="Arbre")
				{
					SDL_RenderCopy(renderer, texture_arbre, NULL, &single_rect);
				}
				else if(it->second->getNom()=="Gaulois")
				{
					SDL_RenderCopy(renderer, texture_gaulois, NULL, &single_rect);
				}
				else if(it->second->getNom()=="Gauloise")
				{
					SDL_RenderCopy(renderer, texture_gauloise, NULL, &single_rect);
				}
				
			}else
			{
				//SDL_SetRenderDrawColor(renderer, 50, 205, 50, 255);
				//SDL_RenderFillRect(renderer, &single_rect);
				SDL_RenderCopy(renderer, texture_vide, NULL, &single_rect);
			}
			
		}
		
		single_rect.y += pos_y + espace;
		single_rect.x =  pos_x + espace ;
	}
	
	SDL_RenderPresent(renderer);
	
}


void Jeu::fermeture_SDL(SDL_Window *win, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void Jeu::boucle_SDL(SDL_Renderer *renderer)
{
	
	SDL_Event ev;
	
	bool isRunning = true;
	
	
	
	while(isRunning)
	{
		this_thread::sleep_for(chrono::milliseconds(1500));
		
		faire_deplacer_objets();
		faire_vieillir_population_gauloise();
		
		faire_mourir_les_gaulois_trop_vieux(5);
		
		
		afficher_contenu_de_la_grille();
		
		SDL_RenderClear(renderer);
		afficher_grille_SDL(renderer);
		
		
		while( SDL_PollEvent( &ev ) != 0 ) 
		{
			switch (ev.type) 
			{
				case SDL_QUIT:
				isRunning = false;
					
			}
		
		}
	}
}

void Jeu::faire_vieillir_population_gauloise()
{
	shared_ptr<Gaulois> gaulois;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{	

		if(it->second->getNom()=="Gaulois"||it->second->getNom()=="Gauloise")
		{
			gaulois = dynamic_pointer_cast<Gaulois> (it->second);
			
			gaulois->vieillir();
		}
	}
	
}

/*
	Certains gaulois qui ont l'age de deces ne meurent pas. Je sais pas pourquoi.
*/



void Jeu::faire_mourir_les_gaulois_trop_vieux(unsigned age_de_deces_probable)
{
	shared_ptr<Gaulois> gaulois;
	
	set<string> cles_gaulois_trop_vieux;
	
	
	set<string>::iterator it_set;
	
	random_device rd;
	mt19937 gen(rd());
	
	uniform_int_distribution<> dis(1, 10);//uniform distribution between 1 and 4 
	 
	int chances_de_deces = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{	

		if(it->second->getNom()=="Gaulois"||it->second->getNom()=="Gauloise")
		{
			gaulois = dynamic_pointer_cast<Gaulois> (it->second);
			
			
			
			if(age_de_deces_probable<=gaulois->getAge())
			{
				//grille->erase(it);
				
				chances_de_deces = dis(gen);
				
				//Quand un gaulois(e) atteint l'age de deces il a 30% de chances de mourir
				
				if(chances_de_deces==8||chances_de_deces==9||chances_de_deces==10)
				{
					cles_gaulois_trop_vieux.insert(gaulois->getPosition());
					
					cout << gaulois->toString() << endl;
				}
				
				
				
			}
		}
	}
	
	for(it_set = cles_gaulois_trop_vieux.begin() ; it_set != cles_gaulois_trop_vieux.end() ; ++it_set)
	{
		grille->erase(grille->find(*it_set));
	}
	
	
}

unsigned Jeu::get_nb_total_gaulois_feminin()
{
	unsigned nb_total_gauloises = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{	

		if(it->second->getNom()=="Gauloise")
		{
			
			nb_total_gauloises++;
		}
	}
	
	return nb_total_gauloises;
}


unsigned Jeu::get_nb_total_gaulois_masculin()
{
	unsigned nb_total_gaulois = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{	

		if(it->second->getNom()=="Gaulois")
		{
			
			nb_total_gaulois++;
		}
	}
	
	return nb_total_gaulois;
}

unsigned Jeu::get_nb_total_gaulois()
{
	return get_nb_total_gaulois_feminin()+get_nb_total_gaulois_masculin();
}

unsigned Jeu::get_nb_total_arbres()
{
	unsigned nb_total_arbres = 0;
	
	
	for ( _it_map it=grille->begin(); it!=grille->end(); ++it) 
	{	

		if(it->second->getNom()=="Arbre")
		{
			
			nb_total_arbres++;
		}
	}
	
	return nb_total_arbres;
}



