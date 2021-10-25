/**
* La classe Concepteur  definit les concepteurs et gere les operations qui sont possible de faire sur un objet Concepteur
* /fichier	concepteur.hpp
* /auteurs	Pascal Gallant et Arthur Panoyan
* /date		25 octobre 2021
* Créé le	6 octobre 2021
*/
#pragma once
#include <string>
#include <memory>
#include <iostream>

class Concepteur
{
public:
	// Un constructeur par défaut et un constructeur paramétré.
	Concepteur() = default;
	Concepteur(const std::string& nom, const unsigned& anneeNaissance, const std::string& pays) :nom_(""), anneeNaissance_(0U), pays_("") {
		nom_ = nom;
		anneeNaissance_ = anneeNaissance;
		pays_ = pays;
	};

	const std::string& getNom() const     { return nom_; }
	void setNom(const std::string& nom)   { nom_ = nom; }
	int getAnneeNaissance() const         { return anneeNaissance_; }
	void setAnneeNaissance(int annee)     { anneeNaissance_ = annee; }
	const std::string& getPays() const    { return pays_; }
	void setPays(const std::string& pays) { pays_ = pays; }

	//const ostream& afficher(ostream& o) const {
	//	o << setw(26) << left << getNom();
	//	o << "\tné en : " << getAnneeNaissance();
	//	o << "\tpays : " << getPays() << endl;
	//	return o;
	//}

private:
	std::string nom_;
	unsigned anneeNaissance_;
	std::string pays_;
};
