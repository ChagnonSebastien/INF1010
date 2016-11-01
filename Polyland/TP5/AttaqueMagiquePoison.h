/*
Fichier: AttaqueMagiquePoison.h
Auteur(s): Maude Carrier
Date de creation: 11 octobre 2016
Description: La créature qui reçoit cette attaque perd de l'énergie due au poison
*/
#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "AttaqueMagique.h"

#define MIN_DUREE_POISON 2

class AttaqueMagiquePoison : public AttaqueMagique
{
public:
    AttaqueMagiquePoison(); // À MODIFIER
	AttaqueMagiquePoison(unsigned int duree); // À MODIFIER
    virtual ~AttaqueMagiquePoison();

    virtual void appliquerAttaque(Creature& Creature); // À MODIFIER

    virtual bool estFini() const;
	
	virtual std::string obtenirTypeAttaque() const;

};
#endif // !ETAT_EMPOISONNE_H

