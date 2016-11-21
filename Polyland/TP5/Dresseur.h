/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>
#include <list>
#include <algorithm>


#include "ObjetMagique.h"
#include "Creature.h"


class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const;

	auto obtenirCreatures() const;
	Creature* obtenirUneCreature(const std::string& nom) const;
	void modifierCreature(std::list<Creature*> creatures);
	
	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

	template<typename T>
	void appliquerFoncteurUnaire(T& foncteur);

	template<typename T>
	void supprimerElements(T& foncteur);

	template<typename T>
	Creature* obtenirCreatureMax(T& foncteur);
		
private:
	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	std::list<Creature*> creatures_;
	// À COMPLÉTER !! créatures

};


template<typename T>
void Dresseur::appliquerFoncteurUnaire(T& foncteur)
{ 
	for_each(creatures_.begin(), creatures_.end(), std::ref(foncteur));
}

template<typename T>
void Dresseur::supprimerElements(T& foncteur) 
{
	//std::remove_if(creatures_.begin(), creatures_.end(), std::ref(foncteur));
	creatures_.remove_if(foncteur);
}


template<typename T>
Creature* Dresseur::obtenirCreatureMax(T& foncteur)
{
	creatures_.sort(foncteur);
	return creatures_.front();
	//std::list<Creature*>::const_iterator it = std::find_if(creatures_.begin(), creatures_.end(), foncteur);
}

#endif