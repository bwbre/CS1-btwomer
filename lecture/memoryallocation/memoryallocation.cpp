/*
brendan
memory allocation 


command in linux to see stack
    --ulimit -a 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Mystruct {
    int num1;
    //arrays must be fixed
    int mynums[30];
    vector<int> numbers2;
    Mystruct *next;
}

int main(int argc, char * argv[]) {
    //its very likely to deal with stuff larger than the 8mb stack limit.. need heap allocation

    /*These are both the same thing, BUT the first creates in stack and the second creates the struct in the heap
        -- the *struct1 is a pointer to the struct.
        -- struct has no name, only an address-- which is assigned to the pointer *struct1.
    */new is saying heap allocated
    Mystruct struct2;
    Mystruct *struct1 = new Mystruct;





    return 0;
}