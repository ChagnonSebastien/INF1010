/*
Fichier: PouvoirSoporifique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe Pouvoir Soporifique correspond a un pouvoir soporifique de creature
*/

#ifndef POUVOIRSPORIFIQUE_H
#define POUVOIRSPORIFIQUE_H

#include "Pouvoir.h"
#include "EtatEndormi.h"

/**
* @brief La classe PouvoirSoporifique, pour decrire un pouvoir soporifique
*/
class PouvoirSoporifique : public Pouvoir
{
public:

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param nombreDeDegats Nombre de degats infliges par le pouvoir
	* @param energieNecessaire Energie necessaire pour lancer le pouvoir
	*/
	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param nombreDeDegats Nombre de degats infliges par le pouvoir
	* @param energieNecessaire Energie necessaire pour lancer le pouvoir
	* @param duree Duree de l'effet
	*/
	PouvoirSoporifique(const std::string& nom,
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
	friend std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& pouvoirSporifique);

private:
	int duree_;

};

#endif