#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"

class CreatureMagique : public Creature
{
public:
	CreatureMagique(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus);
	CreatureMagique(const CreatureMagique& creatureMagique);

	unsigned int obtenirBonus() const;

	CreatureMagique& operator=(const CreatureMagique& creatureMagique);

	void attaquer(const Pouvoir & pouvoir, Creature & creature);

	friend std::ostream& operator<<(std::ostream& o, CreatureMagique& creatureMagique);

private:
	unsigned int bonus_;

};

#endif