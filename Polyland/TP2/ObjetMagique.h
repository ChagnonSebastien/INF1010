#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const std::string &nom, int bonus);
	~ObjetMagique();

	std::string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const std::string& nom);
	void modifierBonus(int bonus);

	void affichage() const; // A MODIFIER... (si necessaire)

private:
	std::string nom_;
	int bonus_;
};

#endif
