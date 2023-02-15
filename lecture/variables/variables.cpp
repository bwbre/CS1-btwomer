/*
Name: Brendan Womer

All about variables
*/


#include <iostream>
#include <iomanip>

using namespace std;

//lecture 9Feb2023 working with variables

int main() {
    float num1, num2;
    int stage=0;
    int incorrectGuess = 0;
    stage=incorrectGuess;

    cout << "please enter two numbers: ";
    cin >> num1 >> num2;

    printf("%.02f + %.02f = %.02f\n", num1, num2, num1+num2);

    cout << stage << endl;
    incorrectGuess=incorrectGuess+1;
    cout << stage << endl;
    incorrectGuess=incorrectGuess+1;
    cout << stage << endl;

}

// int main() {

//     double num1, num2;

//     cout << "please enter two numbers: ";
//     cin >> num1 >> num2;

//     cout << setw(4) << num1 << setw(4) << num2 << endl; 

//     cout << setfill('-');
//     cout << setw(40) << " " << endl;
//     cout << setfill(' ') << setprecision(20) ;
//     cout << setw(20) << num1 << setw(20) << num2 << endl;

    // string someChar;

    // cout << "please enter a letter: " << endl;
    // cin >> someChar;

    // cout << toupper(someChar) ;

// }



//experimenting with 'Escape Sequences' THEY MUST BE IN A STRING OR CHAR (' ' OR " ")
// \n - new line
// \ - back slash
// \t - tab
// \r - carriage return
// \' - single quote
// \" - double quote

// int main(){

//     int num1, num2;
//     float fnum1, fnum2;


//     cout << "Please enter number1: ";
//     cin >> num1;
//     // fnum1 = float(num1);

//     cout << "please enter numer2: ";
//     cin >> num2;
//     // fnum2 = float(fnum2);

//     cout << num1 << " + " << " = " << num1 + num2 << endl;
//     cout << num1 << " - " << " = " << num1 - num2 << endl;
//     cout << num1 << " * " << " = " << num1 * num2 << endl;
//     cout << num1 << " / " << " = " << num1 / num2 << endl;
//     // cout << num1 << " & (/) " << " = " << float(num1) & num2 << endl; //data type conversion to float



// }


// int main() {

//     int inputSeconds;
//     int numHours, numMins, numSeconds;

//     cout << "How many seconds are there: ";
//     cin >> inputSeconds;

//     numHours = inputSeconds/3600;
//     numMins = (inputSeconds/60)%60;
//     numSeconds = inputSeconds%60;

//     cout << "from " << inputSeconds << " you have " << numHours << "hours  " << numMins << "Min " << numSeconds << "Seconds \n";


// }

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

//     string firstname;
//     string lastname;
//     string fullname;

//     cout << "Please enter first and last name: ";
//     cin >> firstname >> lastname;

//     // cout << "please enter first name: ";
//     // getline(cin, firstname);
//     // cin >> firstname;

//     // cout << "please enter last name: ";
//     // getline(cin, lastname);
//     // cin >> lastname;

//     fullname = firstname + " " + lastname;
//     cout << "Welcome " << fullname << endl;


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

