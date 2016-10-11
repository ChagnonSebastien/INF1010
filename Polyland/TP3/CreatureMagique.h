#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"

class CreatureMagique : public Creature
{
public:
	CreatureMagique(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus);
	CreatureMagique(CreatureMagique& creatureMagique);

	CreatureMagique& operator=(const CreatureMagique& creatureMagique) const;

	friend std::ostream& operator<<(std::ostream& o, const CreatureMagique& creatureMagique);

private:
	unsigned int bonus_;

};

#endif