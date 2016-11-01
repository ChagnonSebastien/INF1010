/*
Fichier: AttaqueMagiqueConfusion.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 31 octobre 2016
Description: Les creatures magiques poss�dent des attaques magiques
*/


#ifndef ATAQUEMAGIQUECONFUSION_H
#define ATAQUEMAGIQUECONFUSION_H

#include "AttaqueMagique.h"

/**
* @brief La classe AttaqueMagiqueConfusion pour decrire une attaque magique
*/
class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:

	/**
	* @brief Constructeur par default
	*/
	AttaqueMagiqueConfusion();

	/**
	* @brief Constructeur par parametres
	* @param duree Duree de l'attaque magique confusion
	*/
	AttaqueMagiqueConfusion(unsigned int duree);

	/**
	* @brief Destructeur de la classe
	*/
	~AttaqueMagiqueConfusion();

	/**
	* @brief Pour obtenir le type de l'attaque magique
	* @return type
	*/
	virtual std::string obtenirTypeAttaque() const;

	/**
	* @brief Applique une attaque sur une creature
	* @param creature Creature
	*/
	virtual void appliquerAttaque(Creature & creature) const;

	/**
	* @brief Retourne si la duree de l'attaque magique confusion est termine
	* @return bool
	*/
	virtual bool estFini() const;
};

#endif