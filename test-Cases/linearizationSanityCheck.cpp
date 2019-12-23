#include "suffixTree.h"
#include "linearization.h"
#include "gtest/gtest.h"

using testing::Test;
#include <algorithm>
#include <random>
#include <string>

#define NUM_TEST_CASES 10000
#define RANDOM_STRING_SIZE 10


TEST(linearizationSanityCheck, OutputLexicographicallySmallestLinearization) {
    const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
    std::default_random_engine generator;
    std::uniform_int_distribution<int> letterDistribution(0, 25);
    std::uniform_int_distribution<int> substringDistribution(1, RANDOM_STRING_SIZE);
    
    for (int i = 0; i < NUM_TEST_CASES; i++) { 
        // Create string T
        std::string T = " ";
        
        for (int j = 0; j < RANDOM_STRING_SIZE; j++) {
          T.push_back('a' + letterDistribution(generator));
        }
  
        // ******************* Naive Linearization *******************
        std::string naiveAnswer;
        
        // Create an array of strings to store all rotations of the string T
        std::string arr[T.length()];
        
        // Concatenate the string T with itself and store it into a temporary string concat
        std::string concat = "";
        concat += T + T;
        
        // Store all rotations of T in our array
        for (int i = 0; i < T.length(); i++) 
            arr[i] = concat.substr(i, T.length());
        
        //Sort all rotations
        sort(arr, arr + T.length());
        
        // First element of the array will be lexicographically smallest linearization of the circular string T
        naiveAnswer = arr[0];
        
 
        // ******************* Linearization using suffix tree *******************
        string suffixTreeAnswer;
        Linearization circularString (T);
        suffixTreeAnswer = circularString.linearizeCircularString();
        
        // Test for equality
        ASSERT_EQ(suffixTreeAnswer, naiveAnswer);
        
   } // end of NUM_TEST_CASES loop
    
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

