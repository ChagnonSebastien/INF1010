/*
Fichier: Polyland.cpp
Auteur(s): Sebastien CHAGNON, Audrey LABRIE
Date de creation: 31 aout 2016
Date de modification: 26 septembre 2016
Description: Polyland est le monde de notre jeu
*/
#include "Polyland.h"
#include <ctime>
#include <cstdlib>

Polyland::Polyland() {
	for (int i = 0; i < 100; i++) {
		dresseurs_[i] = nullptr;
	}

	for (int i = 0; i < 1000; i++) {
		creatures_[i] = nullptr;
	}

	nombreDresseurs_ = 0;
	nombreCreatures_ = 0;
}

Polyland::~Polyland() {

	for (int i = 0; i < nombreDresseurs_; i++) {
		delete dresseurs_[i];
	}

	for (int i = 0; i < nombreCreatures_; i++) {
		delete creatures_[i];
	}

}

bool Polyland::ajouterDresseur(Dresseur& dresseur) {

	for(int i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == dresseur.obtenirNom()) {
			return false;
		}
	}

	dresseurs_[nombreDresseurs_] = &dresseur;
	nombreDresseurs_++;
	return true;

}
bool Polyland::retirerDresseur(string nom) {

	for (int i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			dresseurs_[i] = nullptr;
			for (int j = i + 1; j < nombreDresseurs_; i++) {
				dresseurs_[j - 1] = dresseurs_[j];
				dresseurs_[j] = nullptr;
			}
			nombreDresseurs_--;
			return true;
		}
	}
	return false;
}

bool Polyland::ajouterCreature(Creature& creature) {
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == creature.obtenirNom()) {
			return false;
		}
	}

	creatures_[nombreCreatures_] = &creature;
	nombreCreatures_++;
	return true;
}

bool Polyland::retirerCreature(string nom) {
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] = nullptr;
			for (int j = i + 1; j < nombreCreatures_; i++) {
				creatures_[j - 1] = creatures_[j];
				creatures_[j] = nullptr;
			}
			nombreCreatures_--;
			return true;
		}
	}

}

Dresseur* Polyland::choisirDresseurAleatoire() {
	
	srand((unsigned)time(NULL));
	int positionAleatoire = rand() % nombreDresseurs_;

	return dresseurs_[positionAleatoire];

}

Creature* Polyland::choisirCreatureAleatoire() {

	srand((unsigned)time(NULL));
	int positionAleatoire = rand() % nombreCreatures_;

	return creatures_[positionAleatoire];
}

bool Polyland::attraperCreature(Dresseur* dresseur, Creature Creature) {
	srand((unsigned)time(NULL));
	int tentative = rand() % 6;
	
	if (tentative != 3)
		return dresseur->ajouterCreature(Creature);
	else
		return false;
}

bool Polyland::relacherCreature(Dresseur* dresseur, string nom) {

	return dresseur->retirerCreature(nom);

}

void Polyland::infoDresseur(string nom) const {

	int i = 0;

	while (i < nombreCreatures_ && dresseurs_[i]->obtenirNom() == nom) {
		i++;
	}
	
	cout << dresseurs_[i]->obtenirNom() << " possede " << dresseurs_[i]->obtenirNombreCreatures() << " creature(s)" << endl;
	
	for (unsigned int j = 0; j < dresseurs_[i]->obtenirNombreCreatures(); j++) {
		cout << "- " << (j + 1) << " -"; 
		dresseurs_[j]->affichage();
		cout << endl;
	}
}




