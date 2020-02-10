
//include the dictionary class
#include "dictionary.C"

//driver
int main(int argc, char **argv){
    //delimeters
    const char *separators = "\n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~";
    //create new tree
    Dictentry* dict = newEntry();
    string line_c; 
    string line_b;
    ifstream fin;
    ifstream win;

    //open the spelling list txt
    fin.open("aspell_list_en.txt");

    while(fin){
        //get each word by line
        getline(fin, line_c);
        //insert each word into the tree
        insert(line_c, dict);  
    }
    //close read
    fin.close();
    fin.clear();

    //open other file to compare to the tree
    win.open("Austen-Pride-and-Prejudice.txt");
    
    while(win){
        //read in the file by line
        getline(win, line_b);
        //convert the line string to const char to use strtok
        const char *temp= line_b.c_str();
        //split each string line into individual words separated by the delimeters
        char *token = strtok((const_cast <char *> (temp)), separators);
        while(token !=NULL){
            //search if the word is in the tree, if not print out
            if(search(token, dict)==0){
                cout << token << endl;
            }
            //go to the next token
            token = strtok(NULL, separators); 
        }
    }
    //end read
    win.close();
}
