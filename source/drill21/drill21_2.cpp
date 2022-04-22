#include "std_lib_facilities.h"
#include<map>
#include <numeric>

void read(map<string,int>& map)
{
	string name;
	int value;
	cin >> name >> value;
	map.insert(pair<string,int>(name,value));
}

int main() {
	map<string, int> msi;

	msi["apple"] = 2; // input 10 map entries
	msi["cheese"] = 6;
	msi["spoon"] = 5;
	msi["tree"] = 1;
	msi["duck"] = 11;
	msi["door"] = 17;
	msi["zebra"] = 92;
	msi["lamp"] = 16;
	msi["green"] = 9;
	msi["beta"] = 4;

	cout << "Msi original map pairs:\n"; // output map entries
	for (const auto& i : msi)
		cout << i.first << " " << i.second << endl;
	cout << endl;

	msi.erase(msi.begin(), msi.end()); // erase map entries

	cout << "input 10 map<string,int> pairs (example: a 1 b 2 c 3 ...):" << endl;
	for (int i = 0; i < 10; i++) { // input 10 map entries
		read(msi);
	}

	cout << "Msi input map pairs:\n"; // output map entries
	for (const auto& i : msi)
		cout << i.first << " " << i.second << endl;
	cout << endl;

	int sum = accumulate(msi.begin(), msi.end(), 0, // msi map sum
		[](auto prev_sum, auto& msi_entry) {return prev_sum + msi_entry.second; });

	cout << "Msi map sum: " << sum << endl;

	map<int, string> mis;

	vector<pair<int, string>> map_vec; // vector for help

	for (const auto& i : msi) { // msi map pairs swapped into the vector
		map_vec.push_back(make_pair(i.second, i.first));
	}
	
	for(int i = 0; i < map_vec.size(); i++) //vector pairs into mis map
		mis.insert(map_vec[i]);

	cout << "Mis map pairs:\n"; // mis map entries
	for (const auto& i : mis)
		cout << i.first << " " << i.second << endl;
	cout << endl;

	return 0;
}