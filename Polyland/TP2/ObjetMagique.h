#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>

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
	ObjetMagique(const std::string &nom, int bonus);

	/**
	* @brief Destructeur de la classe
	*/
	~ObjetMagique();


	// Getters
	/**
	* @brief Pour obtenir le nom de l'objet magique
	* @return Le nom de l'objet magique
	*/
	std::string obtenirNom() const;

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
	void modifierNom(const std::string& nom);

	/**
	* @brief Pour modifier le bonus de l'objet mgique
	* @param nom Le nouveau bonus de l'objet magique
	*/
	void modifierBonus(int bonus);


	/**
	* @brief Redefinition de l'operateur '<<' avec un objet magique en parametre
	* @param o L'output stream dans lequel ajouter les informations du dresseur
	* @param objetMagique L'objet magique a afficher les informations
	* @return L'output stream recu en parametre
	*/
	std::ostream& operator<<(std::ostream& o) const;

private:
	std::string nom_;
	int bonus_;
};

#endif
