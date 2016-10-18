#include "Elixir.h"

Elixir::Elixir() : PotionMagique()
{
}

Elixir::Elixir(const std::string & nom, int bonus) : PotionMagique(nom, bonus)
{
}

std::ostream & operator<<(std::ostream & os, const Elixir & elixir)
{
	os << "L'objet " << elixir.obtenirNom() << " soigne de " << (2 * elixir.obtenirBonus()) << " points de vie et fournit " << elixir.obtenirBonus() << " point(s) d'énergie";
}

void Elixir::utiliserSur(Creature & creature) const
{
	int pointDeViePlusBonus = creature.obtenirPointDeVie + (obtenirBonus() * 2);
	creature.modifierPointDeVie(pointDeViePlusBonus > creature.obtenirPointDeVieTotal() ? creature.obtenirPointDeVieTotal : pointDeViePlusBonus);

	int energiePlusBonus = creature.obtenirEnergie() + obtenirBonus();
	creature.modifierPointDeVie(energiePlusBonus > creature.obtenirEnergieTotale() ? creature.obtenirEnergieTotale() : energiePlusBonus);
}