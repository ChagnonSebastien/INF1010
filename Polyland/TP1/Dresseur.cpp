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

Creature ** Dresseur::obtenirCreatures() const
{
	return creatures_;
}


//AL: je la comprends pas celle la
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

bool Dresseur::ajouterCreature(const Creature & creature)
{
	bool possedeCreature = false;

	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == creature.obtenirNom()) {
			possedeCreature = true;
		}
	}

	if (possedeCreature) {
		return false;
	}

	//Utiliser modifierNombreCreaturesMax au lieu de nombreCreaturesMax_*=2 ???
	else {
		*creatures_[nombreCreatures_++] = creature;
		if (nombreCreatures_ == nombreCreaturesMax_) {
			nombreCreaturesMax_ *= 2;
		}
		return true;
	}
}

//Utiliser modifierNombreCreatures() au lieu de nombreCreatures_-- ???
bool Dresseur::retirerCreature(const std::string & nom)
{	
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] = nullptr;
			nombreCreatures_--;
			return true;
		}
	}
	return false;
}

//L'attribut point de vie et energie de la créature ne doivent jamais dépasser le nombre des attributs maximaux correspondants (???)
void Dresseur::utiliserObjetMagique(Creature * creature)
{
	creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
}

void Dresseur::affichage() const
{
	cout << "Informations sur le dresseur:" << endl;
	cout << nom_ << " possede " << nombreCreatures_ << " creature(s)" << endl;
}
