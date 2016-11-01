#include "AttaqueMagique.h"

AttaqueMagique::AttaqueMagique(unsigned int duree) : duree_(duree)
{
}

AttaqueMagique::~AttaqueMagique()
{
}

unsigned int AttaqueMagique::obtenirDuree() const
{
	return duree_;
}

void AttaqueMagique::definirDuree(unsigned int duree)
{
	duree_ = duree;
}

void AttaqueMagique::appliquerAttaque(Creature & creature) const
{
	//Virtual : Cette methode est redéfinie dans les classes filles
}

bool AttaqueMagique::estFini() const
{
	//Virtual : Cette methode est redéfinie dans les classes filles
	return true;
}

std::ostream & operator<<(std::ostream & o, const AttaqueMagique& attaqueMagique)
{
	o << "aussi une attaque magique de type " << attaqueMagique.obtenirTypeAttaque() << " qui a une durée de " << attaqueMagique.obtenirDuree();
	return o;
}
