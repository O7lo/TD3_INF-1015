#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

class Jeu
{
public:
	//:un constructeur par défaut et un constructeur paramétré.
	Jeu() = default;
	Jeu(const std::string& titre = "", const unsigned& anneeSortie = 0, const std::string& developpeur = "") {
		setTitre(titre);
		setAnneeSortie(anneeSortie);
		setDeveloppeur(developpeur);
	}

	const std::string& getTitre() const { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const { return anneeSortie_; }
	void setAnneeSortie(unsigned annee) { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	//TODO: Pouvoir accéder à la liste de concepteurs.
	std::shared_ptr<Liste<Concepteur>> getConcepteurs() {

		return listeConcepteur;
	}
	//TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.


private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	// Attribut de la liste des concepteurs du jeu
	std::shared_ptr<Liste<Concepteur>> listeConcepteur = nullptr;
};
