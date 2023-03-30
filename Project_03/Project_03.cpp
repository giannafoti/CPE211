// ****************************************
// Program Title: Project 3
// Project File: Project_03.cpp
// Name: Gianna Foti
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 01/29/23
// program description: Stonks Calculations
// ****************************************
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	
// Variables
		
	string stock;
	int nshares;
	float bprice;
	float sprice;
	float commission; 
	float costofpurchase; 
	float sellcommission;
	float totalreturn;
	float netpl;
	float taxcredit; 
	
	cout << endl;
	cout << string(25, '*') <<endl; 
	cout << "Stock Calculations" <<endl;
	cout << string(25, '*') <<endl;
	cout << endl;

// Inputs	
	cout << "Enter the name of the stock: ";
	cin >> stock;
	cout << stock << endl;
	
	
	cout << "Enter the number of shares purchased: ";
	cin >> nshares;
	cout << nshares << endl;
	
	
	cout << "Enter the buy price per share: ";
	cin >> bprice;
	cout << fixed << setprecision(2);
	cout << bprice << endl;
	
	
	cout << "Enter the sell price per share: ";
	cin >> sprice;
	cout << fixed << setprecision(2);
	cout << sprice << endl;
	cout << endl;
	
	cout << "Results for " << nshares << " shares of " << stock << ":" <<endl;
	cout << string(35, '-') <<endl; 
	
// Calculations	
	commission = nshares*bprice*.02;
	costofpurchase = bprice*nshares+commission;
	sellcommission = nshares*sprice*.015;
	totalreturn = sprice*nshares- sellcommission;
	netpl = totalreturn - costofpurchase;
	taxcredit = netpl *.25;

// Results
	cout << setfill('.') << left ;
	cout << setw(20) << "Buy Commission" << "$" << commission << endl;		
	cout << setw(20) << "Total Cost" << "$" << costofpurchase << endl;	
	cout << setw(20) << "Sell Commission" << "$" << sellcommission << endl;
	cout << setw(20) << "Total Return" << "$" << totalreturn << endl; 
	cout << setw(20) << "Net Profit/Loss" << "$" << netpl << endl;
	cout << setw(20) << "Tax/Credit" << "$" << taxcredit << endl;
	cout << endl;
	
			
 return 0;
}