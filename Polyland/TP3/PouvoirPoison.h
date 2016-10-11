
#ifndef POUVOIRPOISON_H
#define POUVOIRPOISON_H

#include "Pouvoir.h"

class PouvoirPoison : public Pouvoir
{
public:
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

	friend std::ostream& operator<<(std::ostream& os, const PouvoirPoison& pouvoirPoison);

private:
	int duree_;

};

#endif