/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
*/

#include "Dresseur.h"
#include "Foncteur.h"


Dresseur::Dresseur():nom_(""), equipe_("") {}

Dresseur::Dresseur(const std::string& nom, const std::string& equipe): nom_(nom), equipe_(equipe) {}

Dresseur::~Dresseur()
{
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

auto Dresseur::obtenirCreatures() const
{
	return creatures_;
}

Creature* Dresseur::obtenirUneCreature(const std::string& nom) const //� MODIFIFIER !!
{
    /*compl�tez moi*/
	FoncteurCreaturesDeMemeNom foncteur(nom);
	std::list<Creature*>::const_iterator it = std::find_if(creatures_.begin(), creatures_.end(), foncteur);

	if (creatures_.end() == it)
		return nullptr;

	return *it;
}

void Dresseur::modifierCreature(std::list<Creature*> creatures) //A Compl�ter
{
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(Creature* creature)
{
	FoncteurEgalCreatures comparaison(creature);
	std::list<Creature*>::const_iterator position_creature = find_if(creatures_.begin(), creatures_.end(), comparaison);
	if (position_creature != creatures_.end())
		return false;

	creatures_.push_back(creature);
	return true;
}

bool Dresseur::enleverCreature(const std::string& nom) 
{
	FoncteurCreaturesDeMemeNom foncteurComparaison(nom);
	std::list<Creature*>::const_iterator position = find_if(creatures_.begin(), creatures_.end(), foncteurComparaison);
	if (position == creatures_.end())
		return false;

	creatures_.erase(position);

	return true;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

std::string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(const std::string& equipe)
{
	equipe_ = equipe;
}

bool Dresseur::operator==(Dresseur& dresseur) const //A compl�ter
{
    if (creatures_.size() == 0 && dresseur.creatures_.size() == 0)
        return true;
    else if (creatures_.size() != dresseur.creatures_.size())
        return false;

    /*Compl�tez moi! V�rifiez l'�galit� entre les cr�atures via
    find_if*/
	std::list<Creature*>::const_iterator end = dresseur.creatures_.end();
	for (std::list<Creature*>::iterator it = dresseur.creatures_.begin(); it != end; it++) {
		FoncteurEgalCreatures comparaison(*it);
		std::list<Creature*>::const_iterator position = std::find_if(creatures_.begin(), creatures_.end(), comparaison);
		if (position == creatures_.end())
			return false;
	}

	return true;
}

bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur)
{
	return dresseur == nom;
}

std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur)
{
    return os << dresseur.nom_ << " possede " << dresseur.creatures_.size() 
        << " creature(s) et appartient a l'equipe " << dresseur.equipe_ << std::endl;
}

/*
template<typename T>
void Dresseur::appliquerFoncteurUnaire(T& foncteur) {
	
	for_each(creatures_.begin(), creatures_.end(), foncteur);
}*/

/*
template<typename T>
bool Dresseur::supprimerElements(T& foncteur) {
	
	remove_if(creatures_.begin(), creature_.end(), foncteur);

}*/

/*
template<typename T>
Creature* Dresseur::obtenirCreatureMax(T& foncteur) {
	

	std::list<Creature*>::const_iterator it = std::find_if(creatures_.begin(), creatures_.end(), foncteur);
	//std::sort(creature_.begin(), creature_.end(), foncteur);

	//return creature_.last();
	return *it;

}*/