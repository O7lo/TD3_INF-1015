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
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste() = default;

	~Liste() { std::cout << "Détruit!" << std::endl; }

	T& operator[] (const int indice) const
	{ 
		return elements_[indice];
	}
	
	//methode pour avoir la dimension de la liste
	std::ostream& afficherSur(std::ostream& leOstream) const 
	{
		leOstream << elements_;
		return leOstream;
	}

	//: Méthode pour ajouter un élément à la liste
	void ajouterElement(T liste, std::unique_ptr<T> element)
	{
		if (nElements_ == capacite_)
			changerCapacite(liste,capacite_ * 2);
		elements_[nElements_++] = element;
	} 
	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//: Méthode pour changer la capacité de la liste
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

	//: Méthode pour trouver une élément selon un critère (lambda).
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
	//: Attribut contenant les éléments de la liste.
	std::unique_ptr<T[]> elements_ = nullptr;			
};
