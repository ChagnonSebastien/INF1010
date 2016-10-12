
#ifndef POUVOIRSPORIFIQUE_H
#define POUVOIRSPORIFIQUE_H

#include "Pouvoir.h"

class PouvoirSoporifique : public Pouvoir
{
public:
	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

	friend std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& pouvoirSporifique);

private:
	int duree_;

};

#endif