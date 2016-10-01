#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <iostream>
#include "ObjetMagique.h"
#include "Pouvoir.h"

class Creature
{
public:
	Creature(); // A MODIFIER... (si necessaire)
	Creature(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie); // A COMPLETER... (si necessaire)
	~Creature(); // A MODIFIER... (si necessaire) DONE

	std::string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	std::vector<Pouvoir*> obtenirPouvoir() const; // A MODIFIER... (si necessaire) DONE

	void attaquer(Creature& creature);// A MODIFIER... (si necessaire)
	int experienceGagnee(const Creature& creature);

	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoir(std::vector<Pouvoir*>& pouvoirs); // A MODIFIER... (si necessaire) DONE

	void information() const; // A MODIFIER... (si necessaire)

	void apprendrePouvoir(Pouvoir& pouvoir);
	void oublierPouvoir(std::string nom);

	bool operator==(const Pouvoir& pouvoir) const;
	bool operator==(const std::string& nom) const;
	bool operator==(const Creature& creature) const;
	std::ostream& operator<<(std::ostream& o);
	// _________TP2___________

private:

	std::string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	std::vector<Pouvoir*> pouvoir_;

	// _________TP2___________

};

#endif