#include "Pouvoir.h"
#include <iostream>


Pouvoir::Pouvoir()
{
}

Pouvoir::Pouvoir(const Pouvoir& pouvoir) : nom_(pouvoir.obtenirNom()), nombreDeDegat_(pouvoir.obtenirNombreDeDegat()),
energieNecessaire_(pouvoir.obtenirEnergieNecessaire())
{

}

Pouvoir::Pouvoir(const std::string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}

Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

std::string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

void Pouvoir::operator=(const Pouvoir& pouvoir){

	nom_ = pouvoir.obtenirNom();
	nombreDeDegat_ = pouvoir.obtenirNombreDeDegat();
	energieNecessaire_ = pouvoir.obtenirEnergieNecessaire();

}

bool Pouvoir::operator==(const Pouvoir& pouvoir) const {

	return(nom_ == (pouvoir.obtenirNom()));

}

std::ostream & Pouvoir::operator<<(std::ostream& o) const {

	return o << "Son pouvoir est : " << nom_ << " d'energie et inflige "
		<< nombreDeDegat_ << " degats" << std::endl;
}