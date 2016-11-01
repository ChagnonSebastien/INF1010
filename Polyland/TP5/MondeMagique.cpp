#include "MondeMagique.h"

template<Dresseur T, Creature S>
MondeMagique<T, S>::MondeMagique()
{
}

template<Dresseur T, Creature S>
MondeMagique<T, S>::~MondeMagique()
{
}

template<Dresseur T, Creature S>
std::list<T> MondeMagique<T, S>::getListeMaitre()
{
	return std::list<T>();
}

template<Dresseur T, Creature S>
std::list<T> MondeMagique<T, S>::getListeCompgnon()
{
	return std::list<T>();
}
