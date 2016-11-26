/*
Fichier: Pouvoir.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: La classe Pouvoir correspond a un pouvoir de creature
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>

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
	Pouvoir(const std::string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	/**
	* @brief Destructeur de la classe
	*/
	~Pouvoir();
	/**
	* @brief Pour obtenir le nombre de degats infliges par le pouvoir
	* @return Le nombre de degats infliges par le pouvoir
	*/
	unsigned int obtenirNombreDeDegat() const;

	/**
	* @brief Pour obtenir la quantite d'energie necessaire pour lancer le pouvoir
	* @return La quantite d'energie necessaire pour lancer le pouvoir
	*/
	unsigned int obtenirEnergieNecessaire() const;

	/**
	* @brief Pour obtenir le nom du pouvoir
	* @return Le nom du pouvoir
	*/
	std::string obtenirNom() const;

	/*@brief Pour modifier le nombre de degats infliges par le pouvoir
	* @param nom Le nouveau nombre de degats infliges par le pouvoir
	*/
	void modifierNombreDeDegat(unsigned int nombreDegat);

	/**
	* @brief Pour modifier la quantite d'energie necessaire pour lancer le pouvoir
	* @param nom La quantite d'energie necessaire pour lancer le pouvoir
	*/
	void modifierEnergieNecessarie(unsigned int energieNecessaire);

	/**
	* @brief Pour modifier le nom du pouvoir
	* @param nom Le nouveau nom du pouvoir
	*/
	void modifierNom(const std::string& nom);

	/**
	* @brief Le constructeur par copie
	* @param pouvoir Une reference au pouvoir a copier
	*/
	Pouvoir(const Pouvoir& pouvoir);

	/**
	* @brief Redefinition de l'operateur d'affectation
	* @param pouvoir Le pouvoir a copier
	* @return Le pouvoir
	*/
	Pouvoir& operator=(const Pouvoir& pouvoir);

	/**
	* @brief Redefinition de l'operateur '==' avec un pouvoir en parametre
	* @param pouvoir Le pouvoir a comparer avec le pouvoir actuel
	* @return true s'ils ont les memes attributs, false sinon
	*/
	bool operator==(const Pouvoir& pouvoir) const;

	/**
	* @brief Redefinition de l'operateur '<<' avec un pouvoir en parametre
	* @param o L'output stream dans lequel ajouter les informations du pouvoir
	* @param dresseur Le pouvoir a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& os, const Pouvoir& pouvoir);

private:
	std::string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;

};

#endif