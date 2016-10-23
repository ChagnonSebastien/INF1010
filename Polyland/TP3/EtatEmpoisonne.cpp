#include "EtatEmpoisonne.h"

EtatEmpoisonne::EtatEmpoisonne(const std::string & nom) : EtatCreature(nom)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}

EtatEmpoisonne::EtatEmpoisonne(const std::string & nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}

std::ostream & operator<<(std::ostream & o, const EtatEmpoisonne & etatEmpoisonne)
{
	return o << "etat empoisonne :" << etatEmpoisonne.obtenirNom() << " durera " << etatEmpoisonne.duree_;
}

void EtatEmpoisonne::appliquerEtat(Creature & creature)
{
	creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
	duree_--;
}

bool EtatEmpoisonne::estFini() const
{
	return duree_ <= 0;
}