/*
Fichier: CreatureMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Les creatures magiques sont des etres destines au combat
*/

#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "AttaqueMagique.h"
#include "Creature.h"

class CreatureMagique : public Creature
{
public:

	/**
	* @brief Constructeur par default
	*/
	CreatureMagique();

	/**
	* @brief Constructeur par reference
	* @param creature Reference a la creature a copier
	* @param bonus Bonus de la creature magique
	*/
	CreatureMagique(unsigned int bonus, const Creature& creature);

	/**
	* @brief Constructeur par reference
	* @param creature Reference a la creature a copier
	*/
	CreatureMagique(const Creature& creature);

	/**
	* @brief Destructeur de la classe
	*/
	~CreatureMagique();

	/**
	* @brief Pour obtenir lle bonus d'une creature magique
	* @return Le bonus de la creature magique
	*/
	unsigned int obtenirBonus() const;

	/**
	* @brief Pour obtenir l'attaque magique d'une creature magique
	* @return ptr Attaque magique de la creature magique
	*/
	AttaqueMagique* obtenirAttaqueMagique() const;

	/**
	* @brief Pour modifier le bonus d'une creature magique
	* @param nouveau bonus de la creature magique
	* @return Aucun
	*/
	void modifierBonus(unsigned int bonus);

	/**
	* @brief Pour modifier l'attaque magique d'une creature magique
	* @param la nouvelle attaque magique de la creature magique
	* @return Aucun
	*/
	void modifierAttaqueMagique(AttaqueMagique* attaqueMagique);

	/**
	* @brief Redefinition de l'operateur d'affectation
	* @param creatureMagique La creature magique a copier
	*/
	CreatureMagique& operator=(const Creature& creature);

	/**
	* @brief Pour obtenir le type de la creature magique
	* @return type de la creature magique
	*/
	virtual std::string obtenirTypeCreature() const;
	
	/**
	* @brief Pour attaquer une autre creature
	* @param pouvoir Pouvoir utilise pour attaquer la creature ennemie
	* @param creature La creature ennemie
	*/
	void attaquer(Pouvoir& pouvoir, Creature& creature);

	/**
	* @brief Pour changer l'attaque magique d'une creature magique
	* @param la nouvelle attaque magique de la creature magique 
	*/
	void apprendreAttaqueMagique(AttaqueMagique* attaqueMagique);

	/**
	* @brief Pour effacer l'attaque magique d'une creature magique
	* @param la nouvelle attaque magique de la creature magique
	*/
	void oublierAttaqueMagique();

	/**
	* @brief Redefinition de l'operateur '<<' avec une creature en parametre
	* @param o L'output stream dans lequel ajouter les informations de la creature
	* @param creatureMagique La creature magique a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream & o, CreatureMagique& creatureMagique);


private:
	unsigned int bonus_;
	AttaqueMagique* attaqueMagique_;

};

#endif