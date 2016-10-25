/*
Fichier: CreatureMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 24 octobre 2016
Description: Les creatures magiques sont des etres destines au combat
*/

#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H


class CreatureMagique : public Creature
{
public:

	CreatureMagique(unsigned int bonus, const Creature& creature);

	CreatureMagique(const CreatureMagique& creatureMagique);

	~CreatureMagique();

	unsigned int obtenirBonus() const;
	AttaqueMagique* obtenirAttaqueMagique() const;

	void modifierBonus(unsigned int bonus);
	void modifierAttaqueMagique(AttaqueMagique* attaqueMagique);

	CreatureMagique& operator=(const CreatureMagique& creatureMagique);

	virtual std::string obtenirTypeCreature() const;
	
	void attaquer(Pouvoir& pouvoir, Creature& creature);

	void apprendreAttaqueMagique(AttaqueMagique* attaqueMagique);

	void oublierAttaqueMagique();

	friend std::ostream& operator<<(std::ostream & o, CreatureMagique& creatureMagique);


private:
	unsigned int bonus_;
	AttaqueMagique* attaqueMagique_;

};

#endif