#include "Professeur.h"

Professeur::Professeur(const std::string & nom, const std::string & equipe) : Dresseur(nom, equipe)
{
}

Professeur::Professeur(Professeur & professeur) : Dresseur(professeur), outilScientifique_(
	new OutilScientifique(professeur.getOutilScientifique().obtenirNom(),
	professeur.getOutilScientifique().obtenirDesciption()))
{
}

Professeur::~Professeur()
{
	delete outilScientifique_;
	outilScientifique_ = nullptr;
}

OutilScientifique & Professeur::getOutilScientifique() const
{
	return *outilScientifique_;
}

void Professeur::setOutilScientifique(OutilScientifique outilScientifique)
{
	outilScientifique_ = new OutilScientifique(outilScientifique.obtenirNom(), 
		outilScientifique.obtenirDesciption());
}

void Professeur::soignerCreature(Creature & creature)
{
	creature.modifierEnergie(creature.obtenirEnergieTotale);
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal);
}

void Professeur::utiliserOutil(Creature & creature)
{
	outilScientifique_->utiliser(creature);
}

Professeur& Professeur::operator=(const Professeur& professeur)
{
	if (this != &professeur)
	{
		modifierNom(professeur.obtenirNom());
		modifierCreature(professeur.obtenirCreatures());
		modifierEquipe(professeur.obtenirEquipe());
		modifierObjetMagique(professeur.obtenirObjetMagique());

		outilScientifique_ = new OutilScientifique(professeur.getOutilScientifique().obtenirNom(),
			professeur.getOutilScientifique().obtenirDesciption());
	}

	return *this;
}
