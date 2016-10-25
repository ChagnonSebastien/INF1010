/*
Fichier: PouvoirHallucinogene.cpp
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe Pouvoir hallucinogene correspond a un pouvoir hallucinogene de creature
*/

#include "PouvoirHallucinogene.h"

PouvoirHallucinogene::PouvoirHallucinogene(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(0)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

PouvoirHallucinogene::PouvoirHallucinogene(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

std::ostream & operator<<(std::ostream & o, const PouvoirHallucinogene & pouvoirHallucinogene)
{
	return o << pouvoirHallucinogene.obtenirNom() << " possede un nombre de dégat de " << pouvoirHallucinogene.obtenirNombreDeDegat() << " et une energie necessaire de " << pouvoirHallucinogene.obtenirEnergieNecessaire() << std::endl
	 << "  il peut endormir la cible" << std::endl;
}

void PouvoirHallucinogene::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	creatureEnnemie.modifierEtat(new EtatConfus("Coup sur la tête", duree_));
}