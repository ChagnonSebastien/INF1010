/*
Fichier: Elixir.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Elixir est une potion magique
*/

#ifndef ELIXIR_H
#define ELIXIR_H

#include "PotionMagique.h"

/**
* @brief La classe Elixir, pour decrire un objet magique
*/
class Elixir : public PotionMagique
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	Elixir();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom de la potion
	* @param bonus Le bonus de la potion magique
	*/
	Elixir(const std::string &nom, int bonus);

	/**
	* @brief Utilise une potion magique sur une creature
	* @param creature Creature
	*/
	void utiliserSur(Creature & creature) const;

	/**
	* @brief Redefinition de l'operateur '<<'
	* @param o L'output stream
	* @param Elixir L'elixir a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& os, const Elixir& elixir);

};

#endif