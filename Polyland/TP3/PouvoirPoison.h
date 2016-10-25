/*
Fichier: PouvoirPoison.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe Pouvoir poison correspond a un pouvoir poison de creature
*/

#ifndef POUVOIRPOISON_H
#define POUVOIRPOISON_H

#include "Pouvoir.h"
#include "EtatEmpoisonne.h"

/**
* @brief La classe PouvoirPoison, pour decrire un pouvoir poison
*/
class PouvoirPoison : public Pouvoir
{
public:

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param nombreDeDegats Nombre de degats infliges par le pouvoir
	* @param energieNecessaire Energie necessaire pour lancer le pouvoir
	*/
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param nombreDeDegats Nombre de degats infliges par le pouvoir
	* @param energieNecessaire Energie necessaire pour lancer le pouvoir
	* @param duree Duree de l'effet
	*/
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);


	/**
	* @brief Appliquer l'effet offensif du pouvoir sur la creature passee en paramètre
	* @param nom La creature sur laquelle appliquer l'effet offensif
	*/
	void appliquerEffetOffensif(Creature & creatureEnnemie);


	/**
	* @brief Redefinition de l'operateur '<<' avec un pouvoir en parametre
	* @param o L'output stream dans lequel ajouter les informations du pouvoir
	* @param dresseur Le pouvoir a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& os, const PouvoirPoison& pouvoirPoison);

private:
	unsigned int duree_;

};

#endif