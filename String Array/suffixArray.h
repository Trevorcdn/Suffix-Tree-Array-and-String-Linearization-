#ifndef SUFFIXARRAY_H
#define SUFFIXARRAY_H 

#include "suffixTree.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class suffixArray {
    private:
        string S;
        string O;
        suffixTree T;
        int counter;
    public:
        int* Answer;
        suffixArray(string); // Constructor
        ~suffixArray(); // Destructor
        void constructSuffixTree(); // Build the suffix tree for LL$
        int* DFS(); // DFS the suffix tree in lexicographic order and stop once we’ve reached a string-depth of n
        int* DFSUtil(int, int*); // DFS Helper function
        void outputSuffixArray(); // Solve 7.14
        
};
#endif   