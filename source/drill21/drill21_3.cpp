#include "std_lib_facilities.h"
#include<algorithm>

int main() {
	string iname{ "Float_1.txt" };
	ifstream ist{ iname };
	if (!ist) error("can't find input file ", iname);

	vector<double> vd;
	for (double i; ist >> i;)
		vd.push_back(i);

	cout << "VD vector: " << endl;
	for (int i = 0; i < vd.size(); i++)
		cout << vd[i] << " ";
	cout << "\n\n";

	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin()); // copy vd into vi

	cout << "(VD,VI) vector pairs: " << endl; // output vd-vi pairs
	for (int i = 0; i < vd.size(); i++)
		cout << "( " << vd[i] << " , " << vi[i] << " )\n";
	cout << endl;

	double sum_vd = 0; // vd sum
	for (int i = 0; i < vd.size(); i++)
		sum_vd += vd[i];
	cout << "VD vector Sum: " << sum_vd << endl;

	int sum_vi = 0; // vi sum
	for (int i = 0; i < vi.size(); i++)
		sum_vi += vi[i];
	cout << "VI vector Sum: " << sum_vi << endl;

	double vd_vi_diff = abs(sum_vd - sum_vi); // vd vi sum diff
	cout << "VD - VI vector Sum difference: " << vd_vi_diff << "\n\n";

	reverse(vd.begin(), vd.end()); // reverse vd

	cout << "VD vector reversed: " << endl;
	for (int i = 0; i < vd.size(); i++)
		cout << vd[i] << " ";
	cout << "\n\n";

	double mean_vd = sum_vd / vd.size(); // vd mean
	cout << "VD vector Mean: " << mean_vd << "\n\n";

	vector<double> vd2;

	for (int i = 0; i < vd.size(); i++) { // vd2 vector
		if (vd[i] < mean_vd)
			vd2.push_back(vd[i]);
	}

	cout << "VD2 vector: " << endl; 
	for (int i = 0; i < vd2.size(); i++)
		cout << vd2[i] << " ";
	cout << "\n\n";

	sort(vd);

	cout << "VD vector sorted: " << endl;
	for (int i = 0; i < vd.size(); i++)
		cout << vd[i] << " ";
	cout << endl;

	return 0;
}