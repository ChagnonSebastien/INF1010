/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>
#include "Pouvoir.h"

using namespace std;

class Creature
{
public:
	Creature();
	Creature(string nom, int attaque, int defence, int pointDeVie, int energie, Pouvoir pouvoir);
	~Creature();

	string obtenirNom() const;
	void modifierNom(string nom);
	int obtenirAttaque() const;
	void modifierAttaque(int attaque);
	int obtenirDefense() const;
	void modifierDefense(int defense);
	int obtenirPointDeVie() const;
	void modifierPointDeVie(int pointDeVie);
	int obtenirPointDeVieTotal() const;
	void modifierPointDeVieTotal(int pointDeVieTotal);
	int obtenirEnergie() const;
	void modifierEnergie(int energie);
	int obtenirEnergieTotale() const;
	void modifierEnergieTotale(int energieTotal);
	int obtenirExperience() const;
	void modifierExperience(int experience);
	int obtenirExperienceNecessaire() const;
	void modifierExperienceNecessaire(int experienceNecessaire);
	int obtenirNiveau() const;
	void modifierNiveau(int niveau);
	Pouvoir obtenirPouvoir() const;
	void modifierPouvoir(Pouvoir pouvoir);

	void attaquer(Creature & creature);
	int experienceGagner(const Creature& creature);
	void information();

private:
	string nom_;
	int attaque_;
	int defense_;
	int pointDeVie_;
	int pointDeVieTotal_;
	int energie_;
	int energieTotal_;
	int experience_;
	int experienceNecessaire_;
	int niveau_;
	Pouvoir pouvoir_;

};

#endif