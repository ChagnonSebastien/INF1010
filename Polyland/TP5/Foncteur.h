/*
Fichier: Foncteur.
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Plusieurs foncteurs
*/

#ifndef  FRONTEUR
#define  FRONTEUR

#include "Pouvoir.h"
#include "Dresseur.h"
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

/**
* @brief La classe FoncteurObtenirAttaqueCreature
*/
class FoncteurObtenirAttaqueCreature
{
public:
	/**
	* @brief Constructeur par default
	*/
    FoncteurObtenirAttaqueCreature() {}
	/**
	* @brief Destructeur de la classe
	*/
    ~FoncteurObtenirAttaqueCreature() {}

	/**
	* @brief operator() pour foncteur
	* @param pointeur de creature
	* @return attaque de la creature
	*/
    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

/**
* @brief La classe FoncteurComparerCreatures
*/
class FoncteurComparerCreatures
{
public:
	/**
	* @brief Constructeur par default
	*/
	FoncteurComparerCreatures() {}
	/**
	* @brief Destructeur de la classe
	*/
	~FoncteurComparerCreatures() {}

	/**
	* @brief operator() pour foncteur
	* @param pointeurs de creature
	* @return bool
	*/
	bool operator() (Creature* a, Creature* b) const {
		return a->obtenirAttaque() < b->obtenirAttaque();
	}

};

/**
* @brief La classe FoncteurComparerDresseurs
*/
class FoncteurComparerDresseurs
{
public:
	/**
	* @brief Constructeur par default
	*/
	FoncteurComparerDresseurs() {}
	/**
	* @brief Destructeur de la classe
	*/
	~FoncteurComparerDresseurs() {}

	/**
	* @brief operator() pour foncteur
	* @param pointeurs de Dresseur
	* @return bool
	*/
	bool operator() (Dresseur* a, Dresseur* b) const {

		if (a->obtenirNom() < b->obtenirNom())
			return true;
		else
			return false;
	}


};

/**
* @brief La classe FoncteurComparerPouvoirs
*/
class FoncteurComparerPouvoirs
{
public:
	/**
	* @brief Constructeur par default
	*/
	FoncteurComparerPouvoirs() {}
	/**
	* @brief Destructeur de la classe
	*/
	~FoncteurComparerPouvoirs() {}

	/**
	* @brief operator() pour foncteur
	* @param pointeurs de Pouvoir
	* @return bool
	*/
	bool operator() (Pouvoir* a, Pouvoir* b) const {
		return a->obtenirNombreDeDegat() < b->obtenirNombreDeDegat();
	}

};

/**
* @brief La classe FoncteurCreaturesDeMemeNom
*/
class FoncteurCreaturesDeMemeNom
{
public:
	/**
	* @brief Constructeur par paramètre
	*/
	FoncteurCreaturesDeMemeNom(const std::string& nom) :nomDeReference_(nom) {}
	/**
	* @brief Destructeur de la classe
	*/
	~FoncteurCreaturesDeMemeNom() {}

	/**
	* @brief operator() pour foncteur
	* @param pointeurs de creature
	* @return bool
	*/
	bool operator() (Creature* creature) const {
		return creature->obtenirNom() == nomDeReference_;
	}

private:
	std::string nomDeReference_;

};

/**
* @brief La classe FoncteurEgalCreatures
*/
class FoncteurEgalCreatures
{
public:
	/**
	* @brief Constructeur par default
	*/
	FoncteurEgalCreatures(Creature* creature):creature_(creature) {}
	/**
	* @brief Destructeur de la classe
	*/
	~FoncteurEgalCreatures() {}

	/**
	* @brief operator() pour foncteur
	* @param pointeurs de creature
	* @return bool
	*/
	bool operator() (Creature* c) {
		return creature_ == c;
	}

private:
	Creature* creature_;

};

/**
* @brief La classe FoncteurEgalDresseurs
*/
class FoncteurEgalDresseurs
{
public:
	/**
	* @brief Constructeur par parametre
	*/
	FoncteurEgalDresseurs(Dresseur* dresseur):dresseur_(dresseur) {}
	/**
	* @brief Destructeur de la classe
	*/
	~FoncteurEgalDresseurs() {}

	/**
	* @brief operator() pour foncteur
	* @param pointeur de dresseur
	* @return bool
	*/
	bool operator() (Dresseur* d) {
		return dresseur_ == d;
	}

private:
	Dresseur* dresseur_;


};

/**
* @brief La classe FoncteurCreatureVie
*/
class FoncteurCreatureVie
{
public:
	/**
	* @brief Constructeur par parametre
	*/
	FoncteurCreatureVie(unsigned int vieMinimale, unsigned int vieMaximale):vieMinimale_(vieMinimale), vieMaximale_(vieMaximale), compteur_(0) {}
	/**
	* @brief Destructeur de la classe
	*/
	~FoncteurCreatureVie() {}

	/**
	* @brief operator() pour foncteur
	* @param pointeur de creature
	* @return void
	*/
	void operator() (Creature* creature) {
		if ((vieMinimale_ <= creature->obtenirPointDeVie()) && (creature->obtenirPointDeVie()<= vieMaximale_)) {
			compteur_++;
		}
	}

	/**
	* @brief retourne valeur du compteur_
	* @return int compteur_
	*/
	int obtenirCompteur() const { return compteur_; }


private:
	unsigned int vieMinimale_;
	unsigned int vieMaximale_;
	int compteur_;

};

/**
* @brief La classe FoncteurGenerateurNombresAlea
*/
class FoncteurGenerateurNombresAlea
{
public:
	/**
	* @brief Constructeur par parametre
	*/
	FoncteurGenerateurNombresAlea():borneInf_(RAND_MIN_DEFAUT), borneSup_(RAND_MAX_DEFAUT) {}
	/**
	* @brief Constructeur par parametre
	*/
	FoncteurGenerateurNombresAlea(int borneInf, int borneSup):borneInf_(borneInf), borneSup_(borneSup) {}

	/**
	* @brief operator() pour foncteur
	* @return int nombre aleatoire
	*/
	int operator() () const
	{
		srand(time(NULL));
		return rand() % borneSup_ + borneInf_;
	}

private:
	int borneInf_;
	int borneSup_;

};
#endif