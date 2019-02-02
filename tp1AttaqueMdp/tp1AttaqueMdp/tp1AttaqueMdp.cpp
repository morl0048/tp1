// tp1AttaqueMdp.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <openssl\md5.h>

#include <ctime>

using namespace std;

char m_dispo[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*' };


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
			//retour->push_back(mot);
			listeARemplir->push_back(mot);
			//cout << mot << "\n";//prends beaucoup de temps
			nbMot++;
		}
	}

	cout << "Nombre de mots: " << nbMot << "\r\n";

	cout << "Temps chargement dictionnaire: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";
	
	return nbMot;
}

int HashListe(vector<string>* listeClair, vector<string>* listeHash, int nbMots)
{
	const clock_t temps = clock();

	for (int i = 0; i < nbMots; i++)
	{
		string mot = listeClair->at(i);
	}
	//for (int i = 0; i < listeClair.size(); i++)
	//{
	//	/*unsigned char result[MD5_DIGEST_LENGTH];
	//	const unsigned char* str;
	//	str = (unsigned char*)"hello";
	//	unsigned int long_size = 100;
	//	MD5(str,long_size,result);*/
	//	string mot = listeClair.at(i);

	//	unsigned char result[MD5_DIGEST_LENGTH];
	//	const unsigned char* str;
	//	//str = (const unsigned char*)listeClair->at(i);
	//	//MD5(str, listeClair[i].size, result);

	//	string r((char*)result);

	//}

	cout << "Temps hashage dictionnaire: " << float(clock() - temps) / CLOCKS_PER_SEC << "\r\n";

	return 0;
}

//
//vector<string> CreeListeMots(int nbreCharMax)//8 max
//{
//	vector<string> liste;
//
//	size_t i = strlen(m_dispo);
//
//	return liste;
//}

int main()//Je regardes pour ajouter openNp (Multithreading) pour que ça soit plus rapide
{
	vector<string> *listeMots = new vector<string>();
	vector<string> *listeHash = new vector<string>();
	//vector<vector<string>> listeSolution; //ex:[ [hamburger, 6f31ce91f67bf9246ea237850686cc7a], [citronade, 6f31ce91f67bf9246ea23785068765ae], ...]
	
	
	//Charge dictionnaire
	int nbMots = ChargerListeDictionnaire("mots-8-et-moins.txt", listeMots);
	if (nbMots != 0)
	{
		//Hash dictionnaire
		HashListe(listeMots, listeHash, nbMots);
	}


	//Pour pauser à la fin
	string i;
	cin >> i;

    return 0;
}

