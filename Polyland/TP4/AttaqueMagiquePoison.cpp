#include "AttaqueMagiquePoison.h"
#include <time.h>

AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(2) {

}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree) {

}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}

std::string AttaqueMagiquePoison::obtenirTypeAttaque()
{
	return typeid(AttaqueMagiquePoison).name();
}

void AttaqueMagiquePoison::appliquerAttaque(Creature & creature)
{
	srand(time(NULL));
	if (rand() % 3 == 0 && creature.obtenirEnergie() >= 5 && !estFini())
	{
		creature.modifierEnergie(creature.obtenirEnergie() - 2);
	}
}

bool AttaqueMagiquePoison::estFini()
{
	return duree_ == 0;
}
