#include <iostream> //console i/o
#include <fstream>
#include <string>
using namespace std;
int main() {
	ifstream ifs;
	ifs.open("./input.txt"); // reading only
	if (!ifs.is_open()) return 1;
	string name, min_name, max_name; int age, min_age, max_age;
	ifs >> name >> age;
	min_name = max_name = name;
	min_age = max_age = age;
	while (ifs >> name >> age) {
		if (age > max_age) { max_age = age; max_name = name; }
		if (age < min_age) { min_age = age; min_name = name; }
	}
	cout << min_name << " " << min_age << endl;
	cout << max_name << " " << max_age << endl;

	ofstream os("output.txt"); // writing only
	if(os.is_open()){
		os << min_name << " " << min_age << endl;
		os << max_name << " " << max_age << endl;
	}
	if (os.bad()) { /* Failed to write! */ }

	return 0;
}
