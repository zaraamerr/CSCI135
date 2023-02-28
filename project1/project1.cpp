//Name: Zara Amer
//CSCI135
//Date: Feb 27 2023
//Professor Maryash
//Task A Project 1


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;
string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    string word, pos, definition;
    while (fin >> word >> pos >> definition) {
        getline(fin, definition);
        g_words[g_word_count] = word;
        // cout << g_words[g_word_count] << endl;
        // cout << g_words << endl;
        // cout << word << endl;
        g_pos[g_word_count] = pos.substr(0, pos.length());
        // cout << g_pos[g_word_count] << endl;
        g_definitions[g_word_count] = definition.substr(1);
        // cout << g_definitions[g_word_count] << endl;
        g_word_count++;

        if (g_word_count >= g_MAX_WORDS) {
            cerr << "Error: Exceeded maximum number of words" << endl;
            exit(1);
        }
    }

    fin.close();
}

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array
*/
int getIndex(string word){
    for (int i = 0; i < g_word_count; i++){ //loop thru all words in array
        if (g_words[i]==word){ //if a word in the array matches the query word
            return i; //return index of that word
        }
    } 
    return -1; //else return -1 if not found
}

/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getDefinition(string word){
    int index = getIndex(word); //create var called index and use prev 
                                //function to set it to the index of a word
                                //in the array
    if (index == -1){ //if the index of the word isnt found
        return "NOT_FOUND"; //consequently the definition of the word can't also be found
    }
    return g_definitions[index]; //else, return the definition of the word
                                // at the index
}

/*
    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos) 
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getPOS(string word){
    int index = getIndex(word); //create var called index and use prev 
                                //function to set it to the index of a word
                                //in the array
    if (index == -1){ //if the index of the word isnt found
        return "NOT_FOUND"; //consequently the pos of the word can't also be found
    }
    return g_pos[index]; //else, if index and word is found, return its POS
}


/*
    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`
*/

int countPrefix(string prefix){
    int count= 0; //counter variable
    for (int i=0; i < g_word_count; i++){ //loop thru all words in array
        if(g_words[i].substr(0, prefix.length())==prefix){ 
                            //check if given prefix
                            //matches the prefix of any word in the array
            count++; //increment
        }
    }
    return count; //return # of words that start with the given prefix
}




// int main() {
//     readWords("dict.txt");

//     for (int i = 0; i < g_word_count; i++) {
//         cout << g_words[i] << " " << g_pos[i] << ": " << g_definitions[i] << endl;
//     }
//     string word = "Grumpy";
//     string word2 = "Happy";

//     int index = getIndex(word);
//     cout << index << endl;
//     int index2 = getIndex(word2);
//     cout << index2 << endl;
//     string definition1 = getDefinition(word);
//     cout << definition1 << endl;
//     string definition2 = getDefinition(word2);
//     cout << definition2 << endl;
//     string pos1 = getPOS(word);
//     cout << pos1 << endl;
//     string pos2 = getPOS(word2);
//     cout << pos2 << endl; 
//     string prefix1= "Gru";
//     int count = countPrefix(prefix1);
//     cout << count << endl;
//     return 0;
// }
