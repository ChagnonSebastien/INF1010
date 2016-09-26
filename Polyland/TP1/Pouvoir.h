/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>

using namespace std;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(string nom, int nombreDeDegats, int energieNecessaire);
	~Pouvoir();

	string obtenirNom() const;
	void modifierNom(string nom);
	int obtenirNombreDeDegat() const;
	void modifierNombreDeDegat(int nombreDeDegat);
	int obtenirEnergieNecessaire() const;
	void modifierEnergieNecessaire(int energieNecessaire);

	void description();

private:
	string nom_;
	int nombreDeDegats_;
	int energieNecessaire_;

};

#endif