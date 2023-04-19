// ****************************************
// Program Title: Simple Calculator
// Project File: Project_11.cpp
// Name: Gianna Foti
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 04/23/23 
// program description: Bonus Project
// ****************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	// declare input file stream
	ifstream inFile;
	string inFileName;
	
	// prompt user for input
	cout << endl; 
	cout << "Enter the name of the input file now: ";
	cin >> inFileName;
	cout << inFileName << endl << endl;
	
	// attempt to open file
	inFile.open(inFileName.c_str());
	
	// if file stream failed to open, keep prompting
	while (!inFile)
	{
		cout << endl;
		cout << string (15, '*') << " File Open Error " << string(15, '*') << endl; 
		cout << "==> Input file failed to open properly!!\n"; 
	    cout << "==> Attempted to open file: "<< inFileName << endl; 
		cout << "==> Please try again...\n"; 
	    cout << string(47,'*') << endl << endl; 
		cout << "Enter the name of the input file now: ";
		cin >> inFileName;
		cout << inFileName << endl << endl;
		
		inFile.open(inFileName.c_str());
	}
	
	// declare variables
	string type; 
	string operation;
	double value1;
	double value2;
	char rad_deg;  // indicates rad or deg
	double angle;
	double answer; 
	const double PI = 3.14159265; // pi
	
	// priming read
	inFile >> type;
	
	// if file stream in fail state, then empty file
	if (!inFile)
	{
		cout << endl; 
		cout << string(13,'*') << " Input File Is Empty " << string(13,'*') << endl; 
		cout << "==> The input file is empty.\n";  
	    cout << "==> There is no information to process.\n";  
	    cout << "==> Terminating the program!!!\n"; 
	    cout << string(47,'*') << endl << endl;
		return 1;
	}
	
	// while not end of file
	while (!inFile.eof())
	{
		// branch based on instruction type
		if (type == "Math")
		{
			inFile >> operation >> value1 >> value2;
			if (operation == "%")
			{
				answer = int(value1) % int(value2);
				cout << "Mod: " << value1 << '%' << value2 << " = " << answer << endl;
			}
			else if (operation == "+")
			{
				answer = value1 + value2; 
				cout << "Add: " << value1 << '+' << value2 << " = " << answer << endl;
			}
			else if (operation == "-")
			{
				answer = value1 - value2; 
				cout << "Sub: " << value1 << '-' << value2 << " = " << answer << endl;
			}
			else if (operation == "*")
			{
				answer = value1 * value2; 
				cout << "Mul: " << value1 << '*' << value2 << " = " << answer << endl;
			}
			else if (operation == "/")
			{
				answer = value1 / value2; 
				cout << "Div: " << value1 << '/' << value2 << " = " << answer << endl;
			}
			else 
			{
				cout << "Invalid Operator for Math Operations: " << operation << endl;
				//inFile.ignore(INT_MAX, '\n');
			}	
			
		}
		// if trig 
		else if (type == "Trig")
		{
			inFile >> operation >> rad_deg >> angle;
			if (operation == "s")
			{
				// if degrees and conversion to radians 
					if (rad_deg == 'd')
					{ 
						double originalangle;
						originalangle = angle;
						angle = angle * (PI/180);
						answer = sin(angle); 
						cout << "sin(degrees): " << "sin(" << originalangle << ") = " << answer << endl;	
					}
					else
					{ 
						double originalangle;
						originalangle = angle; 
						answer = sin(angle);
						cout << "sin(radians): " << "sin(" << originalangle << ") = " << answer << endl;	
					}
			}
			else if (operation == "c")
			{
				// if degrees and conversion to radians
				if (rad_deg == 'd')
					{
						double originalangle;
						originalangle = angle;
						angle = angle * (PI/180);
						answer = cos(angle); 
						cout << "cos(degrees): " << "cos(" << originalangle << ") = " << answer << endl;	
					}
					else
					{ 
						double originalangle;
						originalangle = angle;
						answer = cos(angle);
						cout << "cos(radians): " << "cos(" << originalangle << ") = " << answer << endl;	
					}
				
			}
			else if (operation == "t")
			{
				// if degrees and conversion to radians
				if (rad_deg == 'd')
					{
						double originalangle;
						originalangle = angle;
						angle = angle * (PI/180);
						answer = tan(angle); 
						cout << "tan(degrees): " << "tan(" << originalangle << ") = " << answer << endl;	
					}
					else
					{ 
						double originalangle;
						originalangle = angle;
						answer = tan(angle);
						cout << "tan(radians): " << "tan(" << originalangle << ") = " << answer << endl;	
					}
			}
			else 
			{	
					cout << "Invalid Operator for Trig Operations: " << operation << endl;
			}
		}
		else
		{
			cout << "Invalid Calculation Type: " << type << endl;
		}
		// get next type and ignore line
		inFile.ignore(INT_MAX, '\n');
		inFile >> type;
	}
	cout << endl;
	return 0;
}