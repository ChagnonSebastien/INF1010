/*
Fichier: Dresseur.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Les dresseurs sont des êtres qui dresse des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>
#include <list>
#include <algorithm>


#include "ObjetMagique.h"
#include "Creature.h"


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
	auto obtenirCreatures() const;

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
	void modifierCreature(std::list<Creature*> creatures);

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
	ObjetMagique obtenirObjetMagique() const;

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
	bool operator==(Dresseur& dresseur) const;

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

	/**
	* @brief Appliquer un foncteur unitaire
	* @param foncteur Le foncteur a utiliser
	*/
	template<typename T>
	void appliquerFoncteurUnaire(T& foncteur);

	/**
	* @brief Suprimer tout les éléments qui sont acceptés par le foncteur
	* @param foncteur Le foncteur a utiliser
	*/
	template<typename T>
	void supprimerElements(T& foncteur);

	/**
	* @brief Optenir une créature déterminer par le foncteur
	* @param foncteur Le foncteur a utiliser
	*/
	template<typename T>
	Creature* obtenirCreatureMax(T& foncteur);
		
private:
	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	std::list<Creature*> creatures_;

};


template<typename T>
void Dresseur::appliquerFoncteurUnaire(T& foncteur)
{ 
	for_each(creatures_.begin(), creatures_.end(), std::ref(foncteur));
}

template<typename T>
void Dresseur::supprimerElements(T& foncteur) 
{
	//std::remove_if(creatures_.begin(), creatures_.end(), std::ref(foncteur));
	creatures_.remove_if(foncteur);
}


template<typename T>
Creature* Dresseur::obtenirCreatureMax(T& foncteur)
{
	creatures_.sort(foncteur);
	return creatures_.front();
	//std::list<Creature*>::const_iterator it = std::find_if(creatures_.begin(), creatures_.end(), foncteur);
}

#endif