
#ifndef ETATEMPOISONNE_H
#define ETATEMPOISONNE_H

#include "EtatCreature.h"

class EtatEmpoisonne : public EtatCreature
{
public:
	EtatEmpoisonne(const std::string& nom);
	EtatEmpoisonne(const std::string& nom, unsigned int duree);

	friend std::ostream& operator<<(std::ostream& o, const EtatEmpoisonne& etatEmpoisonne);

};

#endif