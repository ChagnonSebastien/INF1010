#include "GreenBull.h"

GreenBull::GreenBull() : ObjetMagique()
{
}

GreenBull::GreenBull(const std::string & nom, int bonus) : ObjetMagique(nom, bonus)
{
}

std::ostream & operator<<(std::ostream & os, const GreenBull & greenBull)
{
	os << "L'objet " << greenBull.obtenirNom() << " fournit " << greenBull.obtenirBonus() << " point(s) d'�nergie";
}

void ObjetMagique::utiliserSur(Creature & creature) const
{
	int energiePlusBonus = creature.obtenirEnergie() + bonus_;
	creature.modifierPointDeVie(energiePlusBonus > creature.obtenirEnergieTotale() ? creature.obtenirEnergieTotale() : energiePlusBonus);
}