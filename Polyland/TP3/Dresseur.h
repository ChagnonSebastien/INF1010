/*
Fichier: Dresseur.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Les dresseurs sont des êtres qui dresse des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include <iostream>
#include <vector>

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
	* @param equipe L'equipe du dresseur
	*/
	Dresseur(const std::string& nom, const std::string& equipe);

	/**
	* @brief Constructeur par reference
	* @param dresseur Reference du dersseur a copier
	*/
	Dresseur(const Dresseur & dresseur);

	/**
	* @brief Destructeur de la classe
	*/
	~Dresseur();

	/**
	* @brief Pour obtenir le nom du dresseur
	* @return Le nom du dresseur
	*/
	std::string obtenirNom() const;

	/**
	* @brief Pour modifier le nom du dresseur
	* @param nom Le nouveau nom du dresseur
	*/
	void modifierNom(const std::string& nom);
	
	/**
	* @brief Pour obtenir le nombre de creatures du dresseur
	* @return Le nombre de creatures du dresseur
	*/
	unsigned int obtenirNombreCreatures() const;

	/**
	* @brief Pour obtenir les creatures du dresseur
	* @return Le vecteur de pointeur des creatures du dresseur
	*/
	std::vector<Creature*> obtenirCreatures() const;

	/**
	* @brief Pour obtenir les creatures du dresseur
	* @param nom Nom de la creature à obtenir
	* @return Pointeur de creature
	*/
	Creature* obtenirUneCreature(const std::string& nom) const;

	/**
	* @brief Pour modifier les creatures du dresseur
	* @param creatures Les nouvelles creatures du dresseur
	*/
	void modifierCreature(std::vector<Creature*> creatures);
	
	/**
	* @brief Pour ajouter une creature a un dresseur
	* @param creature Un pointeur sur la creature a ajouter
	* @return true si la creature a ete ajoutee avec succes, false sinon
	*/
	bool ajouterCreature(Creature* creature);

	/**
	* @brief Pour retirer une creature du dresseur
	* @param nom Le nom de la creature a retirer
	* @return true si la creature a ete retiree avec succes, false sinon
	*/
	bool enleverCreature(const std::string& nom);

	/**
	* @brief Pour obtenir l'objet magique du dresseur
	* @return L'objet magique du dresseur
	*/
	ObjetMagique* obtenirObjetMagique() const;

	/**
	* @brief Pour modifier l'objet magique du dresseur
	* @param objetMagique Le nouvel objet magique du dresseur
	*/
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	/**
	* @brief Pour utiliser un objet magique sur une creature
	* @param creature Un pointeur sur la creature sur laquelle utiliser l'objet magique
	*/
	void utiliserObjetMagique(Creature* creature);

	/**
	* @brief Pour obtenir l'equipe
	* @return Le equipe du dresseur
	*/
	std::string obtenirEquipe() const;

	/**
	* @brief Pour modifier l'equipe
	* @param nom La nouvelle equipe du dresseur
	*/
	void modifierEquipe(const std::string& equipe);

	/**
	* @brief Redefinition de l'operateur '<<' avec un dresseur en parametre
	* @param o L'output stream dans lequel ajouter les informations du dresseur
	* @param dresseur Le dresseur a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	/**
	* @brief Redefinition de l'operateur '==' avec un dresseur en parametre
	* @param dresseur Le dresseur a comparer avec le dresseur actuel
	* @return true s'ils ont les memes creatures, false sinon
	*/
	bool operator==(const Dresseur& dresseur) const;

	/**
	* @brief Redefinition de l'operateur '==' avec une chaine de characteres en parametre
	* @param nom Le nom a comparer avec celui du dresseur
	* @return true s'ils ont le meme nom, false sinon
	*/
	bool operator==(const std::string& nom) const;

	/**
	* @brief Redefinition de l'operateur '==' avec une chaine de caracteres et un dresseur en parametre
	* @param nom Le nom a comparer avec celui du dresseur
	* @param dresseur Le dresseur avec qui comparer le nom
	* @return true s'ils ont le meme nom, false sinon
	*/
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

private:
	std::string nom_;
	std::vector<Creature*> creatures_;
	std::string equipe_;
	ObjetMagique* objetMagique_;


};

#endif