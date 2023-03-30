// ****************************************
// Program Title: Project 4
// Project File: Project_04.cpp
// Name: Gianna Foti
// Course Section: CPE-211-01
// Lab Section: 4 
// Due Date: 02/06/23 
// program description: Calculating Initial Velocity and starting angles in degrees
// ****************************************
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	// Variables
	const double gravity = 9.80665;
	const double PI = 3.14159265; 
	double iVelocity;
	double tMaxHeight;
	double tProHitGround;
	double maxHeight;
	double totDistance;
	double startingAngle;
	string titleLine;
	double sAngleinRadians;
	
	
	// Inputs
	cout << endl;
	cout << string(31, '*') <<endl; 
	cout << string (6, '*') << " Projectile Motion "<< string (6, '*')<<endl;
	cout << string(31, '*') <<endl;
	cout << endl;
	 	
	cout << "Enter the title line information: ";
	getline(cin, titleLine);
	cout << titleLine << endl;
	
	cout << "Enter in the velocity (in meters/sec): ";
	cin >> iVelocity;
	cout << fixed << setprecision(3);
	cout << iVelocity << endl;	
	
	cout << "Enter in the angle (in degrees): ";
	cin >> startingAngle;
	cout << fixed << setprecision(3);
	cout << startingAngle << endl;
	cout << endl;
	
	// Calculations
	sAngleinRadians = ((startingAngle)*(PI))/180;
	tMaxHeight = ((iVelocity)*sin(sAngleinRadians))/(gravity);
	tProHitGround = ((2)*(iVelocity)*(sin(sAngleinRadians)))/(gravity);
	maxHeight = (pow(iVelocity, 2)*pow(sin(sAngleinRadians),2))/((2)*(gravity));
	totDistance = iVelocity*tProHitGround*cos(sAngleinRadians);
	
	// Results
	cout << "Results for "<< titleLine << ":" <<endl;
	cout << string (13+ titleLine.length(), '-') << endl; 
	cout << setfill(' ') << left ;
	cout << setw(25) << "Initial Velocity:" << iVelocity << " meters/second" << endl;		
	cout << setw(25) << "Starting Angle:" << startingAngle << " degrees" << endl;
	cout << setw(25) << "Time to Max Height:" << tMaxHeight << " seconds" << endl;
	cout << setw(25) << "Time to Max Distance:" << tProHitGround << " seconds" << endl;
	cout << setw(25) << "Maximum Height:" << maxHeight << " meters" << endl;
	cout << setw(25) << "Maximum Distance:" << totDistance << " meters" << endl;
	cout << endl;
}