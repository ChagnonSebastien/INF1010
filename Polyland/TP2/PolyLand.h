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
	bool retirerDresseur(const std::string& nom); // A MODIFIER... (si necessaire)
	PolyLand operator+=(Dresseur* dresseur);
	PolyLand operator-=(Dresseur* dresseur);

	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)
	bool retirerCreature(const std::string& nom); // A MODIFIER... (si necessaire)
	PolyLand operator+=(Creature& creature);
	PolyLand operator-=(Creature& creature);

	Dresseur* choisirDresseurAleatoire(); // A MODIFIER... (si necessaire)
	Creature* choisirCreatureAleatoire(); // A MODIFIER... (si necessaire)

	bool attraperCreature(Dresseur* dresseur, const Creature& creature); // A MODIFIER... (si necessaire)
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature); // A MODIFIER... (si necessaire)

	friend ostream& operator<<(ostream& o, const PolyLand& polyland);

		
	//________TP2_______

private:
	vector<Creature*> creatures_;
	vector<Dresseur*> dresseurs_;
	//________TP2_______

};
#endif