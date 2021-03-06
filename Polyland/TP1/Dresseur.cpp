/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO, Sebastien CHAGNON, Audrey LABRIE
Date de creation: 31 aout 2016
Date de modification: 26 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#include "Dresseur.h"


Dresseur::Dresseur() :
	nom_(""), creatures_(nullptr), nombreCreatures_(0),
	nombreCreaturesMax_(MAX_NOMBRE_CREATURES)
{
	creatures_ = new Creature*[nombreCreaturesMax_];
}

Dresseur::Dresseur(const std::string & nom) :
	nom_(nom), creatures_(nullptr),nombreCreatures_(0),
	nombreCreaturesMax_(MAX_NOMBRE_CREATURES)
{
	creatures_ = new Creature*[nombreCreaturesMax_];
}

Dresseur::~Dresseur()
{
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string & nom)
{
	nom_ = nom;
}

Creature ** Dresseur::obtenirCreatures() const
{
	return creatures_;
}

void Dresseur::modifierCreature(Creature ** creatures)
{
	creatures_ = creatures;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return nombreCreatures_;
}

void Dresseur::modifierNombreCreatures(unsigned int nombreCreatures)
{
	nombreCreatures_ = nombreCreatures;
}

unsigned int Dresseur::obtenirNombreCreaturesMax() const
{
	return nombreCreaturesMax_;

}

void Dresseur::modifierNombreCreaturesMax(unsigned int nombreCreaturesMax)
{
	nombreCreaturesMax_ = nombreCreaturesMax;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

bool Dresseur::ajouterCreature(const Creature & creature) {

	bool possedeCreature = false;
	Creature ptr = creature;

	for (int i = 0; i < nombreCreatures_; i++)
		if (creatures_[i]->obtenirNom() == creature.obtenirNom())
			return false;

	if (nombreCreatures_ >= nombreCreaturesMax_) {
		
		nombreCreaturesMax_ *= 2;
		Creature** creatures = new Creature*[nombreCreaturesMax_];
		for (int i = 0; i < nombreCreatures_; i++)
			creatures[i] = creatures_[i];
		
		delete creatures_;
		creatures_ = creatures;
	}

	creatures_[nombreCreatures_++] = &ptr;

	cout << "==================" << endl;
	creatures_[0]->information();

	return true;
}

bool Dresseur::retirerCreature(const std::string & nom)
{	
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] = nullptr;
			for (int j = i + 1; i < nombreCreatures_; j++) {
				creatures_[j - 1] = creatures_[j];
				creatures_[j] = nullptr;
			}
			nombreCreatures_--;
			return true;
		}
	}
	return false;
}


void Dresseur::utiliserObjetMagique(Creature * creature)
{
	if ((objetMagique_.obtenirBonus() + creature->obtenirPointDeVie()) >= creature->obtenirPointDeVieTotal()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}

	else if ((objetMagique_.obtenirBonus() + creature->obtenirPointDeVie()) < creature->obtenirPointDeVieTotal()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}

	else if ((objetMagique_.obtenirBonus() + creature->obtenirEnergie()) >= creature->obtenirEnergieTotale()) {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}

	else if ((objetMagique_.obtenirBonus() + creature->obtenirEnergie()) < creature->obtenirEnergieTotale()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
}

void Dresseur::affichage() const
{
	cout << "Informations sur le dresseur:" << endl;
	cout << nom_ << " possede " << nombreCreatures_ << " creature(s)" << endl;
}
