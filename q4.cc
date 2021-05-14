#include <iostream>

using namespace std;        // File: q4.cc

class my_array_over2 {

    int len = 1;

    int* a = new int[1];

public:

    my_array_over2() { a[0] = 0; }

    my_array_over2(int ln, const int* o) : len(ln), a(new int[ln])

    {
        for (int n = 0; n < ln; ++n) a[n] = o[n];
    }

    ~my_array_over2() { delete[] a; }

    /* Put your code here */
    int operator[] (int index) const {
        return a[index];
    }

    int& operator[] (int index) {
        return a[index];
    }

};



void foo(const my_array_over2& a2) {

    std::cout << a2[0] << std::endl;

}

int main() {

    int zero12[] = { 13, 1, 2 };

    my_array_over2 a1(3, zero12);

    a1[1] = 14;// --> comment it -->EXTRA LINE!!! 

    foo(a1);

    return 0;

}
