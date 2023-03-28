/* 
Brendan Womer
CS1 - HW 4 Conditionals

Description : This is a program that will return a variety of useful information using 5 numbers that are provided by the user.

Program Steps:
1. Prompt user for 5 numbers and their name.
9. Greet user
2. Define a function that returns the sum for the 5 numbers.
3. Define a function that returns the product for the 5 numbers.
4. Define a function that returns the average for the 5 numbers.
5. Define a function that returns the smallest value out of the 5 numbers (without using a built-in functions).
6. Define a function that returns the smallest value out of the 5 numbers (without using a built-in functions).
7. Define a function that will return whether or not the floor of the sum is odd, even, or zero. (floor of sum is the sum of all 5 numbers rounded down to nearest integer)
8. Create a basic menu interface to prompt user what functions/features they want to call.
9. Define a test function that will verify the accuracy of the previously defined functions. (Call only when test argument is passed to main).
10. Loop as many times as the user wants.

Notes: 
upon executionfrom main() the program will check to see whether or not a test argument is passed. If it is, then a test is ran and the programs ends.
If test arg isnt passed, then it will call the menu. all features will be called in the menu. After each feature is called in menu() the user will be prompted-
if they want to continue doing more operations, whether or not they want a new set of numbers, or if they want to end. if they choose not to end, then the menu()-
will loop until prompted otherwise-- prompting for new numbers at the beginning if they prompted for it.

*/
#include <iostream>
#include <cassert>

using namespace std;

void printarray(double*, int);
double smallestvalue(double*, bool);
double largestvalue(double*, bool);
bool menu(double*, bool);
int getselection(int, int);
void printmenu();
void promptagain();
void promptname();

//will use first 5 elements of nums[]
template <class T1>
    T1 promptnums(T1 nums[]) {
        //prompt user for 5 numbers, then assign each number to the first 5 positions in the array.
        cout << "\nPlease enter 5 different numbers separated by spaces:  ";
        cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4];
        // cout << "\n--Finished storing values--\n" << endl;
        return 0;
    }

//will calculate the sum and will save the result in the 6th element -- nums[5]
template <class T1>
    T1 sum(T1 nums[], bool dotest) {
        T1 result = (nums[1] + nums[2] + nums[3] + nums[4] + nums[0]);
        // cout << "dotest: " << dotest << endl;
        if (dotest == false) {
            cout << "\n\n\n\nYou chose to find the sum of the 5 numbers:\n" << endl;
            printf("%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n\n", nums[0], nums[1], nums[2], nums[3], nums[4], result);

        } 

        //store the result in element 6 of nums[]
        nums[5] = result;

        return result;
    }

//will calculate the product and will save the result in the 7th element -- nums[6]
template <class T1>
    T1 product(T1 nums[], bool dotest) {
        T1 result = (nums[0] * nums[1] * nums[2] * nums[3] * nums[4]);

        if (dotest == false) {
        cout << "\n\n\n\nYou chose to define the product of the 5 numbers:\n" << endl;
        printf("%.2f * %.2f * %.2f * %.2f * %.2f = %.2f\n\n", nums[0], nums[1], nums[2], nums[3], nums[4], result);
        }

        //store the result in element 7 of nums[]
        nums[6] = result; 

        return result;
    }

// will calculate the average and will save the result in the 8th element -- nums[7]
template <class T1>
    T1 avg(T1 nums[], bool dotest) {
        T1 result = ((sum(nums, true)) / 5);

        if (dotest == false) {
            cout << "\n\n\n\nYou chose to find the average between the 5 numbers:\n\nThe average of all 5 numbers is : " << result <<  "\n" << endl;
        }

        nums[7] = result; 


        return result;
    }


//I dont want to use strings so im arbritarily assigning 0 = zero, 1 = even, 2 = odd.
template <class T1>
    T1 definefloor(T1 nums[], bool dotest) {

        T1 sumt = sum(nums, true);
        T1 result;


        int remainder = (int(sumt) % 2);
        if (remainder == 0 && sumt == 0) {
            if (dotest == false) {
            cout << "\n\n\n\nYou chose to define the sum floor:\n\nThe sum floor is zero\n\n";
            }
            nums[10] = 0;
        }
        else if (remainder == 0 && sumt != 0){
            if (dotest == false) {
            cout << "\n\n\n\nYou chose to define the sum floor:\n\n The sum floor is even\n\n";
            }
            nums[10] = 1;
        } 
        else {
            if (dotest == false) {
            cout << "\n\n\n\nYou chose to define the sum floor:\n\nThe sum floor is odd\n\n";
            }
            nums[10] = 2;
        }

    result = nums[10];
    return result;
    }

template <class T>
    T test(T nums[],bool dotest) {
    //Will test all the functions using a single array, but overwriting the value with new ones for each test.

    //variable to hold the results from the functions.
    T resultt;


    // double nums[5] = {1, 4, 5, 6, 8};
    nums[0] = 1;
    nums[1] = 4;
    nums[2] = 5;
    nums[3] = 6;
    nums[4] = 8; 

    resultt = sum(nums, true);
    assert(resultt == 24);
    resultt = smallestvalue(nums, true);
    assert(resultt == 1);
    // cout << nums[0] << endl;
    resultt = largestvalue(nums, true);
    assert(resultt == 8);
    resultt = product(nums, true);
    assert(resultt == 960);
    resultt = avg(nums, true);
    assert(resultt == 4.8 );
    resultt = definefloor(nums, true);
    assert(resultt == 1 );

    // double nums[5] = {10, 6, 15, 20, 12};
    nums[0] = 10;
    nums[1] = 6;
    nums[2] = 15;
    nums[3] = 20;
    nums[4] = 12;

    resultt = sum(nums, true);
    assert(resultt == 63);
    resultt = smallestvalue(nums, true);
    assert(resultt == 6);
    resultt = largestvalue(nums, true);
    assert(resultt == 20);
    resultt = product(nums, true);
    assert(resultt == 216000);
    resultt = avg(nums, true);
    assert(resultt == 12.6 );
    resultt = definefloor(nums, true);
    assert(resultt == 2 );

    // double nums[5] = {0, 2, 7, 5.5, 12};
    nums[0] = 0;
    nums[1] = 2;
    nums[2] = 7;
    nums[3] = 5.5;
    nums[4] = 12; 

    resultt = sum(nums, true);
    assert(resultt == 26.5);
    resultt = resultt = smallestvalue(nums, true);
    assert(resultt == 0);
    resultt = largestvalue(nums, true);
    assert(resultt == 12);
    resultt = product(nums, true);
    assert(resultt == 0);
    resultt = avg(nums, true);
    assert(resultt == 5.3 );
    resultt = definefloor(nums, true);
    assert(resultt == 1 );

    // double nums[5] = {0,0,0,0,0};
    nums[0] = 0;
    nums[1] = 0;
    nums[2] = 0;
    nums[3] = 0;
    nums[4] = 0; 


    resultt = sum(nums, true);
    assert(resultt == 0);
    resultt = smallestvalue(nums, true);
    assert(resultt == 0);
    resultt = largestvalue(nums, true);
    assert(resultt == 0);
    resultt = product(nums, true);
    assert(resultt == 0);
    resultt = avg(nums, true);
    assert(resultt == 0);
    resultt = definefloor(nums, true);
    assert(resultt == 0);


    return 0;
}




int main(int argc, char* argv[]) {
    //create array that will hold all the values that will be used in the program.
    /* array nums[] will store all the values that will be worked with.
    nums[0 -> 4] are the user selected numbers
    nums[5] sum
    nums[6] product
    nums[7] average
    nums[8] smallestvalue
    nums[9] largestvalue
    nums[10] definefloor */
    double nums[11] = {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0};

    //declaring bool that will be used throughout. if and only if bool == true, the the program will run the tests without printing the outputs, then end. 
    bool dotest = false;

    //no numbers have been nmputted at the beginning of program. declare keepnums as false so it knows it needs new numbers.
    bool keepnums = false;

    //keeprunning will remain true until the user prompts to end the program.
    bool keeprunning = true;

    //i already created a bool for dotest and would have to do a ton of re-writing to replace it with the method i learned today in class.
    if (argc == 2 && string(argv[1]) == "test") {
        dotest = true;
    }
    else {
        dotest = false;
    }


    //test functions when test is used as an argument.
    if (dotest == true) {
        cout << "\ntest time\n";
        test<double>(nums, true);
        cout << "\ntest passed.. Program wil now end." <<endl;
        dotest = false;
        keeprunning = false;
    }

    //this essentially runs the whole program.
    do {
        if (keeprunning == true) {
            keeprunning = menu(nums, dotest);
        }
        else {
            return 0;
        }
    }
    while (keeprunning == true);

    cout << "\nGoodbye." <<endl;
    return 0;
}


void printmenu() {
    cout << "\n\n\n\n\n\n\n\nPlease select one of the following options:\n\n";
    cout << "1. Calculate the sum of the 5 numbers.\n";
    cout << "2. Calculate the product of the 5 numbers.\n";
    cout << "3. Calculate the average of the 5 numbers.\n";
    cout << "4. Find the smallest value among the 5 numbers.\n";
    cout << "5. Find the largest value among the 5 numbers.\n";
    cout << "6. Find whether the floor of sum of the 5 numbers is even, odd, or 0.\n";
    cout << "7. Exit Program\n";
    cout << "------------------------------------------------------------------------\n\n" << endl; 
}

//
bool menu(double nums[], bool dotest) {
    int selection;

    //the previously used keeprunning isnt passed into this function, because it will only be called IF keeprunning was == true in main-- always will be true at the start of this function.
    //if keeprunning == true at the very end, then the menu() fcn will loop.
    bool keeprunning = true;

    // will be used to flag the conditional whether or not a new set of numbers are needed.
    bool keepnums = false;
    promptname();

    /* will loop endlessly while keeprunning == true
    on the first loop it keepnums is false so it will always ask the user for 5 numbers. 
    subsequent loops will check whether or not the player decided to pick new numbers.
    */
    do {

        if (keepnums == false)  {
            promptnums(nums);
            keepnums = true;
        }
 
        //if they prompted they want to keep their numbers this runs.
        if (keepnums == true) {
            printmenu();
            cin.clear();
            
            /*getselection(min, max) allows for the same function to fetch selections while setting a requirement for the input to 
            be within the min and max. the largest and smallest values for the cases below are 1, 9 */
            selection = getselection(1,7);
            switch(selection) {
                case 1:
                    sum(nums, dotest);
                    break;
                case 2:
                    product(nums, dotest);
                    break;
                case 3:
                    avg(nums, dotest);
                    break;
                case 4:
                    smallestvalue(nums, dotest);
                    break;
                case 5:
                    largestvalue(nums, dotest);
                    break;
                case 6:
                    definefloor(nums, dotest);
                    break;
                case 7:
                    cout << "Now exiting program..";
                    keeprunning = false;
                    break;
                }
  
            }

        //just to make sure nothing else runs after the user prompts to exit.
        if (keeprunning == true) {
            cout << "------------------------------------------------------------------------";  
            cin.clear();
            cin.ignore(1000, '\n');


            promptagain();
            cin.clear();
            selection = getselection(1, 3);
            // cout << "\nselection: " << selection << endl;
            // selection = getselection(1, 3);

            switch (selection) {
                case 1:
                    keepnums = true;
                    keeprunning = true;
                    break;
                case 2:
                    keepnums = false;
                    keeprunning = true;
                    break;
                case 3:
                    keeprunning = false;
                    keepnums = false;
                    // cout << "keeprunning: " << keeprunning << "  keepnums: " << keepnums << endl;
                    break;
                }
        }
    }
    while (keeprunning == 1);

    //if true, the menu() fcn will loop. is defaulted to true unless the user selects an option that will make it false.
    return keeprunning;

}


//prints out the smaller menu asking the user to exit or keep going.
void promptagain() {
    cout << "\n\n\nTo continue please select from the following:\n";
    cout << "1. Keep current numbers and go back to menu a\n";
    cout << "2. Select new numbers and go back to menu\n";
    cout << "3. Exit program.\n";
    cout << "------------------------------------------------------------------------\n";
}


//validates the user's input, limited to the available options.
int getselection(int min, int max) {
    int selection;
    do { 
        cout << "Your selection: ";
        
        cin.clear();
        cin >> selection;
        if (selection >= min && selection <= max) {
            //if it makes it here then the selection is within 1 - 7, making the condition true and thus valid. continues fcn.
            cout << "------------------------------------------------------------------------\n\n";
            break;
            }

        //else - fails the test and warns user.
        else {
                cout << "\nINVALID SELECTION\n";
                cin.clear();
                cin.ignore(1000, '\n');
                //since there is no break; the do {} conditional will loop.
            }
        }
    while (true);
    // cout << "debug: selection : " << selection << endl;
    return selection;

}


// void printarray(double array[], int length) {
//     cout << "\n\nnums[] : \n";
//     for (int n=0; n < length; n++){
//         cout << "nums[" << n << "]" << array[n] << endl;
//     }
// }

double smallestvalue(double nums[], bool dotest) {
    double result;

    //Test each number starting at element 0 againt each other number from the 5 prompted values.
    if (nums[0] < nums[1] && nums[0] < nums[2] && nums[0] < nums[3] && nums[0] < nums[4]) {

        if (dotest == false) {
        printf("\n\n\n\nYou chose to find the smallest value from the 5 numbers:\n\n%.2f is the smallest number\n\n", nums[0]);
        }
        result = nums[0];
        }
    else if (nums[1] < nums[0] && nums[1] < nums[2] && nums[1] < nums[3] && nums[1] < nums[4]) {
        if (dotest == false) {
        printf("\n\n\n\nYou chose to find the smallest value from the 5 numbers:\n\n%.2f is the smallest number\n\n", nums[1]);
        }
        result = nums[1];
        }
    else if (nums[2] < nums[0] && nums[2] < nums[1] && nums[2] < nums[3] && nums[2] < nums[4]) {
        if (dotest == false) {
        printf("\n\n\n\nYou chose to find the smallest value from the 5 numbers:\n\n%.2f is the smallest number\n\n", nums[2]);
        }
        result = nums[2];
    }
    else if (nums[3] < nums[0] && nums[3] < nums[1] && nums[3] < nums[2] && nums[3] < nums[4]) {
        if (dotest == false) {
        printf("\n\n\n\nYou chose to find the smallest value from the 5 numbers:\n\n%.2f is the smallest number\n\n", nums[3]);
        }
        result = nums[3];
    }
    else if (nums[4] < nums[0] && nums[4] < nums[1] && nums[4] < nums[2] && nums[4] < nums[3]) {
        if (dotest == false) {
        printf("\n\n\n\nYou chose to find the smallest value from the 5 numbers:\n\n%.2f is the smallest number\n\n", nums[2]);
        }
        result = nums[4];
    }
    else if (nums[4] == nums[0] && nums[4] == nums[1] && nums[4] == nums[2] && nums[4] == nums[3]) {
        if(dotest == false) {
            cout << "\n\n\n\nYou chose to find the smallest value from the 5 numbers:\n\nThey are all equal.\n\n";
        }
    }

    //save the result to it's designated element.
    nums[8] = result;
    return result;
}

double largestvalue(double nums[], bool dotest) {
    double result;

    // cout << "\n";
    //Test each number starting at element 0 againt each other number from the 5 prompted values.
    if (nums[0] > nums[1] && nums[0] > nums[2] && nums[0] > nums[3] && nums[0] > nums[4]) {
        // cout << "nums[0] < nums[" << n << "]";
        if (dotest == false) {
            printf("\n\n\n\nYou chose to find the largest value from the 5 numbers:\n\n%.2f is the largest number\n\n", nums[0]);
            result = nums[0];
            }
        }
    else if (nums[1] > nums[0] && nums[1] > nums[2] && nums[1] > nums[3] && nums[1] > nums[4]) {
        if (dotest == false) {
            printf("\n\n\n\nYou chose to find the largest value from the 5 numbers:\n\n%.2f is the largest number\n\n", nums[1]);
            }
        result = nums[1];
    }
    else if (nums[2] > nums[0] && nums[2] > nums[1] && nums[2] > nums[3] && nums[2] > nums[4]) {
        if (dotest == false) {
            printf("\n\n\n\nYou chose to find the largest value from the 5 numbers:\n\n%.2f is the largest number\n\n", nums[2]);
        }
        result = nums[2];
    }
    else if (nums[3] > nums[0] && nums[3] > nums[1] && nums[3] > nums[2] && nums[3] > nums[4]) {
        if (dotest == false) {
            printf("\n\n\n\nYou chose to find the largest value from the 5 numbers:\n\n%.2f is the largest number\n\n", nums[3]);
            }
        result = nums[3];
    }
    else if (nums[4] > nums[0] && nums[4] > nums[1] && nums[4] > nums[2] && nums[4] > nums[3]) {
        if (dotest == false) {
            printf("\n\n\n\nYou chose to find the largest value from the 5 numbers:\n\n%.2f is the largest number\n\n", nums[4]);
            }
        result = nums[4];
    }
    else if (nums[4] == nums[0] && nums[4] == nums[1] && nums[4] == nums[2] && nums[4] == nums[3]) {
        if(dotest == false) {
        cout << "\n\n\n\nYou chose to find the largest value from the 5 numbers:\n\nthey are all equal.\n" << endl;
        }
        return 0;
    }

    //save the result to it's designated element.
    nums[9] = result;
    return result;
}

void promptname() {
    string name;
    cout << "Hello, Please enter your name : ";
    getline(cin, name);
    cin.clear();

    cout << "\nHello " << name << "." << endl;
}
