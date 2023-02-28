#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;
// template <class num1, class num2>


void sayhello();

int main() 
{
    long num1;

    cout <<"enter #"<<endl;
    cin >> num1;

    // if  (num1 < 0) 
//     {
//         num1 = abs(num1);
//     }
//
//     if (num1%2 == 0 ) {
//         cout << "is even" << endl;
//         } 
//     else {
//         cout << "num1 is odd" << endl;
//         }

    // this is playing with switch fcn, checking if a number is even or odd
    // switch(num1%2) { // switch is used to compare switch(beingcompared) with each case. each case is a value being tested. case '#' -- tests '#' against switch(beingcompared)
    //     case 0;
    //         if(num1 == 0) 
    //         {
    //             cout << "num1 is zero" << endl;
    //         }
    //         else 
    //         {
    //             cout << "num1 is even" << endl;
    //         }
    //         break; //use breaks for each class, doesnt matter if default has one. if    
    //     case 1;
    //         cout << "num1 is odd" << endl;
    //         break; 
    //     default;
    //         cout << "how did u get here?";
    //     }

    // this is playing with if else fcns, checking if num1 is even or odd
    // cout << "num1 is zero" << endl;
    // if (num1 == 0 ) 
    // {
    //     cout << "num1 is zero" << endl;
    // } 
    // else if (num1&2 == 1 ) 
    // {
    //     cout << "num1 is odd " << endl;
    // } 
    // else if (num1%2 == 0) 
    // {
    //     cout << "num1 is even" << endl;
    // } 
    // else 
    // {
    //     cout << "the end, shouldnt get";
    // }
 }





//initial use of if statement main()
// int main() {
//     int num1, num2;
//     int answer;

//     cout << "Please enter 2 numbers: ";
//     cin >> num1 >> num2;

//     answer = (num1 < num2);
//     cout << "is 1 less than 2? " << endl;
    
//     if (answer) {
//         //cout << "the number is not XXX";
//         cout << "num1 is less than to num2 \n" << endl;
//         sayhello();

//     } else {
//         cout << "num1 is more than num2 \n" << endl;

//     }


//     cout << "outside and after if statement" << endl;

//     return 0;

// }

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