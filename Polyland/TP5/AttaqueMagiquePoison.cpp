/*
Fichier: AttaqueMagiquePoison.cpp
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Les creatures magiques possèdent des attaques magiques
*/#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(MIN_DUREE_POISON), foncteur_(FoncteurGenerateurNombresAlea(1,6)) // À MODIFIER
{}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree), foncteur_(FoncteurGenerateurNombresAlea(1, 6)) // À MODIFIER
{}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}

void AttaqueMagiquePoison::appliquerAttaque(Creature & creature) //A modifier
{
	if (duree_ > 0 && creature.obtenirEnergie() >= 5)
	{
		unsigned int energie = creature.obtenirEnergie();
		if (foncteur_() == 0)
		{
			creature.modifierEnergie(energie - 2);
		}
		duree_--;
	}
}

bool AttaqueMagiquePoison::estFini() const
{
    return (duree_ <= 0);
}

std::string AttaqueMagiquePoison::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
