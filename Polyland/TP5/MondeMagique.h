#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H


#include "Dresseur.h"
#include "Creature.h"
#include <list>
#include <algorithm>


template<typename T, typename S>
class MondeMagique
{
public:
	MondeMagique(); //a verifier
	~MondeMagique(); //a verifier

	std::list<T*> obtenirListeMaitre() const;
	std::list<S*> obtenirListeCompagnon() const;

	void ajouter(T* maitre);
	void ajouter(S* compagnon);

	void supprimer(T* maitre);
	void supprimer(S* compagnon);

	template<typename A>
	void supprimerMaitre(const A& pred);

	template<typename B>
	void supprimerCompagnon(const B& pred);

	void vider();

	MondeMagique<T, S>& operator+=(T* maitre);
	MondeMagique<T, S>& operator-=(T* maitre);
	MondeMagique<T, S>& operator+=(S* compagnon);
	MondeMagique<T, S>& operator-=(S* compagnon);

private:
	std::list<T*> listMaitre_;
	std::list<S*> listCompagnon_;
};

#endif // !MONDE_MAGIQUE_H

/// agréagation?????????????
template<typename T, typename S>
inline MondeMagique<T, S>::MondeMagique()
{
};

template<typename T, typename S>
inline MondeMagique<T, S>::~MondeMagique()
{

	while (!listeMaitre_.empty())
	{
		delete listeMaitre_.back();
		listeMaitre_.back() = nullptr;
		listeMaitre_.pop_back();
	}
	while (!listCompagnon_.empty())
	{
		delete listeCompagnon_.back();
		dresseurs_.back() = nullptr;
		dresseurs_.pop_back();
	}
};

template<typename T, typename S>
std::list<T*> MondeMagique<T, S>::obtenirListeMaitre() const
{
	return listeMaitre_;
};

template<typename T, typename S>
std::list<S*> MondeMagique<T, S>::obtenirListeCompagnon() const
{
	return listeCompagnon_;
};

template<typename T, typename S>
void MondeMagique<T, S>::ajouter(T* maitre)
{
	listMaitre_.push_back(maitre);
};

template<typename T, typename S>
inline void MondeMagique<T, S>::ajouter(S* compagnon)
{
	listMaitre_.push_back(compagnon);
};

template<typename T, typename S>
void MondeMagique<T, S>::supprimer(T* maitre) 
{
	std::list<S*>::iterator it = std::find(listMaitre_.begin(), listMaitre_.end(), maitre);
	listMaitre_.erase(it);
};

template<typename T, typename S>
void MondeMagique<T, S>::supprimer(S* compagnon) 
{
	std::list<S*>::iterator it = std::find(listCompagnon_.begin(), listCompagnon_.end(), compagnon);
	listCompagnon_.erase(it);
};

template<typename T, typename S>
void MondeMagique<T, S>::vider()
{
	for(std::list<T*>::iterator it = listeMaitre_.begin(); it != listeMaitre_.end(); it++) {
		delete *it;
	}
	listeMaitre_.clear();

	for (std::list<S*>::iterator it = listeCompagnon_.begin(); it != listeCompagnon_.end(); it++) {
		delete *it;
	}
	listeCompagnon_.clear();

};

template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator+=(T* maitre) 
{
	listeMaitre_.ajouter(maitre);
	return *this;
};

template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator-=(T* maitre)
{
	listeMaitre_.supprimer(maitre);
	return *this;
};

template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator+=(S* compagnon) {

	listeCompagnon_.ajouter(compagnon);
	return *this;

};

template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator-=(S* compagnon) {

	listeCompagnon_.supprimer(compagnon);
	return *this;

};

template<typename T, typename S>
template<typename A>
void MondeMagique<T, S>::supprimerMaitre(const A& pred) 
{
	remove_if(listeMaitre_.begin(), listeMaitre_.end(), pred());
};

template<typename T, typename S>
template<typename B>
void MondeMagique<T, S>::supprimerCompagnon(const B& pred) 
{
	remove_if(listeCompagnon_.begin(), listeCompagnon_.end(), pred());
};