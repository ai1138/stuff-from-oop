//Rec02 By Abed Islam
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>

using namespace std;


struct organicCompound
{
	vector<string> name;
	int carbonNum, hydrogenNum;
};
void openFile(ifstream& orgoFile, vector<organicCompound>& orgoList);
void swapping(organicCompound& a, organicCompound& b);
void bubbleSort(vector<organicCompound>& orgoList);
void displayList(const vector<organicCompound>& orgoList);

void swapping(organicCompound& compoundOne,organicCompound& compoundTwo)
{ 
	organicCompound temp;
	temp = compoundOne;
	compoundOne = compoundTwo;
	compoundTwo = temp;
}
void bubbleSort(vector<organicCompound>& orgoList)
{
	
	for (int i = 0; i < orgoList.size(); i++)
	{
		for (int j = 0; j < orgoList.size() - i - 1; j++)
		{
			if (orgoList[j].carbonNum == orgoList[j + 1].carbonNum)
			{
				if (orgoList[j].hydrogenNum > orgoList[j + 1].hydrogenNum)
				{
					swapping(orgoList[j], orgoList[j + 1]);
				}
				if (orgoList[j].hydrogenNum == orgoList[j + 1].hydrogenNum)
				{
					orgoList[j].name.push_back(orgoList[j + 1].name[0]);
					orgoList.erase(orgoList.begin() + j+ 1);

				}
			}
			if (orgoList[j].carbonNum > orgoList[j + 1].carbonNum)
			{
				swapping(orgoList[j], orgoList[j + 1]);
			}
		}
		
	}
}
void displayList(const vector<organicCompound>& orgoList)
{
	string names;
	for (int i = 0; i < orgoList.size(); i++)
	{
		names = "C" + to_string(orgoList[i].carbonNum) + "H" + to_string(orgoList[i].hydrogenNum);
		if (orgoList[i].name.size() > 1)
		{
			for (int j = 0; j < orgoList[i].name.size(); j++)
			{
				names +=  " " + orgoList[i].name[j];
			}
		}
		else
		{ 
			names += " " + orgoList[i].name[0];
		}
		cout << names<<endl;
		
	}
}
void openFile(ifstream& orgoFile, vector<organicCompound>& orgoList)
{
	char skip;
	if (!orgoFile)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (!orgoFile.eof())
	{
		string compoundName;
		organicCompound x;
		orgoFile >> compoundName;
		x.name.push_back(compoundName);
		orgoFile >> skip;
		orgoFile >> x.carbonNum;
		orgoFile >> skip;
		orgoFile >> x.hydrogenNum;
		orgoList.push_back(x);

	}
	orgoFile.close();
	
}
int main()
{
	ifstream orgoFile("tex.txt");
	vector<organicCompound> orgoList;
	openFile(orgoFile,orgoList);
	bubbleSort(orgoList);
	displayList(orgoList);


}

