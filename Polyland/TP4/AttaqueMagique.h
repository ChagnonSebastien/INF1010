/*
Fichier: Creature.h
Auteur(s): Alexandre MAO, Maude CARRIER et Philippe TROCLET
Date de creation: 31 aout 2016
Date de modification: 11 octobre 2016 par Maude Carrier
Description: Les creatures sont des etres destines au combat
*/
#ifndef ATAQUEMAGIQUE_H
#define ATAQUEMAGIQUE_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "Creature.h"

class AttaqueMagique
{
public:
	AttaqueMagique(unsigned int duree);
	~AttaqueMagique();

	unsigned int obtenirDuree();
	void definirDuree(unsigned int duree);

	virtual std::string obtenirTypeAttaque();

	virtual void appliquerAttaque(Creature & creature);
	virtual bool estFini();

	friend std::ostream& operator<<(std::ostream& o, AttaqueMagique attaqueMagique);

protected:
	unsigned int duree_;
};

#endif