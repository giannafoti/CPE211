// ****************************************
// Program Title: Project_05
// Project File: Project_05.cpp
// Name: Gianna Foti
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 02/12/23 
// program description: Description of 
// What the program does.
// ****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cmath> 
#include <iomanip>

// testing 
using namespace std;
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
	   cout << endl;
	   cout << string (9, '*') << " Command Line Argument Error " << string(9, '*') << endl; 
	   cout << "==> Incorrect number of Command Line Arguments!\n"; 
	   cout << "==> Command for running the program is:\n"; 
	   cout << "==> ./Project_05 inputFileName  outputFileName\n"; 
	   cout << string(47,'*') << endl << endl; 
	   return 1; 
	}
	
// Variables
	float numA;
	float numB;
	float numC;
	float sum; 
	float avg; 
	string rating; 
	 
	ifstream inFile;
	ofstream outFile;
	string inFileName=argv[1];
	string outFileName=argv[2]; 

// cout to the terminal showing what file it is opening
	cout << endl;
	cout << "Opening Input File: " << inFileName << endl;
	
// file open infile error message
	inFile.open(inFileName.c_str());
	if(inFile.fail()) 
	{ 
	   cout << endl; 
	   cout << string(15,'*') << " File Open Error " << string(15,'*') << endl; 
	   cout << "==> Input file failed to open properly!!\n"; 
	   cout << "==> Attempted to open file: " << inFileName << endl; 
	   cout << "==> Terminating program!!!\n"; 
	   cout << string(47,'*') << endl << endl; 
	   return 1; 
	} 

// cout to the terminal showing what file it is outputting to 
	cout << endl;
	cout << "Opening Output File: " << outFileName << endl << endl;

// file open outfile error message	
	outFile.open(outFileName.c_str());
	if(outFile.fail()) 
	{ 
	   cout << string(15,'*') << " File Open Error " << string(15,'*') << endl; 
	   cout << "==> Output file failed to open properly!!\n"; 
	   cout << "==> Attempted to open file: " << outFileName << endl; 
	   cout << "==> Terminating program!!!\n"; 
	   cout << string(47,'*') << endl << endl; 
	   return 1; 
	} 
	
// grabbing first number
	inFile.ignore(INT_MAX, 'A');
	inFile >> numA;
		
	
	inFile.ignore(INT_MAX, 'B');
	inFile >> numB;
	
	
	inFile.ignore(INT_MAX, 'C');
	inFile >> numC;
	
	
// Calculations
	sum = numA + numB + numC;
	avg = (numA + numB +numC)/3;
	
	if (avg >= 75)
	{
		rating = "High";
	}
	else if (avg < 75 && avg >= 25)
	{
		rating = "Medium";
	}
	else if (avg < 25)
	{
		rating = "Low";
	}
		
// if statement for negative number else show results	
	if (numA < 0 || numB < 0 || numC < 0)
	{
		cout << string(15,'*') << " Negative Number " << string(15,'*') << endl; 
		if (numA < 0)
		{
			cout << "==> First number is less than 0" << endl;
		}
		if (numB < 0)
		{
			cout << "==> Second number is less than 0" << endl;
		}
		if (numC < 0)
		{
			cout << "==> Third number is less than 0" << endl; 
		}
		cout << "==> All numbers should be positive\n";
	    cout << "==> Terminating program!!!\n"; 
	    cout << string(47,'*') << endl << endl; 	
	}
	else 
	{
		outFile << fixed << setprecision(2);
		outFile << setfill(' ') << left; 		
		outFile << string(47,'*') << endl;
		outFile << setw(35) << "The numbers read are: " << numA << ' ' << numB << ' ' << numC << endl;
		outFile << setw(35) << "The sum of the numbers is: " << sum << endl; 
		outFile << setw(35) << "The average of these numbers is: " << avg << endl;
		outFile << setw(35) << "This average is: " << rating << endl;
		outFile << string(47,'*') << endl;
	}
 return 0;
}