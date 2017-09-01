/*William Toscano
*/


#define _CRT_SECURE_NO_WARNINGS //removes strcpy errors. Put this before includes
#include <iostream>
#include <iomanip>
#include <cmath> 
#include <fstream>
#include "pokemon.h"




using namespace std;




int Pokedex::readData()
{
	const int strSize = 128;
	char tempString[strSize];
//	int sl;
	ifstream pokemonFile; // the variable of what we will get from file.
	pokemonFile.open("C:\Users\William\Desktop\Pokemon Sorting\pokemon.txt");
	creatureCount = 0; // starts at zero
	if (pokemonFile.is_open())
	{
		while (!pokemonFile.eof()) // while we havn't reached end of file....
		{

			creatures[creatureCount] = new Pokemon;
			pokemonFile.getline(tempString, strSize, ',');  // temporarily store name.
			creatures[creatureCount]->name = new char[strlen(tempString) + 1];
			strcpy(creatures[creatureCount]->name, tempString);
			//pokemonFile.getline(creatures[creatureCount]->name, strSize, ',');
			pokemonFile.getline(tempString, strSize, ',');
			creatures[creatureCount]->type = new char[strlen(tempString) + 1];
			strcpy(creatures[creatureCount]->type, tempString);
			//pokemonFile.getline(creatures[creatureCount]->type, strSize, ',');
			pokemonFile.getline(tempString, strSize, ',');
			creatures[creatureCount]->hitPoints = atoi(tempString);
			pokemonFile.getline(tempString, strSize, ',');
			creatures[creatureCount]->attack = atoi(tempString);
			pokemonFile.getline(tempString, strSize, ',');
			creatures[creatureCount]->defense = atoi(tempString);
			pokemonFile.getline(tempString, strSize, '\n');
			creatures[creatureCount]->ability = new char[strlen(tempString) + 1];
			strcpy(creatures[creatureCount]->ability, tempString);
			//pokemonFile.getline(creatures[creatureCount]->ability, strSize, '\n'); //char pointer
			pokemonFile.peek();
			creatureCount++; //adds one 
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
		system("pause");
		return 0;
	}
	pokemonFile.close(); // always close files.
	return creatureCount; // This fixes the placement of each name. 
}

void Pokedex::display()
{
	cout << left << setw(15) << "NAME" << left << setw(15) << "TYPE" << left << setw(15) << "HITPOINTS" << left << setw(15) << "ATTACK" << left << setw(15) << "DEFENSE" << setw(20) << "ABILITY" << endl;
	for (int i = 0; i < creatureCount; i++)
	{
		cout << left << setw(15) << creatures[i]->name;
		cout << left << setw(15) << creatures[i]->type;
		cout << left << setw(15) << creatures[i]->hitPoints;
		cout << left << setw(15) << creatures[i]->attack;
		cout << left << setw(15) << creatures[i]->defense;
		cout << left << setw(20) << creatures[i]->ability;
		cout << endl;
	}
}

void Pokedex::writeData()
{
	ofstream myFile;
	myFile.open("pokemon.txt");
	for (int i = 0; i < creatureCount; i++)
	{
		myFile << creatures[i]->name << ',' << creatures[i]->type << ',' << creatures[i]->hitPoints << ',' << creatures[i]->attack << ',' << creatures[i]->defense << ',' << creatures[i]->ability << '\n';


	}
	myFile.close();
}

void Pokedex::searchByName(char searchName[])
{

	bool found = false;
	for (int i = 0; i < creatureCount; i++)
	{
		if (strcmp(searchName, creatures[i]->name) == 0)
		{
			found = true;
			cout << "The information of " << creatures[i]->name << " goes as follows: " << endl;
			cout << "The type is " << creatures[i]->type << "." << endl;
			cout << "The hitpoints are at " << creatures[i]->hitPoints << endl;
			cout << "The attack points are at " << creatures[i]->attack << endl;
			cout << "The defense points are at " << creatures[i]->defense << endl;
			cout << "Its ability is " << creatures[i]->ability << endl;
		}

	}
	if (found == false) // if the for loop didn't turn out true, no name was found
	{
		cout << "No name found " << endl;
	}
}

void Pokedex::newCreature()
{
	creatures[creatureCount] = new Pokemon;
	const int strSize = 128;
	char tempString[strSize];
	cout << "What would you like to call the new pokemon? " << endl;
	cin.ignore(); // Always try to include this if your program skips a question. This happened with the search function too
	cin.getline(tempString, strSize, '\n');
	creatures[creatureCount]->name = new char[strlen(tempString) + 1];
	//cin.getline(creatures[creatureCount]->name, strSize, '\n');// getline because it can have spaces
	strcpy(creatures[creatureCount]->name, tempString);
	cout << "What is the type? " << endl;
	cin.getline(tempString, strSize);
	creatures[creatureCount]->type = new char[strlen(tempString) + 1];
	cin.getline(creatures[creatureCount]->type, strSize, '\n');
	strcpy(creatures[creatureCount]->type, tempString);
	cout << "What is the hitpoints of the pokemon " << endl;
	cin.getline(tempString, strSize, '\n');
	creatures[creatureCount]->hitPoints = atoi(tempString);
	cout << "What is the attack points? " << endl;
	cin.getline(tempString, strSize, '\n');
	creatures[creatureCount]->attack = atoi(tempString);
	cout << "What is the defense? " << endl;
	cin.getline(tempString, strSize, '\n');
	creatures[creatureCount]->defense = atoi(tempString);
	cout << "What is its ability? " << endl;
	cin.getline(tempString, strSize);
	creatures[creatureCount]->ability = new char[strlen(tempString) + 1];
	cin.getline(creatures[creatureCount]->ability, strSize, '\n');
	strcpy(creatures[creatureCount]->ability, tempString);
	creatureCount++;
}

void Pokedex::findMaxHP()
{
	int maxHPPosition = -1;
	int currentMaxHP = 0;
	for (int i = 0; i < creatureCount; i++)
	{
		if (creatures[i]->hitPoints > currentMaxHP) // i is changing, not the creature count here.
		{
			currentMaxHP = creatures[i]->hitPoints;
			maxHPPosition = i; // saves the max HP position equal to the position we are in


		}
	}
	cout << "The Pokemon with the highest HP is " << creatures[maxHPPosition]->name << endl;
	cout << "The information of " << creatures[maxHPPosition]->name << " goes as followes. " << endl;
	cout << "The type is " << creatures[maxHPPosition]->type << "." << endl;
	cout << "The hitpoints are at " << creatures[maxHPPosition]->hitPoints << endl;
	cout << "The attack points are at " << creatures[maxHPPosition]->attack << endl;
	cout << "The defense points are at " << creatures[maxHPPosition]->defense << endl;
	cout << "Its ability is " << creatures[maxHPPosition]->ability << endl;


}

int Pokedex::getCreatureCount()
{
	return creatureCount;
}


Pokedex::Pokedex()
{
	creatureCount = 0;


}

Pokedex::~Pokedex()
{
	for (int i = 0; i < creatureCount; i++) {
		if (creatures[i] != nullptr) { // Make sure we don’t try to delete 
			//  memory that hasn’t been allocated.
			delete[] creatures[i]->name;
			delete[] creatures[i]->type;
			delete[] creatures[i]->ability;
			
			// Also delete the ability c-string.
			// Now that the c-strings are deleted, you can delete the creature.
			// Call delete on creatures[i].
		}
		
	}
}