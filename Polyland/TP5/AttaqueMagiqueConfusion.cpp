/*
Fichier: AttaqueMagiqueConfusion.cpp
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Les creatures magiques poss�dent des attaques magiques
*/
#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION), foncteur_(FoncteurGenerateurNombresAlea(1,6)) // � MODIFIER
{}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) :AttaqueMagique(duree), foncteur_(FoncteurGenerateurNombresAlea(1, 6)) // � MODIFIER
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) //A modifier
{
    if (duree_ > 0 && creature.obtenirPointDeVie() >= 5) 
	{
        unsigned int pointDeVie = creature.obtenirPointDeVie();
        if (foncteur_() == 0) 
		{
            creature.modifierPointDeVie(pointDeVie - 2);
        }
        duree_--;
    }
}

bool AttaqueMagiqueConfusion::estFini() const
{
    return ( duree_ <= 0 );
}

std::string AttaqueMagiqueConfusion::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
