/*William Toscano
*/
#define _CRT_SECURE_NO_WARNINGS //removes strcpy errors. Put this before includes

#include <iostream>
#include <iomanip>
#include <cmath> 
#include <fstream>
#include"pokemon.h"


using namespace std;

int main()
{
	char option;
	Pokedex aPokedex;
	char searchName[128];
	//Pokemon creatures[maxCreatures];
	//creatureCount = 0; // number of members starts at 0
	aPokedex.readData(); // Calling load data
	cout << "Successfully loaded " << aPokedex.getCreatureCount() << " creatures." << endl;
	do
	{
		cout << "Welcome to the Pokemon collection program. " << endl;
		cout << "What would you like to do: " << endl;
		cout << "(L)ist, (A)dd, (S)earch, find(M)ax hit point creature, or (Q)uit: " << endl;
		cin >> option;
		cin.clear();
		if (option == 'L')
		{
			aPokedex.display();
		}

		else if (option == 'A')
		{
			aPokedex.newCreature();

		}

		else if (option == 'S')
		{
			cout << "Who would you like to search for? " << endl;
			cin.ignore();
			cin.getline(searchName, 128, '\n');
			aPokedex.searchByName(searchName);
		}

		else if (option == 'M')
		{
			aPokedex.findMaxHP();
		}

		else if (option == 'Q')
		{
			cout << "Have a nice day. " << endl;
			aPokedex.writeData();
			system("pause");
			return 0;

		}

		else if (option != 'Q' || option != 'A' || option != 'S' || option != 'M' || option != 'L') // This is for when the user enters something outside the available options.
		{
			cout << "Error. " << endl;
		}
	} while (option != 'q');
	{
		system("pause");
	}// Include this when you offer the option to quit.

}