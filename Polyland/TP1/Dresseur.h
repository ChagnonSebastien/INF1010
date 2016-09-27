/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO, Sebastien CHAGNON, Audrey LABRIE
Date de creation: 31 aout 2016
Date de modification: 26 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>

#include "Creature.h"
#include "ObjetMagique.h"

/**
* @brief Le nombre de creatures maximal par default d'un dresseur
*/
#define MAX_NOMBRE_CREATURES 2

/**
* @brief La classe Dresseur, pour decrire un dresseur
*/
class Dresseur
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	Dresseur();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du dresseur
	*/
	Dresseur(const std::string& nom);

	/**
	* @brief Destructeur de la classe
	*/
	~Dresseur();


	// Getters
	/**
	* @brief Pour obtenir le nom du dresseur
	* @return Le nom du dresseur
	*/
	std::string obtenirNom() const;

	/**
	* @brief Pour obtenir les creatures du dresseur
	* @return Le pointeur vers les creatures du dresseur
	*/
	Creature** obtenirCreatures() const;

	/**
	* @brief Pour obtenir le nombre de creatures du dresseur
	* @return Le nombre de creatures du dresseur
	*/
	unsigned int obtenirNombreCreatures() const;

	/**
	* @brief Pour obtenir la quantite maximale de creatures du dresseur
	* @return La quantite maximale de creatures du dresseur
	*/
	unsigned int obtenirNombreCreaturesMax() const;

	/**
	* @brief Pour obtenir l'objet magique du dresseur
	* @return L'objet magique du dresseur
	*/
	ObjetMagique obtenirObjetMagique() const;


	// Setters
	/**
	* @brief Pour modifier le nom du dresseur
	* @param nom Le nouveau nom du dresseur
	*/
	void modifierNom(const std::string& nom);

	/**
	* @brief Pour modifier les creatures du dresseur
	* @param creatures Les nouvelles creatures du dresseur
	*/
	void modifierCreature(Creature** creatures);

	/**
	* @brief Pour modifier la quantité de creatures du dresseur
	* @param nombreCreatures La nouvelle quantite de creatures du dresseur
	*/
	void modifierNombreCreatures(unsigned int nombreCreatures);

	/**
	* @brief Pour modifier la quantite de creatures maximum du dresseur
	* @param nombreCreaturesMax La nouvelle quantite de creatures maximum du dresseur
	*/
	void modifierNombreCreaturesMax(unsigned int nombreCreaturesMax);

	/**
	* @brief Pour modifier l'objet magique du dresseur
	* @param objetMagique Le nouvel objet magique du dresseur
	*/
	void modifierObjetMagique(const ObjetMagique& objetMagique);



	/**
	* @brief Pour ajouter une creature a un dresseur
	* @param creature La creature a ajouter
	* @return true si la creature a ete ajoutee avec succes, false sinon
	*/
	bool ajouterCreature(const Creature& creature);

	/**
	* @brief Pour retirer une creature du dresseur
	* @param nom Le nom de la creature a retirer
	* @return true si la creature a ete retiree avec succes, false sinon
	*/
	bool retirerCreature(const std::string& nom);

	/**
	* @brief Pour utiliser un objet magique sur une creature
	* @param creature La creature sur laquelle utiliser l'objet magique
	*/
	void utiliserObjetMagique(Creature* creature);

	/**
	* @brief Afficher les attributs du dresseur
	*/
	void affichage() const;

private:
	/**
	* @brief Le nom de la creature
	*/
	std::string nom_;

	/**
	* @brief Le tableau contenant les creatures du dresseur
	*/
	Creature** creatures_;

	/**
	* @brief Le nombre de creatures du dresseur
	*/
	unsigned int nombreCreatures_;

	/**
	* @brief Le nom de creatures maximal du dresseur
	*/
	unsigned int nombreCreaturesMax_;

	/**
	* @brief L'objet magique du dresseur
	*/
	ObjetMagique objetMagique_;

};

#endif