#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string incom = "inlist_change_incom";
	string filename = "inlist_temp";
	
	//Input Mass
	cout << "Mass=";
	int mass;
	cin >> mass;

	//Open File & Check
	ifstream src(incom, ios::binary);
	ofstream dst(filename, ios::binary);
	dst << src.rdbuf();

	ofstream file(filename.c_str(), ios_base::app | ios_base::out);

	if (!file.is_open()) {
		cerr << "Cannot open file!" << filename;
		return 1;
	}

	//Write
	file << "initial_mass = " << mass << endl;
	file << "/ ! end of controls namelistâ" << endl;

	//Close file & Rename
	file.close();
	string newfilename = "inlist_" + to_string(mass) + "M";
	rename(filename.c_str(), newfilename.c_str());

	return 0;
}

