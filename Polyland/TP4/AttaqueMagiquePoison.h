#ifndef ATAQUEMAGIQUEPOISON_H
#define ATAQUEMAGIQUEPOISON_H

#include "AttaqueMagique.h"

class AttaqueMagiquePoison : public AttaqueMagique
{
	AttaqueMagiquePoison();
	AttaqueMagiquePoison(unsigned int duree);
	~AttaqueMagiquePoison();

	virtual std::string obtenirTypeAttaque();

	void appliquerAttaque(Creature & creature);
	bool estFini();
};

#endif