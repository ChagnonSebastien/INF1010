/*
Fichier: AttaqueMagiqueConfusion.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 31 octobre 2016
Description: Les creatures magiques possèdent des attaques magiques
*/


#ifndef ATAQUEMAGIQUEPOISON_H
#define ATAQUEMAGIQUEPOISON_H

#include "AttaqueMagique.h"


/**
* @brief La classe AttaqueMagiquePoisson pour decrire une attaque magique
*/
class AttaqueMagiquePoison : public AttaqueMagique
{
public:

	/**
	* @brief Constructeur par default
	*/
	AttaqueMagiquePoison();

	/**
	* @brief Constructeur par parametres
	* @param duree Duree de l'attaque magique confusion
	*/
	AttaqueMagiquePoison(unsigned int duree);

	/**
	* @brief Destructeur de la classe
	*/
	~AttaqueMagiquePoison();

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