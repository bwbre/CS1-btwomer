#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void getarraysize(size_t&);

//number of things being passed into array, array size
void populateArray(char[], size_t);

//when pointing to array 

int main(int argc, char *argv[]) {
    size_t arrSize = 10;
    getarraysize(arrSize);
    char nums[arrSize];

    // int *ptr1;
    // int counter;

    populateArray(nums, arrSize);

    cout << "please enter how many elements you want in the array: ";
    cin >> arrSize;

    cout << '\n' << (25 % 2);
    cout << "the size of nums is: " << sizeof(nums) << endl;
    // //first block of array is the address of the array so nums[0] is == &
    // cout << "the address for nums[0] is: " << &nums[0] << endl;


    //While loops are optional. use it when you know how many time u need... for for dont know
    // while (int i = 0; i < arrSize; i++) {
    //     cout << "please enter number: ";
    //     cin >> nums[counter];
    //     counter++;
    // }

    // for(int i = 0; i < arrSize; i++) {
    //     cout << "please enter number: ";
    //     cin >> arrSize;
    // }

    // for(int i = 0; i < arrSize; i++) {
    //     cout << "num[" << i << "] " << nums[i] << endl;
    // }








    // // cout << "\n The size of the array is: " << sizeof[nums] << endl;

    // for (int i = 0, i < arrSize, i++) {
    //     cout << "The address for nums[" << i << "] is: " << &nums[i] << endl;


    // }

    // ptr1 = &nums[0];

    // for (int i=o, i<0, i++) {
    //     cout <<"The address stored in ptr1 is: " << ptr1 << endl;
    //     ptr1++

    // }

}


void getarraysize(size_t&, int arrSize) {
    cout << "Array size is: " << arrSize << endl;
    cin >> arrSize;

}

void populateArray(nums) {
    for (int i = 0, i < arrSize, i++) {
        cout << "The address for nums[" << i << "] is: " << &nums[i] << endl;


    }

}