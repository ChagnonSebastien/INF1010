/*
Fichier: GreenBull.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe GreenBull correspond a un objet magique qui redonne de l'energie
	a la creature
*/

#ifndef GREENBULL_H
#define GREENBULL_H

#include "ObjetMagique.h"

/**
* @brief La classe GreenBull, pour decrire un objet magique
*/
class GreenBull : public ObjetMagique
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	GreenBull();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param bonus Le bonus de l'objet magique
	*/
	GreenBull(const std::string &nom, int bonus);


	/**
	* @brief Pour utiliser l'objet magique sur une creature
	* @param creature La creature sur laquelle utiliser l'objet magique
	*/
	void utiliserSur(Creature & creature) const;


	/**
	* @brief Redefinition de l'operateur '<<' avec un objet magique en parametre
	* @param o L'output stream dans lequel ajouter les informations du dresseur
	* @param objetMagique L'objet magique a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& os, const GreenBull& greenBull);

};

#endif