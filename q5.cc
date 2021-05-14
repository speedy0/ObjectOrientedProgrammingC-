#include <iostream>
#include <vector>

using namespace std;        // File: q5.cc

class zample {
	vector<int> vi;

public:

	zample(vector<int> some_vi) : vi(some_vi) {}

	const vector<int>& get_data() const { return vi; }

};



/* Put your code here */
ostream& operator<<(ostream& out, const zample& z) {
	out << "<" << z.get_data().size() << ":";
	const auto& vi = z.get_data();
	for (auto i = 0; i < vi.size();++i) {
		out << vi[i];
		if (i != vi.size() - 1) {
			out << " ";
		}
	}
	out << ">" << endl;

	return out;
}

istream& operator>>(istream& in, zample& z) {
	vector<int> vi;
	char bracket;
	char colon;
	int size;
	in >> bracket >> size >> colon;
	for (auto i = 0; i < size; i++) {
		int num;
		in >> num;
		vi.push_back(num);
	}
	in >> bracket;
	z = zample(vi);
	return in;
}

int main() {

	vector<int> vi = { 11, 12, 13, 14, 15 };

	zample z1(vi);

	cout << z1 << endl; /* should print: <5: 11 12 13 14 15> I.e., <size: elements> */

	cin >> z1 >> z1; /* should be able to read “<5: 11 12 13 14 15><6: 21 22 23 24 25 26>a” (two samples on the same line, stuck together, with a character ‘a’ immediately following the 2nd one. */

	cout << z1 << endl; /* should print: <6: 21 22 23 24 25 26> */

	char c;

	cin >> c; cout << c << endl; /* should print ‘a’ – the char after the 2nd zample above. */

	return 0;

}