/*
Fichier: Creature.h
Auteur(s): Sébastien CHAGNON, Audrey LABRIE
Date de creation: 13 septembre 2016
Date de modification: 26 septembre 2016
Description: Les creatures sont les etres qui hantent le monde de Polyland
*/

#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

#include "Pouvoir.h"

using namespace std;

/**
* @brief La classe Creature, pour decrire une creature
*/
class Creature
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	Creature();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom de la creature
	* @param attaque Force de l'attaque de la creature
	* @param defence Valeur de la defence de la creature
	* @param pointDeVie Quantite de points de vie total et actuelle de la creature
	* @param energie quantite d'energie totale et actuelle de la creature
	* @param pouvoir Pouvoir de la creature
	*/
	Creature(string nom, int attaque, int defence, int pointDeVie, int energie, Pouvoir pouvoir);

	/**
	* @brief Destructeur de la classe
	*/
	~Creature();


	// Getters
	/**
	* @brief Pour obtenir le nom de la creature
	* @return Le nom de la creature
	*/
	string obtenirNom() const;

	/**
	* @brief Pour obtenir la force d'attaque de la creature
	* @return La force d'attaque de la creature
	*/
	int obtenirAttaque() const;

	/**
	* @brief Pour obtenir la valeur de la defence de la creature
	* @return La valeur de la defence de la creature
	*/
	int obtenirDefense() const;

	/**
	* @brief Pour obtenir la quantite de point de vie de la creature
	* @return La quantite de point de vie de la creature
	*/
	int obtenirPointDeVie() const;

	/**
	* @brief Pour obtenir la quantite de point de vie totale de la creature
	* @return La quantite de point de vie totale de la creature
	*/
	int obtenirPointDeVieTotal() const;

	/**
	* @brief Pour obtenir la quantite d'energie de la creature
	* @return La quantite d'energie de la creature
	*/
	int obtenirEnergie() const;

	/**
	* @brief Pour obtenir la quantite d'energie totale de la creature
	* @return La quantite d'energie totale de la creature
	*/
	int obtenirEnergieTotale() const;

	/**
	* @brief Pour obtenir l'experience de la creature
	* @return L'experience de la creature
	*/
	int obtenirExperience() const;

	/**
	* @brief Pour obtenir l'experience necessaire a la creature pour monter de niveau
	* @return L'experience necessaire a la creature pour monter de niveu
	*/
	int obtenirExperienceNecessaire() const;

	/**
	* @brief Pour obtenir le niveau de la creature
	* @return Le niveau de la creature
	*/
	int obtenirNiveau() const;

	/**
	* @brief Pour obtenir le pouvoir de la creature
	* @return Le pouvoir de la creature
	*/
	Pouvoir obtenirPouvoir() const;


	//Setters
	/**
	* @brief Pour modifier le nom de la creature
	* @param nom Le nouveau nom de la creature
	*/
	void modifierNom(string nom);

	/**
	* @brief Pour modifier la force d'attaque de la creature
	* @param attaque La nouvelle force d'attaque de la creature
	*/
	void modifierAttaque(int attaque);

	/**
	* @brief Pour modifier la valeur de la defence de la creature
	* @param defense La nouvelle valeur de defence de la creature
	*/
	void modifierDefense(int defense);

	/**
	* @brief Pour modifier le nombre de point de vie de la creature
	* @param pointDeVie La nouvelle quantite de point de vie de la creature
	*/
	void modifierPointDeVie(int pointDeVie);

	/**
	* @brief Pour modifier la quantitee de point de vie totale de la creature
	* @param pointDeVieTotal La nouvelle quantitee totale de point de vie de la creature
	*/
	void modifierPointDeVieTotal(int pointDeVieTotal);

	/**
	* @brief Pour modifier la quantitee d'energie de la creature
	* @param energie La nouvelle quantitee d'energie de la creature
	*/
	void modifierEnergie(int energie);

	/**
	* @brief Pour modifier la quantitee d'energie totale de la creature
	* @param energieTotal La nouvelle quantitee d'energie totale de la creature
	*/
	void modifierEnergieTotale(int energieTotal);

	/**
	* @brief Pour modifier la quantitee d'experience de la creature
	* @param nom La nouvelle quantitee d'experience de la creature
	*/
	void modifierExperience(int experience);

	/**
	* @brief Pour modifier la quantitee d'experience necessaire a la creature pour monter de niveau
	* @param nom La nouvelle quantitee d'experience necessaire a la creature pour monter de niveau
	*/
	void modifierExperienceNecessaire(int experienceNecessaire);

	/**
	* @brief Pour modifier le niveau de la creature
	* @param nom Le nouveau niveau de la creature
	*/
	void modifierNiveau(int niveau);

	/**
	* @brief Pour modifier le pouvoir de la creature
	* @param nom Le nouveau pouvoir de la creature
	*/
	void modifierPouvoir(Pouvoir pouvoir);

	/**
	* @brief Pour attaquer une autre creature
	* @param pouvoir Pouvoir utilise pour attaquer la creature ennemie
	* @param creature La creature ennemie
	*/
	void attaquer(Creature & creature);

	/**
	* @brief Pour calculer le nombre d'experience que la creature gagne a la suite d'une victoire
	* @param creature La creature ennemie
	* @return La quantite d'experience gagne
	*/
	int experienceGagner(const Creature& creature);


	/**
	* @brief Affiche les attributs de la creature
	*/
	void information() const;

private:
	// Attributes
	/**
	* @brief Pour garder le nom de la creature
	*/
	string nom_;

	/**
	* @brief Pour garder la force d'attaque de la creature
	*/
	int attaque_;

	/**
	* @brief Pour garder la valeur de la defence de la creature
	*/
	int defense_;

	/**
	* @brief Pour garder la quantite de point de vie de la creature
	*/
	int pointDeVie_;

	/**
	* @brief Pour garder la quantite de point de vie totale de la creature
	*/
	int pointDeVieTotal_;

	/**
	* @brief Pour garder la quantite d'energie de la creature
	*/
	int energie_;

	/**
	* @brief Pour garder la quantite d'energie totale de la creature
	*/
	int energieTotal_;

	/**
	* @brief Pour garder la quantite d'experience de la creature
	*/
	int experience_;

	/**
	* @brief Pour garder la quantite d'experience necessaire a la creature pour monter de niveau
	*/
	int experienceNecessaire_;

	/**
	* @brief Pour garder le niveau de la creature
	*/
	int niveau_;

	/**
	* @brief Pour garder le pouvoir de la creature
	*/
	Pouvoir pouvoir_;

};

#endif