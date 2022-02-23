#include <iostream>
using namespace std;

int max_mas(int A[], int i, int max, int max2) {
	if (i < 0) return max2;
	if (A[i] > max) {
		max2 = max;
		max = A[i];
	}
	else if (A[i] > max2) {
		max2 = A[i];
	}
	max_mas(A, i - 1, max, max2);
}
int main() {
	const int n = 5;
	int A[n];
	cout << "Size of array: " << n << endl << "Enter values: ";
	for (int i = 0; i < n; i++)
		cin >> A[i];  
	int max = INT_MIN;
	int max2 = INT_MIN;
	cout << "Second highest value in array: " << max_mas(A, n - 1, max, max2);
	return 0;
}