#include <iostream>
using namespace std;

int main() {
	int ival;
	while (cin >> ival, !cin.eof()) {
		if (cin.bad()) {
			throw ("IO stream corrupted");
		}
		if (cin.fail()) {
			cerr<< "bad data, try again";
			continue;
		}
	}
}
