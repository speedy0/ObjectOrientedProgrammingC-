#include <iostream>

#include <list>

#include <algorithm>

using namespace std;  
// File: q6.cc
template <typename X>
class zamplex {
	list<X> vi;

public:
	zamplex(list <X> some_vi);
	const list <X>& get_data() const;
	
};

template <class X>
zamplex<X>::zamplex(list <X> some_vi) : vi(some_vi) {

}

template <class X>
const list <X>& zamplex<X>::get_data() const {
	return vi;
}


/* a) Put your code here to get it to compile */

int main() {

	list<float> lf = { 11, 12, 13 };

	zamplex<float> z1(lf);

	const list<float>& lfr = z1.get_data();

	/* b) Put your code here to print the elements of lfr. */
	for (auto num : lfr) {
		cout << num << " ";
	}
	return 0;

}