/*
Brendan Womer
05/08/2023
namespaces and #define
    used for shortcuts and convenience
    used in triangle parrallellogram
*/

#include <iostream>
#include <string>

using namespace std;

#define DEBUG(s) cout << s << endl;
#define DEBUGVAR(s, n) cout << "DEBUG Var: " << s << " DEBUG Value: " << n << endl;
//
namespace mynamespace {
    int num1;
    float num2;
    struct mystructtoo {
        string name1;
    };
}

namespace secondnamespace {
    int num1;
    int num2;
    struct mystruct {
        string name1;
    };
}

int main(int argc, char* argv[]) {
    mynamespace::num1 = 42;
    mynamespace::num2 = 3.5;
    // mynamespace::mystructtoo struct1;
    // mynamespace::struct1.name1 = "not brendan";

    secondnamespace::num1 = 69;
    secondnamespace::num2 = 96;
    secondnamespace::mystruct struct1;
    struct1.name1 = "brendan";
    DEBUGVAR("secondnamespace::struct1.name1", secondnamespace::struct1.name1);

    cout << "mynamespace::num1: " << &mynamespace::num1 << '\n'
        << "mynamespace::num1: " << &mynamespace::num1 << '\n'
        << "mynamespace::name1: " << &mynamespace::name1 << '\n'
        << "secondnamespace::num1: " << &secondnamespace::num1 << '\n'
        << "secondnamespace::num1: " << &secondnamespace::num1 << '\n'
        << "secondnamespace::num1: " << &secondnamespace::num1 << endl;


    return 0;
}