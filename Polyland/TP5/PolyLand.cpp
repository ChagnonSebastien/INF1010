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


using namespace std;

template<typename T, typename S>
bool PolyLand<T,S>::attraperCreature(T* dresseur, S* creature)
{
	return dresseur->ajouterCreature(creature);
}

template<typename T, typename S>
bool PolyLand<T,S>::relacherCreature(T* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}



template<typename T, typename S>
std::ostream & operator<<(std::ostream & o, const PolyLand<T,S>& polyland)
{
	FoncteurComparerDresseurs foncteurComparerDresseur;
	sort(polyland.listMaitre_.begin(), polyland.listMaitre_.end(), foncteurComparerDresseur());

	FoncteurComparerCreatures foncteurComparerCreatures;
	sort(polyland.listCompagnon_.begin(), polyland.listCompagnon_.end(), foncteurComparerCreatures());

	list<S*>::iterator last = polyland.listMaitre_.last();
	copy(polyland.listMaitre_.first(), last, ostream_iterator<S>(o, "\n")->obtenirNom());

	list<T*>::iterator last = polyland.listCompagnon_.last();
	copy(polyland.listCompagnon_.first(), last, ostream_iterator<T>(o, "\n")->obtenirNom());
}


