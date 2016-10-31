#ifndef ATAQUEMAGIQUECONFUSION_H
#define ATAQUEMAGIQUECONFUSION_H

#include "AttaqueMagique.h"

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:
	AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(unsigned int duree);
	~AttaqueMagiqueConfusion();

	virtual std::string obtenirTypeAttaque();

	void appliquerAttaque(Creature & creature);
	bool estFini();
};

#endif