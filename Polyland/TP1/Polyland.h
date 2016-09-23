/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"

class Polyland
{
public:
	Polyland();
	~Polyland();

	bool ajouterDresseur(Dresseur& dresseur);
	bool retirerDresseur(string nom);
	bool ajouterCreature(Creature& creature);
	bool retirerCreature(string nom);

	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();

	bool attraperCreature(Dresseur* dresseur, Creature Creature);
	bool relacherCreature(Dresseur* dresseur, Creature Creature);

	void infoDresseur(string nom) const;

private:
	Dresseur* dresseurs_[100];
	int nombreDresseurs_;
	Creature* creatures_[1000];
	int nombreCreatures_;
};

#endif