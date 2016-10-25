#include "AttaqueMagique.h"

AttaqueMagique::AttaqueMagique(unsigned int duree) : duree_(duree)
{
}

AttaqueMagique::~AttaqueMagique()
{
}

unsigned int AttaqueMagique::obtenirDuree()
{
	return duree_;
}

void AttaqueMagique::definirDuree(unsigned int duree)
{
	duree_ = duree;
}

std::string AttaqueMagique::obtenirTypeAttaque()
{
	return typeid(AttaqueMagique).name();
}

void AttaqueMagique::appliquerAttaque(Creature & creature)
{
	//Virtual : Cette methode est redéfinie dans les classes filles
}

bool AttaqueMagique::estFini()
{
	//Virtual : Cette methode est redéfinie dans les classes filles
	return true;
}

std::ostream & operator<<(std::ostream & o, AttaqueMagique attaqueMagique)
{
	o << "aussi une attaque magique de type class " << attaqueMagique.obtenirTypeAttaque() << " qui a une durée de " << attaqueMagique.obtenirDuree();
	return o;
}
