#include <iostream>
using namespace std;

void num(int number) {
	if (number) {
		num(number / 10);
		cout << number % 10;
	}
}
int rec(int number) {
	if (number > 10) return 1 + rec(number / 10);
	return 1;
}
int sum(int number) {
	if (number / 10) return number % 10 + sum(number / 10);
	else return number % 10;
}
int main() {
	int number;
	while (true) {
		cout << "Enter natural number: ";
		cin >> number;
		if (number > 0) {
			cout << "Recursive output of entered number: ";
			num(number);
			cout << endl;
			cout << "Recursive output digits of number: " << rec(number) << endl;
			cout << "Recursive output sum of digits: " << sum(number);
			break;
		}
		else {
			cout << "Wrong value! Please enter again: " << endl;
		}
	}
	return 0;
}