/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
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
	
	//list<T*>::iterator end = polyland.listMaitre_.end();
	//copy(polyland.listMaitre_.begin(), end, ostream_iterator<S>(o, "\n"));

	//list<S*>::iterator end = polyland.listCompagnon_.end();
	//copy(polyland.listCompagnon_.begin(), end, ostream_iterator<T>(o, "\n"));
	return o;
}
