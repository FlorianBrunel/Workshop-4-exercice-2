#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	string IndicationFin;

	while (IndicationFin != "Fin")
	{
		

		Stockage2D Stock;

		std::cout << "Indiquez si vous souhaitez creer un carre ou un rectangle, visionner la liste ou supprimer un element [c/r/v/s]" << endl;
		std::cout << "* c pour carre." << endl;
		std::cout << "* r pour rectangle." << endl;
		std::cout << "* v pour visionner." << endl;
		std::cout << "* s pour supprimer." << endl;
		std::cout << "" << endl;
		char type;
		std::cin >> type;

		while (type != 'c' && type != 'r' && type != 'v' && type != 's')
		{
			std::cout << "L'entree n'est pas valable." << endl;
			std::cout << "Merci d'indiquer a nouveau le type de figure : " << endl;
			std::cout << "" << endl;
			std::cin >> type;
		}


		// Cr�ation carr� -------------------------------------------------------------------------------------------------------------------------------------------
		if (type == 'c')
		{
			std::cout << "Merci d'indiquer la valeur de cote de ce carre." << endl;

			int parametre;
			cin >> parametre;


			while (parametre < 0)
			{
				std::cout << "ERREUR, valeur inferieure a 0 !" << endl;
				std::cout << "" << endl;
				std::cout << "Merci d'indiquer une valeur correcte : " << endl;
				std::cout << "" << endl;
				cin >> parametre;
			}

			Objet2D* objet = new Cube(parametre); //Cr�ation d'un objet cube.

			//Choix utilisateur concernant le type d'insertion des donn�es dans la liste-----------------------------------------------------------------------------
			cout << "Comment voulez vous ins�rer la donn�e dans la liste [oui/non] ?" << endl;
			string OuiNon;

			cin >> OuiNon;

		
			if (OuiNon == "oui")
			{
				cout << "Comment voulez vous impl�menter ces donn�es ? T�te, queue ou � un index ? [h/t/i]" << endl;

				string typeAjout;
				cin >> typeAjout;

				if (typeAjout == "h")
				{
					Stock.AjouterHead(objet);

				}

				else if (typeAjout == "t")
				{
					Stock.AjouterTail(objet);
				}

				else if (typeAjout == "i")
				{
					int IndexUser;
					cout << "Veuillez indiquer l'index voulu" << endl;
					cin >> IndexUser;

					Stock.AjouterIndex(objet, IndexUser);
				}
			}

			//Fin choix utilisateur type ajout ----------------------------------------------------------------------------------------------------------------------

			//Afichage des informations concernant l'objet ajout� ---------------------------------------------------------------------------------------------------
			std::cout << objet->afficheInfo() << endl;
			std::cout << "" << endl;
			std::cout << "Ses cotes ont pour valeur : " << parametre << endl;
			std::cout << "" << endl;
			std::cout << "Son aire est de : " << objet->getAire() << endl;
			std::cout << "Son perimetre est de : " << objet->getPerimetre() << endl;
		}

// Fin cr�ation carr� ---------------------------------------------------------------------------------------------------------------------------------------


// Cr�ation rectangle ---------------------------------------------------------------------------------------------------------------------------------------
		else if (type == 'r')
		{
			int parametrelong;
			int parametrelarg;

			cout << "Merci d'indiquer la valeur de longueur de ce rectangle." << endl;
			cin >> parametrelarg;

			while (parametrelarg < 0)
			{
				cout << "ERREUR, valeur inferieure a 0 !" << endl;
				cout << "" << endl;
				cout << "Merci d'indiquer une valeur correcte : " << endl;
				cout << "" << endl;
				cin >> parametrelarg;
			}

			cout << "Merci d'indiquer la valeur de longueur de ce rectangle." << endl;
			cin >> parametrelong;

			while (parametrelong < 0)
			{
				cout << "ERREUR, valeur inferieure a 0 !" << endl;
				cout << "" << endl;
				cout << "Merci d'indiquer une valeur correcte : " << endl;
				cout << "" << endl;
				cin >> parametrelong;
			}

			Objet2D* objet = new Rectangle(parametrelarg, parametrelong);

//Choix utilisateur concernant le type d'insertion des donn�es dans la liste-----------------------------------------------------------------------------
			cout << "Comment voulez vous ins�rer la donn�e dans la liste [oui/non] ?" << endl;
			string OuiNon;

			cin >> OuiNon;


			if (OuiNon == "oui")
			{
				cout << "Comment voulez vous impl�menter ces donn�es ? T�te, queue ou � un index ? [h/t/i]" << endl;

				string typeAjout;
				cin >> typeAjout;

				if (typeAjout == "h")
				{
					Stock.AjouterHead(objet);

				}

				else if (typeAjout == "t")
				{
					Stock.AjouterTail(objet);
				}

				else if (typeAjout == "i")
				{
					int IndexUser;
					cout << "Veuillez indiquer l'index voulu" << endl;
					cin >> IndexUser;

					Stock.AjouterIndex(objet, IndexUser);
				}
			}
// Fin cr�ation rectangle --------------------------------------------------------------------------------------------------------------------------------------------			
	
//Afichage des informations concernant l'objet ajout� ----------------------------------------------------------------------------------------------------------------	
			cout << objet->afficheInfo() << endl;
			cout << "" << endl;

			cout << "Sa longueur est : " << parametrelong << endl;
			cout << "" << endl;
			cout << "Sa largeur est : " << parametrelarg << endl;
			cout << "" << endl;

			cout << "Son aire est de : " << objet->getAire() << endl;
			cout << "Son perimetre est de : " << objet->getPerimetre() << endl;
		}
// Fin cr�ation carr� -------------------------------------------------------------------------------------------------------------------------------------------------


// Partie visionnage de la liste --------------------------------------------------------------------------------------------------------------------------------------
		
		else if (type == 'v')
		{
			Stock.AfficherInfos();
		}


// Partie suppresion de la liste --------------------------------------------------------------------------------------------------------------------------------------
		else if (type == 's')
		{
			
		
			string typeSuppression;
			cout << "Quel type de suppression d�sirez vous ? (head, tail, index) [h/t/i]" << endl;
			cin >> typeSuppression;

			
			if (typeSuppression == "h")
			{
				Stock.SupprimerHead();

			}

			else if (typeSuppression == "t")
			{
				Stock.SupprimerTail();
			}

			else if (typeSuppression == "i")
			{
				int IndexUser;
				cout << "Veuillez indiquer l'index voulu" << endl;
				cin >> IndexUser;

				Stock.SupprimerIndex(IndexUser);
			}
		}

		cout << "Voulez vous arr�ter la saisie de donn�e ? Si oui indiquez 'Fin'. Sinon indiquez autre chose." << endl;
		std::cin >> IndicationFin;
	}
	std::cout << "Fin de la tache." << endl;
	return 0;
}