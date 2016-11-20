#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H

#include <list>
#include <algorithm>


template<typename T, typename S>
class MondeMagique
{
public:
	MondeMagique(); //a verifier
	~MondeMagique(); //a verifie

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

}

template<typename T, typename S>
inline MondeMagique<T, S>::~MondeMagique()
{

	while (!listMaitre_.empty())
	{
		delete listMaitre_.back();
		listMaitre_.back() = nullptr;
		listMaitre_.pop_back();
	}
	while (!listCompagnon_.empty())
	{
		delete listCompagnon_.back();
		listCompagnon_.back() = nullptr;
		listCompagnon_.pop_back();
	}
}

template<typename T, typename S>
std::list<T*> MondeMagique<T, S>::obtenirListeMaitre() const
{
	return listMaitre_;
}

template<typename T, typename S>
std::list<S*> MondeMagique<T, S>::obtenirListeCompagnon() const
{
	return listCompagnon_;
}

template<typename T, typename S>
void MondeMagique<T, S>::ajouter(T* maitre)
{
	listMaitre_.push_back(maitre);
}

template<typename T, typename S>
inline void MondeMagique<T, S>::ajouter(S* compagnon)
{
	listCompagnon_.push_back(compagnon);
}


template<typename T, typename S>
void MondeMagique<T, S>::supprimer(T* maitre) 
{
	FoncteurEgalDresseurs comp(maitre);
	std::list<T*>::iterator it = std::find_if(listMaitre_.begin(), listMaitre_.end(), comp);
	listMaitre_.erase(it);
}

template<typename T, typename S>
void MondeMagique<T, S>::supprimer(S* compagnon) 
{
	FoncteurEgalCreatures comp(compagnon);
	std::list<S*>::iterator it = std::find_if(listCompagnon_.begin(), listCompagnon_.end(), comp);
	listCompagnon_.erase(it);
}

template<typename T, typename S>
void MondeMagique<T, S>::vider()
{
	for(std::list<T*>::iterator it = listMaitre_.begin(); it != listMaitre_.end(); it++) {
		delete *it;
	}
	listMaitre_.clear();

	for (std::list<S*>::iterator it = listCompagnon_.begin(); it != listCompagnon_.end(); it++) {
		delete *it;
	}
	listCompagnon_.clear();

}

template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator+=(T* maitre) 
{
	ajouter(maitre);
	return *this;
}

template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator-=(T* maitre)
{
	supprimer(maitre);
	return *this;
}

template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator+=(S* compagnon) {

	ajouter(compagnon);
	return *this;

}

template<typename T, typename S>
MondeMagique<T, S>& MondeMagique<T, S>::operator-=(S* compagnon) {

	supprimer(compagnon);
	return *this;

}

template<typename T, typename S>
template<typename A>
void MondeMagique<T, S>::supprimerMaitre(const A& pred) 
{
	remove_if(listMaitre_.begin(), listMaitre_.end(), pred);
}

template<typename T, typename S>
template<typename B>
void MondeMagique<T, S>::supprimerCompagnon(const B& pred) 
{
	remove_if(listCompagnon_.begin(), listCompagnon_.end(), pred);
}

