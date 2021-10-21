#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"

template <typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'op�rateurs
	Liste(const unsigned& nElements = 0, const unsigned& capacite = 0) {
		nElements_ = nElements;
		capacite_ = capacite;

	}
	~Liste() { std::cout << "D�truit!" << std::endl; }

	T& operator[] (const int indice) const
	{ 
		return elements_[indice];
	}
	
	//methode pour avoir la dimension de la liste
	std::ostream& afficherSur(std::ostream& leOstream) const 
	{
		for (auto i : iter::range(nElements_)) 
		{
			leOstream << elements_;
		}
		return leOstream;
	}

	//TODO: M�thode pour ajouter un �l�ment � la liste
	void ajouterJeu(T liste, std::unique_ptr<T> element)
	{
		if (nElements_ == capacite_)
			changerCapacite(liste,capacite_ * 2);
		elements_[nElements_++] = element;
	} 
	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: M�thode pour changer la capacit� de la liste
	void changerCapacite(T liste, unsigned nouvelleCapacite) {
		if (nouvelleCapacite > nElements_) {
			auto nouvelleListe = std::make_unique<T[]>(nouvelleCapacite);
			for (unsigned i : iter::range(nElements_)) {
				nouvelleListe[i] = elements_[i];
			}
			elements_ = nouvelleListe;
			capacite_ = nouvelleCapacite;
		}
	}

	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).
	template<typename CritereLambda>
	T trouver(const CritereLambda& critere) {
		for (int i : iter::range(nElements_)) {
			if (critere(elements_[i])) {
				return elements_[i];
			}
		}
	}


private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les �l�ments de la liste.
	std::unique_ptr<T[]> elements_;			//ne devrait pas etre un shared_ptr?
};
