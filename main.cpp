/**
* Fonction pricipale du programme qui affiche une liste de jeux et de concepteurs.
* /fichier	main.cpp
* /auteurs	Pascal Gallant et Arthur Panoyan
* /date		26 octobre 2021
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

const string ligne = "\n\033[35m- - - - - - - - - - - - - - - - - - - - \033[0m\n";

//: Vos surcharges d'opérateur <<
ostream& operator<< (ostream& o, const Concepteur& concepteur) {
	o << setw(26) << left << concepteur.getNom();
	o << "\tné en : " << concepteur.getAnneeNaissance();
	o << "\tpays : " << concepteur.getPays() << endl;
	return o;
}

ostream& operator<< (ostream& o, const Liste<Concepteur>& listeConcepteurs)
{
	for (auto i : iter::range(listeConcepteurs.size())) {
		o << setw(26) << left << listeConcepteurs[i]->getNom();
		o << "\tné en : " << listeConcepteurs[i]->getAnneeNaissance();
		o << "\tpays : " << listeConcepteurs[i]->getPays() << endl;
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
	//string ligne = "\n\033[35m- - - - - - - - - - - - - - - - - - - - \033[0m\n";
	for (auto i : iter::range(listeJeux.size())) {
		o << ligne << endl;
		o << setw(36) << left << listeJeux[i]->getTitre();
		o << "Développeur : " << setw(22) << left << listeJeux[i]->getDeveloppeur();
		o << "    Sorti en " << listeJeux[i]->getAnneeSortie();
		o << "\n\nConcepteurs du jeu:\n\n" << listeJeux[i]->getConcepteurs();
		o << ligne << endl;
	}
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
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	
	//TODO: Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	
	cout << lj << endl;

	cout << ligneSeparation << endl;
	
	Jeu copieJeu = *lj[2];

	cout << copieJeu << endl;

	Concepteur copieConcepteur = *lj[2]->getConcepteurs()[1];

	cout << copieConcepteur << endl;

	//TODO: Compléter le main avec les tests demandés.	
	//test de ajout de jeu dans un fichiers
	ofstream listeEcrire;
	listeEcrire.open("jeux.txt");

	listeEcrire << lj << endl;

	listeEcrire.close();
	//test operateur =
	
	if (lj[2] == lj[2]) {
		cout << copieConcepteur << "est egale" << endl;
	}
	else {
		cout << "ne sont pas egale" << endl;
	}
	//test get capacite

	cout << lj.getCapacite() << endl;


	
	copieConcepteur.setNom("Jean-Guy Thibodeau");
	copieConcepteur.setAnneeNaissance(40);
	copieConcepteur.setPays("on s'en %!$& comme dans l'an de sa naissance.");
	cout << copieConcepteur << endl;
	Liste<Concepteur> concepteurs;
	concepteurs.ajouterElement(make_shared<Concepteur>(copieConcepteur));

	Concepteur concepteurParDefaut;
	concepteurParDefaut.setNom("billy");
	concepteurParDefaut.setAnneeNaissance(2000);
	concepteurParDefaut.setPays("kébak");
	cout << concepteurParDefaut;

	Jeu jeu;
	jeu.setTitre("monsieur patate");
	jeu.setDeveloppeur("raymarine");
	jeu.setAnneeSortie(2012);
	//shared_ptr<Concepteur> ptrConcepteur = make_shared<Concepteur>(concepteurParDefaut);
	Liste<Concepteur> lc;
	lc.ajouterElement(make_shared<Concepteur>(concepteurParDefaut));
	jeu.setConcepteurs(lc);
	cout << jeu;
	
	copieJeu.setTitre("Juste le meilleur jeu de tous les temps!");
	copieJeu.setAnneeSortie(2022);
	copieJeu.setDeveloppeur("arthur le mythique et Pascal le légendaire");
	copieJeu.setConcepteurs(concepteurs);
	cout << copieJeu << endl;
	lj.ajouterElement(make_shared<Jeu>(copieJeu));

	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.


	

}