#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
Iter2 Copy(Iter1 f1, Iter1 e1, Iter2 f2) {
	while (f1!=e1) {
		*f2 = *f1;
		++f2;
		++f1;
	}
	return f2;
}


int main() {
	
	array<int,10> a1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	array<int,10> a2 = a1;
	vector<int> v2 = v1;
	list<int> l2 = l1;
	
	cout << "Array:";
	for (int& i : a1)
		cout << " " << i;
	cout << "\n";
	cout << "Vector:";
	for (int& i : v1)
		cout << " " << i;
	cout << "\n";
	cout << "List:";
	for (int& i : l1)
		cout << " " << i;
	cout << "\n\n";

	//value increases
	cout << "Increase Array value by 2.\n";
	for (int& i : a1) 
		i += 2;
	cout << "Increase Vector value by 3.\n";
	for (int& i : v1)
		i += 3;
	cout << "Increase List value by 5.\n\n";
	for (int& i : l1)
		i += 5;

	cout << "Array after increase:";
	for (int& i : a1)
		cout << " " << i;
	cout << "\n";
	cout << "Vector after increase:";
	for (int& i : v1)
		cout << " " << i;
	cout << "\n";
	cout << "List after increase:";
	for (int& i : l1)
		cout << " " << i;
	cout << "\n\n";

	//copy array into vector and list into array
	Copy(a1.begin(), a1.end(), v1.begin());
	cout << "Array copied into Vector.\n";
	Copy(l1.begin(), l1.end(), a1.begin());
	cout << "List copied into Array.\n\n";

	cout << "Array after copies:";
	for (int& i : a1)
		cout << " " << i;
	cout << "\n";
	cout << "Vector after copies:";
	for (int& i : v1)
		cout << " " << i;
	cout << "\n";
	cout << "List after copies:";
	for (int& i : l1)
		cout << " " << i;
	cout << "\n\n";

	//find 3 in vector
	vector<int>::iterator p_3 = find (v1.begin(), v1.end(), 3);
	if (p_3 != v1.end())
		cout << "The Vector contains value 3 in position: " << distance(v1.begin(), p_3) << "\n"
		<< "(The position of the first element is 0)\n";
	else
		cout << "The Vector doesn't contain value 3.\n";

	//find 27 in list
	list<int>::iterator p_27 = find(l1.begin(), l1.end(), 27);
	if (p_27 != l1.end())
		cout << "The List contains value 27 in position: " << distance(l1.begin(), p_27) << "\n"
		<< "(The position of the first element is 0)\n";
	else
		cout << "The List doesn't contain value 27.\n";

	return 0;
}