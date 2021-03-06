/*Computes how much a customer has to pay after purchasing two items.*/

#include "stdafx.h"
#include <iostream>
using namespace std;
const double MEMBERDISCOUNT = 0.9,PROMOTIONDISCOUNT = 0.5;

int main()
{
	double	price1, price2, taxRate,promotionPrice, priceAfterDiscounts, totalPrice;
	char ismember;

	//input
	cout << "Enter price of first item: ";
	cin >> price1;
	cout << "Enter price of second item: ";
	cin >> price2;
	cout << "Does customer have a club card?(Y/N): ";
	cin >> ismember;
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> taxRate;

	//control flow
	//Compute the promotion price
	if (price1<price2)
	{
		promotionPrice = price1 * PROMOTIONDISCOUNT + price2;
	}
	else
	{
		promotionPrice = price2 * PROMOTIONDISCOUNT + price1;
	}
	//Compute the price of membership discount
	if (ismember == 'y')
	{
		priceAfterDiscounts = promotionPrice * MEMBERDISCOUNT ;
		
	}
	else if (ismember == 'n')
	{
		priceAfterDiscounts = promotionPrice  ;

	}

	//compute the total price after tax
	totalPrice = priceAfterDiscounts * (100 + taxRate) / 100;
	//output
	cout << "Base price: " << price1 + price2 << endl;
	cout << "Price after discounts: " << priceAfterDiscounts << endl;
	cout << "Total price: " << totalPrice << endl;
    return 0;
}

