#include "suffixTree.h"
#include "edge.h"
#include "node.h"
#include "gtest/gtest.h"

using testing::Test;
#include <algorithm>
#include <random>
#include <string>

#define NUM_TEST_CASES 10000
#define RANDOM_STRING_SIZE 100
unordered_map <long, Edge> edgeHash;

TEST(suffixTreeSanityCheck, PatternMatchesInText) {
    const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
    std::default_random_engine generator;
    std::uniform_int_distribution<int> letterDistribution(0, 25);
    std::uniform_int_distribution<int> substringDistribution(1, RANDOM_STRING_SIZE);
 
    // Create string T
    std::string T = " ";
    
    for (int j = 0; j < RANDOM_STRING_SIZE; j++) {
      T.push_back('a' + letterDistribution(generator));
    }
    
    // Create Suffix Tree based on T
    suffixTree tree;
    tree.rootNode = 0;
    tree.startIndex = 0;
    tree.endIndex = -1;
  
    // Carry out different phases.
    for (int i = 0; i <= RANDOM_STRING_SIZE; i++)
         carryPhase(tree, i, T);
 
    

    // Creates a Pattern,P, that is a random substring with random size from T    
    for (int i = 0; i < NUM_TEST_CASES; i++) {    
        
        // Arbitrarily calculate substring indexes of T
        int start = substringDistribution(generator), end = substringDistribution(generator);
        
        if (start > end) // Range check
          std::swap(start, end); 
        
        std::string P = T.substr(start, end);
        // Test for equality
        EXPECT_EQ(search(P), true);
    }
    
}



int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

