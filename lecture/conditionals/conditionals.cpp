#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;
// template <class num1, class num2>


void sayhello();

//initial use of if statement main()
int main() {
    int num1, num2;
    int answer;

    cout << "Please enter 2 numbers: " << endl;
    cin >> num1 >> num2;

    answer = (num1 < num2);
    
    if (answer) {
        //cout << "the number is not XXX";
        cout << "num1 is less than to num2 " << endl;
        sayhello();

    }

    cout << "outside and after if statement" << endl;

    return 0;

}

void sayhello() {
    cout << "hello from sayhello() " << endl;


}



// basic testing of conditional
//  int main() {
//     int num1, num2;

//     num1 = 10;
//     num2 = -10;

//     cout << boolalpha << (num1 > num2) << endl;

//     return 0;

// }

// main() {
//     int num1, num2;

//     num1 = 10;
//     num2 = -10;

//     cout << boolalpha << (num1 > num2) << endl;



// }