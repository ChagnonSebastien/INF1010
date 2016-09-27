#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	Dresseur(); // A MODIFIER... (si necessaire)
	Dresseur(const std::string& nom); // A MODIFIER... (si necessaire)
	~Dresseur(); // A MODIFIER... (si necessaire)

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const; // A MODIFIER... (si necessaire)

	Creature** obtenirCreatures() const; // A MODIFIER... (si necessaire)
	void modifierCreature(Creature** creatures); // A MODIFIER... (si necessaire)

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);
	
	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)
	bool enleverCreature(const std::string& nom); // A MODIFIER... (si necessaire)

	void affichage() const; // A COMPLETER... (si necessaire)

private:
	std::string nom_;
	ObjetMagique objetMagique_;

	// ___TP2____


};

#endif