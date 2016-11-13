#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION), foncteur_(FoncteurGenerateurNombresAlea(1,6)) // À MODIFIER
{}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) :AttaqueMagique(duree), foncteur_(FoncteurGenerateurNombresAlea(1, 6)) // À MODIFIER
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) //A modifier
{
    if (duree_ > 0 && creature.obtenirPointDeVie() >= 5) 
	{
        unsigned int pointDeVie = creature.obtenirPointDeVie();
        if (foncteur_() == 0) 
		{
            creature.modifierPointDeVie(pointDeVie - 2);
        }
        duree_--;
    }
}

bool AttaqueMagiqueConfusion::estFini() const
{
    return ( duree_ <= 0 );
}

std::string AttaqueMagiqueConfusion::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
