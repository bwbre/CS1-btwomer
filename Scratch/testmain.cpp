#include <iostream>

using namespace std;

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "sizeof(arr): " << sizeof(arr) << endl;
    cout << "sizeof(arr[0]): " << sizeof(arr[0]) << endl;
    cout << "n: " << n << endl;
}