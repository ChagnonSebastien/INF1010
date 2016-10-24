/*
Fichier: EtatEndormi.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Les etatCreature sont des états dans lequel les créatures sont
*/

#ifndef ETATENDORMI_H
#define ETATENDORMI_H

#include "EtatCreature.h"

/*
* @brief La classe EtatEndormi, pour decrire uun etat d'une creature
*/
class EtatEndormi : public EtatCreature
{
public:

	/**
	* @brief Constructeur par parametres
	* @param nom Nom de l'etat
	*/
	EtatEndormi(const std::string& nom);

	/**
	* @brief Constructeur par parametres
	* @param nom nom de l'etat
	* @param duree Duree de l'état
	*/
	EtatEndormi(const std::string& nom, unsigned int duree);

	/**
	* @brief Determine si l'etat de la creature lui permet d'attaquer
	* @return bool
	*/
	bool peutAttaquer() const;

	/**
	* @brief Pour appliquer sur la creature qui possede le pouvoir
	* @param creature Creature qui possede le pouvoir
	*/
	void appliquerEtat(Creature & creature);

	/**
	* @brief si vrai, Informe la creature qu'elle peut retouner a l'état normal
	* @return bool
	*/
	bool estFini() const;

	/**
	* @brief Redefinition de l'operateur '<<' avec une creature en parametre
	* @param o L'output stream
	* @param etatCreature L'etat de la creature a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& o, const EtatEndormi& etatEndormi);

};

#endif