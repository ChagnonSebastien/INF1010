#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

/**
* @brief La classe Polyland, pour decrire le monde de Polyland
*/
class PolyLand
{
public:

	// Constructors
	/**
	* @brief Constructeur par default
	*/
	PolyLand();

	/**
	* @brief Destructeur de la classe
	*/
	~PolyLand();


	/**
	* @brief Ajouter un dresseur au monde de Polyland
	* @param dresseur Un pointeur sur le dresseur a ajouter
	* @return true si l'ajout a ete un succes, false sinon
	*/
	bool ajouterDresseur(Dresseur* dresseur);

	/**
	* @brief Retirer un dresseur au monde de Polyland
	* @param nom Le nom du dresseur a retirer
	* @return true si le retrait a ete un succes, false sinon
	*/
	bool retirerDresseur(const std::string& nom);

	/**
	* @brief Redefinition de l'operateur '+=' avec un dresseur
	* @param dresseur Un pointeur vers le dresseur a ajouter
	* @return La reference a la classe PolyLand actuelle
	*/
	PolyLand& operator+=(Dresseur* dresseur);

	/**
	* @brief Redefinition de l'operateur '-=' avec un dresseur
	* @param dresseur Un pointeur vers le dresseur a retirer
	* @return La reference a la classe PolyLand actuelle
	*/
	PolyLand& operator-=(Dresseur* dresseur);


	/**
	* @brief Ajouter une creature au monde de Polyland
	* @param creature Creature a ajouter
	* @return true si l'ajout a ete un succes, false sinon
	*/
	bool ajouterCreature(const Creature& creature);

	/**
	* @brief Retirer une creature au monde de Polyland
	* @param nom Une reference du nom de la creature a retirer
	* @return true si le retrait a ete un succes, false sinon
	*/
	bool retirerCreature(const std::string& nom);

	/**
	* @brief Redefinition de l'operateur '+=' avec une creature
	* @param creature Une reference a la creature a ajouter
	* @return La reference a la classe PolyLand actuelle
	*/
	PolyLand& operator+=(Creature& creature);

	/**
	* @brief Redefinition de l'operateur '-=' avec une creature
	* @param creature Une reference a la creature a retirer
	* @return La reference a la classe PolyLand actuelle
	*/
	PolyLand& operator-=(Creature& creature);


	/**
	* @brief Pour obtenir un dresseur aleatoire du monde de Polyland
	* @return Un pointeur vers un dresseur aleatoire
	*/
	Dresseur* choisirDresseurAleatoire();

	/**
	* @brief Pour obtenir une creature aleatoire du monde de Polyland
	* @return Un pointeur vers une creature aleatoire
	*/
	Creature* choisirCreatureAleatoire();


	/**
	* @brief Methode pour qu'un dresseur attrape une creature
	* @param dresseur Un pointeur vers le dresseur a qui ajouter la creature
	* @param Creature Un pointeur vers la creature a ajouter au dresseur
	* @return true si l'ajout a ete un succes, false sinon
	*/
	bool attraperCreature(Dresseur* dresseur, const Creature* creature);

	/**
	* @brief Methode pour qu'un dresseur relache une creature
	* @param dresseur Un pointeur vers le dresseur a qui retirer une creature
	* @param nom Une reference du nom de la creature retirer du dresseur
	* @return true si le retrait a ete un succes, false sinon
	*/
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature);


	/**
	* @brief Redefinition de l'operateur '<<' avec une instance de PolyLand en parametre
	* @param o L'output stream dans lequel ajouter les informations du dresseur
	* @param polyland Une reference a PolyLand
	* @return L'output stream recu en parametre
	*/
	friend ostream& operator<<(ostream& o, const PolyLand& polyland);

		
private:
	vector<Creature*> creatures_;
	vector<Dresseur*> dresseurs_;

};
#endif