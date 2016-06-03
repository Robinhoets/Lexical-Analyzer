// lexical analyzer

#include <iostream>
#include <fstream>
#include <string>
#include "Sentences.h"
// by declaring this, we include stuff like cout, cin, string, vector, map, etc
using namespace std;

int main()
{
	string line;
	int numlines = 0;

	// creates string to be read in
	string mystr;
	// prompt user
	cout << "Enter name of document to be read: ";
	// reads in user prompt to String mystr
	getline(cin,mystr);

	// opens file and changes input to char
	ifstream myfile(mystr.c_str());


	// create Token object
	Sentences datas[28];
	// index to be incremented for each sentence
	int ind = 0;


	/*
		opens myfile
		gets a line and prints it to the screen
		increase numlines
	*/
	if(myfile.is_open())
	{
		while (getline (myfile,line)) 
		{
			datas[ind].set_x(line);
			ind++;
			//cout << line << '\n';
			numlines++;
		}
		myfile.close();
		cout << "number of lines: " << numlines 
		<< '\n';
	}

	else cout << "unable to open file";

	// print out our array - just to test out if it is working
	for (int b=0; b<28; b++)
	{
		cout << datas[b].get_x() << '\n';
	}

	// Exit program
	return 0;
}