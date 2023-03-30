// ****************************************
// Program Title: Project 7
// Project File: Project_07.cpp
// Name: Gianna Foti
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 03/25/23 
// program description: Description of 
// What the program does.
// ****************************************
#include <iostream>
#include <string>
#include <climits> 
#include <iomanip> 
#include <cmath>
#include <fstream> 

using namespace std;

// function prototypes
void printMenu();
int obtainInt();
void obtainVowelsandConsonants(ifstream&, bool); 
bool openInputFile(ifstream & inFile);

// main function
int main()
{
	int choice;
	ifstream inFile;  
	
	do 
	{ 
		bool countConsonants = 0; 
		printMenu(); 
		choice = obtainInt(); 
		switch(choice)
		{
			case 0: 
				cout << endl << "Quit selected.  Terminating program now..." << endl << endl; 
				return 0;
			case 1:
				if ( openInputFile(inFile))
				{
					obtainVowelsandConsonants(inFile, countConsonants);
				}
				
				inFile.close();
				inFile.clear();
				break; 
			case 2:
				countConsonants = true;  
				if (openInputFile(inFile))
				{
					obtainVowelsandConsonants(inFile, countConsonants);
				}
				inFile.close();
				inFile.clear();
				break; 
			default:  
				cout << endl<< string(13, '*') << "  Invalid Selection  " << string(13, '*') << endl;
				cout << "==> Invalid integer value entered" << endl;
				cout << "==> Please enter 0, 1 or 2" << endl;
				cout << string(47, '*') << endl ;
		}
	}
	while (choice!= 3); 
	
	return 0;
}

// menu function
void printMenu()
{	
	cout << endl; 
	cout << string (18, '*') << "  Options  " << string(18, '*') << endl; 
    cout << "0. Exit Program\n";
    cout << "1. Count number of vowels\n";
    cout << "2. Count number of consonants\n";
	cout << string (47, '*') << endl << endl;

}

//getting the integer 
int obtainInt() 
{
	int selection;
	char invalid_selection;
	cout << "Input your selection: ";
	cin >> selection; 
// while in fail state
	while (cin.fail()) {  
		cin.clear();  
		cin >> invalid_selection;  
		cout << invalid_selection << endl << endl;  
		cin.ignore(INT_MAX, '\n');  
		cout << string(13, '*') << "  Invalid Selection  " << string(13, '*') << endl;
		cout << "==> Invalid character entered!!" << endl;
		cout << "==> Please enter 0, 1 or 2" << endl;
		cout << string(47, '*') << endl;
		printMenu();
		cout << "Input your selection: ";
		cin >> selection;  
	}
			
	cin.ignore(INT_MAX, '\n');
	cout << selection << endl;  
	
	return selection;
}

// opening input file with boolean 
bool openInputFile(ifstream & inFile) 
{
    string fileName;
    cout << "Enter the name of the input file now: ";
    cin >> fileName;
	cout << fileName<< endl<< endl;
	 
    inFile.open(fileName);
    if (!inFile) 
	{
       cout << string(14,'*') << "  File Open Error  " << string(14,'*') << endl; 
	   cout << "==> Input file failed to open properly!!\n"; 
	   cout << "==> Attempted to open file: " << fileName << endl; 
	   cout << "==> Selected operation has been canceled\n"; 
	   cout << string(47,'*') << endl; 
        return false;
    }
    return true;
}

// getting vowels and consonants using a priming read getline 
void obtainVowelsandConsonants(ifstream& inFile, bool countConsonants) 
{
	int numLines = 0; 
	string line; 
	int numConsonants = 0; 
	int numVowels = 0; 
	getline(inFile, line);
	if (inFile.eof())
	{
	  	cout << string(15,'*') << "  File Is Empty  " << string(15,'*') << endl; 
	  	cout << "==> Input file is empty\n";  
	  	cout << "==> No information to process\n"; 
	  	cout << string(47,'*') << endl;
		return; 
	}
	// using eof function
	while(!inFile.eof())  	
	{	
		numLines++;
        for (char c : line) 
		{
            if (isalpha(c)) 
			{
                if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') 
				{
                    numVowels++;
                }
                else 
				{
                    numConsonants++;
                }
            }
        }
		getline(inFile, line);
	}
	
	//outputting consonant results
	if (countConsonants) 
	{
		float avgConsonants = float(numConsonants)/numLines; 
		cout << "Counting Number of Consonants" << endl; 
		cout << string(29, '-') << endl; 
        cout << "There are " << numConsonants << " consonants in the file" << "\n";
		cout << "There are " << numLines << " lines in the file" << "\n";
		cout << fixed << setprecision(3) << "This is an average of " << avgConsonants << " consonants per line" << "\n";
    	cout << string(29, '-') << endl;
	}
    else 
	// outputting vowel results 
	{
		float avgVowels = float(numVowels)/numLines; 
		cout << "Counting Number of Vowels" << endl; 
		cout << string(25, '-') << endl; 
        cout << "There are " << numVowels << " vowels in the file" << "\n";
		cout << "There are " << numLines << " lines in the file" << "\n";
		cout << fixed << setprecision(3) << "This is an average of " << avgVowels << " vowels per line" << "\n";
    	cout << string(25, '-') << endl; 
	}
    
	
}




