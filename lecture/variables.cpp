/*
Name: Brendan Womer

All about variables
*/


#include <iostream>

using namespace std;



//experimenting with 'Escape Sequences' 
// \n - new line
// \ - back slash
// \t - tab
// \r - carriage return
// \' - single quote
// \" - double quote

int main(){

    int num1, num2;

    cout << "Please enter number1: ";
    cin >> num1;

    cout << "please enter numer2: ";
    cin >> num2;

    cout << num1 << " + " << " = " << num1 + num2 << endl;
    cout << num1 << " - " << " = " << num1 - num2 << endl;
    cout << num1 << " * " << " = " << num1 * num2 << endl;
    cout << num1 << " / " << " = " << num1 / num2 << endl;
    cout << num1 << " & (/) " << " = " << num1 & num2 << endl;



}


// // int main(){
//     string line3;
//     char ch;

//     line3 = "(>0<)  *   Author: Your \t name    *  ( \\\\\" )_( \" )\n";
//     cout << line3 << endl;
//     cout << "press any character and enter to quit: ";

//     cin.ignore(1);
//     cin.get();
//

// /t - tab
    // line3 = "(>0<)  *   Author: Your \t name    *  ( \" )_( \" )\n";
    // cout << line3 << endl;

    //  line3 = "(>0<)  *   Author: Your --\t name    *  ( \" )_( \" )\n";
    // cout << line3 << endl;

    //  line3 = "(>0<)  *   Author: Your ---\t name    *  ( \" )_( \" )\n";
    // cout << line3 << endl;

// \r AND \n - \r changes
//      line3 = "(>0<)  *   Author: Your --- \n name    *  ( \" )_( \" )\n";
//     cout << line3 << endl;
// }


//experimenting with 'getline' stores string value to temporary storage, ends after stream ends
// int main(){
    // string firstname;
    // string lastname;
    // string fullname;

    // cout << "Please enter name with spaces ":
    // cin >> firstname >> lastname;

    // cout << "please enter first name: ";
    // getline(cin, firstname);
    // cin >> firstname;

    // cout << "please enter last name: ";
    // getline(cin, lastname);
    // cin >> lastname;

    // fullname = firstname + " " + lastname;
    // cout << "Welcome " << fullname << endl;


// }

// int main(){
//     int num1;
//     int num2;
//     int total;

//     cout << "Please enter value:  "; /*streams out of variable*/

//     cin >> num1; /*cin - streams into variable*/
//     cout << "value is: " << num1 << endl;

//     cout << "Please enter value:  ";

//     cin >> num2;
//     cout << "value is: " << num2 << endl;

//     // num1 + num2 = total /* super wrong.. Format is "total = var1 + var 2" BECAUSE "=" is the operator */
//     total = num1 + num2;
//     cout << "value is: " << total << endl;



//     return 0;
// }

// int main(){
//     long number1;

//     number1 = 42;

//     cout << "the memory address of number1:  " << &number1 << endl;
//     cout << "the value of number1:  " << number1 << endl;

//     number1 = 24;

//     cout << "the memory address of number1:  " << &number1 << endl;
//     cout << "the value of number1:  " << number1 << endl;

//     return 0;
// }


// int main(){
//     char number1;

//     number1 = 'j';

//     cout << "the memory address of number1:  " << &number1 << endl;
//     cout << "the value of number1:  " << number1 << endl;

//     number1 = 'b';

//     cout << "the memory address of number1:  " << &number1 << endl;
//     cout << "the value of number1:  " << number1 << endl;

//     return 0;
// }


 /*
  Variables should start with lower case letter 
 */
// int notes(){
//     int number1 = 0; /* sets value at variable creation */
//     int this_is_number1; /* snake case, underline makes the int a snake */
//     int thisIsNumber1; /* camel case (cap letter for humps) */

//     int thisIsTheFirst, int thisIsSecond, int thisIsLast;

//     char thisIsChar1; /* this is a char variable */

//     unsigned long thisIsUnsignedLong; /* unsigned long variable*/

//     cout << "notes" << endl;

//     return 0;
// }

