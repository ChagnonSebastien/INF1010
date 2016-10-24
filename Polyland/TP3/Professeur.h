/*
Fichier: Professeur.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Les professeurs sont des êtres qui dresse des creatures
*/
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "OutilScientifique.h"
#include "Dresseur.h"

/**
* @brief La classe Professeur, pour decrire un professeur
*/
class Professeur : public Dresseur
{
public:

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du dprofesseur
	* @param equipe L'equipe du professeur
	*/
	Professeur(const std::string& nom, const std::string& equipe);

	/**
	* @brief Constructeur par reference
	* @param dresseur Reference du professeur a copier
	*/
	Professeur(const Professeur& professeur);

	/**
	* @brief Destructeur de la classe
	*/
	~Professeur();

	/**
	* @brief Pour obtenir l'outil scientifique du professeur
	* @return L'outil scientifique du prof
	*/
	OutilScientifique* obtenirOutilScientifique() const;

	/**
	* @brief Pour modifier l'outil scientifique du prof
	* @param objetMagique Le nouvel outil scientifique du prof
	*/
	void modifierOutilScientifique(OutilScientifique* outilScientifique);

	/**
	* @brief Pour soigner une creature
	* @param creature Creature à soigner
	*/
	void soignerCreature(Creature& creature);

	/**
	* @brief Pour utiliser un outil sur un creature
	* @param creature Creature a qui l'outil va etre utilisé
	*/
	void utiliserOutil(Creature& creature);

	/**
	* @brief Redefinition de l'operateur d'affectation
	* @param professeur Le prof à copier
	*/
	Professeur& operator=(const Professeur& professeur);

private:
	OutilScientifique* outilScientifique_;

};

#endif