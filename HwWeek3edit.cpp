// Author: Benjamin Foreman
// Date: 3/30/21
// Description: program that calculates shipping costs based on detination, order total, and if item is fragile; then displays results.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// constants for various prices
const double STARTING_SHIP_COST = 0.0;
const double FRAGILE_CHARGE = 2.00;
const double ORDER_MIN_VALUE = 50.00;
const double ORDER_MID_VALUE = 100.00;
const double ORDER_MAX_VALUE = 150.00;
const double USA_MIN_CHARGE = 6.00;
const double USA_MID_CHARGE = 9.00;
const double USA_MAX_CHARGE = 12.00;
const double CAN_MIN_CHARGE = 8.00;
const double CAN_MID_CHARGE = 12.00;
const double CAN_MAX_CHARGE = 15.00;
const double AUS_MIN_CHARGE = 10.00;
const double AUS_MID_CHARGE = 14.00;
const double AUS_MAX_CHARGE = 17.00;
const double EUROPA_MIN_CHARGE = 4'000'000'000.00;
const double EUROPA_MID_CHARGE = 4'100'000'000.00;
const double EUROPA_MAX_CHARGE = 4'200'000'000.00;
// constants for formatting
const int BLOCK_FORMAT_1 = 51;
const int BLOCK_FORMAT_2 = 41;


int main()
{
	// top banner
	cout << setfill('.') << setw(53) << "\n"
		<< "ITCS 2530 - Programming Assignment for Week #3" << endl
		<< setw(53) << "\n" << endl << endl;

	// first line of user input
	cout << left << setw(BLOCK_FORMAT_1) << "Please enter the item name (no spaces)" << ":";
	string item;
	cin >> item;

	//second line of user input
	cout << setw(BLOCK_FORMAT_1) << "Is the item fragile? (y=yes/n=no)" << ":";
	char fragile;
	cin >> fragile;
	double shippingCost = STARTING_SHIP_COST;

	// switch to verify user input either y or n, defaults to closing program
	switch (fragile)
	{
	case 'y':
	case 'Y':
		shippingCost += FRAGILE_CHARGE;
		break;
	case 'n':
	case 'N':
		break;
	default:
		cout << "Invalid entry, exiting" << endl;
		system("pause");
		return 0;
	}

	// third line of user input
	cout << setw(BLOCK_FORMAT_1) << "Please enter your order total" << ":";
	double orderTotal;
	cin >> orderTotal;

	// fourth line of user input
	cout << setw(BLOCK_FORMAT_1) << "Please enter destination. (usa/can/aus/europa)" << ":";
	string dest;
	cin >> dest;
	transform(dest.begin(), dest.end(), dest.begin(), ::toupper);


	// verify if user input usa, can, or aus; closes program if not
	if (dest != "USA" && dest != "CAN" && dest != "AUS" && dest != "EUROPA")
	{
		cout << "Invalid entry, exiting" << endl;
		system("pause");
		return 0;
	}

	// nested if..else statements adding shipping cost based on order value and destinantion
	if (orderTotal < ORDER_MIN_VALUE)
	{
		if (dest == "USA")
			shippingCost += USA_MIN_CHARGE;
		else if (dest == "CAN")
			shippingCost += CAN_MIN_CHARGE;
		else if (dest == "AUS")
			shippingCost += AUS_MIN_CHARGE;
		else if (dest == "EUROPA")
			shippingCost += EUROPA_MIN_CHARGE;
	}
	else if (orderTotal > ORDER_MIN_VALUE && orderTotal <= ORDER_MID_VALUE)
	{
		if (dest == "USA")
			shippingCost += USA_MID_CHARGE;
		else if (dest == "CAN")
			shippingCost += CAN_MID_CHARGE;
		else if (dest == "AUS")
			shippingCost += AUS_MID_CHARGE;
		else if (dest == "EUROPA")
			shippingCost += EUROPA_MID_CHARGE;
	}
	else if (orderTotal > ORDER_MID_VALUE && orderTotal <= ORDER_MAX_VALUE)
	{
		if (dest == "USA")
			shippingCost += USA_MAX_CHARGE;
		else if (dest == "CAN")
			shippingCost += CAN_MAX_CHARGE;
		else if (dest == "AUS")
			shippingCost += AUS_MAX_CHARGE;
		else if (dest == "EUROPA")
			shippingCost += EUROPA_MAX_CHARGE;
	}
	else if (orderTotal > ORDER_MAX_VALUE) 
	{
		if (dest == "EUROPA")
			shippingCost += EUROPA_MAX_CHARGE;
	}

	transform(item.begin(), item.end(), item.begin(), ::toupper);

	//five lines of formatted output, including shipping costs and final total
	cout << setprecision(2) << fixed << endl;
	cout << setw(BLOCK_FORMAT_2) << "Your item is" << item << endl
		<< setw(BLOCK_FORMAT_2) << "Your shipping cost is" << "$" << shippingCost << endl
		<< setw(BLOCK_FORMAT_2) << "You are shipping to" << dest << endl
		<< setw(BLOCK_FORMAT_2) << "Your total shipping costs are" << "$" << shippingCost + orderTotal << endl << endl;

	cout << setw(BLOCK_FORMAT_2) << setfill('-') << "-" << "Thank You!" << endl << endl;

	ofstream outFile;
	outFile.open("Order.txt");
	outFile << setfill('.') << left;
	outFile << setw(BLOCK_FORMAT_2) << "Your item is" << item << endl
		<< setw(BLOCK_FORMAT_2) << "Your shipping cost is" << "$" << shippingCost << endl
		<< setw(BLOCK_FORMAT_2) << "You are shipping to" << dest << endl
		<< setw(BLOCK_FORMAT_2) << "Your total shipping costs are" << "$" << shippingCost + orderTotal << endl << endl;
	outFile.close();

	system("pause");
	return 0;

}

