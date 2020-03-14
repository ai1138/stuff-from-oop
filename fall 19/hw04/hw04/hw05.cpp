// hw05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Noble;
class Warrior
{
public:
	friend Noble;
	Warrior() = default;
	Warrior(string name, int strength)
	{
		this->name = name;
		this->warriorStrength = strength;
	}
	string getName()
	{
		return this->name;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setStrength(int strength)
	{
		this->warriorStrength = strength;
	}
	int getStrength()
	{
		return this->warriorStrength;
	}
	

private:
	string name;
	Noble* noble = nullptr;
	int warriorStrength;


};
class Noble
{
public:
	
	Noble() = default;
	Noble(string name)
	{
		this->name = name;
	}
	const string& getName()
	{
		return this->name;
	}
	void setName(string& name)
	{
		this->name = name;
	}
	void calculateArmyStrength()
	{
		for (size_t i = 0; i < this->army.size(); i++)
		{
			this->strength += army[i]->getStrength();
		}
	}
	void hire(Warrior*& warr)
	{
		if (this->life)
		{
			if (warr->noble == nullptr)
			{
				warr->noble = this;
				army.push_back(warr);
			}
		}
		
		
	}
	void fire(Warrior*& warr)
	{ 
		if (this->life)
		{
			if (warr->noble != nullptr && warr->getStrength() == 0)
			{
				for (size_t i = 0; i < army.size(); ++i)
				{
					if (warr == army[i]) 
					{
						for (size_t index = 0; index < army.size() - 1 - i; ++index) 
						{
							army[index] = army[index + 1];
						}
						army.pop_back();
						warr->noble = nullptr;
						cout << "You don't work for me anymore " << warr->getName() <<
							"! -- " << this->getName() << "." << endl;
					}
				}
			}
		}
	
	}
	void battle(Noble*& nob)
	{
		cout << this->getName() << " battles " << nob->getName() << endl;
		this->calculateArmyStrength();
		nob->calculateArmyStrength();
		if (this->strength == nob->strength)
		{
			if (this->strength > 0) 
			{
				cout << "Mutual annihilation: " << this->getName() << " and " << nob->getName() <<
					" die at each other's hands" << endl;
				
			}
			else
			{
				cout << "Oh NO! They're both dead! Yuck!" << endl;
			}
		}



	}
	
private:

	string name;
	vector<Warrior*> army;
	int strength = 0;
	bool life = true;
};


int main() 
{


}
