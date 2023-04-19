// ****************************************
// Program Title: Sample header file
// Project File: Project_10.cpp
// Name: Gianna Foti
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 04/21/23 
// program description: Description of 
// What the program does.
// ****************************************


// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 10
// all helper function definitions go in this file

// all header files are in the project_10.h header file
#include "Project_10.h"

// using namespace std is in the header file Project_10.h

// **************************************************************
// **********  DO NOT MODIFY ANYTHING ABOVE THIS LINE
// **************************************************************

// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
// **************************************************************

// Function definitions start here. 

// *****************************************
// ************** CONTRUCTORS **************
// *****************************************
Money::Money()
{
	pennies = 0; 
	nickels = 0; 
	dimes = 0; 
	quarters =0; 
}
Money::Money(int p, int n, int d, int q) 
{
	pennies = p; 
	nickels = n;
	dimes = d;
	quarters = q; 
	
}     
Money::Money(int p, int n, int d)
{
	
	pennies = p; 
	nickels = n;
	dimes = d;
	quarters = 0; 
}   
Money::Money(int p, int n)
{
	pennies = p; 
	nickels = n;
	dimes = 0; 
	quarters =0;  
}      
Money::Money(int p)
{
	pennies = p;
	nickels = 0;
	dimes = 0; 
	quarters =0;
}     



// *****************************************
// ************** TRANSFORMERS **************
// *****************************************
void Money::SetMoney(int p, int n, int d, int q)
{
	pennies = p; 
	nickels = n;
	dimes = d;
	quarters = q;  
} 
void Money::AddMoney(int p, int n, int d, int q)
{
	pennies = pennies + p;
	nickels = nickels + n;
	dimes = dimes + d;
	quarters = quarters + q;  
	
} 
void Money::AddMoney(int p, int n, int d)
{
	pennies = pennies + p; 
	nickels = nickels + n;
	dimes = dimes + d;
} 
void Money::AddMoney(int p, int n)
{
	pennies = pennies + p; 
	nickels = nickels + n;
} 
void Money::AddMoney(int p)
{
	pennies = pennies + p; 
} 
		

// *****************************************
// ************** OBSERVERS *******************
// *****************************************
void Money::WriteCoinTotals() const
{
	cout << "Number of Pennies: " << pennies << endl; 
	cout << "Number of Nickels: " << nickels << endl; 
	cout << "Number of Dimes: " << dimes << endl;
	cout << "Number of Quarters: " << quarters << endl;  
	return;
}	
void Money::WriteDollarTotal() const
{
	float dollarTotal;
	dollarTotal = (pennies *.01) + (nickels *.05) + (dimes *.10) + (quarters *.25);
	cout << fixed << setprecision(2) << "The dollar amount of the coins is: $" << dollarTotal << endl; 
}	

