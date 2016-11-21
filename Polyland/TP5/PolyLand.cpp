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
	
	//o << "allo" << std::endl;
	
	FoncteurComparerDresseurs foncteurComparerDresseurs;
	std::sort(polyland.obtenirListeMaitre().begin(), polyland.obtenirListeMaitre().end(), foncteurComparerDresseurs);
/*
	FoncteurComparerCreatures foncteurComparerCreatures;
	std::sort(polyland.obtenirListeCompagnon().begin(), polyland.obtenirListeCompagnon().end(), foncteurComparerCreatures);
	*/
	for (std::list<Dresseur*>::const_iterator it = polyland.obtenirListeMaitre().begin(); it != polyland.obtenirListeMaitre().end(); it++) {
		o << *it << std::endl;
	}

	for (std::list<Creature*>::const_iterator it = polyland.obtenirListeCompagnon().begin(); it != polyland.obtenirListeCompagnon().end(); it++) {
		o << *it << std::endl;
	}
	
	//list<T*>::iterator end = polyland.listMaitre_.end();
	//copy(polyland.listMaitre_.begin(), end, ostream_iterator<S>(o, "\n"));

	//list<S*>::iterator end = polyland.listCompagnon_.end();
	//copy(polyland.listCompagnon_.begin(), end, ostream_iterator<T>(o, "\n"));
	o << "allo" << std::endl;
	return o;
}
