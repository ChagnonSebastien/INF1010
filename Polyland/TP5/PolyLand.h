/*
Fichier: PolyLand.h
Auteur(s): Audrey Labrie (1827808) et Sebastien Chagnon (1804702)
Date de modification: 21 novembre 2016
Description: Polyland represente le pays que l'on va explorer, il va contenir
les differents elements de jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#include "MondeMagique.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>



/**
* @brief La classe Polyland, pour decrire le monde de Polyland
*/
class PolyLand: public MondeMagique<Dresseur, Creature>
{
public:

	/**
	* @brief Methode pour qu'un dresseur attrape une creature
	* @param dresseur Un pointeur vers le dresseur a qui ajouter la creature
	* @param Creature Un pointeur vers la creature a ajouter au dresseur
	* @return true si l'ajout a ete un succes, false sinon
	*/
	bool attraperCreature(Dresseur* dresseur, Creature* creature);

	/**
	* @brief Methode pour qu'un dresseur relache une creature
	* @param dresseur Un pointeur vers le dresseur a qui retirer une creature
	* @param nom Une reference du nom de la creature retirer du dresseur
	* @return true si le retrait a ete un succes, false sinon
	*/
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature);

	/**
	* @brief Redefinition de l'operateur '<<' avec une instance de PolyLand en parametre
	* @param o L'output stream dans lequel ajouter les informations du dresseur
	* @param polyland Une reference a PolyLand
	* @return L'output stream recu en parametre
	*/
	friend std::ostream& operator<<(std::ostream& o, const PolyLand& polyland);
};

#endif