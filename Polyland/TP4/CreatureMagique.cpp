
#include "Creature.h"
#include "CreatureMagique.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"

CreatureMagique::CreatureMagique() : Creature(), bonus_(0), attaqueMagique_(nullptr)
{
}

CreatureMagique::CreatureMagique(unsigned int bonus, const Creature& creature) :Creature(creature), bonus_(bonus), attaqueMagique_(nullptr)
{
}

CreatureMagique::CreatureMagique(const Creature& creature):Creature(creature), bonus_(0), attaqueMagique_(nullptr)
{
	if (creature.obtenirTypeCreature() == typeid(CreatureMagique).name())
	{
		bonus_ = ((CreatureMagique)creature).obtenirBonus();

		if (((CreatureMagique)creature).obtenirAttaqueMagique() != nullptr) {
			if (((CreatureMagique)creature).obtenirAttaqueMagique()->obtenirTypeAttaque() == typeid(AttaqueMagiqueConfusion).name()) {
				attaqueMagique_ = new AttaqueMagiqueConfusion(((CreatureMagique)creature).obtenirAttaqueMagique()->obtenirDuree());
			}
			else if (((CreatureMagique)creature).obtenirAttaqueMagique()->obtenirTypeAttaque() == typeid(AttaqueMagiquePoison).name())
			{
				attaqueMagique_ = new AttaqueMagiquePoison(((CreatureMagique)creature).obtenirAttaqueMagique()->obtenirDuree());
			}
		}
	}
}

CreatureMagique::~CreatureMagique()
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}

CreatureMagique& CreatureMagique::operator=(const Creature& creature)
{
	Creature::operator=(creature);
	if (creature.obtenirTypeCreature() == typeid(CreatureMagique).name())
	{
		bonus_ = ((CreatureMagique) creature).obtenirBonus();

		if (((CreatureMagique)creature).obtenirAttaqueMagique() != nullptr) {
			if (((CreatureMagique)creature).obtenirAttaqueMagique()->obtenirTypeAttaque() == typeid(AttaqueMagiqueConfusion).name()) {
				attaqueMagique_ = new AttaqueMagiqueConfusion(((CreatureMagique)creature).obtenirAttaqueMagique()->obtenirDuree());
			}
			else if (((CreatureMagique)creature).obtenirAttaqueMagique()->obtenirTypeAttaque() == typeid(AttaqueMagiquePoison).name())
			{
				attaqueMagique_ = new AttaqueMagiquePoison(((CreatureMagique)creature).obtenirAttaqueMagique()->obtenirDuree());
			}
		}
	}
	else
	{
		bonus_ = 0;
		attaqueMagique_ = nullptr;
	}
	return *this;

}
std::string CreatureMagique::obtenirTypeCreature() const
{
	return typeid(CreatureMagique).name();
}
;


unsigned int CreatureMagique::obtenirBonus() const 
{
	return bonus_;
}


AttaqueMagique* CreatureMagique::obtenirAttaqueMagique() const 
{
	return attaqueMagique_;
}

void CreatureMagique::modifierBonus(unsigned int bonus) 
{
	bonus_ = bonus;
}


void CreatureMagique::modifierAttaqueMagique(AttaqueMagique* attaqueMagique) 
{
	attaqueMagique_ = attaqueMagique;
}

void CreatureMagique::attaquer(Pouvoir& pouvoir, Creature& creature) 
{
	if (attaqueMagique_->obtenirDuree() > 0) {
		attaqueMagique_->appliquerAttaque(creature);
	}

	Creature::attaquer(pouvoir, creature);
	unsigned int nouveauPdV = obtenirPointDeVie() + bonus_;
	modifierPointDeVie(nouveauPdV > obtenirPointDeVieTotal() ? obtenirPointDeVieTotal() : nouveauPdV);

}


void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique* attaqueMagique) {

	attaqueMagique_ = attaqueMagique;
}

void CreatureMagique::oublierAttaqueMagique() {

	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}

std::ostream& operator<<(std::ostream & o, CreatureMagique & creatureMagique)
{
	o << static_cast<Creature&>(creatureMagique);
	o << "Cette creature de la class CreatureMagique ";

	if (creatureMagique.obtenirAttaqueMagique() != nullptr)
		o << creatureMagique.obtenirAttaqueMagique();
	
	return o;

}

