// ****************************************
// Program Title: Project_08
// Project File: Project_08.cpp
// Name: Gianna Foti
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 4/9/23 
// program description: Description of 
// What the program does.
// ****************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

//function prototypes;
bool readInput(ifstream&, float[], int&, float&);
void sortLH(float[], int&);
void calculateAvg(float[], int&, float&);
void calculateMed(float[], int&, float&);
void calculateVar(float[], int&, float&);
void OpenInputFile(ifstream&); 


int main() 
{
	ifstream inFile;
    string filename;
	float myArray[50];
	int num; 
	float median;
	float average;
	float value;
	float variance;
	float STD;
   
	OpenInputFile(inFile);
	
	if (readInput(inFile, myArray, num, value))
	{
	 
		sortLH(myArray,num);
		calculateAvg(myArray,num,average);
		calculateMed(myArray, num, median);
		calculateVar(myArray, num, variance);
		STD = sqrt(variance);

		cout << string(15, '*') << " File Statistics " << string(15, '*') << endl;
		cout << string(47, '*') << endl;
		cout << setfill('.') << left ;
		cout << setw(25) << "Number of Values"<< num << endl;		
		cout << setw(25) << "Average" << average << endl;	
		cout << setw(25) << "Median" << median << endl;
		cout << setw(25) << "Variance" << variance << endl; 
		cout << setw(25) << "Standard Deviation"<< STD << endl;
		cout << string(47, '*') <<endl; 
		cout << endl;

	}
    
    return 0;
}
//Opening Input File
void OpenInputFile(ifstream& inFile)
{
	string filename;
	
	cout << endl;
	cout << "Enter the name of the input file (ctrl-c to exit): ";
	cin >> filename;
	cout << filename << endl << endl;  
	inFile.open(filename.c_str());  
	 
	
	while (inFile.fail())  
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file could not be opened." << endl;
		cout << "==> " << filename << " is an invalid file!!"  << endl;
		cout << "==> Try Again." << endl;
		cout << string(47, '*') << endl << endl;
		
		inFile.clear();
		cout << "Enter the name of the input file (ctrl-c to exit): ";
		cin >> filename;
		
		cout << filename << endl << endl;   
		inFile.open(filename.c_str());
	}
}
 
//reading array 
bool readInput (ifstream& inFile, float myArray[], int& num, float& value)
{
	inFile >> num;
	if(inFile.eof())
	{
		cout << string(15,'*') << " Empty Input File " << string(14,'*') << endl;
		cout << "==> Input file is empty." << endl;
		cout << "==> Program terminated." << endl;
		cout << string(47, '*') << endl << endl;
		return false;
	}
	if (!inFile)
	{
		cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		cout << "==> Error occurred reading the number of values" << endl;
		cout << "==> present in the input file."  << endl;
		cout << "==> Program terminated." << endl;
		cout << string(47, '*') << endl << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < num; i++) 
		{
        	inFile >> value;
			if (!inFile)
			{
				if(inFile.eof())
				{
					cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
					cout << "==> Error occurred trying to read in number #" << i + 1 << endl;
					cout << "==> Number was not present in the input file." << endl;
					cout << "==> Program terminated." << endl;
					cout << string(47, '*') << endl << endl;
					return false;
				}
				cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
				cout << "==> Error occurred reading in number #" << i + 1 << endl;
				cout << "==> Invalid Character found in file." << endl;
				cout << "==> Program terminated." << endl;
				cout << string(47, '*') << endl << endl;
				return false;
						
			}
			
			myArray[i] = value;	
		}
	}
	return true;
}
		
	
		
		

//sorting array from low to high <3
void sortLH(float myArray[], int& num) 
{
	float t;
    for (int i = 0; i < num; i++) 
		{
        for (int j = i + 1; j < num; j++) 
			{
            if (myArray[j] < myArray[i]) 
				{
                t = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = t;
            	}
        	}
    	}
}

//calculating average
void calculateAvg (float myArray[], int& num, float& average)
{

	float sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += myArray[i];
	}
	average = sum/num; 
	
}


// calculating median
void calculateMed(float myArray[], int& num, float& median)
{ 
	int index;
	index = num/2;
	
	if (num%2 == 0)
	{
		median = (myArray[index] + myArray[index - 1]) / 2.0;;
		
	}
	else
	{
		median = myArray[index];
		 
	}
}


//calculating variance
void calculateVar(float myArray[], int& num, float& variance)
{
	float sum = 0.0;
    float mean = 0.0;

    // Calculate the mean
    for (int i = 0; i < num; i++) {
        sum += myArray[i];
    }
    mean = sum / num;

    // Calculate the variance
    for (int i = 0; i < num; i++) {
        variance += pow(myArray[i] - mean, 2);
    }
    variance = variance/num;

}



