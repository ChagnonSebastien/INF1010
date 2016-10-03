#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand()
{
}


PolyLand::~PolyLand()
{
	for (int i = 0; i < creatures_.size(); i++) {
		delete creatures_[i];
		creatures_[i] = nullptr;
	}

	for (int i = 0; i < dresseurs_.size(); i++) {
		delete dresseurs_[i];
		dresseurs_[i] = nullptr;
	}
}

bool PolyLand::ajouterDresseur(Dresseur* dresseur) // A MODIFIER... (si necessaire)
{
	if (dresseurs_.size() >= MAX_DRESSEURS)
		return false;

	for (unsigned int i = 0; i < dresseurs_.size(); i++)
		if (*dresseur == dresseurs_[i]->obtenirNom()) {
			std::cout << dresseur->obtenirNom() << " n'a pas été ajouté" << std::endl;
			return false;
		}

	dresseurs_.push_back(dresseur);
	std::cout << dresseur->obtenirNom() << " a bien été ajouté !" << std::endl;
	return true;
}

bool PolyLand::retirerDresseur(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
		if (*dresseurs_[i] == nom)
		{
			delete dresseurs_[i];
			dresseurs_.erase(dresseurs_.begin() + i);
			return true;
		}
	
	return false;
}

PolyLand PolyLand::operator+=(Dresseur * dresseurs_)
{
	ajouterDresseur(dresseurs_);
	return *this;
}

PolyLand PolyLand::operator-=(Dresseur * dresseurs_)
{
	retirerDresseur(dresseurs_->obtenirNom());
	return *this;
}

bool PolyLand::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	if(creatures_.size() >= MAX_CREATURES)
		return false;

	for (int i = 0; i < creatures_.size(); i++)
		if (creature == creatures_[i]->obtenirNom()) {
			std::cout << creature.obtenirNom() << " n'a pas été ajouté" << std::endl;
			return false;
		}

	creatures_.push_back(new Creature());
	*creatures_[creatures_.size() - 1] = creature;
	std::cout << creature.obtenirNom() << " a bien été ajouté !" << std::endl;
	return true;
}

bool PolyLand::retirerCreature(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < creatures_.size(); i++)
		if (*creatures_[i] == nom)
		{
			delete creatures_[i];
			creatures_.erase(creatures_.begin() + i);
			return true;
		}

	return false;
}

PolyLand PolyLand::operator+=(Creature & creature)
{
	ajouterCreature(creature);
	return *this;
}

PolyLand PolyLand::operator-=(Creature & creature)
{
	retirerCreature(creature.obtenirNom());
	return *this;
}

Dresseur* PolyLand::choisirDresseurAleatoire() // A MODIFIER... (si necessaire)
{
	if (dresseurs_.size() > 0) 
    {
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else 
    {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire() // A MODIFIER... (si necessaire)
{
	if (creatures_.size() > 0) 
    {
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur,const Creature& creature) // A MODIFIER... (si necessaire)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

ostream& operator<<(ostream& o, const PolyLand& polyland)
{
	for (int i = 0; i < polyland.creatures_.size(); i++)
		cout << *polyland.dresseurs_[i];
}
