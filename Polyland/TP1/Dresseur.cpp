#include "Dresseur.h"


// INITIALISER OBJET MAGIQUE
Dresseur::Dresseur() :
	nom_(""), creatures_(nullptr), nombreCreatures_(0),
	nombreCreaturesMax_(MAX_NOMBRE_CREATURES)
{
}

Dresseur::Dresseur(const std::string & nom) :
	nom_(nom), creatures_(nullptr),nombreCreatures_(0),
	nombreCreaturesMax_(MAX_NOMBRE_CREATURES)
{
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

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature * creature)
{
	creature->modifierPointDeVie(creature->obtenirPointDeVie() + this->objetMagique_.obtenirBonus());
	creature->modifierEnergie(creature->obtenirEnergie() + this->objetMagique_.obtenirBonus());
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return nombreCreatures_;
}

Creature ** Dresseur::obtenirCreatures() const
{
	return creatures_;
}

void Dresseur::modifierCreature(Creature ** creatures)
{
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(const Creature & creature)
{
	return creatures_[nombreCreatures_++] = &creature;
}

bool Dresseur::retirerCreature(const std::string & nom)
{
	return false;
}

void Dresseur::affichage() const
{
}
