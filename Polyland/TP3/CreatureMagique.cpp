#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const std::string & nom, unsigned int attaque, unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus): Creature(nom, attaque, defense, pointDeVie, energie), bonus_(bonus)
{
}

CreatureMagique::CreatureMagique(const CreatureMagique & creatureMagique)
	: Creature(creatureMagique)
{
	bonus_ = creatureMagique.bonus_;
}

CreatureMagique & CreatureMagique::operator=(const CreatureMagique & creatureMagique) 
{
	Creature::operator=(creatureMagique);
	bonus_ = creatureMagique.bonus_;
	return *this;
}
unsigned int CreatureMagique::obtenirBonus() const
{


	return bonus_;
}
std::ostream & operator<<(std::ostream & o, CreatureMagique& creatureMagique)
{
	o << dynamic_cast<Creature&>(creatureMagique)
		<< "Elle a un bonus de " << creatureMagique.obtenirBonus();
	return o;

}

void CreatureMagique::attaquer(const Pouvoir & pouvoir, Creature & creature)
{
	Creature::attaquer(pouvoir, creature);
	unsigned int nouveauPdV = obtenirPointDeVie() + bonus_;
	modifierPointDeVie(nouveauPdV > obtenirPointDeVieTotal() ? obtenirPointDeVieTotal() : nouveauPdV);
}