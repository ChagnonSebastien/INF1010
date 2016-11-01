#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H

#include <list>

#include "Dresseur.h"
#include "Creature.h"

template<Dresseur T, Creature S>
class MondeMagique
{
public:
	MondeMagique();
	~MondeMagique();

	list<T> getListeMaitre();
	list<T> getListeCompgnon();

	void ajouter(T* maitre);
	void ajouter(S* compagnon);

	void suprimer(T* maitre);
	void suprimer(S* compagnon);

	void suprimerMaitre();

	void vider();

	MondeMagique& operator+=(T* maitre);
	MondeMagique& operator-=(T* maitre);
	MondeMagique& operator+=(S* compagnon);
	MondeMagique& operator-=(S* compagnon);

private:
	list<T*> listMaitre_;
	list<S*> listCompagnon_;
};

#endif // !MONDE_MAGIQUE_H

