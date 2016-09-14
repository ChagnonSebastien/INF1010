/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef OBJET_MAGIQUE_H
#define OBJET_MAGIQUE_H

#include <string>

using namespace std;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(string nom, int bonus);
	~ObjetMagique();

	void modifierNom(string nom);
	string obtenirNom();
	void modifierBonus(int bonus);
	int obtenirBonus();

	void affichage();

private:
	string nom_;
	int bonus_;

};

#endif