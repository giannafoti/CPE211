// ****************************************
// Program Title: 
// Project File: Project_06.cpp
// Name: Gianna Foti
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 02/28/23 
// program description: class averages
// **************************************** 
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cmath> 
#include <iomanip>

using namespace std;

int main (int argc, char *argv[])
{
	// check arguments 
	if (argc != 3)
	{
	   cout << endl;
	   cout << string (9, '*') << " Command Line Argument Error " << string(9, '*') << endl; 
	   cout << "==> Incorrect number of Command Line Arguments!\n"; 
	   cout << "==> Command for running the program is:\n"; 
	   cout << "==> ./Project_06 inputFileName outputFileName\n"; 
	   cout << string(47,'*') << endl << endl; 
	   return 1; 
	}
	
	// declaring variables
	int numQuiz; //  The number of quiz scores 
	int numHw; //  the number of homework scores
	int numExam; //  the number of exam scores
	int line;
	string lastName;  
	string firstName;
	
	ifstream inFile;
	ofstream outFile;
	string inFileName=argv[1];
	string outFileName=argv[2];
	
	
	// cout to the terminal showing what file it is outputting to 
	cout << endl;
	cout << "Opening Input File: " << inFileName << endl << endl;
	
	//file open infile message error
	inFile.open(inFileName.c_str());
	while(inFile.fail())
	{
		cout << string (15, '*') << " File Open Error " << string(15, '*') << endl; 
		cout << "==> Input file failed to open properly!!\n"; 
	    cout << "==> Attempted to open file: "<< inFileName << endl; 
		cout << "==> Please try again...\n"; 
	    cout << string(47,'*') << endl << endl; 
		
		inFile.clear();
		
		cout << "Enter the name of the input file: ";
		cin >> inFileName; 
		cout << inFileName << endl << endl;
		inFile.open(inFileName.c_str());				   
	}
	
	// cout to the terminal showing what file it is outputting to 
	cout << "Opening Output File: " << outFileName << endl << endl;
	
	// file open outfile error message	
	outFile.open(outFileName.c_str());
	while(outFile.fail()) 
	{ 
	   cout << string(15,'*') << " File Open Error " << string(15,'*') << endl; 
	   cout << "==> Output file failed to open properly!!\n"; 
	   cout << "==> Attempted to open file: " << outFileName << endl; 
	   cout << "==> Please try again...\n"; 
	   cout << string(47,'*') << endl << endl; 
	   
	   outFile.clear();
		
	   cout << "Enter the name of the output file: ";
	   cin >> outFileName; 
	   cout << outFileName << endl << endl;
	   outFile.open(outFileName.c_str());
	} 
	
	
	inFile >> numQuiz;
	if(inFile.fail())
	{
	   cout << string(13,'*') << " Input File Is Empty " << string(13,'*') << endl; 
	   cout << "==> The input file is empty.\n";  
	   cout << "==> Terminating the program.\n"; 
	   cout << string(47,'*') << endl << endl;
	   
	   outFile << "Input file " << inFileName << " is empty." << endl; 
	   return 1; 
	}
	
	//grabbing ints on first line		
	inFile >> (numHw);
	inFile >> (numExam);
	
	//max line
	inFile >> (lastName);
	inFile >> (firstName);

	
	int counter = 0;
	int sumQuiz =0;
	int num;
	while (counter < numQuiz)
	{
		inFile >> num;
		sumQuiz = num + sumQuiz; 
		counter++;
		
	} 
	
	counter = 0;
	int sumHw =0;
	while (counter < numHw)
	{
		inFile >> num;
		sumHw = num + sumHw; 
		counter++;
		
	} 
	
	counter = 0;
	int sumExam =0;
	while (counter < numExam)
	{
		inFile >> num;
		sumExam = num + sumExam; 
		counter++;
	}
	
	int maxTotal = sumQuiz + sumHw +sumExam;
	float average = (maxTotal/maxTotal)*100;
	

	
	//Formatting heading
	outFile << left << setw(3) << "#" << setw(12) << "Last" << setw(7) << "First" << setw(6) << "Quiz" << setw(6)
			<< "HW" << setw(6) << "Exam" << setw(7) << "Total" << setw(7) << "Average" << endl;
	
	outFile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" 
         << setw(6) << "----" << setw(6) << "---" << setw(6) << "----"  
         << setw(7) << "-----" << "-------" << endl; 
	 
	
	// formatting Max Line
	outFile << left << fixed << setprecision(2) << setw(3) << " " << setw(12) << lastName << setw(7) << firstName << setw(6) << sumQuiz << setw(6)
			<< sumHw << setw(6) << sumExam << setw(7) << maxTotal << average << endl;                
	outFile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" 
         << setw(6) << "----" << setw(6) << "---" << setw(6) << "----"  
         << setw(7) << "-----" << "-------" << endl;
	
	
	//Priming read  
	inFile >> lastName;
	
	//check if no students be der
	if (inFile.eof())
	{
		outFile << "Input file did not contain any students" << endl;
		cout <<  "Input file did not contain any students" << endl;
		return 1; 
	}
	
	// fancy long loop that lets me do it many times
	counter = 0;
	int total = 0;
	float classAverage; 
	float sumAverage;
	while(!inFile.eof())  	
	{	
		line = line + 1;
		inFile >> firstName;
		counter = 0;
		sumQuiz = 0;
		while(counter < numQuiz)  
			{
				inFile >> num;
				sumQuiz = num + sumQuiz;
				counter ++;		 
			}
		counter = 0;
		sumHw =0;
		while(counter < numHw)  
			{
				inFile >> num;
				sumHw = num + sumHw;
				counter ++; 
			}
		counter = 0;
		sumExam = 0; 
		while(counter < numExam)  
			{
				inFile >> num;
				sumExam = num +  sumExam;
				counter ++;  
			}
			total = sumQuiz + sumHw + sumExam; 
			average = (float(total)/maxTotal)*100;
			sumAverage = average + sumAverage;
			classAverage = sumAverage/line;
			
			outFile << left << fixed << setprecision(2) << setw(3) << line << setw(12) << lastName.substr(0,10) << setw(7) << firstName.substr(0,5) << setw(6) << sumQuiz << setw(6)
			<< sumHw << setw(6) << sumExam << setw(7) << total << average << endl;
			inFile >> lastName;	
	}
	 
			
	//formatting rest
	outFile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" 
         << setw(6) << "----" << setw(6) << "---" << setw(6) << "----"  
         << setw(7) << "-----" << "-------" << endl << endl;
	outFile << "Class Average = " << classAverage << endl;
	


 return 0;
}