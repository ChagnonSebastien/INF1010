/*
Fichier: CreatureMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Les creatures magiques sont des etres destines au combat
*/

#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H

#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"


/*
* @brief La classe CreatureMagique, pour decrire une creature magique
*/
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
	CreatureMagique(const Creature& creature, unsigned int bonus);

	/**
	* @brief Constructeur par reference
	* @param creature Reference a la creature a copier
	*/
    CreatureMagique(const CreatureMagique& creatureMagique);

	/**
	* @brief Destructeur de la classe
	*/
	virtual ~CreatureMagique(); // À MODIFIER (si nécessaire...)
	

	/**
	* @brief Pour obtenir le type de la creature magique
	* @return type de la creature magique
	*/
	virtual std::string obtenirTypeCreature() const;


	/**
	* @brief Pour obtenir lle bonus d'une creature magique
	* @return Le bonus de la creature magique
	*/
	unsigned int obtenirBonus() const;

	/**
	* @brief Pour modifier le bonus d'une creature magique
	* @param nouveau bonus de la creature magique
	* @return Aucun
	*/
	void modifierBonus(unsigned int bonus);

	/**
	* @brief Pour obtenir l'attaque magique d'une creature magique
	* @return ptr Attaque magique de la creature magique
	*/
	AttaqueMagique* obtenirAttaque() const;

	/**
	* @brief Pour changer l'attaque magique d'une creature magique
	* @param la nouvelle attaque magique de la creature magique
	*/
	void apprendreAttaqueMagique(const AttaqueMagique* attaqueMagique);

	/**
	* @brief Pour effacer l'attaque magique d'une creature magique
	* @param la nouvelle attaque magique de la creature magique
	*/
	void oublierAttaqueMagique(const AttaqueMagique* attaqueMagique);
	
	/**
	* @brief Pour attaquer une autre creature
	* @param pouvoir Pouvoir utilise pour attaquer la creature ennemie
	* @param creature La creature ennemie
	*/
    virtual void attaquer(const Pouvoir& pouvoir, Creature& creature); // À MODIFIER (si nécessaire...)

	/**
	* @brief Redefinition de l'operateur d'affectation
	* @param creatureMagique La creature magique a copier
	*/
	CreatureMagique& operator=(const CreatureMagique& creatureMagique);

	/**
	* @brief Redefinition de l'operateur '<<' avec une creature en parametre
	* @param o L'output stream dans lequel ajouter les informations de la creature
	* @param creatureMagique La creature magique a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature); // À MODIFIER (si nécessaire...)
private:
    unsigned int bonus_;
	AttaqueMagique* attaqueMagique_;
};

#endif