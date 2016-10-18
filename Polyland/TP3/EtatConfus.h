
#ifndef ETATCONFU_H
#define ETATCONFU_H

#include "EtatCreature.h"

class EtatConfus : public EtatCreature
{
public:
	EtatConfus(const std::string& nom);
	EtatConfus(const std::string& nom, unsigned int duree);

	bool peutAttaquer() const;

	void appliquerEtat(Creature & creature);

	bool estFini() const;

	friend std::ostream& operator<<(std::ostream& o, const EtatConfus& etatConfu);

};

#endif