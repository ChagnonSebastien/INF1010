#include "Professeur.h"

Professeur::Professeur(const std::string & nom, const std::string & equipe) : Dresseur(nom, equipe)
{
	outilScientifique_ = nullptr;
}

Professeur::Professeur(const Professeur & professeur) : Dresseur(professeur)
{
	outilScientifique_ = professeur.obtenirOutilScientifique();
}

Professeur::~Professeur()
{
	delete outilScientifique_;
	outilScientifique_ = nullptr;
}

OutilScientifique* Professeur::obtenirOutilScientifique() const
{
	return outilScientifique_;
}

void Professeur::modifierOutilScientifique(OutilScientifique* outilScientifique)
{
	outilScientifique_ = outilScientifique;
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

Professeur& Professeur::operator=(const Professeur & professeur)
{
		this->modifierNom(professeur.obtenirNom());
		this->modifierEquipe(professeur.obtenirEquipe());
		this->modifierOutilScientifique(professeur.obtenirOutilScientifique());
		this->modifierCreature(professeur.obtenirCreatures());

		if (professeur.obtenirObjetMagique() != nullptr)
			this->modifierObjetMagique(*professeur.obtenirObjetMagique());

	return *this;
}
