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
    int n=100;

    //O(n)
    for (int i=0; i < n; i++) {
        //O(n*n)
        for (int j = 0; j < n; i++) {
            
        }

    }

    return 0;
}