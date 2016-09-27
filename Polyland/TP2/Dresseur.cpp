#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_("") {}; // A MODIFIER... (si necessaire)

Dresseur::Dresseur(const std::string& nom):	nom_(nom)
{
	creatures_ = new Creature*[MAX_NOMBRE_CREATURES](); // A MODIFIER... (si necessaire)
}


Dresseur::~Dresseur() // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
	delete[]creatures_;
	creatures_ = nullptr;
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return nombreCreatures_;
}

Creature** Dresseur::obtenirCreatures() const // A MODIFIER... (si necessaire)
{
	return creatures_;
}

void Dresseur::modifierCreature(Creature** creatures) // A MODIFIER... (si necessaire)
{
	creatures_ = creatures;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

bool Dresseur::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	if (nombreCreatures_ < MAX_NOMBRE_CREATURES) {
		for (unsigned int i = 0; i < nombreCreatures_; i++)
		{
			if (creatures_[i]->obtenirNom() == creature.obtenirNom())
				return false;
		}
		creatures_[nombreCreatures_] = new Creature();
		*creatures_[nombreCreatures_] = creature;
		nombreCreatures_++;
	}
	else {
		return false;
	}
}

bool Dresseur::enleverCreature(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		if (creatures_[i]->obtenirNom() == nom)
		{
			nombreCreatures_--;
			creatures_[i] = creatures_[nombreCreatures_];
			delete creatures_[nombreCreatures_];
			creatures_[nombreCreatures_] = nullptr;

			return true;
		}
	}
	return false;
}

void Dresseur::affichage() const // A MODIFIER... (si necessaire)
{
	std::cout << nom_ << " possede " << nombreCreatures_  << " creature(s) "<< std::endl;
}

// ___TP2___
