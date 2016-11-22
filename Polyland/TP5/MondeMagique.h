/*
Fichier: MondeMagique.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: La classe MondeMagique correspond au monde qui contient des 
dresseurs et créatures
*/
#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H

#include <list>
#include <algorithm>

/**
* @brief La classe MondeMagique
*/
template<typename T, typename S>
class MondeMagique
{
public:
	/**
	* @brief Constructeur par default
	*/
	MondeMagique(); 
	/**
	* @brief Destructeur de la classe
	*/
	~MondeMagique();

	/**
	* @brief Pour obtenir la liste de maitre
	* @return list
	*/
	std::list<T*> obtenirListeMaitre() const;

	/**
	* @brief Pour obtenir la liste de compagnon
	* @return list
	*/
	std::list<S*> obtenirListeCompagnon() const;

	/**
	* @brief Pour ajouter un maitre
	* @param maitre
	*/
	void ajouter(T* maitre);
	/**
	* @brief Pour ajouter un compagnon
	* @param compagnon
	*/
	void ajouter(S* compagnon);
	/**
	* @brief Pour supprimer un maitre
	* @param maitre
	*/
	void supprimer(T* maitre);
	/**
	* @brief Pour supprimer un compagnon
	* @param compagnon
	*/
	void supprimer(S* compagnon);

	/**
	* @brief Pour supprimer un maitre selon un foncteur
	* @param predicat
	*/
	template<typename A>
	void supprimerMaitre(const A& pred);

	/**
	* @brief Pour supprimer un compagnon selon un foncteur
	* @param predicat
	*/
	template<typename B>
	void supprimerCompagnon(const B& pred);

	/**
	* @brief Pour vider le monde magique
	*/
	void vider();

	/**
	* @brief Redefinition de l'operateur '+=' avec un maitre
	* @param maitre Une reference a la maitre a ajouter
	* @return La reference a la classe mondeMagique
	*/
	MondeMagique<T, S>& operator+=(T* maitre);
	/**
	* @brief Redefinition de l'operateur '-=' avec un maitre
	* @param maitre Une reference a la maitre a enlever
	* @return La reference a la classe mondeMagique
	*/
	MondeMagique<T, S>& operator-=(T* maitre);
	/**
	* @brief Redefinition de l'operateur '+=' avec un compagnon
	* @param compagnon Une reference a le compagnon a ajouter
	* @return La reference a la classe mondeMagique
	*/
	MondeMagique<T, S>& operator+=(S* compagnon);
	/**
	* @brief Redefinition de l'operateur '-=' avec un compagnon
	* @param maitre Une reference a le compagnon a enlever
	* @return La reference a la classe mondeMagique
	*/
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
	
	for(auto it = listMaitre_.begin(); it != listMaitre_.end(); it++) {
		supprimer(*it);
	}
	listMaitre_.clear();

	for (auto it = listCompagnon_.begin(); it != listCompagnon_.end(); it++) {
		supprimer(*it);
	}
	listCompagnon_.clear();
	
	/*
	for_each(listMaitre_.begin(), listMaitre_.end(), supprimer);
	listMaitre_.clear();

	for_each(listCompagnon_.begin(), listCompagnon_.end(), supprimer);
	listCompagnon_.clear();
	*/
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

