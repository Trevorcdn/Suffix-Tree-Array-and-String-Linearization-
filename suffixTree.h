#ifndef SUFFIXTREE_H
#define SUFFIXTREE_H 
#include <unordered_map> // Required c++11 support.
#include "node.h"
#include "edge.h"
#include <iostream>

class suffixTree {
    public:
        // TODO rootNode is not a good name, change this.
        int rootNode;   // Origin of the suffix tree
        int startIndex; // Starting index of the string represented.
        int endIndex;   // End index of the string represented.

        // Constructor
        suffixTree() :
            rootNode(0), 
            startIndex(-1),
            endIndex(-1){};
        suffixTree(int root, int start, int end) :
            rootNode(root),
            startIndex(start),
        endIndex(end) {};
        // Real means that the suffix string ends at a node and thus the
        // remaining string on that edge would be an empty string.
        bool endReal() {return startIndex > endIndex;} 
        // Img means that the suffixTree of current string ends on an imaginary
        // node, which means in between an edge. 
        bool endImg() {return endIndex >= startIndex;} 
        
        void migrateToClosestParent();
};

    // Additional function declarations
    Edge findEdge(int node, int asciiChar);
    long returnHashKey(int node, int c);
    void carryPhase(suffixTree &tree, int lastIndex, string Input);
    // void carryPhase(suffixTree &tree, int lastIndex); //original
    bool search(string pattern);
    int breakEdge(suffixTree &s, Edge &e);
    void printAllEdges();
    
    
    
#endif                                                                             
