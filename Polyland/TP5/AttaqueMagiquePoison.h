/*
Fichier: AttaqueMagiquePoison.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Les creatures magiques possèdent des attaques magiques
*/


#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "AttaqueMagique.h"
#include "Foncteur.h"

#define MIN_DUREE_POISON 2

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
    virtual ~AttaqueMagiquePoison();

	/**
	* @brief Applique une attaque sur une creature
	* @param creature Creature
	*/
    virtual void appliquerAttaque(Creature& Creature);

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
#endif // !ETAT_EMPOISONNE_H

