#include <gtest/gtest.h>
#include <string.h>

#define NUM_CHAR 26

char FirstMissingAlphabet(std::string inputString)
{
    // Find first missing alphabet
    char missing;
    bool foundList[NUM_CHAR] = {false}; //running list for marking found alphabets
    /*
    Scan the input string and mark the found alphabets.
    Check the found list until missing alphabet is reached.
    Treat upper and lower case as same, ignore special charaters (?!)
    */
    for(auto i = 0; i < inputString.size(); i++){
      if(inputString[i] >= 'a' && inputString[i] <= 'z'){
        foundList[inputString[i] - 'a'] = true;
      }else if(inputString[i] >= 'A' && inputString[i] <= 'Z'){
        foundList[inputString[i] - 'A'] = true;
      }
    }
    bool found = false;
    for(auto i = 0; i < NUM_CHAR && !found; i++){
      if(!foundList[i]){
        missing = 'a' + i;
        found = true;
      }
    }
    return missing;
}

TEST(FirstMissingAlphabet, OneCharacterInputMissingA)
{
    const std::string inputString = "abbZXwE3!&/AWbbdd";
    const char expectedMissing = 'c';
    char foundMissing = FirstMissingAlphabet(inputString);
    ASSERT_EQ(expectedMissing, foundMissing);
}
