#include "EtatConfus.h"
#include <time.h>

EtatConfus::EtatConfus(const std::string & nom) : EtatCreature(nom)
{
	type_ = TypeEtat::TypeEtat_confus;
}

EtatConfus::EtatConfus(const std::string & nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat::TypeEtat_confus;
}

std::ostream & operator<<(std::ostream & o, const EtatConfus & etatConfu)
{
	return o << "etat confu :" << etatConfu.obtenirNom() << " durera " << etatConfu.duree_;
}

bool EtatConfus::peutAttaquer() const
{
	srand(time(NULL));
	return rand() % 2;
}

void EtatConfus::appliquerEtat(Creature & creature)
{
	srand(time(NULL));
	if (!(rand() % 3))
	{
		unsigned int dommage = creature.obtenirPointDeVie() / 20;
		creature.modifierPointDeVie(dommage < 5 ? 5 : dommage);
	}

	duree_--;
}

bool EtatConfus::estFini() const
{
	srand(time(NULL));
	return (!(rand() % 3) || duree_ <= 0);
}