#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

class PolyLand
{
public:
	PolyLand(); // A MODIFIER... (si necessaire)
	~PolyLand(); // A MODIFIER... (si necessaire)
	
	bool ajouterDresseur(Dresseur* dresseur); // A MODIFIER... (si necessaire)
	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)

	bool retirerDresseur(const std::string& nom); // A MODIFIER... (si necessaire)
	bool retirerCreature(const std::string& nom); // A MODIFIER... (si necessaire)

	Dresseur* choisirDresseurAleatoire(); // A MODIFIER... (si necessaire)
	Creature* choisirCreatureAleatoire(); // A MODIFIER... (si necessaire)

	bool attraperCreature(Dresseur* dresseur, const Creature& creature); // A MODIFIER... (si necessaire)
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature); // A MODIFIER... (si necessaire)
	
	void infoDresseur(const std::string& nom) const; // A MODIFIER... (si necessaire)

	//________TP2_______

private:
	//________TP2_______

};
#endif