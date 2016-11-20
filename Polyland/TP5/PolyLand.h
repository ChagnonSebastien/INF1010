/*
Fichier: PolyLand.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: Polyland represente le pays que l'on va explorer, il va contenir
            les differents elements de jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#include "MondeMagique.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


template<typename T, typename S>
class PolyLand: public MondeMagique<T, S>
{
public:

	bool attraperCreature(T* dresseur, S* creature);
	bool relacherCreature(T* dresseur, const std::string& nomCreature);

	template<typename T, typename S>
	friend std::ostream& operator<<(std::ostream& o, const PolyLand<T,S>& polyland);

};


template<typename T, typename S>
bool PolyLand<T, S>::attraperCreature(T* dresseur, S* creature)
{
	return dresseur->ajouterCreature(creature);
}

template<typename T, typename S>
bool PolyLand<T, S>::relacherCreature(T* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

template<typename T, typename S>
std::ostream & operator<<(std::ostream & o, const PolyLand<T, S>& polyland)
{
	o << "allo" << std::endl;
	FoncteurComparerDresseurs foncteurComparerDresseurs;
	sort(polyland.obtenirListeMaitre().begin(), polyland.obtenirListeMaitre().end(), foncteurComparerDresseurs);

	FoncteurComparerCreatures foncteurComparerCreatures;
	sort(polyland.obtenirListeCompagnon().begin(), polyland.obtenirListeCompagnon().end(), foncteurComparerCreatures);

	for (std::list<T*>::const_iterator it = polyland.obtenirListeMaitre().begin(); it != polyland.obtenirListeMaitre().end(); it++) {
		o << *it << std::endl;
	}

	for (std::list<S*>::const_iterator it = polyland.obtenirListeCompagnon().begin(); it != polyland.obtenirListeCompagnon().end(); it++) {
		o << *it << std::endl;
	}

	//list<T*>::iterator end = polyland.listMaitre_.end();
	//copy(polyland.listMaitre_.begin(), end, ostream_iterator<S>(o, "\n"));

	//list<S*>::iterator end = polyland.listCompagnon_.end();
	//copy(polyland.listCompagnon_.begin(), end, ostream_iterator<T>(o, "\n"));
	o << "allo" << std::endl;
	return o;
}
#endif