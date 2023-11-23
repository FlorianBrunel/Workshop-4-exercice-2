#pragma once
using namespace std;
#include <string>


class Objet2D
{
protected:
	int dim1;
	int dim2;

public:
	Objet2D();
	Objet2D(int tdim1, int tdim2);
	virtual int getPerimetre();
	virtual int getAire(); 
	virtual string afficheInfo();

	//Accesseurs de suivant : 
	
	Objet2D* getSuivant() const;
	void setSuivant(Objet2D* Suivant);

private:
	Objet2D* Suivant;
};

class Rectangle : public Objet2D
{
public:
	Rectangle();
	Rectangle(int tdim1, int tdim2);
	int getLongueur();
	int getLargeur();
	virtual int getPerimetre();
	virtual int getAire();
	virtual string afficheInfo();
};

class Cube : public Rectangle
{
public:
	Cube();
	Cube(int tcote);
	int getCote();
	int getPerimetre();
	int getAire();
	string afficheInfo();
};

//Classe permettant le stockage dans une liste d'objet 2D (Donc carré et ou rectangle)

class Stockage2D : public Objet2D
{
private:
	struct Liste_chainee
	{
		Objet2D* obj;
		Liste_chainee* suivant;
	};
	
	Liste_chainee* Head;
	Liste_chainee* Tail;

public:

	Stockage2D() : Head(nullptr), Tail(nullptr) {} //Constructeur, il n'y a rien de stocké donc on met les deux ptr à null.

	//Fonctions d'ajout à la liste
	void AjouterHead(Objet2D* obj /*Pointe vers un carré ou rectangle*/);
	void AjouterTail(Objet2D* obj);
	void AjouterIndex(Objet2D* obj, int indexVal);

	//Fonctions de suppression dans la liste
	void SupprimerHead();
	void SupprimerTail();
	void SupprimerIndex(int indexVal);

	//Fonction d'affichage
	void AfficherInfos();
};