#include "AttaqueMagiqueConfusion.h"
#include <time.h>

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() : AttaqueMagique(2) {

}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) : AttaqueMagique(duree) {

}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

std::string AttaqueMagiqueConfusion::obtenirTypeAttaque() const
{
	return typeid(AttaqueMagiqueConfusion).name();
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) const
{
	srand(time(NULL));
	if (rand() % 3 == 0 && creature.obtenirPointDeVie() >= 5 && !estFini())
	{
		creature.modifierPointDeVie(creature.obtenirPointDeVie() - 2);
	}
}

bool AttaqueMagiqueConfusion::estFini() const
{
	return duree_ == 0;
}
