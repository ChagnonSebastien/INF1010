/*
Fichier: main.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 24 septembre 2016 par Maude Carrier
Description: Programme de test
*/

#include <iostream>
#include <time.h>
#include <clocale>  // pour setlocale
#include <functional> //pour bind
#include <map>

#include "AttaqueMagique.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include "CreatureMagique.h"
#include "Foncteur.h"


int main()
{
	srand(time(NULL));
    setlocale(LC_ALL, "");

	// Dresseurs
    Dresseur vous("Vous", "PolyMtl");
    Dresseur sacha("Sacha", "UDEM");

    //Creatures
    Creature pokachu("Pokachu", 10, 20, 100, 50);
    Creature salimouche("Salimouche", 20, 15, 110, 50);

	// Creer la CREATURE MAGIQUE pokachoum en utilisant la creature existante pokachu et un bonus de 3.
	// Le nom de pokachoum devrai ensuite etre modifie pour "Pokachoum" et sa defense passera de 2 a 7.
	// A COMPLETER...


	// Creer la CREATURE MAGIQUE Touflamme en utilisant la creature existante Salimouche et un bonus de 2.
	// Le nom de Touflamme devrai ensuite etre modifie pour "Touflamme" et son attaque passera de 12 a 15.
	// A COMPLETER...


    //Pouvoirs
    Pouvoir bouleDeFeu("Boule de feu", 5, 5);
	Pouvoir eclair("Eclair", 10, 5);
	Pouvoir tonerre("Tonnerre", 15, 10);

	// Faites apprendre le pouvoir bouleDeFeu par Salimouche, les pouvoirs tonerre et eclair par pokachu ainsique le pouvoir
	// tonerre par touflamme.
	// A COMPLETER...


	PolyLand polyland;

	// Ajouter les dresseurs vous et sacha ainsi que les créatures pokachu, salimouche,
	// pokachoum et touflamme à polyland avec l'opérateur +=
	// A COMPLETER...

	// En vous promenant dans Polyland, vous attrappez un pokachu et Sacha attrappe un salimouche et un touflamme
	// A COMPLETER...


    std::cout << "TEST AFFICHAGE" << std::endl;
    std::cout << "pouvoir de la creature avant trie" << std::endl;
    std::cout << pokachu << std::endl;

    pokachu.trierPouvoir(FoncteurComparerPouvoir());
    std::cout << "pouvoir de la creature apres trie" << std::endl;
    std::cout << pokachu << std::endl;

	std::cout << "Affichage de Polyland" << std::endl;
	std::cout << polyland << std::endl;
    std::cout << "FIN TEST AFFICHAGE" << std::endl;
    std::cout <<  std::endl;

    std::cout << "TEST DRESSEUR" << std::endl;

    if (vous == sacha) //Les deux dresseurs n'ont pas les mêmes créatures
        std::cout << "DRESSEUR operateur== : Erreur Technique!!!!" << std::endl;

    sacha.ajouterCreature(&pokachu);
    vous.ajouterCreature(&salimouche);
    vous.ajouterCreature(&touflamme);
    if (!(vous == sacha)) //Les deux dresseurs ont maintenant les mêmes créatures
        std::cout << "DRESSEUR operateur== : Erreur Technique!!!!" << std::endl;
    vous.enleverCreature(touflamme.obtenirNom());

    FoncteurCreatureVie vieCompriseEntre(80, 150);
    vous.appliquerFoncteurUnaire(vieCompriseEntre);
    if (vieCompriseEntre.obtenirCompteur() == 2)
        std::cout << "appliquerFoncteurUnaire: OK" << std::endl;
    else
        std::cout << "appliquerFoncteurUnaire: Erreur Technique!!!!" << std::endl;

    std::cout << "TEST DRESSEUR : obtenir element max" << std::endl;
    std::cout << *(vous.obtenirCreatureMax(FoncteurComparerCreature())) << std::endl;
    std::cout << "TEST DRESSEUR : FIN obtenir element max" << std::endl;

    std::cout << "TEST DRESSEUR : suppression" << std::endl;
    //Supprime les créatures ayant une attaque supérieure a
    //attaque max
    unsigned int attaqueMax = 11;
    FoncteurObtenirAttaqueCreature obtenirAttaque;
    vous.supprimerElements(
        std::bind(
            /*A COMPLETER générer un opérateur > pour les entiers*/,
            //Le bind ci-dessous permet d'appeler la méthode obtenirAttaque() de la
            //Creature* passée en argument du foncteur lors des appels de ce dernier dans supprimerElements
                std::bind( 
                    obtenirAttaque,
                    /*A COMPLETER utiliser le premier placeholder (attention aux namespace) (reçoit un Creature*)*/
                ),
                /*A COMPLETER faire en sorte que le résultat de obtenirAttaque() soit comparer à attaquer max*/
        )
    );
    //N.B: A l'issue de la fonction vous ne devriez plus posséder de Salimouche

    std::cout << vous << std::endl;
    std::cout << "FIN TEST DRESSEUR" << std::endl;
    std::cout << std::endl;
	

    std::cout << "Début MAP" << std::endl;
    std::cout << "Oyez fiers dresseurs, l'incroyable tournoi de polyland a lieu aujourd'hui!!!" << std::endl;

    //Les règles de ce tournoi sont particulières, chaque dresseur ne peut inscrire qu'une seule créature!!!
    //Créez une map Dresseur*-->Creature* avec une clé qui compare les dresseurs* en ordre alphabétique suivant leur nom.
    //Cette map utilisera peut-être un foncteur pour faire la comparaison ...
	// Cette map permettra de savoir quel dresseur a inscrit quelle créature!
	// A COMPLETER...


	//Vous désirez inscrire pokachu au tournoi
	//Sacha désire inscrire touflamme au tournoi
	// A COMPLETER...


    std::cout << "Début MAP" << std::endl;
    std::cout << "Vous a inscrit la créature:" << std::endl;
    std::cout << *(creaturesInscrites[&vous]) << std::endl;
    std::cout << "Sacha a inscrit la créature:" << std::endl;
    std::cout << *(creaturesInscrites[&sacha]) << std::endl;

	//Debut du duel avec Touflamme
	std::cout << std::endl << "Touflamme se jette sur votre Pokachu" << std::endl;
	std::cout << "Un duel entre Pokachu et Touflamme est engagé" << std::endl;

	//Vous attaquez Touflamme tant que qu'elle est en vie, et miraculeusement touflamme ne réplique jamais... Vous allez gagner ce duel.
	//Étapes: While (touflamme a encore des points de vie) { pokachu attaque }
	//Faites bien attention à utiliser les créatures qui se trouvent dans la map, et non les créature de Polyland.
    //Vous êtes dans un tournoi après tout !!
	//A COMPLETER...


	//Sacha désire remplacer sa créature inscrite au tournoi. Remplacez Touflamme par Salimouche.
	// A COMPLETER...


	std::cout << std::endl << "FIN DE POLYLAND ... :(" << std::endl;
	std::cout << "Vous supprimer Sacha de polyland" << std::endl;
	polyland -= &sacha;
	std::cout << "Vous supprimer Pokachu de polyland" << std::endl;
	polyland -= &pokachu;

	polyland.vider();

	system("pause");
	return 0;
}