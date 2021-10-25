#pragma once
#include <string>
#include <memory>
#include <iostream>

class Concepteur
{
public:
	// Un constructeur par d�faut et un constructeur param�tr�.
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
	ostream& afficherConcepteur(ostream& o) {
		o << setw(26) << left << getNom();
		o << "\tn� en : " << getAnneeNaissance();
		o << "\tpays : " << getPays() << endl;
	}

private:
	std::string nom_;
	unsigned anneeNaissance_;
	std::string pays_;
};
