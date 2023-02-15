/*function lecture
a function has parenthesis
Just like a mathmatical function, for each input(s) there is a unique output.

setw() is a black box that takes in an int and modifies
*/

/* pass by value is main() s1=42 at its memaddressX and prompt() s1=42 memaddressY.. prompt(s1) loses value unless returned.
pass by reference is main() s1=42 with memaddressX is used in prompt() by reference, so s1 in prompt() uses same memadress

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



/*messing with bad over complicated use templates and types*/
// int addNums(int num1, int num2) {
//     return num1 + num2
// }

// float addNums(float num1, float num2) {
//     return num1 + num2 + 10;
// }

// int addNums(float num1, int num2) {
//     return num1 + num2;
// }

/* create template to recognize any data type (float, int) by using types*/
// template <class type1, class type2>


// type1 addnums(type1 num1, type2 num2) {
//     type2 answer;
//     answer = num1 + num2;
//     return answer;

// }


/* function "prototype" before the actual function is defined allow it avoid issues of 
fcns being called before they are created.. create empty fcn at beginning that MUST match
the later defined function*/

void sayhello();
void saybye();

template <class t1, class t2>
t1 addnums(t1, t2);

void sayhello() {
    cout << "hello world" << endl;
    saybye();
}

void saybye() {
    cout << "goodbye world" << endl;
    sayhello();
}

//this is for organizing the reference passing example
void random(){
    


void prompt(int&);



int main() {
    // sayhello();

    int n1, n2; 

    cout << "mem address for n1 and n2 " << &n1 << " " << &n2 << endl;
  
    prompt(n1);
        cout << "mem address for n1 and n2 after prompt(n1) in main " << &n1 << " " << &n2 << endl;
    prompt(n2);
        cout << "mem address for n1 and n2 after prompt(n2) in main " << &n1 << " " << &n2 << endl;

    n1 = 42.5;
    n2 = 15.2;

    cout << n1 << " + " << n2 << " = " << addnums<float, int>(n1, n2) << endl;
    cout << n1 << " + " << n2 << " = " << addnums<int, float>(n1, n2) << endl;


    return 0;
}

void prompt(int &n1) {
    cout << "mem address for n1 inside promp() " << &n1 << endl;

}

template <class t1, class t2>
t1 addnums(t1 num1, t2 num2) {
    return num1 + num2;
}
}
























// void sayHello() {
//     cout << "hello from sayhello() new text " << endl;
// }

// void getline(int, int){}

// float addNums(int num1, int num2) {
//     cout << "\n----------beginning of addnum()\n";
//     float result;
//     result = num1 + num2;   
//     cout << num1 << " <#3 addnum() #4> " << num2 << "\nthis is fcn float addNums() output of result is: " << result;
//     cout << "\n----------end of addnums()\n" << endl;
//     return result;


// }

// int main() {
//     cout << "\n ---beginning of main()" << endl;
//     //create num3, 4, 5, 6 for this local function main()
//     int num3, num4;
//     int num5;
//     float addNumsAnswer;

//     //input num1 and num2 
//     cout << " this is main(): please enter two numbers w/ space : ";
//     cin >> num3 >> num4;
//     cout << num3 << " <#3 main() #4> " << num4 << "\n";

//     /*CANNOT call a void fcn inside of cout. void fcn has no output, therefore no output
//     to stream. this is an example: */
//     // cout << "result of hello is " << sayhello() << endl;


//     /* call function addNums() with the inputs of the local values of num1 and num2*/
//     addNumsAnswer = addNums(num3, num4);
//     cout << "main() after calling addNums() where addnums() is the value of addnumsanswer: " << " num3: " << num3 << " num4: " << num4 << ", addNums(): " << addNumsAnswer << "\n";
    
//     cout << "main() pick num 3 and num5: ";
//     cin >> num3 >> num5;
//     addNumsAnswer = addNums(num5, num3);
//     cout << "\nthis is main() cout of addnums() with num5 and num3: " << num5 << " + " << num3 << " = " << addNumsAnswer << endl;
//     sayHello();

//     // cout << "result of hello is " << sayHello << endl;
//     // cout << "add numbers added together" << addNums(num1, num2) << endl;
//     return 0;


// }

// void greet(string firstname) {

//     cout << "hello"<< firstname << endl;

// }



// void prompt() {
//     string firstname;
//     cin >> "enter firstname" >> firstname >> endl;
//     cout << "welcome " << firstname << "to my program" << endl;
//     return firstname;
//     //outputs string firstname
// }

// void printNum(int num1) {
//     cout << "print num1 memory location: " << &num1 << endl;
//     cout << "print num2 memory location: " << &num1 << endl;

// }

// int main() {
    // //call fcn
    // greet();
    // //create playername and assign it to the output of prompt()
    // string playername = prompt();
    // //calls greet with the input of playername
    // greet(playername);
    // greet("bob ");
    // greet("phil ");

    // return 0;


//     int num1;
//     int num2;
//     num1 = 42;
//     cout << "inside main: " << &num1 << endl;
//     cout << "inside main: " << &num2 << endl;

//     printnum(num1);
// }


