#include "suffixTree.h"
#include "gtest/gtest.h"
#include "suffixArray.h"

using testing::Test;
#include <algorithm>
#include <random>
#include <string>

#define NUM_TEST_CASES 1//1000
#define RANDOM_STRING_SIZE 10//100


TEST(suffixArraySanityCheck, OutputSuffixIndiciesInLexographicalOrder) {
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
    
/*************************************************************************************
***********************NAIVE LEXOGRAPHICAL COMPARISON********************************    
*************************************************************************************/
        int textLength = T.length();
        string suffixes[textLength]; //initalize string array to hold all the possible suffixes   
        int naiveArray[textLength]; //outputs naive version of suffixArray 
        
        //Loop puts in all possible suffixes in the string array
        for(int a = 0; a < textLength; a++)
        {
            suffixes[a] = T.substr(a);
        }
        
        sort(suffixes, suffixes + textLength); //sorts the suffixes array
        
        //loop to determine the indicies of the suffixes that had been sorted lexographically small
        for(int b = 0; b < textLength; b++)
        {
            naiveArray[b] = textLength - suffixes[b].length() + 1;
        }
/*************************************************************************************
***********************END NAIVE LEXOGRAPHICAL COMPARISON****************************   
*************************************************************************************/

        // // Create Suffix Tree based on T
        // suffixTree tree (0, 0, -1);
      
        // // Carry out different phases.
        // for (int i = 0; i <= RANDOM_STRING_SIZE; i++)
        //     carryPhase(tree, i, T);

 
  
         int* suffixArrayOutput;
         suffixArray str (T); //WIP
         suffixArrayOutput = str.Answer;//WIP
         
        
        
         //Makes sure that both size of the arrays are equal or else Seg Faults
         //ASSERT_EQ(suffixArrayOutput.size(), naiveArray.size());
         
         // Test for equality of naive and Suffix tree method
         for(int j = 0; j< RANDOM_STRING_SIZE; j++)
            EXPECT_EQ(naiveArray[j], suffixArrayOutput[j]);
        
    } //end of NUM_TEST_CASES loop
    
}


int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
