/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef CREATURE_H
#define CREATURE_H

#include "Pouvoir.h"

class Creature
{
public:
	void Creature::attaquer(const Pouvoir & pouvoir, Creature & creature);
	int Creature::experienceGagner(const Creature& creature);

private:

};

#endif