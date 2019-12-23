#ifndef LINEARIZATION_H
#define LINEARIZATION_H 

#include "suffixTree.h"
#include <iostream>
#include <string>

using namespace std;

class Linearization {
    private:
        string S;
        string L;
        suffixTree T;
    public:
        Linearization(string); // Constructor
        ~Linearization(); // Destructor
        void createStringL(); // Arbitrarily cut the string S, resulting in a linear string L
        void constructSuffixTree(); // Build the suffix tree for LL$
        string DFS(); // DFS the suffix tree in lexicographic order and stop once we’ve reached a string-depth of n
        int DFSUtil(int, int, int*); // DFS Helper function
        string linearizeCircularString(); // Solve 7.13
};

#endif   