
#ifndef ETATENDORMI_H
#define ETATENDORMI_H

#include "EtatCreature.h"

class EtatEndormi : public EtatCreature
{
public:
	EtatEndormi(const std::string& nom);
	EtatEndormi(const std::string& nom, unsigned int duree);

	friend std::ostream& operator<<(std::ostream& o, const EtatEndormi& etatEndormi);

};

#endif