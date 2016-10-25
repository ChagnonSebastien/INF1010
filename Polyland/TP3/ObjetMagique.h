/*
Fichier: ObjetMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe ObjetMagique correspond aux differents objets utilisables
			par le dresseur sur ses creatures
*/

#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>
#include <iostream>

#include "Creature.h"

class Creature;

/**
* @brief La classe ObjetMagique, pour decrire un objet magique
*/
class ObjetMagique
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	ObjetMagique();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param bonus Le bonus de l'objet magique
	*/
	ObjetMagique(const std::string &nom, int bonus);

	/**
	* @brief Destructeur de la classe
	*/
	~ObjetMagique();


	// Getters
	/**
	* @brief Pour obtenir le nom de l'objet magique
	* @return Le nom de l'objet magique
	*/
	std::string obtenirNom() const;

	/**
	* @brief Pour obtenir le bonus de l'objet magique
	* @return Le bonus de l'objet magique
	*/
	int obtenirBonus() const;


	// Setters
	/**
	* @brief Pour modifier le nom de l'objet mgique
	* @param nom Le nouveau nom de l'objet magique
	*/
	void modifierNom(const std::string& nom);

	/**
	* @brief Pour modifier le bonus de l'objet mgique
	* @param nom Le nouveau bonus de l'objet magique
	*/
	void modifierBonus(int bonus);


	/**
	* @brief Pour utiliser l'objet magique sur une creature
	* @param creature La creature sur laquelle utiliser l'objet magique
	*/
    void utiliserSur(Creature& creature) const;


	/**
	* @brief Redefinition de l'operateur '<<' avec un objet magique en parametre
	* @param o L'output stream dans lequel ajouter les informations du dresseur
	* @param objetMagique L'objet magique a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& os, const ObjetMagique& objet);

private:
	std::string nom_;
	int bonus_;
};

#endif
