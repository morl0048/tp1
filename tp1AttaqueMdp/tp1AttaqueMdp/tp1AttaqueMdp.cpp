// tp1AttaqueMdp.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "md5.h"

#include <ctime>

#include "compteur.h"

using namespace std;

const char m_dispo[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*' };


int ChargerListeDictionnaire(string pathFichier, vector<string>* listeARemplir)
{
	const clock_t temps = clock();

	string mot;
	int nbMot = 0;
	ifstream inputFileStream(pathFichier);

	if (inputFileStream)
	{
		while (inputFileStream >> mot)
		{
			listeARemplir->push_back(mot);
			nbMot++;
		}
	}

	cout << "Temps chargement dictionnaire: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";
	cout << "Nombre de mots: " << nbMot << "\r\n";

	return nbMot;
}

int HashListe(vector<string>* listeClair, vector<string>* listeHash, int nbMots)
{
	const clock_t temps = clock();

	for (int i = 0; i < nbMots; i++)
	{
		listeHash->push_back(md5(listeClair->at(i)));
	}

	cout << "Temps hashage dictionnaire: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";

	return 0;
}

//Crée une liste avec tous les mots possible d'une longueur indiquée
//https://codereview.stackexchange.com/questions/166571/create-all-combinations-of-length-n-from-a-given-alphabet-2
int CreeListeMots(int nbreCharMax, vector<string>* listeARemplir)//8 max
{
	const clock_t temps = clock();

	int nbCharDispo = strlen(m_dispo);
	unsigned long long int nbMot = pow(nbCharDispo, nbreCharMax);

	vector<int> index(nbreCharMax, 0);

	for(;;)
	{
		string mot(index.size(), ' ');
		for (unsigned long long int i = 0; i < index.size(); ++i)
		{
			mot[i] = m_dispo[index[i]];
		}
		listeARemplir->push_back(mot);

		for (unsigned long long int i = index.size() - 1; ; --i)
		{
			if (i < 0)
			{
				cout << "Temps de création de mots de longueur " << nbreCharMax << ": " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";
				return nbMot;
			}

			++index[i];

			if (index[i] == nbCharDispo)
			{
				index[i] = 0;
			}
			else
			{
				break;
			}
		}
	}
}

//Ajoute une liste de mots dans un fichier spécifié
bool AjouteListeMotsDansFichierTexte(string pathFichier, vector<string>* listeAAjouter)
{
	const clock_t temps = clock();

	ofstream openFileStream;
	openFileStream.open(pathFichier, ios_base::app);

	for (unsigned long long int i = 0; i < listeAAjouter->size(); i++)
	{
		openFileStream << listeAAjouter->at(i) << "\n";
	}

	openFileStream.close();

	cout << "Temps d'ajout de la liste de mot au fichier: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";

	return true;
}

int main()//Je regardes pour ajouter openNp (Multithreading) pour que ça soit plus rapide
{
	//vector<string> *listeMot = new vector<string>();
	//vector<string> *listeHash = new vector<string>();
	//
	//for (int i = 1; i <= 8; i++)//8max
	//{
	//	vector<string> *listeMotCree = new vector<string>();
	//	CreeListeMots(i, listeMotCree);
	//	AjouteListeMotsDansFichierTexte("mots-8-et-moins-crees.txt", listeMotCree);
	//}
	//
	//////Charge dictionnaire
	////int nbMot = ChargerListeDictionnaire("mots-8-et-moins.txt", listeMot);
	////if (nbMot != 0)
	////{
	////	//Hash dictionnaire
	////	HashListe(listeMot, listeHash, nbMot);
	////}
	string dispo = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%&*";
	size_t longueurMax = 3;

	Compteur c(longueurMax, dispo);//8 max

	int i = 0;
	while(c.Increment())
	{
		//Hash le mot
		//vérifie si correspond à un ou plusieurs mots dans la table
		i++;
	}

	//Pour pauser à la fin
	string s;
	cin >> s;

    return 0;
}

