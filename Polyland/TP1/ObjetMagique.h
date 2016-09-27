/*
Fichier: ObjetMagique.h
Auteur(s): Sebastien CHAGNON, AudreyLABRIE
Date de creation: 13 septembre 2016
Date de modification: 26 septembre 2016
Description: les objets magiques sont detenus par les dresseurs
*/
#ifndef OBJET_MAGIQUE_H
#define OBJET_MAGIQUE_H

#include <string>
#include <iostream>

using namespace std;

/**
* @brief La classe ObjetMagique, pour decrire un objet magique
*/
class ObjetMagique
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	ObjetMagique();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom du pouvoir
	* @param bonus Le bonus de l'objet magique
	*/
	ObjetMagique(string nom, int bonus);

	/**
	* @brief Destructeur de la classe
	*/
	~ObjetMagique();


	// Getters
	/**
	* @brief Pour obtenir le nom de l'objet magique
	* @return Le nom de l'objet magique
	*/
	string obtenirNom() const;

	/**
	* @brief Pour obtenir le bonus de l'objet magique
	* @return Le bonus de l'objet magique
	*/
	int obtenirBonus() const;


	// Setters
	/**
	* @brief Pour modifier le nom de l'objet mgique
	* @param nom Le nouveau nom de l'objet magique
	*/
	void modifierNom(string nom);

	/**
	* @brief Pour modifier le bonus de l'objet mgique
	* @param nom Le nouveau bonus de l'objet magique
	*/
	void modifierBonus(int bonus);


	/**
	* @brief Affiche les attributs de l'objet magique
	*/
	void affichage();

private:
	string nom_;
	int bonus_;

};

#endif