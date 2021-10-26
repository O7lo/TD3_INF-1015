/**
* Fonction pricipale du programme qui affiche une liste de jeux et de concepteurs.
* /fichier	main.cpp
* /auteurs	Pascal Gallant et Arthur Panoyan
* /date		25 octobre 2021
* Créé le	6 octobre 2021
*/
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <functional>
using namespace std;

static const string ligne = "\n\033[35m- - - - - - - - - - - - - - - - - - - - \033[0m\n";
static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

//: Vos surcharges d'opérateur <<
ostream& operator<< (ostream& o, const Concepteur& concepteur) {
	o << concepteur.getNom();
	o << concepteur.getAnneeNaissance();
	o << concepteur.getPays();
	return o;
}

ostream& operator<< (ostream& o, const Liste<Concepteur>& listeConcepteurs)
{
	for (auto i : iter::range(listeConcepteurs.size())) {
		o << *listeConcepteurs[i];
	}
	return o;
}

ostream& operator<< (ostream& o, const Jeu& jeu) {
	o << ligne << endl;
	o << setw(36) << left << jeu.getTitre();
	o << "Développeur : " << setw(22) << left << jeu.getDeveloppeur();
	o << "    Sorti en " << jeu.getAnneeSortie();
	o << "\n\nConcepteurs du jeu:\n\n" << jeu.getConcepteurs();
	o << ligne << endl;
	return o;
}

ostream& operator<< (ostream& o, const Liste<Jeu>& listeJeux)
{
	o << ligneSeparation << endl;
	for (auto i : iter::range(listeJeux.size())) {
		o << *listeJeux[i];
	}
	o << ligneSeparation << endl;
	return o;
}




int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion
	
	Liste<Jeu> lj = creerListeJeux("jeux.bin");
	

	// Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	
	cout << lj << endl;

	
	
	Jeu copieJeu = *lj[5];

	cout << copieJeu << endl;

	// Compléter le main avec les tests demandés.	
	ofstream listeEcrire;
	listeEcrire.open("jeux.txt");

	listeEcrire << lj << endl;

	listeEcrire.close();


		



	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.


	

}