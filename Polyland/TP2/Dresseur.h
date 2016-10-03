#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <vector>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

using namespace std;

class Dresseur
{
public:
	Dresseur();
	Dresseur(const string& nom, const string& equipe);
	~Dresseur();

	string obtenirNom() const;
	void modifierNom(const string& nom);
	
	unsigned int obtenirNombreCreatures() const;

	string obtenirNom() const;
	void modifierNom(const string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	vector<Creature*> obtenirCreatures() const;
	void modifierCreature(vector<Creature*> creatures);

	string obtenirEquipe() const;
	void modifierEquipe(string equipe);

	Creature obtenirCreature(string nom);

	friend ostream& operator<<(ostream& o, const Dresseur& dresseur);
	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const string nom) const;
	friend bool operator==(const string nom, const Dresseur& dresseur);

	void utiliserObjetMagique(Creature* creature);
	
	bool ajouterCreature(const Creature& creature);
	bool enleverCreature(const string& nom);

private:
	string nom_;
	ObjetMagique objetMagique_;
	vector<Creature*> creatures_;
	string equipe_;


};

#endif