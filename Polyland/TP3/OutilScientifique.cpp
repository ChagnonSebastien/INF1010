/*
Fichier: ObjetScientifique.cpp
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Il s'agit des différents outils utilisables par un professeur
*/

#include "OutilScientifique.h"

OutilScientifique::OutilScientifique(const std::string & nom, const std::string & description) :
    nom_(nom), description_(description)
{
}

OutilScientifique::~OutilScientifique()
{
}

std::string OutilScientifique::obtenirNom() const
{
    return nom_;
}

std::string OutilScientifique::obtenirDesciption() const
{
    return description_;
}

void OutilScientifique::utiliser(Creature & creature)
{
    //methode de classe de base
    //ne fait rien
}

std::ostream & operator<<(std::ostream & os, const OutilScientifique & outil)
{
    return os << "l'outil " << outil.nom_ << " Permet de " << outil.description_;
}
