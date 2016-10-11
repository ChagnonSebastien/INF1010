#include "EtatEndormi.h"

EtatEndormi::EtatEndormi(const std::string & nom) : EtatCreature(nom)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const std::string & nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

std::ostream & operator<<(std::ostream & o, const EtatEndormi & etatEndormi)
{
	o << "etat endormi :" << etatEndormi.obtenirNom() << " durera " << etatEndormi.duree_;
}

bool EtatCreature::peutAttaquer() const
{
	return false;
}

void EtatCreature::appliquerEtat(Creature & creature)
{
	if (duree_ <= 0)
		duree_--;
}

bool EtatCreature::estFini() const
{
	return duree_ <= 0;
}