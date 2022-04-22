#include "std_lib_facilities.h"

struct Item { 
	string name; 
	int iid; 
	double value;
};

istream& operator>>(istream& is, Item& it) {
	string s;
	int i;
	double d;

	is >> s >> i >> d;
	Item item{ s, i, d };
	it = item;

	return is;
}

ostream& operator<<(ostream& os, Item& it) {
	os << it.name << ' ' << it.iid << ' ' << it.value << endl;
	return os;
}

template<typename T>
void print(string s, T& t)
{
	cout << s << endl;
	for (auto i = t.begin(); i != t.end(); i++)
		cout << *i;
	cout << endl;
}

struct Compare_by_Name {
	bool operator()(const Item& a, const Item& b) const
	{ return a.name < b.name; }
};
struct Compare_by_Id {
	bool operator()(const Item& a, const Item& b) const
	{ return a.iid < b.iid; }
};
struct Compare_by_Value {
	bool operator()(const Item& a, const Item& b) const
	{ return a.value < b.value; }
};

int main() {
	string iname{"Item_1.txt"};
	ifstream ist_vector{ iname };
	if (!ist_vector) error("can't find input file ", iname);

	vector<Item> vi;
	for (Item i; ist_vector >> i;)
		vi.push_back(i);

	print("Vector after text input:", vi);

	sort(vi.begin(), vi.end(), Compare_by_Name()); // sort by name

	print("Vector after sorting by name:", vi);

	sort(vi.begin(), vi.end(), Compare_by_Id()); // sort by id

	print("Vector after sorting by id:", vi);

	sort(vi.begin(), vi.end(), Compare_by_Value()); // sort by value

	print("Vector after sorting by value:", vi);

	Item horse_shoe{ "horse shoe",99,12.34 }; // insert 2 Item
	Item Canon{ "Canon S400", 9988, 499.95 };
	vi.insert(vi.begin(), horse_shoe);
	vi.insert(vi.begin(), Canon);

	print("Vector after inserting two items:", vi);

	string name; // erase by name
	name = "apple";
	vi.erase(find_if(vi.begin(), vi.end(), [name](const Item& a) {return a.name == name; }));
	name = "zebra";
	vi.erase(find_if(vi.begin(), vi.end(), [name](const Item& a) {return a.name == name; }));

	print("Vector after erasing apple and zebra:", vi);

	int id; // erase by id
	id = 1;
	vi.erase(find_if(vi.begin(), vi.end(), [id](const Item& a) {return a.iid == id; }));
	id = 99;
	vi.erase(find_if(vi.begin(), vi.end(), [id](const Item& a) {return a.iid == id; }));

	print("Vector after erasing id 1 and id 99:", vi);

	// List
	ifstream ist_list{ iname };
	if (!ist_list) error("can't find input file ", iname);

	list<Item> li;
	for (Item i; ist_list >> i;)
		li.push_back(i);

	print("List after text input:", li);

	li.sort(Compare_by_Name()); // sort by name

	print("List after sorting by name:", li);

	li.sort(Compare_by_Id()); // sort by id

	print("List after sorting by id:", li);

	li.sort(Compare_by_Value()); // sort by value

	print("List after sorting by value:", li);

	li.insert(li.begin(), horse_shoe); // insert 2 Item
	li.insert(li.begin(), Canon);

	print("List after inserting two items:", li);

	name = "apple"; // erase by name
	li.erase(find_if(li.begin(), li.end(), [name](const Item& a) {return a.name == name; }));
	name = "zebra";
	li.erase(find_if(li.begin(), li.end(), [name](const Item& a) {return a.name == name; }));

	print("List after erasing apple and zebra:", li);

	id = 1; // erase by id
	li.erase(find_if(li.begin(), li.end(), [id](const Item& a) {return a.iid == id; }));
	id = 99;
	li.erase(find_if(li.begin(), li.end(), [id](const Item& a) {return a.iid == id; }));

	print("List after erasing id 1 and id 99:", vi);

	return 0;
}