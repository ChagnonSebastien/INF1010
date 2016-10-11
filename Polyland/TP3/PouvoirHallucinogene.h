#ifndef POUVOIRHALLUCINOGENE_H
#define POUVOIRHALLUCINOGENE_H

#include "Pouvoir.h"

class PouvoirHallucinogene : public Pouvoir
{
public:
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

	friend std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& pouvoirHallucinogene);

private:
	int duree_;

};

#endif