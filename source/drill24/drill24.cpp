#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include<numeric>
#include<cmath>
#include<complex>
using namespace Numeric_lib;

void sqrt_of_input() { // 4
	int i;
	cout << "Input an int: ";
	cin >> i;
	if (i < 0)
		cout << "no square root" << endl;
	else
		cout << "square root: " << sqrt(i) << endl;
}

int main() {

	cout << "Size of char: " << sizeof(char) << endl; // 1
	cout << "Size of short: " << sizeof(short) << endl;
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of long: " << sizeof(long) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of double*: " << sizeof(double*) << endl;

	Matrix<int> a(10); // 2
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);

	cout << "\nMatrix sizes: \n\n"; 
	cout << "Size of Matrix<int> a(10): " << sizeof(a) << endl;
	cout << "Size of Matrix<int> b(100): " << sizeof(b) << endl;
	cout << "Size of Matrix<double> c(10): " << sizeof(c) << endl;
	cout << "Size of Matrix<int, 2> d(10, 10): " << sizeof(d) << endl;
	cout << "Size of Matrix<int, 3> e(10, 10, 10): " << sizeof(e) << endl;

	cout << "\nNumber of matrix elements: \n\n"; // 3
	cout << "Number of Matrix<int> a(10) elements: " << a.size() << endl;
	cout << "Number of Matrix<int> b(100) elements: " << b.size() << endl;
	cout << "Number of Matrix<double> c(10) elements: " << c.size() << endl;
	cout << "Number of Matrix<int, 2> d(10, 10) elements: " << d.size() << endl;
	cout << "Number of Matrix<int, 3> e(10, 10, 10) elements: " << e.size() << endl;

	cout << "\nSquare input function test: \n"; // 4
	sqrt_of_input();

	cout << "\nMatrix of 10 doubles: \n"; // 5
	Matrix<double> d10(10);
	cout << "Enter 10 float numbers: \n";
	for (int i = 0; i < 10; i++)
		cin >> d10(i);
	cout << d10 << endl;

	cout << "\nEnter the dimensions of (n,m) multiplication table: "; // 6
	int n, m;
	cin >> n >> m;

	Matrix<double, 2> n_m_table(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			n_m_table(i, j) = i * j;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cout << n_m_table(i, j) << ' ';
		cout << endl;
	}

	cout << "\nMatrix of 10 complex<doubles>: \n"; // 7
	Matrix<complex<double>> c10(10);
	cout << "Enter 10 complex numbers: \n";
	for (int i = 0; i < 10; i++)
		cin >> c10(i);
	complex<double> sum = accumulate(c10.data(), c10.data() + c10.size(), complex<double>{});
	cout << "Sum of complex Matrix: " << sum << endl;

	cout << "\nFill up Matrix(2, 3): \n"; // 8
	Matrix<int, 2> matrix_m(2, 3);
	cout << "Enter 6 integers: \n";

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> matrix_m(i, j);

	cout << "\nMatrix(2, 3): \n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << matrix_m(i, j) << ' ';
		cout << endl;
	}
	return 0;
}