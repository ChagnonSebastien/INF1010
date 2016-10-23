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
	return o << pouvoirSporifique.obtenirNom() << " possede un nombre de dégat de " << pouvoirSporifique.obtenirNombreDeDegat() << " et une energie necessaire de " << pouvoirSporifique.obtenirEnergieNecessaire() << std::endl
	 << "  il peut endormir la cible" << std::endl;
}

void PouvoirSoporifique::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	creatureEnnemie.modifierEtat(new EtatEndormi("Marchant de sable", duree_));
}