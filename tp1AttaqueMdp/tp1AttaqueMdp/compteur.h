#pragma once
#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

class Compteur
{
public:
	Compteur(size_t longueur, string charPossible);
	Compteur(size_t longueur, string charPossible, string value);
	~Compteur();
	bool Increment();
	bool IncrementPos(size_t i, bool* overflow);
	string GetValue();
	void SetValue(string value);

private:
	string m_charPossible;
	size_t m_nbCharPossible;
	string m_value;
	size_t m_longueur;
};