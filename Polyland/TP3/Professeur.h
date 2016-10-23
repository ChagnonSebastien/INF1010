
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "OutilScientifique.h"
#include "Dresseur.h"

class Professeur : public Dresseur
{
public:
	Professeur(const std::string& nom, const std::string& equipe);
	Professeur(Professeur& professeur);
	~Professeur();

	OutilScientifique& obtenirOutilScientifique() const;
	void modifierOutilScientifique(OutilScientifique outilScientifique);

	void soignerCreature(Creature& creature);
	void utiliserOutil(Creature& creature);

	Professeur& operator=(const Professeur& professeur);

private:
	OutilScientifique* outilScientifique_;

};

#endif