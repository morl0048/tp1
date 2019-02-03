// tp1AttaqueMdp.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "md5.h"

#include <ctime>

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

int CreeListeMots(int nbreCharMax, vector<string>* listeARemplir)//8 max
{
	int nbCharDispo = strlen(m_dispo);
	unsigned long long int nbMot = pow(nbCharDispo, nbreCharMax);
	vector<char> *mot = new vector<char>();
	
	for (int i = 0; i < nbreCharMax; i++)
	{
		mot->push_back(NULL);
	}

	for (int i = 0; i < nbCharDispo; i++)
	{
		mot->at(0) = m_dispo[i];
	}


	return nbMot;
}

int main()//Je regardes pour ajouter openNp (Multithreading) pour que ça soit plus rapide
{
	vector<string> *listeMot = new vector<string>();
	vector<string> *listeHash = new vector<string>();
	vector<string> *listeMotCree = new vector<string>();
	
	CreeListeMots(8, listeMotCree);
	
	//Charge dictionnaire
	int nbMot = ChargerListeDictionnaire("mots-8-et-moins.txt", listeMot);
	if (nbMot != 0)
	{
		//Hash dictionnaire
		HashListe(listeMot, listeHash, nbMot);
	}


	//Pour pauser à la fin
	string i;
	cin >> i;

    return 0;
}

