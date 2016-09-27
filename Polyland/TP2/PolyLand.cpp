#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() // A MODIFIER... (si necessaire)
{
	dresseurs_ = new Dresseur*[MAX_DRESSEURS]();
	creatures_ = new Creature*[MAX_CREATURES]();
}


PolyLand::~PolyLand() // A MODIFIER... (si necessaire)
{
	delete[]dresseurs_;
	dresseurs_ = nullptr;

	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
	delete[]creatures_;
	creatures_ = nullptr;

}

bool PolyLand::ajouterDresseur(Dresseur* dresseur) // A MODIFIER... (si necessaire)
{
	if (nombreDresseurs_ >= MAX_DRESSEURS)
		return false;
	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (dresseurs_[i]->obtenirNom() == dresseur->obtenirNom())
			return false;
	}
	dresseurs_[nombreDresseurs_++] = dresseur;
	std::cout << dresseur->obtenirNom() << " a bien été ajouté !" << std::endl;
	return true;
}

bool PolyLand::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	if(nombreCreatures_ >= MAX_CREATURES)
		return false;
	creatures_[nombreCreatures_] = new Creature();
	*creatures_[nombreCreatures_] = creature;
	nombreCreatures_++;
	std::cout << creature.obtenirNom() << " a bien été ajouté !" << std::endl;
	return true;
}

bool PolyLand::retirerDresseur(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (dresseurs_[i]->obtenirNom() == nom)
		{
			dresseurs_[i] = dresseurs_[nombreDresseurs_ - 1];
			dresseurs_[nombreDresseurs_ - 1] = nullptr;
			nombreDresseurs_--;
			return true;
		}
	}
	return false;
}

bool PolyLand::retirerCreature(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		if (creatures_[i]->obtenirNom() == nom)
		{
			delete creatures_[i];
			creatures_[i] = creatures_[nombreCreatures_ - 1];
			creatures_[nombreCreatures_ - 1] = nullptr;
			nombreCreatures_--;
			return true;
		}
	}
	return false;
}

Dresseur* PolyLand::choisirDresseurAleatoire() // A MODIFIER... (si necessaire)
{
	if (nombreDresseurs_ > 0) 
    {
		unsigned int indice = rand() % nombreDresseurs_;
		return dresseurs_[indice];
	}
	else 
    {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire() // A MODIFIER... (si necessaire)
{
	if (nombreCreatures_ > 0) 
    {
		unsigned int indice = rand() % nombreCreatures_;
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

void PolyLand::infoDresseur(const std::string& nom) const // A MODIFIER... (si necessaire)
{
	Dresseur* dresseur = nullptr;
	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (dresseurs_[i]->obtenirNom() == nom)
		{
			dresseur = dresseurs_[i];
			break;
		}
	}
	if (dresseur != nullptr)
	{
		std::cout << "Informations sur le dresseur: " << std::endl;
		dresseur->affichage();
		for (unsigned int i = 0; i < dresseur->obtenirNombreCreatures(); i++)
		{
			std::cout << "- " << i + 1 << " - ";
			dresseur->obtenirCreatures()[i]->information();
		}
	}
	else
	{
		std::cout << "Dresseur introuvable!" << std::endl;
	}
}
