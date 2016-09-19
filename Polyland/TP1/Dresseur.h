/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include "ObjetMagique.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
    Dresseur();
    Dresseur(const std::string& nomz);
    ~Dresseur();

    std::string obtenirNom() const;
    void modifierNom(const std::string& nom);

	Creature** obtenirCreatures() const;
	void modifierCreature(Creature** creatures);

	unsigned int obtenirNombreCreatures() const;
	void modifierNombreCreatures(unsigned int nombreCreatures);

	unsigned int obtenirNombreCreaturesMax() const;
	void modifierNombreCreaturesMax(unsigned int nombreCreaturesMax);

    ObjetMagique obtenirObjetMagique() const;
    void modifierObjetMagique(const ObjetMagique& objetMagique);


    bool ajouterCreature(const Creature& creature);
    bool retirerCreature(const std::string& nom);
	void utiliserObjetMagique(Creature* creature);
    void affichage() const;

private:
    std::string nom_;
    Creature** creatures_;
    unsigned int nombreCreatures_;
    unsigned int nombreCreaturesMax_;
    ObjetMagique objetMagique_;

};

#endif