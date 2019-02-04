// tp1AttaqueMdp.cpp : Définit le point d'entrée pour l'application console.
//Louka Morneau
//2019-02-04
//Cours de sécurité informatique de l'UQAR

#include "stdafx.h"
#include <iostream>//cin,cout
#include <fstream>//ofstream
#include <string>//string
#include <vector>//vector
#include <ctime>//clock

#include "md5.h"//md5
#include "compteur.h"//compteur

using namespace std;

//Prends chaque mot d'un fichier et les ajoute dans listeARemplir.
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

//Hash une liste de mot et retourne le résultat dans listHash.
void HashListe(vector<string>* listeClair, vector<string>* listeHash, int nbMots)
{
	const clock_t temps = clock();

	for (int i = 0; i < nbMots; i++)
	{
		listeHash->push_back(md5(listeClair->at(i)));
	}

	cout << "Temps hashage dictionnaire: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";

	return;
}

//Vérifie si un hash donné avec son mot respectif est dans la liste des hash à trouver. Si oui, ajoute la combinaison au fichier de réponse.
void VerifHashDansListe(string hash, string mot, vector<string>* listeHashATrouver)
{
	if (find(listeHashATrouver->begin(), listeHashATrouver->end(), hash) != listeHashATrouver->end())
	{
		ofstream fichierReponse;
		fichierReponse.open("reponse.txt", ios_base::app);
		fichierReponse << mot << " - " << hash << "\n";
		fichierReponse.close();
		cout << "Correspondance trouvée: " << mot << " - " << hash << "\n";
	}
}


int main()
{
	const clock_t temps = clock();

	//load les hash à trouver (Partie 1 et 2)
	vector<string>* listeHashATrouver = new vector<string>();
	ChargerListeDictionnaire("hashs-a-trouver.txt", listeHashATrouver);

	//Partie 1
	cout << "Partie 1:\n";
	vector<string> *listeMot = new vector<string>();
	vector<string> *listeHash = new vector<string>();

	//Charge dictionnaire
	int nbMot = ChargerListeDictionnaire("mots-8-et-moins.txt", listeMot);
	if (nbMot != 0)
	{
		//Hash dictionnaire
		HashListe(listeMot, listeHash, nbMot);
	}

	for (int i = 0; i < nbMot; i++)
	{
		VerifHashDansListe(listeHash->at(i), listeMot->at(i), listeHashATrouver);
	}

	cout << "Temps d'exécution partie 1: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";
	
	//Partie 2
	cout << "Partie 2:\n";
	string dispo = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%&*";
	size_t longueurMax = 8;
	Compteur c(longueurMax, dispo);//Outil de création de mots
	c.SetValue("g$x6nf");

#pragma omp parallel
	{
		do//Chaque cpu core va faire ++ chacun leur tour (Singleton Compteur)
		{
			string mot = c.GetValue();
			VerifHashDansListe(md5(mot), mot, listeHashATrouver);
		} while (c.Increment());//Tant que pas d'overflow
	}

	c.~Compteur();

	cout << "Temps d'exécution partie 2: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";

	cout << "Temps d'exécution total: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";

	//Pour pauser à la fin
	string s;
	cin >> s;

    return 0;
}

