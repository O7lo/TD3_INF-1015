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
	// Constructeurs et surcharges d'opérateurs
	Liste() = default;

	~Liste() {}

	std::shared_ptr<T> operator[] (const int indice) const
	{ 
		return elements_.get()[indice];
	}
	
	T& operator= (const Liste<T> autre) const {
		this->capacite_ = autre.getCapacite();
		this->nElements_ = autre.size();
		for (int i : iter::range(nElements_)) {
			this->elements_[i] = autre.elements_[i];
		}
		return *this;
	}

	//: Méthode pour ajouter un élément à la liste
	void ajouterElement(std::shared_ptr<T> element)
	{
		if (nElements_ == capacite_)
			changerCapacite(capacite_ * 2+1);
		elements_.get()[nElements_] = element;
		nElements_++;
	} 
	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//: Méthode pour changer la capacité de la liste
	void changerCapacite(unsigned nouvelleCapacite) {
		if (nouvelleCapacite > nElements_) {
			auto nouvelleListe = std::make_shared<std::shared_ptr<T>[]>(nouvelleCapacite);
			for (unsigned i : iter::range(nElements_)) {
				nouvelleListe.get()[i] = elements_.get()[i];
			}
			elements_ = nouvelleListe;
			capacite_ = nouvelleCapacite;
		}
	}

	//: Méthode pour trouver une élément selon un critère (lambda).
	template <typename critereLambda>
	std::shared_ptr<T> trouver(const critereLambda& critere) {
		for (int i : iter::range(nElements_)) {
			if (critere(*elements_.get()[i])) {
				return elements_.get()[i];
			}
		}
	}
	/*Concepteur* (string nom) {
		for (auto i : range(nElements_)) {
			elements_.get()[i]->getNom();
		}
	}*/

private:
	unsigned nElements_=0;
	unsigned capacite_=0;
	//: Attribut contenant les éléments de la liste.
	std::shared_ptr<std::shared_ptr<T>[]> elements_ = nullptr;			

};
