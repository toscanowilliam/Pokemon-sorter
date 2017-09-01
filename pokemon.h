#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>



const int maxCreatures = 100;

struct Pokemon {
	char * name;
	int hitPoints;
	int attack;
	int defense;
	char * ability;
	char * type;
};



class Pokedex {
	Pokemon * creatures[maxCreatures];
	int creatureCount;
public:
	void newCreature();
	void display();
	void searchByName(char searchName[]);
	void findMaxHP();
	void writeData();
	int readData();
	int getCreatureCount();
	Pokedex();
	~Pokedex();

};
