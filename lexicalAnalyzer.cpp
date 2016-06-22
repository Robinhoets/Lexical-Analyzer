// lexical analyzer

#include <iostream>
#include <fstream>
#include <string.h>
#include "Sentences.h"
#include "Words.h"
#include <stdio.h>
#include <iomanip>

// by declaring this, we include stuff like cout, cin, string, vector, map, etc
using namespace std;


bool isSpace(char cha);
bool isSymbol(char cha);
bool isOperator(char cha);
bool isKeyword(string tok);
bool isAlphabet(char cha);
bool isDigit(char cha);
bool isUnderscore(char cha);

int main()
{
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
	string datas[28];
	// index to be incremented for each sentence
	int ind = 0;


	/*
		opens myfile
		sets line to datas array
		increase numlines
	*/
	if(myfile.is_open())
	{
		string token;
		string line;	// line that gets read in
		char next;	// will be filled with each character in each line to be analyzed
		
		while (getline (myfile,line)) 
		{
			for(int i=0; i<line.length(); i++)
			{
				next = line[i];

				if (isSpace(next)) { 
					cout << token << '\n';
					//*** add code to check if valid variable(identifer) ***
					token.clear();
				}
				else if (isSymbol(next)) {
					cout << token << '\n';
					//*** add code to check if valid variable(identifer) ***
					token.clear();

				}
				else if (isOperator(next)) {
					cout << token << '\n';
					//*** add code to check if valid variable(identifer) ***
					token.clear();
				}
				else if (isAlphabet(next)) {
					token += next;
				}
				else if(isDigit(next)) {
					token += next;
				}
				else if(isUnderscore(next)) {
					token += next;
				}

			}

	
		}
		myfile.close();

	}

	else cout << "unable to open file";



	// Exit program
	return 0;
}

bool isSpace(char cha)
{
	if(cha==' ' || cha=='\n' || cha=='\t' || cha==',')
		return true;
	else
		return false;
}

bool isSymbol(char cha)
{
	if(cha=='(' || cha==')' || cha=='{' || cha=='}' || cha==';' || cha=='[' || cha==']')
		return true;
	else
		return false;
}

bool isOperator(char cha)
{
	if(cha=='+' || cha=='-' || cha=='/' || cha=='%' || cha=='=' || cha=='<' || cha=='>')
		return true;
	else
		return false;
}

bool isKeyword(string tok)
{
	if(tok=="alignas" || tok=="alignof" || tok=="and" || tok=="and_eq" || tok=="asm" || tok=="atomic_cancel" || 
		tok=="atomic_commit" || tok=="atomic_noexcept" || tok=="auto" || tok=="bitand" || tok=="bitor" || 
		tok=="bool" || tok=="break" || tok=="case" || tok=="catch" || tok=="char" || tok=="char16_t" || 
		tok=="char32_t" || tok=="class" || tok=="compl" || tok=="concept" || tok=="const" || tok=="constexpr" || 
		tok=="const_cast" || tok=="continue" || tok=="decltype" || tok=="default" || tok=="delete" || 
		tok=="do" || tok=="double" || tok=="dynamic_cast" || tok=="else" || tok=="enum" || tok=="explicit" || 
		tok=="export" || tok=="extern" || tok=="false" || tok=="float" || tok=="for" || tok=="friend" || 
		tok=="goto" || tok=="if" || tok=="inline" || tok=="int" || tok=="import" || tok=="long" || 
		tok=="module" || tok=="mutable" || tok=="namespace" || tok=="new" || tok=="noexcept" || tok=="not" || 
		tok=="not_eq" || tok=="nullptr" || tok=="operator" || tok=="or" || tok=="or_eq" || tok=="private" || 
		tok=="protected" || tok=="public" || tok=="register" || tok=="reinterpret_cast" || tok=="requires" || 
		tok=="return" || tok=="short" || tok=="signed" || tok=="sizeof" || tok=="static" || 
		tok=="static_assert" || tok=="static_cast" || tok=="struct" || tok=="switch" || tok=="synchronized" || 
		tok=="template" || tok=="this" || tok=="thread_local" || tok=="throw" || tok=="true" || tok=="try" || 
		tok=="typedef" || tok=="typeid" || tok=="typename" || tok=="union" || tok=="unsigned" || tok=="using" || 
		tok=="virtual" || tok=="void" || tok=="volatile" || tok=="wchar_t" || tok=="while" || tok=="xor" || tok=="xor_eq" )
		return true;
	else
		return false;
}

bool isAlphabet(char cha)
{
	if(cha=='a' || cha=='b' || cha=='c' || cha=='d' || cha=='e' || cha=='f' || cha=='g' || cha=='h' || cha=='i' || cha=='j' || 
		cha=='k' || cha=='l' || cha=='m' || cha=='n' || cha=='o' || cha=='p' || cha=='q' || cha=='r' || cha=='s' || cha=='t' || 
		cha=='u' || cha=='v' || cha=='w' || cha=='x' || cha=='y' || cha=='z' || cha=='A' || cha=='B' || cha=='C' || cha=='D' || 
		cha=='E' || cha=='F' || cha=='G' || cha=='H' || cha=='I' || cha=='J' || 
		cha=='K' || cha=='L' || cha=='M' || cha=='N' || cha=='O' || cha=='P' || cha=='Q' || cha=='R' || cha=='S' || cha=='T' || 
		cha=='U' || cha=='V' || cha=='W' || cha=='X' || cha=='Y' || cha=='Z')
		return true;
	else
		return false;
}

bool isDigit(char cha)
{
	if(cha=='1' || cha=='2' || cha=='3' || cha=='4' || cha=='5' || cha=='6' || cha=='7' || cha=='8' || cha=='9')
		return true;
	else
		return false;
}

bool isUnderscore(char cha)
{
	if(cha=='_')
		return true;
	else
		return false;
}