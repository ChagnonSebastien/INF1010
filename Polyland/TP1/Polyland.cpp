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
bool Polyland::retirerDresseur(Dresseur& dresseur) {

	for (int i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == dresseur.obtenirNom()) {
			dresseurs_[i] = nullptr;
			nombreDresseurs_--;
			for (int j = i + 1; j < 100; i++) {
				dresseurs_[j] = dresseurs_[j - 1];
				dresseurs_[j] = nullptr;
			}
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
bool Polyland::retirerCreature(Creature& creature) {
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == creature.obtenirNom()) {
			creatures_[i] = nullptr;
			nombreCreatures_--;
			for (int j = i + 1; j < 100; i++) {
				creatures_[j] = creatures_[j - 1];
				creatures_[j] = nullptr;
			}
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

bool Polyland::attraperCreature(Dresseur* dresseur, Creature* Creature) {
	srand((unsigned)time(NULL));
	int tentative = rand() % 6;
	
	if (tentative != 3)
		return dresseur->ajouterCreature(*Creature);
	else
		return false;
}

bool Polyland::relacherCreature(Dresseur* dresseur, Creature* Creature) {


}

void Polyland::infoDresseur() const {

}

