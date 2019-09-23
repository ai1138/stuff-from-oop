
//author Abed Islam
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	ifstream myFile("jabberwocky.txt");
	string line;
	if (!myFile)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (getline(myFile, line)) 
	{
		cout << line << endl;
	}
	
	myFile.clear();
	myFile.seekg(0);

	string word;
	int count = 0;
	while (myFile >> word)
	{
		count++;
	}

	cout << "the number of words are " << count<< endl;
	myFile.close();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
