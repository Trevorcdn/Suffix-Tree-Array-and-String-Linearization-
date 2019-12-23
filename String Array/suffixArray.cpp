// 7.14 Circular String Linearization
// output an Array that contains the indicies of the suffixes of the text in lexicographically smallest order
// For example, mississippi is an int array of 11,8,5,2,1,10,9,7,4,6,3

#include "suffixArray.h"
#include "suffixTree.h"
#include "edge.h"
#include "node.h"

#include <iostream>
#include <string>
#include <stdlib.h> 
#include <algorithm>
#include <vector>
#define FILLER 123
#define DELIMITER 36

using namespace std;

unordered_map <long, Edge> edgeHash;
// String Input Constructor
suffixArray::suffixArray (string str) {
    S = str;
    O = str; // save original string without delimeter
    // Append delimeter
    S.append("$");
    // Initialize counter for Answer array
    counter = 0;
    // Initialize Answer array
    Answer = new int[O.size()];
}

// Destructor
suffixArray::~suffixArray() {
    edgeHash.clear();
    Node::noOfNodes = 1;
}

// Solve 7.14; Output the suffix array 
void suffixArray::outputSuffixArray() {
    int* answer = new int[S.size()]; 
    
    // Call functions below to output the suffix array
    constructSuffixTree();
    answer = DFS();
    
    // for(int i = 0; i <S.size(); i++)
    //   cout << answer[i] <<endl;
    
    printAllEdges();
    // return answer;    
    
    cout<<"_______THIS IS THE ANSWER VECTOR____________"<<endl;
    for(int i = 0; i <S.size() -1; i++)
      cout<<Answer[i]<<endl;
      
      
      
}

// Build the suffix tree for LL$
void suffixArray::constructSuffixTree() {
    T.rootNode = 0;
    T.startIndex = 0;
    T.endIndex = -1;
    
    for (int i = 0; i <= S.size(); i++)
        carryPhase(T, i, S);   
}

// DFS the suffix tree in lexicographic order and stop once we’ve reached a string-depth of n
int* suffixArray::DFS() {
    int node = 0; // starting node
    
    // Mark all the vertices as not visited
    int* visited = new int[S.size()];
    
    for (int i = 0; i < S.size(); i++)
        visited[i] = 0;

    // Call the recursive helper function to print DFS traversal
    int* array = new int[O.size()];
    array = DFSUtil(node, visited);

    return array;
}

// DFS Helper Function
int* suffixArray::DFSUtil(int node, int* visited) {
    // Mark the current node as visited
    cout << "NODE: " << node << " is VISITED" << endl;
    visited[node] = 1;
    
    // Base case; if node is leaf
    bool isLeaf = false;
    
    for (int i = 0; i < S.size(); i++) {
        Edge e = Edge::findEdge(node, S[i]);
        
        if (e.startNode == -1)  // if invalid edge
            isLeaf = true;
        else { // if valid edge exists
            isLeaf = false;
            break;
        }
    }
    
    if (isLeaf) {
        cout << "----------------------LEAF at node------------------- " << node << endl;
         for (auto it = edgeHash.begin(); it != edgeHash.end(); it++) {
            if(node == it->second.endNode && it->second.startNode == 0)
            {
                Answer[counter] = it->second.startLabelIndex + 1;
                counter++;
                break;
            }
            else if(node == it->second.endNode)
                 {  Answer[counter] = it->second.startLabelIndex;
                    counter++;
                    break;
                     
                 }
         }
        //Answer.push_back(node);
        return visited;
    }

    // Initialize array to sort in lexicographic order
    int array[S.size()];

    // Find all edges of given node
    for (int i = 0; i < S.size(); i++) {
        Edge e = Edge::findEdge(node, S[i]);

        if (e.startNode != -1 && visited[e.endNode] == 0) { // if valid edge and not visited
            array[i] = S[i]; 
            if (node == 0 && array[i] == DELIMITER) // ignore first delimeter
                array[i] = FILLER;
            cout << "VALID EDGE. Node: "<< node << " startNode: "<< e.startNode << " endNode: " << e.endNode << " Letter: "<< (char)array[i] << endl;
        }
        else // Get "rid" of unwanted elements in array
            array[i] = FILLER;
    }
        
    // Sort by smallest lexicographic ordeccr
    sort(array, array + S.size());
    
    cout << "SORTED ARRAY: " << endl;
    for (int i = 0; i < S.size(); i++) {   
        cout << (char)array[i] << " " ;
    }
    cout << endl;
    
    // DFS the suffix tree in smallest lexicographic order (first element of array is the smallest) 
    // and mark as visited
    Edge e = Edge::findEdge(node, array[0]);

    cout << "NODE AT: " << node << endl;
    cout << "----> endNode is " << e.endNode << endl;
    
    // Recursion
    DFSUtil(e.endNode, visited);
    
    // Check for unvisited paths
    for (int i = 0; i < S.size(); i++) {
        Edge e = Edge::findEdge(node, array[i]);
        
        if (e.startNode != -1 && visited[e.endNode] == 0) {
            cout << "checking for unvisited paths!" << endl;
            DFSUtil(e.endNode, visited);
        }
    }
    
    return visited;
}