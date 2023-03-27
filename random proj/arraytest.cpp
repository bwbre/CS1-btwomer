#include <iostream>

using namespace std;

   
   
int main() {   
    int nums[12];
    for (int n = 1; n <= 11; ++n){
        nums[n] = n+1;
        cout << "nums[" << n << "]: " << nums[n] << endl;
    }

    nums[5] = "test";
    cout << string(nums[5])
    cout << nums[12];

    cout << "the end.";
    return 0;
}