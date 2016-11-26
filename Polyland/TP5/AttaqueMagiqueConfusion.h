/*
Fichier: AttaqueMagiqueConfusion.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Les creatures magiques possèdent des attaques magiques
*/

#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include <stdlib.h>

#include "AttaqueMagique.h"
#include "Foncteur.h"

#define MIN_DUREE_CONFUSION 3

/**
* @brief La classe AttaqueMagiqueConfusion pour decrire une attaque magique
*/
class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:

	/**
	* @brief Constructeur par default
	*/
    AttaqueMagiqueConfusion(); // À MODIFIER

	/**
	* @brief Constructeur par parametres
	* @param duree Duree de l'attaque magique confusion
	*/
	AttaqueMagiqueConfusion(unsigned int duree); // À MODIFIER

	/**
	* @brief Destructeur de la classe
	*/
    virtual ~AttaqueMagiqueConfusion(); 

	/**
	* @brief Applique une attaque sur une creature
	* @param creature Creature
	*/
    virtual void appliquerAttaque(Creature& Creature); // À MODIFIER
	
	/**
	* @brief Retourne si la duree de l'attaque magique confusion est termine
	* @return bool
	*/
    virtual bool estFini() const;


	/**
	* @brief Pour obtenir le type de l'attaque magique
	* @return type
	*/
	virtual std::string obtenirTypeAttaque() const;

private:
	FoncteurGenerateurNombresAlea foncteur_;

};
#endif 




