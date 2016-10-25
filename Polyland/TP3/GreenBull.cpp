/*
Fichier: GreenBull.cpp
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe GreenBull correspond a un objet magique qui redonne de l'energie
a la creature
*/

#include "GreenBull.h"

GreenBull::GreenBull() : ObjetMagique()
{
}

GreenBull::GreenBull(const std::string & nom, int bonus) : ObjetMagique(nom, bonus)
{
}

std::ostream & operator<<(std::ostream & o, const GreenBull & greenBull)
{
	 return o << "L'objet " << greenBull.obtenirNom() << " fournit " << greenBull.obtenirBonus() << " point(s) d'énergie";
}

void GreenBull::utiliserSur(Creature & creature) const
{
	int energiePlusBonus = creature.obtenirEnergie() + obtenirBonus();
	creature.modifierPointDeVie(energiePlusBonus > creature.obtenirEnergieTotale() ? creature.obtenirEnergieTotale() : energiePlusBonus);
}