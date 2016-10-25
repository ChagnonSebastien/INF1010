/*
Fichier: ObjetScientifique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Il s'agit des différents outils utilisables par un professeur
*/

#ifndef OUTIL_SCIENTIFIQUE_H
#define OUTIL_SCIENTIFIQUE_H

#include <string>

#include "Creature.h"

/**
* @brief La classe OutilScientifique, pour decrire un outil scientifique
*/
class OutilScientifique
{
public:

	/**
	* @brief Constructeur par parametres
	* @param nom Nom de l'outil
	* @param description La description de l'outil
	*/
    OutilScientifique(const std::string& nom, const std::string& description);

	/**
	* @brief Destructeur de la classe
	*/
    ~OutilScientifique();


	// Getters
	/**
	* @brief Pour obtenir le nom de l'outil scientifique
	* @return Le nom de l'outil scientifique
	*/
    std::string obtenirNom() const;

	/**
	* @brief Pour obtenir la description de l'outil scientifique
	* @return La description de l'outil scientifique
	*/
    std::string obtenirDesciption() const;


	/**
	* @brief Pour utiliser l'outil scientifique sur une creature
	* @param creature La creature sur laquelle utiliser l'outil scientifique
	*/
    void utiliser(Creature& creature);


	/**
	* @brief Redefinition de l'operateur '<<' avec un outil scientifique en parametre
	* @param os L'output stream dans lequel ajouter les informations de l'outil
	* @param outil L'outil scientifique a afficher les informations
	* @return L'output stream recu en parametre
	*/
    friend std::ostream& operator<<(std::ostream& os, const OutilScientifique& outil);
private:
    std::string nom_;
    std::string description_;
};
#endif


