#include "ObjetMagique.h"

ObjetMagique::ObjetMagique() :nom_(""), bonus_(0)
{
}

ObjetMagique::ObjetMagique(string nom, int bonus):nom_(nom), bonus_(bonus)
{
}

ObjetMagique::~ObjetMagique()
{
}

void ObjetMagique::modifierNom(string nom)
{
	nom_ = nom;
}

string ObjetMagique::obtenirNom() const
{
	return nom_;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;

}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::affichage()
{
	cout << "L'objet " << nom_ << " fournit un bonus de " << bonus_ << endl;
}
