/*
Fichier: Pouvoir.h
Auteur(s): Sébastien CHAGNON, Audrey LABRIE
Date de creation: 13 septembre 2016
Date de modification: 26 septembre 2016
Description: les pouvoir sont détenus par les créatures
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>

using namespace std;

/**
* @brief La classe Pouvoir, pour decrire un pouvoir
*/
class Pouvoir
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	Pouvoir();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param nombreDeDegats Nombre de degats infliges par le pouvoir
	* @param energieNecessaire Energie necessaire pour lancer le pouvoir
	*/
	Pouvoir(string nom, int nombreDeDegats, int energieNecessaire);

	/**
	* @brief Destructeur de la classe
	*/
	~Pouvoir();


	// Getters
	/**
	* @brief Pour obtenir le nom du pouvoir
	* @return Le nom du pouvoir
	*/
	string obtenirNom() const;

	/**
	* @brief Pour obtenir le nombre de degats infliges par le pouvoir
	* @return Le nombre de degats infliges par le pouvoir
	*/
	int obtenirNombreDeDegat() const;

	/**
	* @brief Pour obtenir la quantite d'energie necessaire pour lancer le pouvoir
	* @return La quantite d'energie necessaire pour lancer le pouvoir
	*/
	int obtenirEnergieNecessaire() const;


	// Setters
	/**
	* @brief Pour modifier le nom du pouvoir
	* @param nom Le nouveau nom du pouvoir
	*/
	void modifierNom(string nom);

	/**
	* @brief Pour modifier le nombre de degats infliges par le pouvoir
	* @param nom Le nouveau nombre de degats infliges par le pouvoir
	*/
	void modifierNombreDeDegat(int nombreDeDegat);

	/**
	* @brief Pour modifier la quantite d'energie necessaire pour lancer le pouvoir
	* @param nom La quantite d'energie necessaire pour lancer le pouvoir
	*/
	void modifierEnergieNecessaire(int energieNecessaire);



	/**
	* @brief Affiche les attributs du pouvoir
	*/
	void description();

private:
	string nom_;
	int nombreDeDegats_;
	int energieNecessaire_;

};

#endif