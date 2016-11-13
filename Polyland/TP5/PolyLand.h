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
#include "Foncteur.h"


template<typename T, typename S>
class PolyLand: public MondeMagique<T, S>
{
public:

	bool attraperCreature(T* dresseur, S* creature);
	bool relacherCreature(T* dresseur, const std::string& nomCreature);
	friend std::ostream& operator<<(std::ostream& o, const PolyLand<T,S>& polyland);

};
#endif