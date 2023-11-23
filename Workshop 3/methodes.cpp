#include "pch.h"
#include <iostream>


Objet2D* Objet2D::getSuivant() const
{
	return Suivant;
}

void Objet2D::setSuivant(Objet2D* NouveauSuivant)
{
	this->Suivant = NouveauSuivant;
}


Objet2D :: Objet2D()
{
}

Objet2D :: Objet2D(int tdim1, int tdim2)
{
	this->dim1 = tdim1;
	this->dim2 = tdim2;
}

int Objet2D :: getPerimetre()
{
	int Perim = 2 * dim1 + 2 * dim2;
	return Perim;
}

int Objet2D :: getAire()
{
	int Aire = dim1 * dim2;
	return Aire;
}

string Objet2D :: afficheInfo()
{
	string Info = "Ceci est un Objet 2D.";
	return Info;
}



Rectangle :: Rectangle()
{
}

Rectangle :: Rectangle(int tdim1, int tdim2)
{
	this->dim1 = tdim1;
	this->dim2 = tdim2;
}

int Rectangle :: getLongueur()
{
	return dim1;
}

int Rectangle::getLargeur()
{
	return dim2;
}

int Rectangle :: getPerimetre()
{
	int Perim = 2 * dim1 + 2 * dim2;
	return Perim;
}

int Rectangle :: getAire()
{
	int Aire = dim1 * dim2;
	return Aire;
}

string Rectangle :: afficheInfo()
{
	string Info = "Ceci est un rectangle.";
	return Info;
}

Cube :: Cube()
{

}

Cube :: Cube(int tcote)
{
	this->dim1 = tcote;
	this->dim1 = tcote;
}

int Cube::getCote()
{
	return dim1;
}

int Cube::getPerimetre()
{
	int Perim = 4 * dim1;
	return Perim;

}

int Cube::getAire()
{
	int Aire = dim1 * dim1;
	return Aire;
}

string Cube::afficheInfo()
{
	string Info = "Ceci est un carre.";
	return Info;
}


void Stockage2D::AjouterHead(Objet2D* obj /*Pointe vers un carr� ou rectangle*/)
{
	Liste_chainee* NvelleVal = new Liste_chainee{ obj, nullptr }; //Cr�� une nouvelle case au tableau au d�but de celui-ci. On ins�re donc un objet et on se ratache au pointeur null( qui est le premier pointeur )
	if (Head == nullptr) // Si la t�te est vide, alors l'�l�ment que l'on ajoute sera donc la t�te et la fin de 
	{
		Head = Tail = NvelleVal;
	}
	else //Si la liste n'est pas vide, on ajoute le pointeur de la nouvelle comme la nouvelle t�te, et la t�te pointe maintenant vers la nouvelle valeur.
	{
		NvelleVal->suivant = Head;
		Head = NvelleVal;
	}
}

void Stockage2D::AjouterTail(Objet2D* obj)
{
	Liste_chainee* NvelleVal = new Liste_chainee{ obj, nullptr }; //Cr�� une nouvelle case au tableau en fin de celui-ci. On ins�re donc un objet et on se ratache au pointeur null( qui est le premier pointeur )
	if (Head == nullptr) // Si la t�te est vide, alors l'�l�ment que l'on ajoute sera donc la t�te et la fin de 
	{
		Tail = Head = NvelleVal;
	}
	else //Si la liste n'est pas vide, on ajoute le pointeur de la nouvelle comme la nouvelle t�te, et la t�te pointe maintenant vers la nouvelle valeur.
	{
		NvelleVal->suivant = Tail;
		Tail = NvelleVal;
	}
}

void Stockage2D::AjouterIndex(Objet2D* obj, int indexVal)
{
	Liste_chainee* NvelleVal = new Liste_chainee{ obj, nullptr };
	if (indexVal == 0) //Si l'index voulu est nul, on ajoute � la t�te du tableau
	{
		AjouterHead(obj);
	}
	else
	{
		Liste_chainee* temp = Head;
		for (int i = 0; i < indexVal - 1 && temp != nullptr; ++i)
		{
			temp = temp->suivant;
		}
		if (temp != nullptr)
		{
			NvelleVal->suivant = temp->suivant;
			temp->suivant = NvelleVal;
			if (temp == Tail)
			{
				Tail = NvelleVal;
			}
			else
			{
				cout << "Index invalide" << endl;
			}
		}
	}
}


void Stockage2D::SupprimerHead()
{
	if (Head != nullptr)
	{
		Liste_chainee* temp = Head;
		Head = Head->suivant;
		delete temp;
	}
}

void Stockage2D::SupprimerTail()
{
	if (Head == nullptr) // Si la t�te est nul, alors on ne fait rien car il n'y a rien � supprimer.
	{
		return;
	}
	if (Head == Tail) //Si la t�te est �gale � la queue, c'est � dire si il y a un seul �l�ment, alors on supprime la t�te, et la t�te et  la queue sont fusionn�es et associ�es � un pointeur nul.
	{
		delete Head;
		Head = Tail = nullptr;
		return;
	}
	Liste_chainee* temp = Head;
	while (temp->suivant != Tail) //On parcours la liste tant, tant qu'on ne trouve pas le pointeur qui pointe vers la queue on ne fait rien.
	{
		temp = temp->suivant;
		//On passe au pointeur suivant grace au tempon
	}
	delete Tail; //Une fois arriv� � la queue, on la supprime
	Tail = temp; //La queue prend la valeur du tempon
	Tail->suivant = nullptr; //La nouvelle queue pointe vers rien, car c'est la nouvelle fin de la liste chain�e.
}

void Stockage2D::SupprimerIndex(int indexVal)
{
	if (indexVal == 0) //Si l'index correspond au premier �l�ment de la liste, alors on appelle simplement la suppression en t�te.
	{
		SupprimerHead();
	}
	else
	{
		Liste_chainee* temp = Head; // On utilise un pointeur tempon qui d�marre � la t�te de la liste
		for (int i = 0; i < indexVal - 1 && temp != nullptr; ++i) // On parcours tout les �l�ments de la liste jusqu'� l'avant dernier avant l'index.
		{
			temp = temp->suivant; //Le tampon pointe vers la case suivante.
		}
		if (temp != nullptr && temp->suivant != nullptr) // On verrifie que l'objet � supprimer exite bien.
		{
			Liste_chainee* IndexASupprimer = temp->suivant; //IndexASupprimer est un pointeur vers la valeur que l'on veut supprimer
			temp->suivant = IndexASupprimer->suivant;
			if (IndexASupprimer == Tail) // On v�rifie que si l'index � supprimer n'est pas le dernier.
			{
				Tail = temp; // Si c'est le cas, on met la queue � la valeur pr�c�dent la derni�re afin de ne pas la supprimer.
			}
			delete IndexASupprimer; // On supprime l'objet que l'on souhaite supprimer via l'index
		}
		else
		{
			cout << "Index inexistant" << endl;
		}
	}
}

void Stockage2D::AfficherInfos()
{
	Liste_chainee* temporaire = Head;
	while (temporaire != nullptr) //On parcours tout les �l�ments, et on les affiche.
	{
		cout << "test" << endl;
		cout << "|" << "Aire de l'objet : " << temporaire->obj->getAire() << "|" << endl;  //On veut afficher chaque objet sous cette forme : |Aire de l'objet : 25|
		temporaire = temporaire->suivant;
	}
	if (Head == nullptr) {
		cout << "vide" << endl;
	}
}
