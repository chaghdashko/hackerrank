/*
 * main.cpp
 *
 *  Created on: 4 Tem 2016
 *      Author: cagdasko
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double mealCost;
	int tipPercent;
	int taxPercent;
	int totalCost;
	double tipAmount;
	double taxAmount;

	cin >> mealCost >> tipPercent >> taxPercent;

	tipAmount = mealCost * ((float) tipPercent / 100);
	taxAmount = mealCost * ((float) taxPercent / 100);

	totalCost = round(mealCost + tipAmount + taxAmount);

	cout << "The total meal cost is " << totalCost << " dollars." << endl;

	return 0;
}


