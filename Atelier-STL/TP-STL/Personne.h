#pragma once
#include <iostream>
#include <string>
using namespace std; 

namespace personne {
	class Personne
	{
		private: 
			string nom;
			string adresse;
			string numero;
		public:
			Personne(string n, string ad, string num) {
				this->nom = n;
				this->adresse = ad;
				this->numero = num;
			}

			void print_Person() const {
				cout << " Nom : " << nom << ", Adresse : " << adresse << ", Numero : " << numero << endl;
			}
	};

};
