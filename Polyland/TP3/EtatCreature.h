/*
Fichier: EtatCreature.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Les etatCreature sont des états dans lequel les créatures sont
*/
#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>

#include "Creature.h"  
#include "TypeEtat.h"

//déclaration anticipée nécessaire à cause des inclusions circulaires
class Creature;

/*
* @brief La classe EtatCreature, pour decrire uun etat d'une creature
*/

class EtatCreature
{
public:

	/**
	* @brief Constructeur par parametres
	* @param nom Nom de l'etat
	*/
    EtatCreature(const std::string& nom);

	/**
	* @brief Constructeur par parametres
	* @param nom nom de l'etat
	* @param duree Duree de l'état
	*/
    EtatCreature(const std::string& nom, unsigned int duree);

	/**
	* @brief Destructeur de la classe
	*/
    ~EtatCreature();

	/**
	* @brief Pour appliquer sur la creature qui possede le pouvoir
	* @param creature Creature qui possede le pouvoir
	*/
    void appliquerEtat(Creature& creature); //à appliquer sur la créature qui possède ce pouvoir

	/**
	* @brief Determine si l'etat de la creature lui permet d'attaquer
	* @return bool
	*/
    bool peutAttaquer() const; //détermine si l'état de la créature lui permet d'attaquer

    /**
	* @brief si vrai, Informe la creature qu'elle peut retouner a l'état normal
	* @return bool
	*/
    bool estFini() const; //si vrai, informe la créature qu'elle peut retourner à l'état normal

	/**
	* @brief Pour obtenir le nom de l'etat
	* @return Le nom de la creature
	*/
    std::string obtenirNom() const;

	/**
	* @brief Pour obtenir le type
	* @return type de letat
	*/
    TypeEtat obtenirType() const;

	/**
	* @brief Pour obtenir la duree de letat
	* @return la duree de l'état
	*/
	unsigned int obtenirDuree() const;

	/**
	* @brief Redefinition de l'operateur '<<' avec une creature en parametre
	* @param o L'output stream dans lequel ajouter les informations de la creature
	* @param etatCreature L'etat de la creature a afficher les informations
	* @return L'output stream recu en parametre
	*/
    friend std::ostream& operator<<(std::ostream& o, const EtatCreature& etatCreature);

private:
    std::string nom_;
protected:
    unsigned int duree_;
    TypeEtat type_;
};
#endif // !ETAT_CREATURE_H




