#include "Pouvoir.h"

Pouvoir::Pouvoir(): 
	nom_(""), nombreDeDegats_(0),
	energieNecessaire_(0)
{
}

Pouvoir::Pouvoir(string nom, int nombreDeDegats, int energieNecessaire) :
	nom_(nom), nombreDeDegats_(nombreDeDegats),
	energieNecessaire_(energieNecessaire)
{
}

Pouvoir::~Pouvoir()
{
}

string Pouvoir::obtenirNom() const
{
	return nom_;
}

void Pouvoir::modifierNom(string nom)
{
	nom_ = nom;
}

int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegats_;
}

void Pouvoir::modifierNombreDeDegat(int nombreDeDegat)
{
	nombreDeDegats_ = nombreDeDegat;
}

int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

void Pouvoir::modifierEnergieNecessaire(int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::description()
{
	cout << "Son pouvoir est : " << nom_ << " d'energie et inflige " 
		<< nombreDeDegats_ << " degats" << endl;
}
