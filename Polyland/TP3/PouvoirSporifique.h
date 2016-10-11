
#ifndef POUVOIRSPORIFIQUE_H
#define POUVOIRSPORIFIQUE_H

#include "Pouvoir.h"

class PouvoirSporifique : public Pouvoir
{
public:
	PouvoirSporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirSporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

	friend std::ostream& operator<<(std::ostream& os, const PouvoirSporifique& pouvoirSporifique);

private:
	int duree_;

};

#endif