#include "PouvoirHallucinogene.h"

PouvoirHallucinogene::PouvoirHallucinogene(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
}

PouvoirHallucinogene::PouvoirHallucinogene(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
}

std::ostream & operator<<(std::ostream & os, const PouvoirHallucinogene & pouvoirHallucinogene)
{
	// TODO: insert return statement here
}
