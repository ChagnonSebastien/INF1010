/*
Fichier: ObjetMagique.cpp
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: La classe ObjetMagique correspond aux differents objets utilisables
par le dresseur sur ses creatures
*/

#include "ObjetMagique.h"
#include <iostream>

ObjetMagique::ObjetMagique()
{
}

ObjetMagique::ObjetMagique(const std::string & nom, int bonus):
	nom_(nom), bonus_(bonus)
{
}


ObjetMagique::~ObjetMagique()
{
}

std::string ObjetMagique::obtenirNom() const
{
	return nom_;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}

void ObjetMagique::utiliserSur(Creature & creature) const
{
    if ((creature.obtenirPointDeVieTotal() - creature.obtenirPointDeVie()) >= obtenirBonus()) {
        creature.modifierPointDeVie(creature.obtenirPointDeVie() + obtenirBonus());
    }
    else {
        creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
    }
    if ((creature.obtenirEnergieTotale() - creature.obtenirEnergie()) > obtenirBonus()) {
        creature.modifierEnergie(creature.obtenirEnergie() + obtenirBonus());
    }
    else {
        creature.modifierEnergie(creature.obtenirEnergieTotale());
    }
}

std::ostream& operator<<(std::ostream& os, const ObjetMagique& objet)
{
	return os << "l'objet " << objet.obtenirNom() << "fournit un bonus de " << objet.obtenirBonus() << std::endl;
}
