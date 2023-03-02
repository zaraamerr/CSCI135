//Name: Zara Amer
//CSCI135
//Date: Feb 27 2023
//Professor Maryash
//Project 1


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


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

/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists 
                          or if the array reached maximum 
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/

bool addWord(string word, string definition, string pos) {
    // Check if the word already exists in the dictionary
    int index = getIndex(word);
    if (index >= 0) {
        return false; // word already exists
    }
    
    // Check if the dictionary is full
    if (g_word_count >= g_MAX_WORDS) {
        return false; // dictionary is full
    }
    
    // Add the word, definition, and pos to the end of the respective global arrays
    g_words[g_word_count] = word;
    g_definitions[g_word_count] = definition;
    g_pos[g_word_count] = pos;
    g_word_count++;
    
    return true; // word successfully added
}

/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of 
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/

bool editWord(string word, string definition, string pos) {
    int index = getIndex(word);
    if (index == -1) {
        return false;
    } else {
        g_definitions[index] = definition;
        g_pos[index] = pos;
        return true;
    }
}


/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.  
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(string word) {
    int index = getIndex(word);
    if (index == -1) {
        // word doesn't exist in the dictionary
        return false;
    }
    // shift all elements after index one position to the left
    for (int i = index; i < g_word_count - 1; i++) {
        g_words[i] = g_words[i + 1];
        g_definitions[i] = g_definitions[i + 1];
        g_pos[i] = g_pos[i + 1];
    }
    // decrease the word count and set the last element to empty string
    g_word_count--;
    g_words[g_word_count] = "";
    g_definitions[g_word_count] = "";
    g_pos[g_word_count] = "";
    return true;
}

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

// game-loop for Hangman
void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}

/*
    @param            :   The string with a word from the dictionary 
    @return           :   string of "_" based on the number of
                          characters in the given `word` 
    @post             :   Return string of "_" based on the length
                          of the given `word`.
                          For example, if the word is "game", then
                          the function would return "____". In other
                          words, a string of four "_"s.
*/

string maskWord(string word) {
    string masked = "";
    for (int i = 0; i < word.length(); i++) { //for every letter in the word
        masked += "_"; //add a space
    }
    return masked; //return the masked version of the word
}

/*
    @param            :   The integer for the difficulty of the game
                          (0 for easy, 1 for normal, and 2 for hard) 
    @return           :   The number of tries given the `difficulty`
                          (9 for easy, 7 for normal, and 5 for hard)
    @post             :   Return the number of tries based on given
                          difficulty (0-easy: 9 tries, 1-normal: 7
                          tries, 2-Hard: 5 tries) 
*/

int getTries(int difficulty) {
    if (difficulty == 0) { //easy
        return 9; //9 tries
    } else if (difficulty == 1) { //normal
        return 7; //7 tries
    } else if (difficulty == 2) { //hard
        return 5; //5 tries
    } else {
        // invalid difficulty level, return -1 or throw an exception
        return -1;
    }
}

/*
    @param tries      :   The integer for remaining tries 
    @param difficulty :   The integer for the difficulty of the game 
                          (0 for easy, 1 for normal, and 2 for hard) 
    @post             :   prints the number of lives left and number
                          of lives used using "O" and "X". DO NOT
                          PRINT AN ENDLINE

    For example : calling `printAttemps(2, 1)` would print "OOXXXXX". 
                  Based on given `difficulty`, we know the total tries
                  is 7 (from `getTries(1)`). Also, the player has 2
                  `tries` remaining based on the given parameter.
                  Therefore, the function prints two "0"s to indicate
                  the remaining tries and 5 "X"s to indicate the tries
                  that have been used (7-2=5)          
*/

void printAttempts(int tries, int difficulty) {
    int totalTries = getTries(difficulty); //num of tries based on difficulty
    for (int i = 0; i < totalTries; i++) { //iterates thru the tries
        if (i < tries) { //index less than tries
            cout << "O"; //O
        } else {
            cout << "X"; //X
        }
    }
}

/*
    @param word       :   The string word from the dictionary
    @param letter     :   The char letter that that will be revealed
    @param(&) current :   The string representing a masked word
    @return           :   `true` if the `letter` exists in `word`,
                          otherwise return `false`  
    @post             :   If the given `letter` exists in `word`
                          reveal the `letter` in `current` masked word
                          and return `true`. Otherwise, return `false`

    For example : Let's say we have the following main function:
                  int main(){
                      string w = "g___";
                      cout << revealLetter("good", 'o', "g___") << endl;
                      cout <<  w << endl;
                  }
                  The first `cout` will print 1 because the letter 'o'
                  exists in "good". Thus, the function returned `true`.
                  The second `cout` will print "goo_". The variable `w`
                  has been modified by the function to reveal all the
                  `o`s in "good" resulting in "goo_"           
*/

bool revealLetter(string word, char letter, string& current) {
    bool found = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            current[i] = letter;
            found = true;
        }
    }
    return found;
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
//     bool success = addWord("apple", "a fruit", "noun");

//     // Edit the word
//     success = editWord("apple", "a type of fruit", "noun");
//     if (success) {
//         cout << "Edit successful" << endl;
//     } else {
//         cout << "Edit failed" << endl;
//     }

//     // Remove the word
//     success = removeWord("apple");
//     if (success) {
//         cout << "Removal successful" << endl;
//     } else {
//         cout << "Removal failed" << endl;
//     }

//     return 0;
// }
