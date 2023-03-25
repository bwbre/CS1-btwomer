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

Notes: at least one must be able to accept multiple data types

array for 5 nums
5] sum
6] product
7] average (using sum)
8] smallestvalue
9] largestvalue
10] definefloor(array)

---nums[] = {num1, num2, num3, num4, num5, sum, product, avg, smallestvalue, largestvalue, definefloor}

*/
#include <iostream>
#include <iomanip>

using namespace std;

void printarray(double*, int);
void smallestvalue(double*);
void largestvalue(double*);
bool menu(double*);
int getselection(int, int);
void printmenu();
void promptagain();

//will use first 5 elements of nums[]
template <class T1>
    T1 promptnums(T1 nums[]) {
        //prompt user for 5 numbers, then assign each number to the first 5 positions in the array.
        cout << "\nPlease enter 5 different numbers separated by spaces:  ";
        cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4];
        cout << "\n--Finished storing values--\n" << endl;
        // printarray(nums, 5);
        return 0;
    }

//will calculate the sum and will save the result in the 6th element -- nums[5]
template <class T1>
    T1 sum(T1 nums[]) {
        T1 result = (nums[1] + nums[2] + nums[3] + nums[4] + nums[0]);
        printf("\n%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", nums[0], nums[1], nums[2], nums[3], nums[4], result);
        //store the result in element 6 of nums[]
        nums[5] = result;
        cout << "The sum of all 5 numbers is: " << result << " And num[5] = " << nums[5] << endl;
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
        T1 result = (sum(nums) / 5);
        // printf("\n%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\nT", nums[0], nums[1], nums[2], nums[3], nums[4], result);
        nums[7] = result; 
        cout << "\nThe average of all 5 numbers is : " << result << " And num[6] = " << nums[7] << endl;

        return 0;
    }




int main() {
    //create array that will hold all the values that will be used in the program.
    double nums[11] = {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0};
    //keeprunning will remain true until the user prompts to end the program.
    bool keeprunning;
    keeprunning = true;

    cout << "\n--initializing...\n" << endl;

    do {
        menu(nums);
        keeprunning = menu(nums);
    }
    while (keeprunning == true);

    // sum(nums);
    // product(nums);
    // avg(nums);
    // smallestvalue(nums);
    // largestvalue(nums);
    // printarray(nums, 10);

    //debug
    cout << "\nGoodbye." <<endl;
    return 0;
}


void printmenu() {
    cout << "\n\n\n\n\nPlease select one of the following options:\n\n";
    cout << "1. Calculate the sum of the 5 numbers.\n";
    cout << "2. Calculate the product of the 5 numbers.\n";
    cout << "3. Calculate the average of the 5 numbers.\n";
    cout << "4. Find the smallest value among the 5 numbers.\n";
    cout << "5. Find the largest value among the 5 numbers.\n";
    cout << "6. Find whether the floor of sum of the 5 numbers is even, odd, or 0.\n";
    cout << "7. Print array.\n";
    cout << "8. Exit Program\n" << endl;
}

//using cases 
bool menu(double nums[]) {
    int selection;

    //if keeprunning == true at the very end, then the menu() fcn will loop.
    bool keeprunning = true;

    //Will start with no value, but at the end of the function the user will have the choice to keep the existing numbers(true) or get new ones(false) 
    bool keepnums;

    //check whether or not the user has prompted whether they want to use a new set of numbers.
    do  {
        promptnums(nums);
    }
    while (keepnums == false);

    printmenu();

    /*getselection(min, max) allows for the same function to fetch selections while setting a requirement for the input to 
    be within the min and max. the largest and smallest values for the cases below are 1, 9 */
    selection = getselection(1,9);
    switch(selection) {
        case 1:
            sum(nums);
            break;
        case 2:
            product(nums);
            break;
        case 3:
            avg(nums);
            break;
        case 4:
            smallestvalue(nums);
            break;
        case 5:
            largestvalue(nums);
            break;
        case 6:
            // definefloor(nums);
            break;
        case 7:
            printarray(nums, 5);
            break;
        case 8:
            // cout << "totally exiting program";
            keeprunning = false;
            break;
        default:
            cout << "DEBUG: Invalid selection";
            break;
    }

    promptagain();
    getselection(1, 3);
    // selection = getselection(1, 3);

    switch (selection) {
        case 1:
            keepnum = true;
            menu();
            break;
        case 2:
            keepnum = false;
            menu();
            break;
        case 3:
            keeprunning = false;
            break;
    }
    
    return keeprunning;
}

void promptagain();{
    cout << "\nPlease select from the following:\n";
    cout << "1. Go back to menu\n";
    cout << "2. Select new numbers and go back to menu\n";
    cout << "3. Exit program.\n\n"
}


int getselection(int min, int max) {
    int selection;
    do { cout << "Your selection: ";
        if (cin >> selection && selection >= min && selection <= max) {
            //if it makes it here then the selection is within 1 - 8, making the condition true and thus valid. continues fcn.
            break;
            }

            //else - fails the test
        else {
                cout << "\nINVALID SELECTION";
                printmenu();
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

void smallestvalue(double nums[]) {
    double result;
    cout << "\n";
    //Test each number starting at element 0 againt each other number from the 5 prompted values.
    if (nums[0] < nums[1] && nums[0] < nums[2] && nums[0] < nums[3] && nums[0] < nums[4]) {
        // cout << "nums[0] < nums[" << n << "]";
        printf("nums[0], or %.2f is the smallest number\n", nums[0]);
        result = nums[0];
        }
    else if (nums[1] < nums[0] && nums[1] < nums[2] && nums[1] < nums[3] && nums[1] < nums[4]) {
        printf("nums[1], or %.2f is the smallest number\n", nums[1]);
        result = nums[1];
        }
    else if (nums[2] < nums[0] && nums[2] < nums[1] && nums[2] < nums[3] && nums[2] < nums[4]) {
        printf("nums[2], or %.2f is the smallest number\n", nums[2]);
        result = nums[2];
    }
    else if (nums[3] < nums[0] && nums[3] < nums[1] && nums[3] < nums[2] && nums[3] < nums[4]) {
        printf("nums[3], or %.2f is the smallest number\n", nums[3]);
        result = nums[3];
    }
    else if (nums[4] < nums[0] && nums[4] < nums[1] && nums[4] < nums[2] && nums[4] < nums[3]) {
        printf("nums[2], or %.2f is the smallest number\n", nums[2]);
        result = nums[4];
    }
    else {
        cout << "DEBUG: there is not a smallest number.\n";
    }

    //save the result to it's designated element.
    nums[8] = result;
}

void largestvalue(double nums[]) {
    double result;
    cout << "\n";
    //Test each number starting at element 0 againt each other number from the 5 prompted values.
    if (nums[0] > nums[1] && nums[0] > nums[2] && nums[0] > nums[3] && nums[0] > nums[4]) {
        // cout << "nums[0] < nums[" << n << "]";
        printf("nums[0], or %.2f is the largest number\n", nums[0]);
        result = nums[0];
        }
    else if (nums[1] > nums[0] && nums[1] > nums[2] && nums[1] > nums[3] && nums[1] > nums[4]) {
        printf("nums[1], or %.2f is the largest number\n", nums[1]);
        result = nums[1];
        }
    else if (nums[2] > nums[0] && nums[2] > nums[1] && nums[2] > nums[3] && nums[2] > nums[4]) {
        printf("nums[2], or %.2f is the largest number\n", nums[2]);
        result = nums[2];
    }
    else if (nums[3] > nums[0] && nums[3] > nums[1] && nums[3] > nums[2] && nums[3] > nums[4]) {
        printf("nums[3], or %.2f is the largest number\n", nums[3]);
        result = nums[3];
    }
    else if (nums[4] > nums[0] && nums[4] > nums[1] && nums[4] > nums[2] && nums[4] > nums[3]) {
        printf("nums[4], or %.2f is the largest number\n", nums[4]);
        result = nums[4];
    }
    else {
        cout << "DEBUG: there is not a largest number.\n";
    }

    //save the result to it's designated element.
    nums[9] = result;
}