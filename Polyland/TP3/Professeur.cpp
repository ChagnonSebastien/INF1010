#include "Professeur.h"

Professeur::Professeur(const std::string & nom, const std::string & equipe) : Dresseur(nom, equipe)
{
}

Professeur::Professeur(Professeur & professeur) : Dresseur(professeur), outilScientifique_(
	new OutilScientifique(professeur.obtenirOutilScientifique().obtenirNom(),
	professeur.obtenirOutilScientifique().obtenirDesciption()))
{
}

Professeur::~Professeur()
{
	delete outilScientifique_;
	outilScientifique_ = nullptr;
}

OutilScientifique & Professeur::obtenirOutilScientifique() const
{
	return *outilScientifique_;
}

void Professeur::modifierOutilScientifique(OutilScientifique outilScientifique)
{
	outilScientifique_ = new OutilScientifique(outilScientifique.obtenirNom(), 
		outilScientifique.obtenirDesciption());
}

void Professeur::soignerCreature(Creature & creature)
{
	creature.modifierEnergie(creature.obtenirEnergieTotale());
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
}

void Professeur::utiliserOutil(Creature & creature)
{
	outilScientifique_->utiliser(creature);
}

Professeur& Professeur::operator=(const Professeur& professeur)
{
	if (this != &professeur)
	{
		delete outilScientifique_;
		outilScientifique_ = new OutilScientifique(*(professeur.outilScientifique_));
		modifierNom(professeur.obtenirNom());
		modifierCreature(professeur.obtenirCreatures());
		modifierEquipe(professeur.obtenirEquipe());
		modifierObjetMagique(professeur.obtenirObjetMagique());
		//delete outilScientifique_;
		//outilScientifique_ = nullptr;
		//std::cout << obtenirOutilScientifique();
		//outilScientifique_ = new OutilScientifique(professeur.obtenirOutilScientifique().obtenirNom(),
			//professeur.obtenirOutilScientifique().obtenirDesciption());
	}

	return *this;
}
