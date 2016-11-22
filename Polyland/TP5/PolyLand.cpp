/*
Fichier: PolyLand.cpp
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Polyland represente le pays que l'on va explorer, il va contenir
les differents elements de jeu
*/
#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <iostream>
#include "Foncteur.h"



bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

std::ostream & operator<<(std::ostream & o, const PolyLand& polyland)
{
	
	FoncteurComparerDresseurs foncteurComparerDresseurs;
	std::list<Dresseur*> dresseurs = polyland.obtenirListeMaitre();
	dresseurs.sort(foncteurComparerDresseurs);

	FoncteurComparerCreatures foncteurComparerCreatures;
	std::list<Creature*> creatures = polyland.obtenirListeCompagnon();
	creatures.sort(foncteurComparerCreatures);

	for (std::list<Dresseur*>::const_iterator it = dresseurs.begin(); it != dresseurs.end(); it++) {
		o << **it << std::endl;
	}

	for (std::list<Creature*>::const_iterator it = creatures.begin(); it != creatures.end(); it++) {
		o << **it << std::endl;
	}
	
	return o;
}
