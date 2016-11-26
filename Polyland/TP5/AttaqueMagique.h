/*
Fichier: AttaqueMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Les creatures magiques possèdent des attaques magiques
*/
#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>
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
	AttaqueMagique(unsigned int duree) { duree_ = duree; }

	/**
	* @brief Destructeur de la classe
	*/
	virtual ~AttaqueMagique() {}

	/**
	* @brief Pour obtenir la duree d'une attaque magique
	* @return la duree de l'attaque magique
	*/
	unsigned int obtenirDuree() const { return duree_; }

	/**
	* @brief Pour definir la duree d'une attaque magique
	* @param duree Nouvelle duree de l'attaque magique
	* @return Aucun
	*/
	void modifierDuree(unsigned int duree) { duree_ = duree; }


	/**
	* @brief Pour obtenir le type de l'attaque magique
	* @return type
	*/
	virtual std::string obtenirTypeAttaque() const { return typeid(AttaqueMagique).name(); }

	/**
	* @brief Applique une attaque sur une creature
	* @param creature Creature
	*/
    virtual void appliquerAttaque(Creature& creature) = 0; //à appliquer sur la créature qui possède ce pouvoir

	/**
	* @brief Methode redefinie dans les classes filles
	* @return bool
	*/
	virtual bool estFini() const { return true;	} //si vrai, informe la créature qu'elle peut retourner à l'état normal

	/**
	* @brief Redefinition de l'operateur '<<' avec une attaque magique en parametre
	* @param o L'output stream dans lequel ajouter les informations
	* @param attaqueMagique L'attaque magique a afficher
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& o, const AttaqueMagique& attaqueMagique)
	{ 
		return o << "Attaque magique de type " << attaqueMagique.obtenirTypeAttaque() << " avec une durée de " << attaqueMagique.duree_ << std::endl;
	} 

protected:
    unsigned int duree_;
};
#endif




