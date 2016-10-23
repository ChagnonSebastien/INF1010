#include "PotionMagique.h"

PotionMagique::PotionMagique() : ObjetMagique()
{
}

PotionMagique::PotionMagique(const std::string & nom, int bonus) : ObjetMagique(nom, bonus)
{
}

std::ostream & operator<<(std::ostream & o, const PotionMagique & potionMagique)
{
	return o << "L'objet " << potionMagique.obtenirNom() << " soigne de " << potionMagique.obtenirBonus() << " points de vie";
}

void PotionMagique::utiliserSur(Creature & creature) const
{
	unsigned int pointDeViePlusBonus = creature.obtenirPointDeVie() + obtenirBonus();
	creature.modifierPointDeVie(pointDeViePlusBonus > creature.obtenirPointDeVieTotal() ? creature.obtenirPointDeVieTotal() : pointDeViePlusBonus);
}