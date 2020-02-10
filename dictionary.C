#include <iostream>
//include header file
#include "dictionary.h"
using namespace std;

//create a strcut class for a new entry, set isEndofWord to false and set all the children
//pointer to null, then return the entry
inline Dictentry *newEntry(void){
    Dictentry *entry=new Dictentry;
    entry->isEndOfWord=false;
    for (int i=0; i<ALPHA; i++){
        entry->children[i]=NULL;
    }
    return entry;
};
//1. loop through string by each character
// start at root
// 2. find the correct index of the character for example A=0, B=1, C=2, etc
// .... and a=0, b=1, c=2 and include index for apostrophe in the 26th index
//3. check if character exists in the tree, 2a. if not add new entry
//3b.. if there is, continue to the next entry
//4. end of loop, change last entry endofWord to true
inline void insert(string entry, struct Dictentry *root){
    //2. start from the root
    struct Dictentry *currentNode =root;
    //1. loop
    for(int i=0; i<entry.length(); i++){
        //2. index
        int index= entry[i];
        //calculate index based off ASCII #
        if(index>=65 && index<91){
            index=index-65;
        }
        if(index>=97 && index<123){
            index=index-97;
        }
        if(index==39){
            index=index-13;
        }
        //if character is null create a new entry
        if (currentNode->children[index]==NULL){
            currentNode->children[index]= newEntry();
        }
        //move on to the next character
        currentNode= currentNode->children[index];
    }
    //mark end of word
    currentNode->isEndOfWord = true;
}

//1.check if tree is empty, if so return false, if not continue
//2.starting at the root node loop through the entry by each cahracter
//3. calculate the index of the character
//4. if the char equals null it means that path doesn't exist so it would be false
//5. After loop is completed check if isEndofword equals true
inline bool search(string entry, struct Dictentry *root){
    //2. start at the root
    struct Dictentry *currentNode = root;
    //1. check for enmpty tree
    if(currentNode==NULL){
        return false;
    }
    //2. loop
    for(int i=0; i<entry.length(); i++){
        //3. index
        int index= entry[i];
        if(index>=65 && index<91){
            index=index-65;
        }
    
        if(index>=97 && index<123){
            index=index-97;
        }
        if(index==39){
            index=index-13;
        }
        //4. checks to see if current chacater path is in the tree, if no false
        if(!currentNode->children[index]){
            return false;
        }
        //go to the next character
        currentNode = currentNode->children[index];
    }
    //5. checks to see is endofword is true and is current node isn't null, if so return true
    return (currentNode != NULL && currentNode->isEndOfWord);
}