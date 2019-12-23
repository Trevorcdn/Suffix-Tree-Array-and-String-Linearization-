#include "suffixArray.h"

#include <iostream>
#include <string>

using namespace std;

/* Main.cpp is used for manual testing of the applications*/

int main() {
    // Get string input from the user
    string S;
    
    cout << "Enter a string S: ";
    cin >> S;

    suffixArray str (S);
    str.outputSuffixArray();
    
    return 0;
}