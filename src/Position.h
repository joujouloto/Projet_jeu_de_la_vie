#ifndef POSITION_H
#define POSITION_H


//-------------------------------------------------

#include <string>



//------------------------------------------------

using namespace std;


class Position
{
	protected:
	
	int abscisse;
	int ordonnee;
	
	public:
	
	Position();
	Position(int abs, int ord);
	int getAbscisse();
	int getOrdonnee();
	string toString();
	
	Position a_gauche();
	Position a_droite();
	Position en_haut();
	Position en_bas();
	
	bool operator < (const Position &other) const ;
	bool operator ==(const Position& p2) const ;
	
	
};



#endif