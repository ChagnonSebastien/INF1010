#include "PouvoirPoison.h"

PouvoirPoison::PouvoirPoison(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}

PouvoirPoison::PouvoirPoison(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}

std::ostream & operator<<(std::ostream & os, const PouvoirPoison & pouvoirPoison)
{
	os << pouvoirPoison.obtenirNom() << " possede un nombre de dégat de " << pouvoirPoison.obtenirNombreDeDegat() << " et une energie necessaire de " << pouvoirPoison.obtenirEnergieNecessaire() << std::endl;
	os << "  il peut empoisonner la cible" << std::endl;
}

void Pouvoir::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	creatureEnnemie.modifierEtat(type_);
}