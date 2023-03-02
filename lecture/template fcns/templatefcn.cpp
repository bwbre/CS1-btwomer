
#include <iostream>
#include <cassert>

using namespace std;

template <class t1, class t2>
t1 addnums(t1, t2);

void test();

/* 
---argc is a 1 index counter of how many arguments are passing thru
    -executable name is always arg1
---argv

*/
int main(int argc, char *argv[]) {
    /* // cout << "argc: " << argc << endl;
    // for (int i=0; i<argc; i++) 
    //     {
    //     cout << "argv[" << i << "]: " << argv[i] << endl;
    //     } */
   
    int num1, num2;
    int answer;

    if (argc >= 2 && (string)argv[1] == "test") {
        test();
        return 0;
    }

    num1 = 42;
    num2 = 15;

    answer = addnums<int, int>(num1, num2);
    cout << "Your answer is " << answer << endl;

    return 0;
}

void test() {
    /*C doesn't recognize template, must create variable,
        -we use int result = fcn() , then next line asser(result == 57)    
         VS.  assert(addnum)
    */
    int result = addnums<int, int>(42, 15);
    assert(result == 57);

    result = addnums<int, int>(9000, 1);
    assert(result = 9001);
    cout << "All test cases pass.\n";



}

template <class t1, class t2>
t1 addnums(t1 num1, t2 num2) {
    return num1 + num2;
}
