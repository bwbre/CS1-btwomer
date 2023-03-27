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
array nums[] will store all the values that will be worked with.
nums[0 -> 4] are the user selected numbers
nums[5] sum
nums[6] product
nums[7] average
nums[8] smallestvalue
nums[9] largestvalue
nums[10] definefloor

---nums[] = {num1, num2, num3, num4, num5, sum, product, avg, smallestvalue, largestvalue, definefloor}

*/
#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

void printarray(double*, int);
double smallestvalue(double*, bool);
double largestvalue(double*, bool);
bool menu(double*, bool);
int getselection(int, int);
void printmenu();
void promptagain();

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

        if (dotest == false) {
            printf("\n%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", nums[0], nums[1], nums[2], nums[3], nums[4], result);
            cout << "The sum of all 5 numbers is: " << result << " And num[5] = " << nums[5] << endl;
        }   
        //store the result in element 6 of nums[]
        nums[5] = result;

        return result;
    }

//will calculate the product and will save the result in the 7th element -- nums[6]
template <class T1>
    T1 product(T1 nums[]) {
        T1 result = (nums[1] * nums[2] * nums[3] * nums[4] * nums[0]);
        printf("\n%.2f * %.2f * %.2f * %.2f * %.2f = %.2f\n", nums[0], nums[1], nums[2], nums[3], nums[4], result);
        //store the result in element 7 of nums[]
        nums[6] = result; 
        cout << "The product of all 5 numbers is : " << result << " And num[6] = " << nums[6] << endl;
        return 0;
    }

// will calculate the average and will save the result in the 8th element -- nums[7]
template <class T1>
    T1 avg(T1 nums[]) {
        T1 result = ((sum(nums, false)) / 5);
        // printf("\n%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\nT", nums[0], nums[1], nums[2], nums[3], nums[4], result);
        nums[7] = result; 
        cout << "\nThe average of all 5 numbers is : " << result << " And num[6] = " << nums[7] << endl;

        return 0;
    }


//I dont want to use strings so im arbritarily assigning 0 = zero, 1 = even, 2 = odd.
template <class T1>
    T1 definefloor(T1 nums[]) {
        T1 sumt = sum(nums , false);
            // cout << "Sum: " << sumt << endl;
            int remainder = (int(sumt) % 2);
        if (remainder == 0 && sumt == 0) {
            cout << "\nThe sum floor is zero\n";
            nums[10] = 0;
        }
        else if (remainder == 0 && sumt != 0){
            cout << "\nThe sum floor is even\n";
            nums[10] = 1;
        } 
        else {
            cout << "\nThe sum floor is odd\n";
            nums[10] = 2;
        }
    return 0;
    }

template <class T>
    T test(T nums[],bool dotest) {
    //create test array and result variable that will be tested
    // double nums[5] = {1, 4, 5, 6, 8};
    // double nums[5] = {10, 6, 15, 20, 12};
    // double nums[5] = {0, 2, 7, 5.5, 12};
    // double nums[5] = {0,0,0,0,0};
    T resultt;

    nums[0] = 1;
    nums[1] = 4;
    nums[2] = 5;
    nums[3] = 6;
    nums[4] = 8; 
    cout << endl;

    for (int n = 1; n <= 11; ++n){
        nums[n] = n+1;
        cout << "nums[" << n << "]: " << nums[n] << endl;
    }
    resultt = sum(nums, false);
    assert(resultt == 24);
    resultt = smallestvalue(nums, false);
    assert(resultt == 1);
    resultt = largestvalue(nums, false);
    assert(resultt == 8);
    resultt = product(nums);
    assert(resultt == 960);
    resultt = avg(nums);
    assert(resultt == 4.8 );
    resultt = definefloor(nums);
    assert(resultt == 1 );


    nums[0] = 10;
    nums[1] = 6;
    nums[2] = 15;
    nums[3] = 20;
    nums[4] = 12;
    cout << endl;


    for (int n = 1; n <= 11; ++n){
        nums[n] = n+1;
        cout << "nums[" << n << "]: " << nums[n] << endl;
    }

    resultt = sum(nums, false);
    assert(resultt == 63);
    resultt = smallestvalue(nums, false);
    assert(resultt == 6);
    resultt = largestvalue(nums, false);
    assert(resultt == 20);
    resultt = product(nums);
    assert(resultt == 216000);
    resultt = avg(nums);
    assert(resultt == 12.6 );
    resultt = definefloor(nums);
    assert(resultt == 2 );

    nums[0] = 0;
    nums[1] = 2;
    nums[2] = 7;
    nums[3] = 5.5;
    nums[4] = 12; 
    cout<< endl;

    for (int n = 1; n <= 11; ++n){
        nums[n] = n+1;
        cout << "nums[" << n << "]: " << nums[n] << endl;
    }
    resultt = sum(nums, false);
    assert(resultt == 26.5);
    resultt = resultt = smallestvalue(nums, false);
    assert(resultt == 0);
    resultt = largestvalue(nums, false);
    assert(resultt == 12);
    resultt = product(nums);
    assert(resultt == 0);
    resultt = avg(nums);
    assert(resultt == 5.3 );
    resultt = definefloor(nums);
    assert(resultt == 1 );

    nums[0] = 0;
    nums[1] = 0;
    nums[2] = 0;
    nums[3] = 0;
    nums[4] = 0; 
    cout << endl;

    for (int n = 1; n <= 11; ++n){
        nums[n] = n+1;
        cout << "nums[" << n << "]: " << nums[n] << endl;
    }

    resultt = sum(nums, false);
    assert(resultt == 0);
    resultt = smallestvalue(nums, false);
    assert(resultt == 0);
    resultt = largestvalue(nums, false);
    assert(resultt == 0);
    resultt = product(nums);
    assert(resultt == 0);
    resultt = avg(nums);
    assert(resultt == 0);
    resultt = definefloor(nums);
    assert(resultt == 0);

}




int main(int argc, char* argv[]) {
    //create array that will hold all the values that will be used in the program.
    /*
    
    */
    double nums[11] = {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0};

    bool dotest = true;

    //keeprunning will remain true until the user prompts to end the program.
    bool keeprunning;
    keeprunning = true;

    //test functions when test is used as an argument.
    if (dotest = true) {
        cout << "\ntest time\n";
        test<double, bool>(nums, true);
        cout << "test passed" <<endl;
    }

    //this essentially runs the whole program.
    do {
        if (keeprunning == true) {
            keeprunning = menu(nums, false);
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
    cout << "\n\n\n\nPlease select one of the following options:\n\n";
    cout << "1. Calculate the sum of the 5 numbers.\n";
    cout << "2. Calculate the product of the 5 numbers.\n";
    cout << "3. Calculate the average of the 5 numbers.\n";
    cout << "4. Find the smallest value among the 5 numbers.\n";
    cout << "5. Find the largest value among the 5 numbers.\n";
    cout << "6. Find whether the floor of sum of the 5 numbers is even, odd, or 0.\n";
    cout << "7. Print array.\n";
    cout << "8. Exit Program\n";
    cout << "------------------------------------------------------------------------\n" << endl; 
}

//
bool menu(double nums[], bool dotest) {
    int selection;
    dotest = true;
    //if keeprunning == true at the very end, then the menu() fcn will loop.
    bool keeprunning = true;

    // will be used to flag the conditional whether or not a new set of numbers are needed.
    bool keepnums = false;

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
            selection = getselection(1,9);
            switch(selection) {
                case 1:
                    cout << "do test: " << dotest<< endl;
                    sum(nums, dotest);
                    break;
                case 2:
                    product(nums);
                    break;
                case 3:
                    avg(nums);
                    break;
                case 4:
                    smallestvalue(nums, dotest);
                    break;
                case 5:
                    largestvalue(nums, dotest);
                    break;
                case 6:
                    definefloor(nums);
                    break;
                case 7:
                    printarray(nums, 10);
                    break;
                case 8:
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
    cout << "\n\nTo continue please select from the following:\n";
    cout << "1. Keep current numbers and go back to menu a\n";
    cout << "2. Select new numbers and go back to menu\n";
    cout << "3. Exit program.\n\n";
}


//validates the user's input, limited to the available options.
int getselection(int min, int max) {
    int selection;
    do { 
        cout << "Your selection: ";
        cin.clear();
        cin >> selection;
        if (selection >= min && selection <= max) {
            //if it makes it here then the selection is within 1 - 8, making the condition true and thus valid. continues fcn.
            cout << "\n------------------------------------------------------------------------\n";
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
    return selection;

}


void printarray(double array[], int length) {
    cout << "\n\nnums[] : \n";
    for (int n=0; n < length; n++){
        cout << "nums[" << n << "]" << array[n] << endl;
    }
}

double smallestvalue(double nums[], bool dotest) {
    double result;
    cout << "\n";
            cout << "\nnums[0] " << nums[0] << "]\n";
            cout << "nums[1] "  << nums[1] << "]\n";
            cout << "nums[2] " << nums[2] << "]\n";
            cout << "nums[3] " << nums[3] << "]\n";
            cout << "nums[4] " << nums[4] << "]\n";
    //Test each number starting at element 0 againt each other number from the 5 prompted values.
    if (nums[0] < nums[1] && nums[0] < nums[2] && nums[0] < nums[3] && nums[0] < nums[4]) {

        if (dotest == false) {
        printf("num[0]   %.2f is the smallest number\n\n", nums[0]);
        }
        result = nums[0];
        }
    else if (nums[1] < nums[0] && nums[1] < nums[2] && nums[1] < nums[3] && nums[1] < nums[4]) {
        if (dotest == false) {
        printf("num[1]   %.2f is the smallest number\n\n", nums[1]);
        }
        result = nums[1];
        }
    else if (nums[2] < nums[0] && nums[2] < nums[1] && nums[2] < nums[3] && nums[2] < nums[4]) {
        if (dotest == false) {
        printf("num[2]   %.2f is the smallest number\n\n", nums[2]);
        }
        result = nums[2];
    }
    else if (nums[3] < nums[0] && nums[3] < nums[1] && nums[3] < nums[2] && nums[3] < nums[4]) {
        if (dotest == false) {
        printf("num[3]   %.2f is the smallest number\n\n", nums[3]);
        }
        result = nums[3];
    }
    else if (nums[4] < nums[0] && nums[4] < nums[1] && nums[4] < nums[2] && nums[4] < nums[3]) {
        if (dotest == false) {
        printf("num[4]   %.2f is the smallest number\n\n", nums[2]);
        }
        result = nums[4];
    }
    else {
        cout << "\nDEBUG: there is not a smallest number.\n\n";
    }

    //save the result to it's designated element.
    cout << result << " dddd---";
    nums[8] = result;
    return result;
}

double largestvalue(double nums[], bool dotest) {
    double result;
    cout << "\n";
    //Test each number starting at element 0 againt each other number from the 5 prompted values.
    if (nums[0] > nums[1] && nums[0] > nums[2] && nums[0] > nums[3] && nums[0] > nums[4]) {
        // cout << "nums[0] < nums[" << n << "]";
        if (dotest == false) {
            printf("nums[0], or %.2f is the largest number\n", nums[0]);
            result = nums[0];
            }
        }
    else if (nums[1] > nums[0] && nums[1] > nums[2] && nums[1] > nums[3] && nums[1] > nums[4]) {
        if (dotest == false) {
            printf("nums[1], or %.2f is the largest number\n", nums[1]);
            }
        result = nums[1];
    }
    else if (nums[2] > nums[0] && nums[2] > nums[1] && nums[2] > nums[3] && nums[2] > nums[4]) {
        if (dotest == false) {
            printf("nums[2], or %.2f is the largest number\n", nums[2]);
        }
        result = nums[2];
    }
    else if (nums[3] > nums[0] && nums[3] > nums[1] && nums[3] > nums[2] && nums[3] > nums[4]) {
        if (dotest == false) {
            printf("nums[3], or %.2f is the largest number\n", nums[3]);
            }
        result = nums[3];
    }
    else if (nums[4] > nums[0] && nums[4] > nums[1] && nums[4] > nums[2] && nums[4] > nums[3]) {
        if (dotest == false) {
            printf("nums[4], or %.2f is the largest number\n", nums[4]);
            }
        result = nums[4];
    }
    else {
        cout << "DEBUG: there is not a largest number.\n";
    }

    //save the result to it's designated element.
    nums[9] = result;
    cout << "result = " << result<<endl;
    return result;
}


