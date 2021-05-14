#include <iostream>

using namespace std;    // File: q2.cc

class my_array_class {
    int len = 2;
    int* a = new int[2];

public:

    my_array_class() { a[0] = 1; a[1] = 2; }

    my_array_class(int ln, const int* o) : len(ln), a(new int[ln])
    {
        for (int n = 0; n < ln; ++n) a[n] = o[n];
    }

    ~my_array_class() { delete[] a; }



    int get(int n) const 
    {
        return a[n]; 
    }

    int set(int n, int v) { int tmp = a[n]; a[n] = v; return tmp; }

};



void foo(const my_array_class& a2) {

    std::cout << a2.get(0) << std::endl;

}



int main() {

    int zero12[] = { 13, 1, 2 };

    my_array_class a1(3, zero12);

    foo(a1);

    return 0;

}