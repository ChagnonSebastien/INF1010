/*
Fichier: AttaqueMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 31 octobre 2016
Description: Les creatures magiques possèdent des attaques magiques
*/
#ifndef ATAQUEMAGIQUE_H
#define ATAQUEMAGIQUE_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "Creature.h"

/**
* @brief La classe AttaqueMagique pour decrire une attaque magique
*/
class AttaqueMagique
{
public:

	/**
	* @brief Constructeur par parametres
	* @param duree Duree de l'attaque magique
	*/
	AttaqueMagique(unsigned int duree);

	/**
	* @brief Destructeur de la classe
	*/
	~AttaqueMagique();

	/**
	* @brief Pour obtenir la duree d'une attaque magique
	* @return la duree de l'attaque magique
	*/
	unsigned int obtenirDuree() const;

	/**
	* @brief Pour definir la duree d'une attaque magique
	* @param duree Nouvelle duree de l'attaque magique
	* @return Aucun
	*/
	void definirDuree(unsigned int duree);

	/**
	* @brief Pour obtenir le type de l'attaque magique
	* @return type
	*/
	virtual std::string obtenirTypeAttaque() const = 0;

	/**
	* @brief Applique une attaque sur une creature
	* @param creature Creature
	*/
	virtual void appliquerAttaque(Creature & creature) const = 0;

	/**
	* @brief Methode redefinie dans les classes filles
	* @return bool
	*/
	virtual bool estFini() const;

	/**
	* @brief Redefinition de l'operateur '<<' avec une attaque magique en parametre
	* @param o L'output stream dans lequel ajouter les informations
	* @param attaqueMagique L'attaque magique a afficher
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& o, const AttaqueMagique& attaqueMagique);

protected:
	unsigned int duree_;
};

#endif