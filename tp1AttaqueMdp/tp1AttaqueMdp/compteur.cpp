#include "stdafx.h"
#include "compteur.h"

Compteur::Compteur(size_t longueur, string charPossible)
{
	m_charPossible = charPossible;
	m_nbCharPossible = charPossible.length();
	m_longueur = longueur;
	for (size_t i = 1; i < longueur; i++)
	{
		m_value += " ";
	}
	m_value += charPossible[0];
}

Compteur::Compteur(size_t longueur, string charPossible, string value) : Compteur(longueur, charPossible)
{
	this->SetValue(value);
}

Compteur::~Compteur()
{
	m_charPossible.clear();
	m_nbCharPossible = NULL;
	m_value.clear();
	m_longueur = NULL;
}

bool Compteur::Increment()
{
	bool retenue;
	bool overflow = false;
	int i = 0;
	do
	{
		retenue = IncrementPos(i, &overflow);
		i++;
	} while (retenue && !overflow);
	if (overflow)
		return false;
	return true;
}

bool Compteur::IncrementPos(size_t i, bool* overflow)
{
	bool retenue = false;
	
	i++;

	if (i > m_longueur)//changer pos 8 lorsque 8 de long = overflow
	{
		*overflow = true;
	}
	else
	{
		if (m_value[m_longueur - i] == ' ')//si vide
		{
			m_value[m_longueur - i] = m_charPossible[0];
		}
		else
		{
			size_t j = m_charPossible.find(m_value[m_longueur - i]);
			j++;//monte d'un char

			if (j >= m_nbCharPossible)
			{
				m_value[m_longueur - i] = m_charPossible[0];//retour à la case zéro si dépasse
				retenue = true;//et garde retenue
			}
			else
			{
				m_value[m_longueur - i] = m_charPossible[j];//sinon, inc le char
			}
		}
	}
	
	return retenue;
}

string Compteur::GetValue()
{
	string temp = m_value;
	temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
	return temp;
}

void Compteur::SetValue(string value)//!!ATTENTION!! ne regarde pas si bon alphabet ni longueur mot
{
	while (value.length < this->m_longueur)
	{
		value.insert(0, " ");
	}
	this->m_value = value;
}