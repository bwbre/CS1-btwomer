#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <fstream>

using namespace std;


int main() {
    // double num1;
    // double num2;
    // cin >> num1 >> num2;
    // double Ans = num1 / num2;
    // cout << scientific << "sci: " << Ans << endl;
    // cout << fixed << setprecision(4) << "deci: " << Ans << endl;

    int oc_val;
    cin >> oct >> oc_val;
    cout << "dec: " << dec << oc_val + 94 << endl;
    cout << "hex: " << hex << oc_val-15<< endl;



    return 0;


}