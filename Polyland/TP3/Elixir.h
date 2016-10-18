
#ifndef ELIXIR_H
#define ELIXIR_H

#include "PotionMagique.h"

class Elixir : public PotionMagique
{
public:
	Elixir();
	Elixir(const std::string &nom, int bonus);

	void utiliserSur(Creature & creature) const;

	friend std::ostream& operator<<(std::ostream& os, const Elixir& elixir);

};

#endif