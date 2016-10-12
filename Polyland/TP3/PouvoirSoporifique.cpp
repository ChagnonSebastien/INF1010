#include "PouvoirSoporifique.h"

PouvoirSoporifique::PouvoirSoporifique(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
}

PouvoirSoporifique::PouvoirSoporifique(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
}

std::ostream & operator<<(std::ostream & os, const PouvoirSoporifique & pouvoirSporifique)
{
	// TODO: insert return statement here
}
