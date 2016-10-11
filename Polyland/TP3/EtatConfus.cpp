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
	o << "etat confu :" << etatConfu.obtenirNom() << " durera " << etatConfu.duree_;
}

bool EtatCreature::peutAttaquer() const
{
	srand(time(NULL));
	return rand() % 2;
}

void EtatCreature::appliquerEtat(Creature & creature)
{
	srand(time(NULL));
	if (rand() % 3)
	{
		int dommage = creature.obtenirPointDeVie / 20;
		creature.modifierPointDeVie(dommage < 5 ? 5 : dommage);
	}

	duree_--;
}

bool EtatCreature::estFini() const
{
	srand(time(NULL));
	return rand() % 3 || duree_ <= 0;
}