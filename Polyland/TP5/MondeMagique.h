#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H

#include <list>

#include "Dresseur.h"
#include "Creature.h"

template<typename T, typename S>
class MondeMagique
{
public:
	MondeMagique();
	~MondeMagique();

	std::list<T*> getListeMaitre();
	std::list<S*> getListeCompgnon();

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
	std::list<T*> listMaitre_;
	std::list<S*> listCompagnon_;
};

#endif // !MONDE_MAGIQUE_H

template<Dresseur T, Creature S>
inline MondeMagique<T, S>::MondeMagique()
{
}

template<Dresseur T, Creature S>
inline MondeMagique<T, S>::~MondeMagique()
{
}

template<Dresseur T, Creature S>
inline std::list<T> MondeMagique<T, S>::getListeMaitre()
{
	return std::list<T>();
}

template<Dresseur T, Creature S>
inline std::list<T> MondeMagique<T, S>::getListeCompgnon()
{
	return std::list<T>();
}

template<Dresseur T, Creature S>
inline void MondeMagique<T, S>::ajouter(T * maitre)
{
}
