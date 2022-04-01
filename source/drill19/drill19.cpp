#include "std_lib_facilities.h"

template<typename T>
struct S { 

	S() {};
	S(T v) : val{ v } {};
	T& get();
	const T& get() const;

	T& set(const T&);
	T& operator=(const T&);

private:
	T val; 
};

template<typename T>
T& S<T>::get() {
	return val;
}

template<typename T>
const T& S<T>::get() const {
	return val;
}

template<typename T>
T& S<T>::set(const T& s) {
	return val=s;
}

template<typename T>
T& S<T>::operator=(const T& s) {
	return val = s;
}

template<typename T> 
void read_val(T& v) {
	cin >> v;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
	char ch = 0;
	T val;

	is >> ch;
	if (ch != '{') {
		is.unget();
		return is;
	}
	while (is >> val >> ch) {
		v.push_back(val);
		if (ch != ',') break;
	}
	if (ch != '}') {
		error("Format error");
	}

	return is;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{ ";
	for (int i = 0; i < v.size(); i++) {
		os << v[i];
		if (i + 1 < v.size()) os << ',';
		os << " ";
	}
	os << "}";
	return os;
}

int main() {
	S<int> int_S(5);
	S<char> char_S('$');
	S<double> double_S(0.5);
	S<string> string_S("Sajt");
	S<vector<int>> vector_S(vector<int>{ 1,2,3,4,5 });
	/*
	cout << int_S.val << endl;
	cout << char_S.val << endl;
	cout << double_S.val << endl;
	cout << string_S.val << endl;
	cout << "{ ";
	for (int i = 0; i < vector_S.val.size(); i++)
		cout << vector_S.val[i] << ", ";
	cout << "}\n";
	*/

	cout << int_S.get() << endl;
	cout << char_S.get() << endl;
	cout << double_S.get() << endl;
	cout << string_S.get() << endl;
	cout << "{";
	for (int i = 0; i < vector_S.get().size(); i++) {
		cout << vector_S.get()[i];
		if (i + 1 < vector_S.get().size()) cout << ", ";
	}
	cout << "}\n";

	cout << "intput int: ";
	int i;
	read_val(i);
	int_S = i;

	cout << "intput char: ";
	char c;
	read_val(c);
	char_S = c;

	cout << "intput double: ";
	double d;
	read_val(d);
	double_S = d;

	cout << "intput string: ";
	string s;
	read_val(s);
	string_S = s;

	cout << int_S.get() << endl;
	cout << char_S.get() << endl;
	cout << double_S.get() << endl;
	cout << string_S.get() << endl;

	cout << "input vector<int> (example: {1,2,3} ): ";
	vector<int> v_i;
	read_val(v_i);
	vector_S = v_i;

	cout << vector_S.get() << endl;

	return 0;
}