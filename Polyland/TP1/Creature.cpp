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

int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

void Creature::modifierEnergieTotale(int energieTotal)
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

// enlever pouvoir
void Creature::attaquer(Creature & creature)
{
	//L'attaque est possible si votre créature a assez d'energie
	//Et que la creature adverse a encore des points de vie
	//Si la creature adverse n'a plus de vie, afficher un message en conséquent
	
	if (energie_ < pouvoir_.obtenirEnergieNecessaire()) {
		cout << nom_ << " n'a pas assez d'énergie pour attaquer"
			<< " avec ce pouvoir." << endl;
		return;
	}

	if (creature.obtenirPointDeVie <= 0) {
		cout << creature.obtenirNom() 
			<< " n'a plus de vie. Inutile d'attaquer." << endl;
		return;
	}

	//Calcul du nombre de degat selon une formule
	unsigned int degat = (pouvoir_.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
	//On choisit un nombre aléatoire entre 1 et 6
	int tentative = rand() % 6;
	//l'attaque rate une fois sur 6
	if (tentative != 3) {
		//Afficher le nom de la créature qui lance l'attaque, le nom de l'attaque,
		//le nombre de dégat infligé, et la créature qui est attaquée
		cout << nom_ << " lance " << pouvoir_.obtenirNom() 
			<< " qui inflige " << degat << " degat à " << creature.obtenirNom()
			<< endl;

		//Afficher le nombre d'XP gagné si c'est approprié, n'oubliez pas de faire
		//les modifications adéquates
		if (creature.obtenirPointDeVie() <= 0)
			cout << nom_ << " a gagné " << experienceGagner(creature) 
				<< " XP" << endl;

		//Afficher le nombre de point de vie restant de la créature attaquée
		//Faites attention aux requis d'une attaque
		cout << nom_ << " a encore " << pointDeVie_ << " PV" 
			<< endl;
	}
	else {
		// L'attaque a raté
		std::cout << "Attaque " << pouvoir_.obtenirNom() << " a échoué" << endl;
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


void Creature::information()
{
	cout << nom_ << " a " << attaque_ << " en attaque et " << defense_ 
		<< " en defense," << endl;
	cout << "Il a " << pointDeVie_ << "/" << pointDeVieTotal_ << " et " 
		<< energie_ << "/" << energieTotal_ << " Energie" << endl;
	cout << "Il est au niveau " << niveau_ << " avec " << experience_ 
		<< "d'XP" << endl;
	cout << "Il lui manque " << experienceNecessaire_ 
		<< " jusqu'au prochain niveau" << endl;
	cout << "Son pouvoir est : " << pouvoir_.obtenirNom() << " necessite " 
		<< pouvoir_.obtenirEnergieNecessaire() << " mana et inflige " 
		<< pouvoir_.obtenirNombreDeDegat() << " degats" << endl;


}