
#ifndef POTIONMAGIQUE_H
#define POTIONMAGIQUE_H

#include "ObjetMagique.h"

class PotionMagique : public ObjetMagique
{
public:
	PotionMagique();
	PotionMagique(const std::string &nom, int bonus);

	friend std::ostream& operator<<(std::ostream& os, const PotionMagique& potionMagique);

};

#endif