#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() : nom_(""), equipe_("")
{
}


Dresseur::Dresseur(const string & nom, const string & equipe) : nom_(nom), equipe_(equipe)
{
}


Dresseur::~Dresseur() // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const string& nom)
{
	nom_ = nom;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

vector<Creature*> Dresseur::obtenirCreatures() const
{
	return creatures_;
}

void Dresseur::modifierCreature(vector<Creature*> creatures)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}

	creatures_ = creatures;
}

string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(string equipe)
{
	equipe_ = equipe;
}

Creature* Dresseur::obtenirUneCreature(string nom)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
		if (*creatures_[i] == nom)
			return creatures_[i];
}

bool Dresseur::operator==(const Dresseur & dresseur) const
{
	if (creatures_.size() != dresseur.obtenirNombreCreatures())
		return false;

	if (creatures_.empty() && dresseur.obtenirCreatures().empty())
		return true;
	
	unsigned int compteur = 0;
	
	for (unsigned int i = 0; i < dresseur.obtenirNombreCreatures(); i++)
	{
		for (unsigned int j = 0; j < creatures_.size(); j++)
			if (*(creatures_[i]) == *(dresseur.obtenirCreatures()[j])) {
				compteur++;
			}
	}

	if (compteur == dresseur.obtenirNombreCreatures())
		return true;

	return false;
}

bool Dresseur::operator==(const string nom) const
{
	return nom == nom_;
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

bool Dresseur::ajouterCreature(const Creature* creature) // A MODIFIER... (si necessaire)
{
	if (creatures_.size() >= MAX_NOMBRE_CREATURES)
		return false;

	creatures_.push_back(new Creature());
	*creatures_[creatures_.size() - 1] = *creature;
	return true;
}

bool Dresseur::enleverCreature(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
		if (*creatures_[i] == nom) {
			creatures_.erase(creatures_.begin() + i);
			return true;
		}

	return false;
}

ostream& operator<<(ostream& o, const Dresseur& dresseur) // A MODIFIER... (si necessaire)
{
	return o << dresseur.obtenirNom() << " possede " << dresseur.obtenirNombreCreatures()  << " creature(s) "
		<< "et appartient a l'equipe " << dresseur.obtenirEquipe() << endl;
}

bool operator==(const string nom, const Dresseur & dresseur)
{
	return (dresseur.obtenirNom() == nom);
}

// ___TP2___
