// Ceasar Cipher by Abed Islam 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


//This function is meant to decrypt each line 
void decryptLine(string& line,int rotation)
{
	
	for (size_t i = 0; i < line.length(); i++)
	{
		
		if (line[i] >= 'a' && line[i] <= 'z')
		{
			//this line will moves the letter back in the decipher
			line[i] = line[i] - rotation;
			//the if statement handles the case where after the rotation the ascii value is lower than a. When this happen the valye needs to be subsetted
			if (line[i] < 'a')
			{
				//this is the actual subsetting by adding the difference of z and a that gives us 26 and we add one to that to give us 27 by adding 27 
				//we are able to properly  rotate the char to the position it should be in
				line[i] = line[i] + ('z' - 'a') + 1;
			}

		}
	}
	
}
//this function purpose is to actually take a file and decrypt it
void fileRead(string encodedFile)
{
	vector<string> theLines;
	ifstream myFile(encodedFile);

	string line;
	if (!myFile)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}

	//this loop adds every line into a vector
	while (getline(myFile, line))
	{
		theLines.push_back(line);
	}
	//the first line is the shift number so it is taken from the vector and stored
	int rotation = stoi(theLines[0]);
	//this loop decrypts and prints the decryption in the proper order
	for (int i = theLines.size() - 1; i > 0; i--)
	{
		decryptLine(theLines[i], rotation);
		cout << theLines[i];
	}
}

int main()
{
	//durr is a dummy txt file to test the code
	fileRead("durr.txt");

}

