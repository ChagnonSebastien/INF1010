#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <vector>
#include "Creature.h"

/**
* @brief Le nombre de creatures maximal par default d'un dresseur
*/
#define MAX_NOMBRE_CREATURES 2

using namespace std;

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
	Dresseur(const string& nom, const string& equipe);

	/**
	* @brief Destructeur de la classe
	*/
	~Dresseur();


	// Getters
	/**
	* @brief Pour obtenir le nom du dresseur
	* @return Le nom du dresseur
	*/
	string obtenirNom() const;

	/**
	* @brief Pour obtenir l'equipe
	* @return Le equipe du dresseur
	*/
	string obtenirEquipe() const;

	/**
	* @brief Pour obtenir les creatures du dresseur
	* @return Le vecteur de pointeur des creatures du dresseur
	*/
	vector<Creature*> obtenirCreatures() const;

	/**
	* @brief Pour obtenir le nombre de creatures du dresseur
	* @return Le nombre de creatures du dresseur
	*/
	unsigned int obtenirNombreCreatures() const;

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
	void modifierNom(const string& nom);

	/**
	* @brief Pour modifier l'equipe
	* @param nom La nouvelle equipe du dresseur
	*/
	void modifierEquipe(string equipe);

	/**
	* @brief Pour modifier les creatures du dresseur
	* @param creatures Les nouvelles creatures du dresseur
	*/
	void modifierCreature(vector<Creature*> creatures);

	/**
	* @brief Pour modifier l'objet magique du dresseur
	* @param objetMagique Le nouvel objet magique du dresseur
	*/
	void modifierObjetMagique(const ObjetMagique& objetMagique);


	/**
	* @brief Pour obtenir une creature avec un nom donnee
	* @param nom Le nom de la creature demandee
	* @return Un pointeur de la creature demandee
	*/
	Creature* obtenirUneCreature(string nom);

	/**
	* @brief Pour utiliser un objet magique sur une creature
	* @param creature Un pointeur sur la creature sur laquelle utiliser l'objet magique
	*/
	void utiliserObjetMagique(Creature* creature);

	/**
	* @brief Pour ajouter une creature a un dresseur
	* @param creature Un pointeur sur la creature a ajouter
	* @return true si la creature a ete ajoutee avec succes, false sinon
	*/
	bool ajouterCreature(const Creature* creature);

	/**
	* @brief Pour retirer une creature du dresseur
	* @param nom Le nom de la creature a retirer
	* @return true si la creature a ete retiree avec succes, false sinon
	*/
	bool enleverCreature(const string& nom);


	/**
	* @brief Redefinition de l'operateur '<<' avec un dresseur en parametre
	* @param o L'output stream dans lequel ajouter les informations du dresseur
	* @param dresseur Le dresseur a afficher les informations
	* @return L'output stream recu en parametre
	*/
	friend ostream& operator<<(ostream& o, const Dresseur& dresseur);

	/**
	* @brief Redefinition de l'operateur '==' avec un dresseur en parametre
	* @param dresseur Le dresseur a comparer avec le dresseur actuel
	* @return true s'ils ont les memes creatures, false sinon
	*/
	bool operator==(const Dresseur& dresseur) const;

	/**
	* @brief Redefinition de l'operateur '==' avec un dresseur en parametre
	* @param nom Le nom a comparer avec celui du dresseur
	* @return true s'ils ont le meme nom, false sinon
	*/
	bool operator==(const string nom) const;

	/**
	* @brief Redefinition de l'operateur '==' avec un dresseur en parametre
	* @param nom Le nom a comparer avec celui du dresseur
	* @param dresseur Le dresseur avec qui comparer le nom
	* @return true s'ils ont le meme nom, false sinon
	*/
	friend bool operator==(const string nom, const Dresseur& dresseur);

private:
	string nom_;
	ObjetMagique objetMagique_;
	vector<Creature*> creatures_;
	string equipe_;


};

#endif