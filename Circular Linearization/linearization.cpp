// 7.13 Circular String Linearization
// output the lexicographically smallest linearization of the circular string.

#include "linearization.h"
#include "suffixTree.h"
#include "edge.h"
#include "node.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h> 
#include <time.h>

using namespace std;

unordered_map <long, Edge> edgeHash;

// Linearization Constructor
Linearization::Linearization (string str) {
    S = str;
}

// Destructor
Linearization::~Linearization() {
    edgeHash.clear();
    Node::noOfNodes = 1;
}

// Solve 7.13; Find linearization of the circular string S
string Linearization::linearizeCircularString() {
    string answer;

    // Call functions below to solve the lexicographically smallest linearization of the circular string S
    createStringL();
    constructSuffixTree();
    
    return DFS();
}

// Arbitrarily cut the string S, resulting in a linear string L
// Create a new string by doubling L and appending a delimiter
void Linearization::createStringL() {
    int index;

    // Initialize random seed
    srand (time(NULL));
    
    // Generate random index number between 0 and S.length
    index = rand() % S.length();

    // Split the string S with randomly generated index number
    string first = S.substr(0, index);
    string last = S.substr(index, S.length());
    
    last.append(first);
    L.append(last);
    
    // Double L
    L.append(L);
    
    // Append delimeter
    L.append("$");
}

// Build the suffix tree for LL$
void Linearization::constructSuffixTree() {
    T.rootNode = 0;
    T.startIndex = 0;
    T.endIndex = -1;
    
    for (int i = 0; i <= L.size(); i++)
        carryPhase(T, i, L);   
}

// DFS the suffix tree in lexicographic order and stop once we’ve reached a string-depth of n
string Linearization::DFS() {
    string answer = ""; // empty string
    int depth = 0; // starting depth
    int node = 0; // starting node
    
    // Mark all the vertices as not visited
    int* visited = new int[L.size()];
    for (int i = 0; i < L.size(); i++)
        visited[i] = 0;

    // Call the recursive helper function to print DFS traversal
    int strlength = DFSUtil(node, depth, visited);
    
    // Return the string we’ve just traversed
    for (int i = 0; i < L.size(); i++) 
        if (visited[i])
            answer += (char)visited[i];
            
    return answer;
}

// DFS Helper Function
int Linearization::DFSUtil(int node, int depth, int* visited) {
    // Base case
    if (depth == S.size()) 
         return depth;

    int array[S.size()];
    int labelLength = 0;
    
    // Find all edges of given node
    for (int i = 0; i < S.size(); i++) {
        Edge e = Edge::findEdge(node, L[i]);
        
        if (e.startNode != -1) // if valid edge
            array[i] = L[i]; 
    }
    
    // Sort by smallest lexicographic order
    sort(array, array + S.size());

    // Calculate string depth
    Edge e = Edge::findEdge(node, array[0]);
    labelLength = e.endLabelIndex - e.startLabelIndex + 1;
    
    if (depth + labelLength > S.size()) { // check if edge exceed string depth
        for (int i = 0; i < S.size() - depth; i++) 
            visited[e.startLabelIndex + i] = L[e.startLabelIndex + i];
            
        depth = S.size();
        return depth; 
    }
    
    depth += labelLength;
    
    // DFS the suffix tree in smallest lexicographic order (first element of array is the smallest) 
    // and mark as visited
    for (int i = 0; i < labelLength; i++) 
        visited[e.startLabelIndex + i] = L[e.startLabelIndex + i];

    // Recursion
    DFSUtil(e.endNode, depth, visited);

    return depth;
}