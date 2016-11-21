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

//Froncteur permettant d'obtenir l'attaque de la créature passée en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

class FoncteurComparerCreatures
{
public:
	FoncteurComparerCreatures() {}
	~FoncteurComparerCreatures() {}

	bool operator() (Creature* a, Creature* b) const {
		return a->obtenirAttaque() > b->obtenirAttaque();
	}

};

class FoncteurComparerDresseurs
{
public:
	FoncteurComparerDresseurs() {}
	~FoncteurComparerDresseurs() {}

	bool operator() (Dresseur* a, Dresseur* b) const {

		if (a->obtenirNom() < b->obtenirNom())
			return true;
		else
			return false;
	}


};


class FoncteurComparerPouvoirs
{
public:
	FoncteurComparerPouvoirs() {}
	~FoncteurComparerPouvoirs() {}

	bool operator() (Pouvoir* a, Pouvoir* b) const {
		return a->obtenirNombreDeDegat() < b->obtenirNombreDeDegat();
	}

};

class FoncteurCreaturesDeMemeNom
{
public:
	FoncteurCreaturesDeMemeNom(const std::string& nom) :nomDeReference_(nom) {}
	~FoncteurCreaturesDeMemeNom() {}

	bool operator() (Creature* creature) const {
		return creature->obtenirNom() == nomDeReference_;
	}

private:
	std::string nomDeReference_;

};

class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures(Creature* creature):creature_(creature) {}
	~FoncteurEgalCreatures() {}

	bool operator() (Creature* c) {
		return creature_ == c;
	}

private:
	Creature* creature_;

};

class FoncteurEgalDresseurs
{
public:
	FoncteurEgalDresseurs(Dresseur* dresseur):dresseur_(dresseur) {}
	~FoncteurEgalDresseurs() {}

	bool operator() (Dresseur* d) {
		return dresseur_ == d;
	}

private:
	Dresseur* dresseur_;


};

class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie(unsigned int vieMinimale, unsigned int vieMaximale):vieMinimale_(vieMinimale), vieMaximale_(vieMaximale), compteur_(0) {}
	~FoncteurCreatureVie() {}

	void operator() (Creature* creature) {
		if ((vieMinimale_ <= creature->obtenirPointDeVie()) && (creature->obtenirPointDeVie()<= vieMaximale_)) {
			compteur_++;
		}
	}
	int obtenirCompteur() const { return compteur_; }


private:
	unsigned int vieMinimale_;
	unsigned int vieMaximale_;
	int compteur_;

};

class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea():borneInf_(RAND_MIN_DEFAUT), borneSup_(RAND_MAX_DEFAUT) {}
	FoncteurGenerateurNombresAlea(int borneInf, int borneSup):borneInf_(borneInf), borneSup_(borneSup) {}

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