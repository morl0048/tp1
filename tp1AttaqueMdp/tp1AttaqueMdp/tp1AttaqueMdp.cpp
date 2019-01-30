// tp1AttaqueMdp.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main()//Je regardes pour ajouter openNp (Multithreading) pour que ça soit plus rapide
{
	string mot;
	vector<string> listeMots;
	int nbMots = 0;

	ifstream inputFileStream("mots-8-et-moins.txt");
	if (!inputFileStream)
	{
		cout << "Le fichier de mots est introuvable.\n";
		return 0;
	}

	while (inputFileStream>>mot)
	{
		listeMots.push_back(mot);
		cout << mot << "\n";
		nbMots++;
	}

	cout << "Nombre de mots: " << nbMots;
	string i;
	cin >> i;//Pour pauser à la fin

    return 0;
}

