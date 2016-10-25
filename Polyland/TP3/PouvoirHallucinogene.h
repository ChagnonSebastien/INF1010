/*
Fichier: PouvoirHallucinogene.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe Pouvoir hallucinogene correspond a un pouvoir hallucinogene de creature
*/

#ifndef POUVOIRHALLUCINOGENE_H
#define POUVOIRHALLUCINOGENE_H

#include "Pouvoir.h"
#include "EtatConfus.h"

/**
* @brief La classe PouvoirHallucinogene, pour decrire un pouvoir hallucinogene
*/
class PouvoirHallucinogene : public Pouvoir
{
public:

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param nombreDeDegats Nombre de degats infliges par le pouvoir
	* @param energieNecessaire Energie necessaire pour lancer le pouvoir
	*/
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param nombreDeDegats Nombre de degats infliges par le pouvoir
	* @param energieNecessaire Energie necessaire pour lancer le pouvoir
	* @param duree Duree de l'effet
	*/
	PouvoirHallucinogene(const std::string& nom,
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
	friend std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& pouvoirHallucinogene);

private:
	int duree_;

};

#endif