// TP-STL.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <deque>
#include <string>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include<unordered_map>
#include "Personne.h"

using namespace std;
using namespace personne;

bool lowercase_vowel(char c ){
	if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) return true;
	return false;
}


void print_list(list<string>& ll) {
	for (auto it = ll.begin(); it != ll.end(); it++) {
		cout << *it << endl ;
	}
	cout << endl;
}

bool char_non_accpt(char c)
{
	if (c != '\t' && c != ' ' && c != '?' && c != '.' && c != '!') return true;
	return false;
}

int main()
{
	/**                                         EXO : 1 -  Partie 1                                         */

	cout << "/**                                         EXO : 1 -  Partie 1                                         */ " << endl;
	int nombre_mots;
	string mot;
	deque<string> deque;
	list<string> liste;
	cout << "Donnez le nombre de mots que vous voulez entrer : ";
	cin >> nombre_mots;
	for (int i = 0; i < nombre_mots; i++)
	{
		cout << "Donnez le mot [" << i + 1 << "] = ";
		cin >> mot;
		deque.push_back(mot);
	}
	// copiage du contenu du deque vers une liste 
	for (auto it = deque.begin(); it != deque.end(); it++)
	{
		liste.push_back(*it);
	}
	// trier la liste : 
	liste.sort();
	print_list(liste);


	/****                                      EXO : 1 -   Partie 2                                         */

	cout << "/**                                         EXO : 1 -  Partie 2                                         */ " << endl;

	stack<char> my_stack;
	stack<char> s_reverse;
	stack<char> temp;
	string phrase;
	bool est_palindrome = true;


	cout << "Donnez Votre phrase : ";
	getline(cin, phrase);
	
	for (int i = 0; i < phrase.length(); i++)
	{
		if (char_non_accpt(phrase[i]))
		{
			my_stack.push(phrase[i]);
			temp.push(phrase[i]);
		}
	}
	// reversing temp into s_reverse : 
	while (!temp.empty())
	{
		s_reverse.push(temp.top());
		temp.pop();
	}
	// traitement : 
	while (my_stack.empty())
	{
		if (my_stack.top() != s_reverse.top())
		{
			est_palindrome = false;
			break;
		}
		my_stack.pop();
		s_reverse.pop();
	}
	if (est_palindrome)
	{
		cout << " La phrase que vous avez donnee est : PALINDROME " << endl;
	}
	else {
		cout << " La phrase que vous avez donnee n'est pas Palindrome " << endl;
	}


	/****                                            EXO : 1 - Partie 3                                         */
	cout << "/**                                         EXO : 1 -  Partie 3                                         */ " << endl;

	auto cmp = [](string a, string b)
	{
		// less
		return a < b;
	};
	priority_queue<string, vector<string>, decltype(cmp)> Q(cmp);
	vector<string> v;
	string input;
	int nombre_mot;
	cout << "Donnez le nombre de mot : ";
	cin >> nombre_mot;
	for (int i = 0; i < nombre_mot; i++)
	{
		cout << "Mot [ " << i + 1 << " ] = ";
		cin >> input;
		v.push_back(input);
	}
	for (string i : v)
	{
		Q.push(i);
	}
	cout << " --=> Priority Queue en ordre deroissant :   ";
	while (!Q.empty())
	{
		cout << Q.top() << " ";
		Q.pop();
	}
	cout << endl;

	/****                                EXO : 2 - partie : 1                                                          */
	cout << "/**                                         EXO : 2 -  Partie 1                                         */ " << endl;

	list<string> ma_liste;
	int nombre_mot; 
	string mot;
	cout << "Donnez le nombre de mot que vous voulez entrez : ";
	cin >> nombre_mot;

	 /*insertion à la liste à l'aide de l'iterateur ; 
	 insertion au début ; */
	auto it = ma_liste.begin();
	for (int i = 0; i < nombre_mot; i++)
	{
		cout << "Donnez le mot [" << i + 1 << "] = ";
		cin >> mot;
		ma_liste.insert(it, mot);
	}
	print_list(ma_liste);


	/****                                EXO : 2 - partie : 2                                                          */
	cout << "/**                                         EXO : 2 -  Partie 2                                         */ " << endl;

	for (auto it = ma_liste.begin(); it != ma_liste.end(); it++)
	{
		transform(it->begin(), it->end(), it->begin(), [](char &c) { 
			if (lowercase_vowel(c)) {
				c = '*';
			}
				return c;
			});
	}
	print_list(ma_liste);


	/****                                EXO : 2 - partie : 3                                                         */
	cout << "/**                                         EXO : 2 -  Partie 3                                         */ " << endl;

	for (auto it = ma_liste.begin(); it != ma_liste.end(); it++)
	{
		transform(it->begin(), it->end(), it->begin(), [](char c) { return toupper(c); });
	}
	print_list(ma_liste);

	/****                                EXO : 3 			                                                         */
	cout << "/**                                         EXO : 3                                       */ " << endl;
	

	auto cmp = [](Personne p1, Personne p2) {
		return p1 < p2;
	};
	unordered_multimap<string, Personne> un_mp_person = {
		{"Ayachi",Personne("Ayachi","Hay el amal","0673829398")},
		{"Machtor",Personne("Machtor","Hay el amal","0674839308")}
		
		};

	Personne* p1 = new Personne("Elharoui", "Hey el amal", "0674779308");
	un_mp_person.insert(make_pair("Elharoui", *p1));
	
	for (auto it = un_mp_person.begin(); it != un_mp_person.end(); it++)
	{
		cout << " Cle : " << it->first << " ->  ";
		it->second.print_Person();
	}
	




	system("pause>0");
   
}

