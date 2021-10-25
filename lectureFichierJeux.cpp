	// Fonctions pour lire le fichier binaire.
#include "lectureFichierJeux.hpp"
#include <fstream>
#include "cppitertools/range.hpp"
#include <functional>
using namespace std;

#pragma region "Fonctions de lecture de base"
UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion

shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& listeJeux, string nom)
{
	// Compléter la fonction (équivalent de trouverDesigner du TD2).
	auto critere = [&nom](const auto concepteur) {
		return concepteur.getNom() == nom;
	};
	for (unsigned i : iter::range(listeJeux.size())) {
		shared_ptr<Concepteur> concepteurTrouve = listeJeux[i]->trouverConcepteur(critere);
		if (concepteurTrouve!=nullptr) {
			return concepteurTrouve;
		}
	}
	return nullptr;
}

shared_ptr<Concepteur> lireConcepteur(Liste<Jeu>& lj, istream& f)
{
	string nom              = lireString(f);
	unsigned anneeNaissance = lireUint16(f);
	string pays             = lireString(f);
	Concepteur concepteur(nom,anneeNaissance,pays);

	// Compléter la fonction (équivalent de lireDesigner du TD2).
	shared_ptr<Concepteur> concepteurExistant = chercherConcepteur(lj, nom);
	if (concepteurExistant!=nullptr) {
		return concepteurExistant;
	}
	else {
		shared_ptr<Concepteur> nouveauConcepteur = make_shared<Concepteur>(concepteur);
		
		cout << "Allocation du concepteur \"" << nouveauConcepteur->getNom() << "\" réussie.\n";
		return nouveauConcepteur;
	}
}

shared_ptr<Jeu> lireJeu(istream& f, Liste<Jeu>& lj)
{
	string titre          = lireString(f);
	unsigned anneeSortie  = lireUint16(f);
	string developpeur    = lireString(f);
	unsigned nConcepteurs = lireUint8(f);
	// Compléter la fonction (équivalent de lireJeu du TD2).
	Liste<Concepteur> listeConcepteurs;
	for (unsigned int i = 0; i < nConcepteurs; i++) {
		listeConcepteurs.ajouterElement(lireConcepteur(lj, f));
	}
	Jeu jeu(titre, anneeSortie, developpeur, listeConcepteurs);
	shared_ptr<Jeu> ptrJeu = make_shared<Jeu>(jeu);
	cout << "Allocation du jeu \"" << ptrJeu->getTitre() << "\" réussie.\n";
	return ptrJeu;
}

Liste<Jeu> creerListeJeux(const string& nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lireUint16(f);
	//TODO: Compléter la fonction.
	Liste<Jeu> listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements))
		lireJeu(f, listeJeux);

	return {};
}
