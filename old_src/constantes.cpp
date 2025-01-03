/*
	Nom du fichier: constantes.cpp


*/

//------------------------------------------------------

#include <memory>

#include <map>

//------------------------------------------------------



#include "Gaulois.h"

#include "constantes.h"


//-------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------


bool ne_deborde_pas_par_la_gauche(Gaulois * gaulois_ou_gauloise)
{
	if(LIMITE_GAUCHE <= gaulois_ou_gauloise->getNumeroLigne()-1)
	{
		return true;
	}else
		return false;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool ne_deborde_pas_par_la_droite(Gaulois * gaulois_ou_gauloise, int nb_lignes)
{
	int LIMITE_DROITE = nb_lignes;
	
	if( LIMITE_DROITE >= gaulois_ou_gauloise->getNumeroLigne()+1)
	{
		return true;
	}else
		return false;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool ne_deborde_pas_par_le_haut(Gaulois * gaulois_ou_gauloise)
{
	if( LIMITE_HAUT <= gaulois_ou_gauloise->getNumeroColonne()-1)
	{
		return true;
	}else
		return false;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool ne_deborde_pas_par_le_bas(Gaulois * gaulois_ou_gauloise, int nb_cases_par_ligne)
{
	int LIMITE_BAS = nb_cases_par_ligne;
	
	
	if( LIMITE_BAS >= gaulois_ou_gauloise->getNumeroColonne()+1)
	{
		return true;
	}else
		return false;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------


//Les objets immobiles comme les arbres ne se deplacent pas donc ils sont à la même place dans l'ancienne grille et dans la nouvelle grille

bool case_a_gauche_n_est_pas_occupee_par_un_arbre (_map ancienne_grille , 
Gaulois * gaulois_ou_gauloise)
{
	
	_it_map it;
	
	
	_objet objet ;
	
	
	it = ancienne_grille->find(
	
	to_string(gaulois_ou_gauloise->getNumeroLigne()-1)
	+"x"+
	to_string(gaulois_ou_gauloise->getNumeroColonne())
	
	);
	
	bool case_vide = true;
	
	if( it != ancienne_grille->end() )
	{
		objet = it->second;
	
	
		if( objet->getType() == "Arbre" )
		{
			case_vide = false;			
		}
	}
	
	
	
	return case_vide;
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool case_a_droite_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , 
Gaulois * gaulois_ou_gauloise)
{
	
	
	_it_map it;
	
	shared_ptr<Objet> objet;

	
	
	it = ancienne_grille->find(
	to_string(gaulois_ou_gauloise->getNumeroLigne()+1)
	+"x"+
	to_string(gaulois_ou_gauloise->getNumeroColonne()) 
	) 
	;
	
	bool case_vide = true;
	
	if( it != ancienne_grille->end() )
	{
		objet = it->second;
	
	
		if( objet->getType() == "Arbre" )
		{
			case_vide = false;			
		}
	}
	
	return case_vide;
	
	
}

//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool case_en_haut_n_est_pas_occupee_par_un_arbre ( _map ancienne_grille , 
Gaulois * gaulois_ou_gauloise)
{
	
	_it_map it;
	
	_objet objet ;
	
	
	it = ancienne_grille->find(
	to_string(gaulois_ou_gauloise->getNumeroLigne())
	+"x"+
	to_string(gaulois_ou_gauloise->getNumeroColonne()-1) 
	);
	
	bool case_vide = true;
	
	
	if( it != ancienne_grille->end() )
	{
		objet = it->second;
	
	
		if( objet->getType() == "Arbre" )
		{
			case_vide = false;			
		}
	}
	
	return case_vide;
}


//-----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

bool case_en_bas_n_est_pas_occupee_par_un_arbre (_map  ancienne_grille , 
Gaulois * gaulois_ou_gauloise)
{
	
	_it_map it;
	
	_objet objet ;


	it = ancienne_grille->find(
	to_string(gaulois_ou_gauloise->getNumeroLigne())
	+"x"+
	to_string(gaulois_ou_gauloise->getNumeroColonne()+1)
	);
	
	bool case_vide = true;
	
	
	if( it != ancienne_grille->end() )
	{
		objet = it->second;
	
	
		if( objet->getType() == "Arbre" )
		{
			case_vide = false;			
		}
	}
	
	return case_vide;
}