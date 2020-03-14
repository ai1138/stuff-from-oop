//warriors and dragons hw2 by Abed Islam 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*struct Warrior
{
	string name;
	int battleStrength;
	//made battle a method for the warrior struct
	string battle(Warrior &other)
	{

		if (this->battleStrength == 0 && other.battleStrength == 0)
		{
			return "Oh, NO! They're both dead! Yuck!\n";
		
		}
		if (this->battleStrength > other.battleStrength)
		{
			other.battleStrength = 0;
			return this ->name + " defeats " + other.name;
		}
		else if (this->battleStrength == other.battleStrength)
		{
			this->battleStrength = 0;
			other.battleStrength = 0;
			return "Mutual Annihilation: "  + this->name + " and "  + other.name
				+ " die at each other's hands\n";
		}
		else
		{
			this->battleStrength = 0;
			return other.name + " defeats " + this->name;
		}
	}
	Warrior(string& name, int battleStrength) :
	name(name), battleStrength(battleStrength) {}
};*/

class Warrior
{
	public:
		
		Warrior() = default;
		Warrior(string name,string wepName,int strength)
		{
			this->name = name;
			this->wep = Weapon(wepName, strength);
		}
		string getName()
		{
			return this->name;
		}
		void setName(string name)
		{
			this->name = name;
		}
		void setWeapon(string name, int strength)
		{
			this->wep = Weapon(name, strength);
		}
		string battle(Warrior& other)
		{

			if (this->wep.getStength() == 0 && other.wep.getStength() == 0)
			{
				return "Oh, NO! They're both dead! Yuck!\n";

			}
			if (this->wep.getStength() > other.wep.getStength())
			{
				other.wep.setStrength(0);
				return this->name + " defeats " + other.name;
			}
			else if (this->wep.getStength() == other.wep.getStength())
			{
				this->wep.setStrength(0);
				other.wep.setStrength(0);
				return "Mutual Annihilation: " + this->name + " and " + other.name
					+ " die at each other's hands\n";
			}
			else
			{
				this->wep.setStrength(0);
				return other.name + " defeats " + this->name;
			}
		}
		friend ostream& operator<<(ostream& os, Warrior& s);
		
	private:
		string name;
		class Weapon
		{
			public:
				Weapon()
				{
					this->name = "";
					this->strength = 0;

				}
				Weapon(string name, int strength)
				{
					this->name = name;
					this->strength = strength;
				}
				void setName(string name)
				{
					this->name = name;
				}
				void setStrength(int strength)
				{
					this->strength = strength;
				}
				string getName()
				{
					return this->name;
				}
				int getStength()
				{
					return this->strength;
				}
				
			private:
				string name;
				int strength;
		};
		Weapon wep;
		
};

//prototyping
void createWarrior(vector<Warrior> &warriorCatalog,Warrior w1);
void startBattle(vector<Warrior>& warriorCatalog,string w1,string w2 );
void gameStats(vector<Warrior>& warriorCatalog);
ostream& operator<<(ostream& os, Warrior& s);

int main()
{
	string command;

	string warriorName;
	string wepName;
	int wepStrength;

	string firstWarrior;
	string secondWarrior;
	vector<Warrior> warriorCatalog;
	//make file stream
	ifstream gameFile("warriors.txt");

	
	while (gameFile >> command)
	{
		
		/*creates warrior on command*/
		if (command == "Warrior") 
		{
			gameFile >> warriorName >> wepName >>wepStrength;
			createWarrior(warriorCatalog,Warrior(warriorName,wepName,wepStrength));
		}
		//starts the battle 
		else if (command == "Battle")
		{
			gameFile >> firstWarrior >> secondWarrior;
			startBattle(warriorCatalog,firstWarrior, secondWarrior);
			
		}
		// run the status function
		else 
		{
			gameStats(warriorCatalog);
		}
	}
	// close file 
	gameFile.close();
}


ostream& operator<<(ostream& os, Warrior& s)
{
	os << s.getName() << " " << s.wep.getName() << " " << " "  << s.wep.getStength();
	return os;
}

void createWarrior(vector<Warrior> &warriorCatalog,Warrior name)
{
	warriorCatalog.push_back(name);
}

void startBattle(vector<Warrior>& warriorCatalog,string name1,string name2)
{
	//looks for the warrior and starts the fight
	int w1 =0 ;
	int w2 = 0;
	for (int i = 0; i < warriorCatalog.size(); i++)
	{
		if(warriorCatalog[i].getName()== name1) 
		{ 
			w1 = i;
		}
		else if (warriorCatalog[i].getName() == name2)
		{
			w2 = i;
		}
	}
	cout << warriorCatalog[w2].battle(warriorCatalog[w1])<<endl;
}

void gameStats(vector<Warrior>& warriorCatalog)
{
	cout << "There are: " << warriorCatalog.size() << " warriors\n";
	for (int i = 0; i < warriorCatalog.size(); i++)
	{
		cout << warriorCatalog[i] << endl;
	}
}
