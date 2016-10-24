/*
Fichier: PotionMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Les potions magiques
*/

#ifndef POTIONMAGIQUE_H
#define POTIONMAGIQUE_H

#include "ObjetMagique.h"

/**
* @brief La classe PotionMagique, pour decrire un objet magique
*/
class PotionMagique : public ObjetMagique
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	PotionMagique();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom de la potion
	* @param bonus Le bonus de la potion magique
	*/
	PotionMagique(const std::string &nom, int bonus);

	/**
	* @brief Utilise une potion magique sur une creature
	* @param creature Creature
	*/
	void utiliserSur(Creature & creature) const;

	/**
	* @brief Redefinition de l'operateur '<<' avec une potionMagique en parametre
	* @param o L'output stream
	* @param potiontMagique L'outil magique a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& os, const PotionMagique& potionMagique);

};

#endif