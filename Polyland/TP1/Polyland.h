/*
Fichier: Polyland.h
Auteur(s): Sebastien CHAGNON, Audrey LABRIE
Date de creation: 31 aout 2016
Date de modification: 26 septembre 2016
Description: Polyland est le monde de notre jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"

/**
* @brief La classe Polyland, pour decrire le monde de Polyland
*/
class Polyland
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	Polyland();

	/**
	* @brief Destructeur de la classe
	*/
	~Polyland();


	/**
	* @brief Ajouter un dresseur au monde de Polyland
	* @param dresseur Dresseur a ajouter
	* @return true si l'ajout a ete un succes, false sinon
	*/
	bool ajouterDresseur(Dresseur& dresseur);

	/**
	* @brief Retirer un dresseur au monde de Polyland
	* @param nom Le nom du dresseur a retirer
	* @return true si le retrait a ete un succes, false sinon
	*/
	bool retirerDresseur(string nom);

	/**
	* @brief Ajouter une creature au monde de Polyland
	* @param creature Creature a ajouter
	* @return true si l'ajout a ete un succes, false sinon
	*/
	bool ajouterCreature(Creature& creature);

	/**
	* @brief Retirer une creature au monde de Polyland
	* @param nom Le nom de la creature a retirer
	* @return true si le retrait a ete un succes, false sinon
	*/
	bool retirerCreature(string nom);


	/**
	* @brief Pour obtenir un dresseur aleatoire du monde de Polyland
	* @return Un dresseur aleatoire
	*/
	Dresseur* choisirDresseurAleatoire();

	/**
	* @brief Pour obtenir une creature aleatoire du monde de Polyland
	* @return Une creature aleatoire
	*/
	Creature* choisirCreatureAleatoire();


	/**
	* @brief Methode pour qu'un dresseur attrape une creature
	* @param dresseur Le dresseur a qui ajouter la creature
	* @param Creature La creature a ajouter au dresseur
	* @return true si l'ajout a ete un succes, false sinon
	*/
	bool attraperCreature(Dresseur* dresseur, Creature Creature);

	/**
	* @brief Methode pour qu'un dresseur relache une creature
	* @param dresseur Le dresseur a qui retirer une creature
	* @param nom Le nom de la creature retirer du dresseur
	* @return true si le retrait a ete un succes, false sinon
	*/
	bool relacherCreature(Dresseur* dresseur, string nom);


	/**
	* @brief Affiche les informations d'un dresseur
	* @param nom Le nom du dresseur a afficher les informations
	*/
	void infoDresseur(string nom) const;

private:
	Dresseur* dresseurs_[100];
	int nombreDresseurs_;
	Creature* creatures_[1000];
	int nombreCreatures_;
};

#endif