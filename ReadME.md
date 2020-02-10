This folder contains three C++ files (spellcheck.C, dictionary.h, and dictionary.C) and 3 text files.
1) First implement a dictionary tree that provides the abilities for a caller to insert words
to a tree to build a dictionary and search the tree to find if a given word matches (caseinsensitive search) any stored word in the tree.
2) Then write code to test your dictionary tree implementation by building a dictionary
tree from a source dictionary text file and then use the dictionary tree to perform spell
checks on all words read from another text file and print out all misspelled words there. 


--Dictionary.h --
This is the header file for dictinary.C. Inlucdes all libraries needed. I create the Dictentry Object and defines is parameters.
I also define the size of the children to be 27. One for every letter in the alphabet plus a apostrophe (26+1).

--Dictionary.C--
This file allows you to create a newEntry, insert a new entry to the Dictionary, and search for an entry in the Dicitonary.
newEntry is O(n)
insert is O(n)
search is O(n)

--Spellcheck.C--
This reads is a file of words to be added to create our dictionary. Once all the words have been added to the tree it reads another file
and goes through that file and seaches if every words is contained in the dictionary. If not then it is outputted because it is either 
spelled wrong or not consider a valid word depending on the intial text file.

