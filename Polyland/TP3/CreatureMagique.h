/*
Fichier: CreatureMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Les creatures magiques sont des etres destines au combat
*/

#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"

class CreatureMagique : public Creature
{
public:

	/**
	* @brief Constructeur par parametres
	* @param nom Nom de la creature
	* @param attaque Force de l'attaque de la creature
	* @param defense Valeur de la defence de la creature
	* @param pointDeVie Quantite de points de vie total et actuelle de la creature
	* @param energie quantite d'energie totale et actuelle de la creature
	* @param bonus bonus de la creature
	*/
	CreatureMagique(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus);

	/**
	* @brief Constructeur par reference
	* @param creatureMagique Reference a la creature a copier
	*/
	CreatureMagique(const CreatureMagique& creatureMagique);

	/**
	* @brief Pour obtenir lle bonus d'une creature magique
	* @return Le bonus de la creature magique
	*/
	unsigned int obtenirBonus() const;

	/**
	* @brief Redefinition de l'operateur d'affectation
	* @param creatureMagique La creature magique a copier
	*/
	CreatureMagique& operator=(const CreatureMagique& creatureMagique);

	/**
	* @brief Pour attaquer une autre creature
	* @param pouvoir Pouvoir utilise pour attaquer la creature ennemie
	* @param creature La creature ennemie
	*/
	void attaquer(const Pouvoir & pouvoir, Creature & creature);

	/**
	* @brief Redefinition de l'operateur '<<' avec une creature en parametre
	* @param o L'output stream dans lequel ajouter les informations de la creature
	* @param creatureMagique La creature magique a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& o, CreatureMagique& creatureMagique);

private:
	unsigned int bonus_;

};

#endif