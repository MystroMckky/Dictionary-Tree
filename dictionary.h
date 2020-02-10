//libraries used through the files
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
//declare the MAX_SIZE which is equal to each letter in the alphabet which is 26 plus apostrophe
#define ALPHA 27

//create Object Dictentry, this will be the individual entries in the tree
//the will come with two properties a bool for marking end of the word
// and an array of entries size ALPHA for the children of each char
class Dictentry{
    public:
    bool isEndOfWord;
    struct Dictentry *children[ALPHA];
    
};

