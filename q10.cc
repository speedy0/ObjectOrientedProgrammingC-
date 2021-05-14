#include <algorithm>
#include <iostream>
#include <iomanip>      // std::setw
#include <sstream>      // std::ostringstream
#include <string>
#include <map>
#include <utility>      // std::pair
#include <vector>
/* add further includes here if you need to */

using namespace std;                  // File: q7.cc (for Q7–Q10)


/* Turn a token to a string - tokens cannot contain spaces or other characters that are not valid for a variable name. */
#define X(token) #token


string null = X(NULL);


string department_names[] = {
   X(Sales)
   , X(Engineering)
   , X(Clerical)
   , X(Marketing)
};

string employee_names[] = {
   X(Rafferty)
   , X(Jones)
   , X(Heisenberg)
   , X(Robinson)
   , X(Smith)
   , X(Williams)
};


/* Table department: columns = DepartmentID, DepartmentName */
map<int, string*> department = { {31, department_names + 0}
                                ,{33, department_names + 1}
                                ,{34, department_names + 2}
                                ,{35, department_names + 3} };

/* Table employee: columns = LastName, DepartmentID */
map<string*, int> employee = { {employee_names + 0, 31}
                              ,{employee_names + 1, 33}
                              ,{employee_names + 2, 33}
                              ,{employee_names + 3, 34}
                              ,{employee_names + 4, 34}
                              ,{employee_names + 5,  0} };


string get_null_or_X(int x) {
    ostringstream os;  os << setw(15);

    if (0 == x) os << null;
    else        os << x;

    return os.str();
}

string get_null_or_X(const string* x) {

    ostringstream os;  os << setw(15);

    if (nullptr == x) os << null;
    else              os << *x;

    return os.str();
}

string get_null_or_X(const char* x) {

    ostringstream os;

    os << setw(15) << x;

    return os.str();

}


/* //Unneeded, new void print_dep() can be found at the bottom for question 10!!
void print_dep() {

    cout << get_null_or_X(X(DepartmentID))
         << get_null_or_X(X(DepartmentName)) << endl;

    auto it = department.begin();
    while (it != department.end()) {
        cout << "" << get_null_or_X(it->first) << "" << get_null_or_X(it->second) << endl;

        it++;
    }

}*/

void print_emp() {

    cout << get_null_or_X(X(LastName))
         << get_null_or_X(X(DepartmentID)) << endl;

    auto it = employee.begin();
    while (it != employee.end())
    {
        cout << "" << get_null_or_X(it->first) << "" << get_null_or_X(it->second) << endl;
        it++;
    }
}



void print_inner_join() {

    cout << get_null_or_X(X(LastName))
        << get_null_or_X(X(DepartmentID))
        << get_null_or_X(X(DepartmentName)) << endl;

    auto it = employee.begin();
    while (it != employee.end())
    {
        int dep_id = it->second;
        string dep_name = null;
        const auto dep_it = department.find(dep_id);

        if (dep_it != department.cend()) 
        {
            dep_name = get_null_or_X(dep_it->second);
            cout << get_null_or_X(it->first) << "  " << dep_id << "  " << dep_name << endl;
        }
        it++;
    }
}

class compare_dep_name {

public:
    bool operator()(const pair<int, string*>& left, const pair<int, string*>& right) {
        return *(left.second) < *(right.second);
    }
};

void print_dep() {
    cout << get_null_or_X(X(DepartmentID))
        << get_null_or_X(X(DepartmentName)) << endl;

    vector<pair<int, string*>> department_vec;
    auto it = department.begin();
    while (it != department.end()) {
        department_vec.push_back(*it);
        it++;
    }

    sort(department_vec.begin(), department_vec.end(), compare_dep_name());
   
    for (const auto &p: department_vec){
        cout << "" << get_null_or_X(p.first) << "" << get_null_or_X(p.second) << endl;
    }

}
int main() {

    print_dep();

    print_emp();

    print_inner_join();

    return 0;

}