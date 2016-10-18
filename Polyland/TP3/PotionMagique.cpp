#include "PotionMagique.h"

PotionMagique::PotionMagique() : ObjetMagique()
{
}

PotionMagique::PotionMagique(const std::string & nom, int bonus) : ObjetMagique(nom, bonus)
{
}

std::ostream & operator<<(std::ostream & os, const PotionMagique & potionMagique)
{
	os << "L'objet " << potionMagique.obtenirNom() << " soigne de " << potionMagique.obtenirBonus() << " points de vie";
}

void PotionMagique::utiliserSur(Creature & creature) const
{
	int pointDeViePlusBonus = creature.obtenirPointDeVie + obtenirBonus();
	creature.modifierPointDeVie(pointDeViePlusBonus > creature.obtenirPointDeVieTotal() ? creature.obtenirPointDeVieTotal : pointDeViePlusBonus);
}