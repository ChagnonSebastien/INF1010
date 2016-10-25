
#include "Creature.h"
#include "..\TP4\CreatureMagique.h"

CreatureMagique::CreatureMagique(unsigned int bonus, const Creature& creature) :Creature(creature), bonus_(bonus)
{
};

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique):Creature(creatureMagique), bonus_(creatureMagique.obtenirBonus()), attaqueMagique_(creatureMagique.obtenirAttaqueMagique())
{
};

CreatureMagique::~CreatureMagique()
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
};

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
	Creature::operator=(creatureMagique);
	bonus_ = creatureMagique.obtenirBonus();
	attaqueMagique_ = new AttaqueMagique(creatureMagique.obtenirAttaqueMagique);
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
		attaqueMagique_->appliquerAttaque();
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

