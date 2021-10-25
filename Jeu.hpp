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
	Jeu(const std::string& titre, const unsigned& anneeSortie, const std::string& developpeur,const Liste<Concepteur>& listeConcepteurs):titre_(titre),anneeSortie_(anneeSortie),developpeur_(developpeur),listeConcepteurs_(listeConcepteurs) {

	}

	const std::string& getTitre() const { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const { return anneeSortie_; }
	void setAnneeSortie(unsigned annee) { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	// Pouvoir accéder à la liste de concepteurs.
	const Liste<Concepteur> getConcepteurs() const {
		return listeConcepteurs_;
	}
	// Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.
	template <typename critereLambda>
	std::shared_ptr<Concepteur> trouverConcepteur(const critereLambda& critere) {
		return listeConcepteurs_.trouver(critere);
	}

	const ostream& afficherJeu(ostream& o) const {
		o << ligne << endl;
		o << setw(36) << left << titre_;
		o << "Développeur : " << setw(22) << left << developpeur_;
		o << "    Sorti en " << anneeSortie_;
		o << "\n\nConcepteurs du jeu:\n\n" << listeConcepteurs_.afficherListe();
		o << ligne << endl;
		return o;
	}


private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	// Attribut de la liste des concepteurs du jeu
	Liste<Concepteur> listeConcepteurs_;
};
