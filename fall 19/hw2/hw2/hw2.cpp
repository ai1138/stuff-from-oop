//warriors and dragons by Abed Islam 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Warrior
{
	string name;
	int battleStrength;
	string battle(Warrior &other)
	{
		if (this->battleStrength > other.battleStrength)
		{
			other.battleStrength = 0;
			return this->name+ "has won";
		}
		else if (this->battleStrength == other.battleStrength)
		{
			this->battleStrength = 0;
			other.battleStrength = 0;
			return "yall dead";
		}
		else
		{
			this->battleStrength = 0;
			return other.name + "has won";
		}
	}
};

void createWarrior(vector<Warrior> &warriorCatalog,string name);
void startBattle(vector<Warrior>& warriorCatalog,string name1, string name2);

int main()
{
	ifstream myFile("warriors.txt");
	vector<Warrior> warriorCatalog;
	string command;
	if (!myFile)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (!myFile.eof())
	{
		
	}
}

void createWarrior(vector<Warrior> &warriorCatalog,string name)
{

}

void startBattle(vector<Warrior>& warriorCatalog,string name1,string name2)
{

}
