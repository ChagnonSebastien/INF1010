#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <iostream>
#include "ObjetMagique.h"
#include "Pouvoir.h"


/**
* @brief La classe Creature, pour decrire une creature
*/
class Creature
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	Creature();

	/**
	* @brief Constructeur par parametres
	* @param nom Nom de la creature
	* @param attaque Force de l'attaque de la creature
	* @param defense Valeur de la defence de la creature
	* @param pointDeVie Quantite de points de vie total et actuelle de la creature
	* @param energie quantite d'energie totale et actuelle de la creature
	*/
	Creature(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie);

	/**
	* @brief Constructeur par reference
	* @param creature Reference a la creature a copier
	*/
	Creature(const Creature& creature);

	/**
	* @brief Destructeur de la classe
	*/
	~Creature();


	// Getters
	/**
	* @brief Pour obtenir le nom de la creature
	* @return Le nom de la creature
	*/
	std::string obtenirNom() const;

	/**
	* @brief Pour obtenir la force d'attaque de la creature
	* @return La force d'attaque de la creature
	*/
	unsigned int obtenirAttaque() const;

	/**
	* @brief Pour obtenir la valeur de la defence de la creature
	* @return La valeur de la defence de la creature
	*/
	unsigned int obtenirDefense() const;

	/**
	* @brief Pour obtenir la quantite de point de vie de la creature
	* @return La quantite de point de vie de la creature
	*/
	unsigned int obtenirPointDeVie() const;

	/**
	* @brief Pour obtenir la quantite de point de vie totale de la creature
	* @return La quantite de point de vie totale de la creature
	*/
	unsigned int obtenirPointDeVieTotal() const;

	/**
	* @brief Pour obtenir la quantite d'energie de la creature
	* @return La quantite d'energie de la creature
	*/
	unsigned int obtenirEnergie() const;

	/**
	* @brief Pour obtenir la quantite d'energie totale de la creature
	* @return La quantite d'energie totale de la creature
	*/
	unsigned int obtenirEnergieTotale() const;

	/**
	* @brief Pour obtenir l'experience de la creature
	* @return L'experience de la creature
	*/
	unsigned int obtenirExperience() const;

	/**
	* @brief Pour obtenir l'experience necessaire a la creature pour monter de niveau
	* @return L'experience necessaire a la creature pour monter de niveu
	*/
	unsigned int obtenirExperienceNecessaire() const;

	/**
	* @brief Pour obtenir le niveau de la creature
	* @return Le niveau de la creature
	*/
	unsigned int obtenirNiveau() const;

	/**
	* @brief Pour obtenir le pouvoir de la creature
	* @return Le vecteur de pouvoirs de la creature
	*/
	std::vector<Pouvoir*> obtenirPouvoirs() const;


	//Setters
	/**
	* @brief Pour modifier le nom de la creature
	* @param nom Le nouveau nom de la creature
	*/
	void modifierNom(std::string nom);

	/**
	* @brief Pour modifier la force d'attaque de la creature
	* @param attaque La nouvelle force d'attaque de la creature
	*/
	void modifierAttaque(unsigned int attaque);

	/**
	* @brief Pour modifier la valeur de la defence de la creature
	* @param defense La nouvelle valeur de defence de la creature
	*/
	void modifierDefense(unsigned int defense);

	/**
	* @brief Pour modifier le nombre de point de vie de la creature
	* @param pointDeVie La nouvelle quantite de point de vie de la creature
	*/
	void modifierPointDeVie(unsigned int pointDeVie);

	/**
	* @brief Pour modifier la quantitee d'energie de la creature
	* @param energie La nouvelle quantitee d'energie de la creature
	*/
	void modifierEnergie(unsigned int energie);

	/**
	* @brief Pour modifier la quantitee d'experience de la creature
	* @param nom La nouvelle quantitee d'experience de la creature
	*/
	void modifierExperience(unsigned int experience);

	/**
	* @brief Pour modifier le niveau de la creature
	* @param nom Le nouveau niveau de la creature
	*/
	void modifierNiveau(unsigned int niveau);

	/**
	* @brief Pour modifier le pouvoir de la creature
	* @param nom Le nouveau vecteur de pouvoirs de la creature
	*/
	void modifierPouvoirs(std::vector<Pouvoir*>& pouvoirs);


	/**
	* @brief Pour attaquer une autre creature
	* @param pouvoir Pouvoir utilise pour attaquer la creature ennemie
	* @param creature La creature ennemie
	*/
	void attaquer(Pouvoir & pouvoir, Creature & creature);

	/**
	* @brief Pour calculer le nombre d'experience que la creature gagne a la suite d'une victoire
	* @param creature La creature ennemie
	* @return La quantite d'experience gagne
	*/
	int experienceGagnee(const Creature& creature);

	/**
	* @brief Pour ajouter un pouvoir a la creature
	* @param pouvoir Le pouvoir a ajouter
	*/
	void apprendrePouvoir(Pouvoir& pouvoir);

	/**
	* @brief Pour retirer un pouvoir a la creature
	* @param pouvoir Le pouvoir a retirer
	*/
	void oublierPouvoir(Pouvoir* pouvoir);


	/**
	* @brief Redefinition de l'operateur d'affectation
	* @param pouvoir La creature a copier
	*/
	Creature& Creature::operator=(const Creature& creature);

	/**
	* @brief Redefinition de l'operateur '==' avec une creature en parametre
	* @param creature La creature a comparer avec la creature actuelle
	* @return true s'ils ont les memes attributs, false sinon
	*/
	bool operator==(const Creature& creature) const;

	/**
	* @brief Redefinition de l'operateur '==' avec une chaine de caracteres en parametre
	* @param nom Le nom a comparer avec celui de la creature
	* @return true s'ils ont le meme nom, false sinon
	*/
	bool operator==(const std::string& nom) const;

	/**
	* @brief Redefinition de l'operateur '==' avec une chaine de caracteres de une creature en parametre
	* @param nom Le nom a comparer avec celui de la creature
	* @param creature La creature avec qui comparer le nom
	* @return true s'ils ont le meme nom, false sinon
	*/
	friend bool operator==(const std::string& nom, const Creature& creature);

	/**
	* @brief Redefinition de l'operateur '<<' avec une creature en parametre
	* @param o L'output stream dans lequel ajouter les informations de la creature
	* @param creature La creature a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& o, const Creature& creature);

private:

	std::string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	std::vector<Pouvoir*> pouvoir_;

};

#endif