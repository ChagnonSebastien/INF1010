#include "Creature.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
;

Creature::Creature() :nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
energie_(0), experience_(0), niveau_(1)  // A MODIFIER... (si necessaire)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

Creature::Creature(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie) :
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

Creature::Creature(const Creature& creature): nom_(creature.obtenirNom()), attaque_(creature.obtenirAttaque()), defense_(creature.obtenirDefense()),
pointDeVie_(creature.obtenirPointDeVie), pointDeVieTotal_(creature.obtenirPointDeVieTotal), energie_(creature.obtenirEnergie), energieTotal_(creature.obtenirEnergieTotale),
experience_(creature.obtenirExperience), experienceNecessaire_(creature.obtenirExperienceNecessaire), niveau_(creature.obtenirNiveau)
{
	unsigned int nbPouvoirs = creature.obtenirPouvoir().size();
	for (unsigned int i = 0; i < nbPouvoirs; i++) {
		Pouvoir* p = new Pouvoir;
		*p = *(creature.obtenirPouvoir[i]);
		pouvoir_.push_back(p);
	}
}

Creature::~Creature() // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < pouvoir_.size(); i++) {
		delete pouvoir_[i];
	}
	pouvoir_.clear();
}

std::string Creature::obtenirNom() const
{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

std::vector<Pouvoir*> Creature::obtenirPouvoir() const
{
	return pouvoir_;
}


void Creature::attaquer(Pouvoir & pouvoir, Creature & creature)// A MODIFIER... (si necessaire)
{
	int pouvoirUtiliser;
	for (unsigned int i = 0; i < pouvoir_.size(); i++) {
		if (*(pouvoir_[i]) == pouvoir) {
			pouvoirUtiliser = i;
		}
	}
	if (energie_ >= pouvoir_[pouvoirUtiliser]->obtenirEnergieNecessaire())
	{
		if (creature.obtenirPointDeVie() >= 0)
		{
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = (pouvoir_[pouvoirUtiliser]->obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				std::cout << nom_ << " lance " << pouvoir_[pouvoirUtiliser]->obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << std::endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					int xp = experienceGagnee(creature);
					std::cout << nom_ << " a gagné " << xp << " XP" << std::endl;
				}
				else
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				std::cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << std::endl;
				energie_ -= pouvoir_[pouvoirUtiliser]->obtenirEnergieNecessaire();
			}
			else {
				std::cout << "Attaque " << pouvoir_[pouvoirUtiliser]->obtenirNom() << " a échouée" << std::endl;
			}
		}
		else
			std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << std::endl;
	}

}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0)
	{
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_))
		{
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else
		{
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::modifierNom(std::string nom)
{
	nom_ = nom;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::modifierPouvoirs(std::vector<Pouvoir*>& pouvoirs) // A MODIFIER... (si necessaire)
{
	unsigned int nbPouvoirs = pouvoirs.size();
	for (unsigned int i = 0; i < nbPouvoirs; i++) {
		Pouvoir* p = new Pouvoir;
		*p = *(pouvoirs[i]);
		pouvoir_.push_back(p);
	}
}


Creature& Creature::operator=(const Creature& creature)
{
	nom_ = creature.obtenirNom;
	attaque_ = creature.obtenirAttaque;
	defense_ = creature.obtenirDefense;
	pointDeVie_ = creature.obtenirPointDeVie;
	pointDeVieTotal_ = creature.obtenirPointDeVieTotal;
	energie_ = creature.obtenirEnergie;
	energieTotal_ = creature.obtenirEnergieTotale;
	experience_ = creature.obtenirExperience;
	experienceNecessaire_ = creature.obtenirExperienceNecessaire;
	niveau_ = creature.obtenirNiveau;


	unsigned int nbPouvoirs = creature.obtenirPouvoir().size();

	for (unsigned int i = 0; i < nbPouvoirs; i++) {
		Pouvoir* p = new Pouvoir;
		*p = *(creature.obtenirPouvoir()[i]);
		pouvoir_.push_back(p);
	}

	return *this;
}

void Creature::apprendrePouvoir(Pouvoir& pouvoir)
{
	Pouvoir* p = new Pouvoir;
	*p = pouvoir;
	pouvoir_.push_back(p);
}
void Creature::oublierPouvoir(Pouvoir& pouvoir)
{
	for (unsigned int i = 0; i < pouvoir_.size(); i++) {
		if (*(pouvoir_[i]) == pouvoir) {
			pouvoir_.erase(pouvoir_.begin() + i);
		}
	}

}

bool Creature::operator==(const Creature& creature) const
{
	if (nom_ != creature.obtenirNom) {
		return false;
	}
	if (attaque_ != creature.obtenirAttaque) {
		return false;
	}
	if (defense_ != creature.obtenirDefense) {
		return false;
	}
	if (pointDeVie_ != creature.obtenirPointDeVie) {
		return false;
	}
	if (pointDeVieTotal_ != creature.obtenirPointDeVieTotal) {
		return false;
	}
	if (energie_ != creature.obtenirEnergie) {
		return false;
	}
	if (energieTotal_ != creature.obtenirEnergieTotale) {
		return false;
	}
	if (experience_ != creature.obtenirExperience) {
		return false;
	}
	if (experienceNecessaire_ != creature.obtenirExperienceNecessaire) {
		return false;
	}
	if (niveau_ != creature.obtenirNiveau) {
		return false;
	}

	return true;
}

bool Creature::operator==(const std::string& nom) const {

	return (nom_ == nom);
}

bool Creature::operator==(const Creature& creature) const {

	return (creature.obtenirNom() == nom_);
}


bool operator==(const std::string & nom, const Creature & creature) {

	return (nom == creature.obtenirNom);
}

std::ostream & operator<<(std::ostream & o, const Creature& creature)
{
	o << creature.obtenirNom << " a " << creature.obtenirAttaque << " en attaque et " << creature.obtenirDefense << " en defense," << std::endl
		<< "Il a " << creature.obtenirPointDeVie << "/" << creature.obtenirPointDeVieTotal << " et "
		<< creature.obtenirEnergie << "/" << creature.obtenirEnergieTotale << " Energie" << std::endl
		<< "Il est au niveau " << creature.obtenirNiveau << " avec " << creature.obtenirExperience
		<< "d'XP" << std::endl << "Il lui manque " << creature.obtenirExperienceNecessaire
		<< " jusqu'au prochain niveau" << std::endl << "Son pouvoir est : ";
	
	for (unsigned int i = 0; i < creature.obtenirPouvoir.size(); i++) {
	  o << *(creature.obtenirPouvoir[i]) << std::endl;
	}

}