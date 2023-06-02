#include"Sale.h"
#include<iostream>
#include <string>

using namespace std;

int main()
{
	double pri1, pri2;

	cout << "=========================================" << endl;
	cout << "Price Compare Program" << endl;
	cout << "=========================================" << endl;

	cout << "Insert item1 price: $";
	cin >> pri1;
	cout << "Insert item2 price: $";
	cin >> pri2;
	cout << endl;

	string dis;
	cout << "-----------------------------------------" << endl;
	cout << "Insert discount percent: ";
	cin >> dis;
	cout << "-----------------------------------------" << endl;
	double disp;

	for (int i = 0; i < dis.length(); i++) {
		if (dis[i] == '%') {
			dis[i] = '\0';
			break;
		}
	}
	disp = stod(dis);  // double형으로 형변환

	DiscountSale item1(pri1, disp);
	DiscountSale item2(pri2, disp);

	cout << "Result:" << endl;
	if (item1 < item2) {     
		cout << "Discount price of item1 is cheaper" << endl;
		cout << "Saving discount price is $" << item1.Savings(item2) <<endl;

	}
	else {
		cout << "Discount price of item2 is cheaper" << endl;
		cout << "Saving discount price is $" << item2.Savings(item1) << endl;
	}

	double tmep = item2.Savings(item1);

	return 0;
}