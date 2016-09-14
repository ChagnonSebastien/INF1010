#include "Creature.h"

Creature::Creature() :
	nom_(""), attaque_(0), defense_(0), pointDeVie_(0), pointDeVieTotal_(0),
	energie_(0), energieTotal_(0), experience_(0), experienceNecessaire_(0),
	niveau_(0), pouvoir_()
{
}

Creature::Creature(string nom, int attaque, int defence, int pointDeVie,
	int energie, Pouvoir pouvoir) :
	nom_(nom), attaque_(attaque), defense_(defence), pointDeVie_(pointDeVie),
	pointDeVieTotal_(pointDeVie), energie_(energie), energieTotal_(energie),
	experience_(0), experienceNecessaire_(100), niveau_(1), pouvoir_()
{
}

Creature::~Creature()
{
}

string Creature::obtenirNom() const
{
	return nom_;
}

void Creature::modifierNom(string nom)
{
	nom_ = nom;
}

int Creature::obtenirAttaque() const
{
	return attaque_;
}

void Creature::modifierAttaque(int attaque)
{
	attaque_ = attaque;
}

int Creature::obtenirDefense() const
{
	return defense_;
}

void Creature::modifierDefense(int defense)
{
	defense_ = defense;
}

int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

void Creature::modifierPointDeVie(int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

void Creature::modifierPointDeVieTotal(int pointDeVieTotal)
{
	pointDeVieTotal_ = pointDeVieTotal;
}

int Creature::obtenirEnergie() const
{
	return energie_;
}

void Creature::modifierEnergie(int energie)
{
	energie_ = energie;
}

int Creature::obtenirEnergieTotal() const
{
	return energieTotal_;
}

void Creature::modifierEnergieTotal(int energieTotal)
{
	energieTotal_ = energieTotal;
}

int Creature::obtenirExperience() const
{
	return experience_;
}

void Creature::modifierExperience(int experience)
{
	experience_ = experience;
}

int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

void Creature::modifierExperienceNecessaire(int experienceNecessaire)
{

	experienceNecessaire_ = experienceNecessaire;
}

int Creature::obtenirNiveau() const
{
	return niveau_;
}

void Creature::modifierNiveau(int niveau)
{
	niveau_ = niveau;
}

Pouvoir Creature::obtenirPouvoir() const
{
	return pouvoir_;
}

void Creature::modifierPouvoir(Pouvoir pouvoir)
{
	pouvoir_ = pouvoir;
}

void Creature::attaquer(const Pouvoir & pouvoir, Creature & creature)
{
	//L'attaque est possible si votre créature a assez d'energie
	//Et que la creature adverse a encore des points de vie
	
	if (this->energie_ >= pouvoir.obtenirEnergieNecessaire()) {
		cout << this->nom_ << " n'a pas asser d'énergie pour attaquer"
			<< " avec ce pouvoir." << endl;
		return;
	}

	if (creature.obtenirPointDeVie <= 0) {
		cout << creature.obtenirNom() << " n'a plus de vie. Innutile d'attaquer"
			<< endl;
		return;
	}

	//Calcul du nombre de degat selon une formuleobtenirNombreDeDegat(
	unsigned int degat = (pouvoir.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
	//On choisit un nombre aléatoire entre 1 et 6
	int tentative = rand() % 6;
	//l'attaque rate une fois sur 6
	if (tentative != 3) {
		//Afficher le nom de la créature qui lance l'attaque, le nom de l'attaque,
		//le nombre de dégat infligé, et la créature qui est attaquée
		cout << this->nom_ << " lance " << pouvoir.obtenirNom() << " qui inflige "
			<< degat << " degat à " << creature.obtenirNom();

		//Afficher le nombre d'XP gagné si c'est approprié, n'oubliez pas de faire
		//les modifications adéquates
		if (creature.obtenirPointDeVie() <= 0)
			cout << this->nom_ << " a gagné " << experienceGagner(creature) << "XP";

		//Afficher le nombre de point de vie restant de la créature attaquée
		//Faites attention aux requis d'une attaque
		cout << this->nom_ << " a encore " << this->pointDeVie_ << " PV";
	}
	else {
        //La créature adverse est déjà vaincue
		cout << "Attaque " << pouvoir.obtenirNom() << " a échouée" << endl;
	}


}

int Creature::experienceGagner(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) *
		 (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else {
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}
