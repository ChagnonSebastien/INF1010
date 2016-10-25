/*
Fichier: PouvoirSoporifique.cpp
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe Pouvoir Soporifique correspond a un pouvoir soporifique de creature
*/

#include "PouvoirSoporifique.h"

PouvoirSoporifique::PouvoirSoporifique(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(0)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

PouvoirSoporifique::PouvoirSoporifique(const std::string & nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

std::ostream & operator<<(std::ostream & o, const PouvoirSoporifique & pouvoirSporifique)
{
	return o << pouvoirSporifique.obtenirNom() << " possede un nombre de d�gat de " << pouvoirSporifique.obtenirNombreDeDegat() << " et une energie necessaire de " << pouvoirSporifique.obtenirEnergieNecessaire() << std::endl
	 << "  il peut endormir la cible" << std::endl;
}

void PouvoirSoporifique::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	creatureEnnemie.modifierEtat(new EtatEndormi("Marchant de sable", duree_));
}